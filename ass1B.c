#include <stdio.h>
#include <gmp.h>

void karatsuba(const char* num1, const char* num2, char* result) {
    int n = 0;
    while (num1[n] != '\0' || num2[n] != '\0') {
        n++;
    }

    if (n <= 4) {
        mpz_t x, y, temp;
        mpz_inits(x, y, temp, NULL);

        mpz_set_str(x, num1, 10);
        mpz_set_str(y, num2, 10);
        mpz_mul(temp, x, y);
        gmp_printf("%Zd", temp);

        mpz_clears(x, y, temp, NULL);
        return;
    }

    int half = n / 2;
    const char* a = num1;
    const char* b = num1 + half;
    const char* c = num2;
    const char* d = num2 + half;

    char ac[2 * half + 1], bd[2 * half + 1], adbc[2 * half + 1];
    karatsuba(a, c, ac);
    karatsuba(b, d, bd);

    mpz_t x, y, z0, z1, z2, temp;
    mpz_inits(x, y, z0, z1, z2, temp, NULL);

    mpz_set_str(x, a, 10);
    mpz_set_str(y, b, 10);
    mpz_add(temp, x, y);
    gmp_printf("%Zd", temp);  // x + y

    mpz_set_str(x, c, 10);
    mpz_set_str(y, d, 10);
    mpz_add(temp, x, y);
    gmp_printf("%Zd", temp);  // z1

    karatsuba(ac, bd, adbc);

    mpz_set_str(x, adbc, 10);
    mpz_set_str(y, ac, 10);
    mpz_set_str(z0, bd, 10);

    mpz_sub(temp, y, z1);
    mpz_sub(z1, temp, z2);

    mpz_mul_2exp(temp, z2, 2 * half);
    mpz_add(z2, z2, temp);

    mpz_mul_2exp(temp, z1, half);
    mpz_add(z1, z1, temp);

    mpz_add(z2, z2, z0);
    mpz_add(z1, z1, z0);

    gmp_printf("%Zd", z2);
    gmp_printf("%Zd", z1);

    mpz_clears(x, y, z0, z1, z2, temp, NULL);
}

int main() {
    // Input two large numbers as strings
    char num1[1000001], num2[1000001];
    
    printf("Enter the first large number: ");
    scanf("%s", num1);

    printf("Enter the second large number: ");
    scanf("%s", num2);

    // Multiply the numbers using Karatsuba algorithm
    char result[2 * 1000001];
    karatsuba(num1, num2, result);

    return 0;
}
