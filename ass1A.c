#include <stdio.h>

int main() {
    char a[100];
    char b[100];
    int r[1000] = {0};
    int dr[1000] = {0};

    printf("Enter the First Number:    ");
    scanf("%s", a);
    getchar();

    printf("Enter the Second Number:    ");
    scanf("%s", b);
    getchar();

    int lenA, lenB, lenr;
    int carry = 0;

    for (lenA = 0; a[lenA] != '\0'; lenA++) {}
    for (lenB = 0; b[lenB] != '\0'; lenB++) {}

    for (int i = 0; i < lenA; i++) {
        int digitA = a[lenA - i - 1] - '0';
        carry = 0;

        for (int j = 0; j < lenB; j++) {
            int digitB = b[lenB - j - 1] - '0';
            int product = digitA * digitB + r[i + j] + carry;
            carry = product / 10;
            r[i + j] = product % 10;
        }

        r[i + lenB] += carry;
    }

    lenr = lenA + lenB;

    int carrysum = 0;
    for (int k = 0; k < lenr; k++) {
        int digitsum = dr[k] + r[k] + carrysum;
        dr[k] = digitsum % 10;
        carrysum = digitsum / 10;
    }

    while (carrysum) {
        dr[lenr] = carrysum % 10;
        carrysum /= 10;
        lenr++;
    }

    // Print the result in reverse order
    for (int n = lenr - 1; n >= 0; n--) {
        printf("%d", dr[n]);
    }

    return 0;
}
