//FormAI DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <string.h>

// function to calculate the sum of two numbers in a string
int addStringNumbers(char* num1, char* num2) {
    int len1 = strlen(num1), len2 = strlen(num2);

    // check if any string is empty
    if (len1 == 0) {
        return atoi(num2);
    } else if (len2 == 0) {
        return atoi(num1);
    }

    // find the maximum length of the two strings
    int len = (len1 > len2) ? len1 : len2;

    // initialize variables to store digits and carry
    int dig1, dig2, carry = 0, sum = 0;

    // loop through both strings in reverse order
    for (int i = 0; i < len; i++) {
        dig1 = (i < len1) ? num1[len1 - i - 1] - '0' : 0;
        dig2 = (i < len2) ? num2[len2 - i - 1] - '0' : 0;
        sum = dig1 + dig2 + carry;
        carry = sum / 10;
    }

    // if there is a remaining carry, add it to the sum
    if (carry) {
        sum += carry;
    }

    return sum;
}

int main() {
    char num1[] = "123";
    char num2[] = "45";
    int result = addStringNumbers(num1, num2);
    printf("The result is: %d\n", result);
    return 0;
}