#include <stdio.h>
#include <gmp.h>
int countSetBits(const mpz_t num) {
    int count = 0;
    int size = mpz_sizeinbase(num, 2);
    for (int i = 0; i < size; i++) {
        count += mpz_tstbit(num, i);
    }
    return count;
}
int main() {  
    mpz_t number;
    mpz_init(number);
    printf("Enter the large number: ");
    gmp_scanf("%Zd", number);
    int setBitsCount = countSetBits(number);
    printf("Number of set bits in the binary representation: %d\n", setBitsCount);
    mpz_clear(number);
    return 0;
}
