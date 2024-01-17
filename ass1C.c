#include <stdio.h>

// Function to get the length of a null-terminated string
int getLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to multiply two large numbers
void multiplyLargeNumbers(const char *num1, const char *num2, char *result) {
    int len1 = getLength(num1);
    int len2 = getLength(num2);

    // Initialize the result array with zeros
    for (int i = 0; i < len1 + len2; i++) {
        result[i] = '0';
    }
    result[len1 + len2] = '\0';

    // Multiply each digit and add to the result
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry; // Add carry to the current digit
    }
}

int main() {
    // Input two large numbers as strings
    char num1[1000], num2[1000];
    
    printf("Enter the first number: ");
    scanf("%s", num1);

    printf("Enter the second number: ");
    scanf("%s", num2);

    // Result can have at most len1 + len2 digits
    char result[2000];

    // Multiply the numbers
    multiplyLargeNumbers(num1, num2, result);

    // Find the first non-zero digit (to remove leading zeros)
    int start = 0;
    while (result[start] == '0' && result[start + 1] != '\0') {
        start++;
    }

    // Display the result
    printf("Result of multiplication: %s\n", result + start);

    return 0;
}
