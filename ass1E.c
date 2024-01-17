#include <stdio.h>
#include <gmp.h>
void computePasscode(const mpz_t N, const mpz_t M, mpz_t passcode) {
    mpz_invert(passcode, N, M);
}

int main() {
    mpz_t N, M, passcode;
    mpz_init(N);
    mpz_init(M);
    mpz_init(passcode);
    printf("Enter N: ");
    gmp_scanf("%Zd", N);
    printf("Enter M: ");
    gmp_scanf("%Zd", M);
    computePasscode(N, M, passcode);
    printf("Passcode: ");
    mpz_out_str(stdout, 10, passcode);
    printf("\n");
    mpz_clear(N);
    mpz_clear(M);
    mpz_clear(passcode);
    return 0;
}
