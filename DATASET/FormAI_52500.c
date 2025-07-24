//FormAI DATASET v1.0 Category: Funny ; Style: complex
#include<stdio.h>

// Function to check whether a given number is a palindrome or not
int isPalindrome(int num) {
    int temp = num, rev = 0, rem;
    while (temp != 0) {
        // Getting last digit of the number
        rem = temp % 10;
        // Adding the digit to a new variable in reverse order
        rev = rev * 10 + rem;
        // Removing the last digit from the original number
        temp /= 10;
    }
    // Comparing original and reverse number
    if (num == rev)
        return 1;
    else
        return 0;
}

int main() {
    int num, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &num);
    // Loop for printing the pyramid
    for (i = 1; i <= num; i++) {
        // Loop for printing spaces
        for (j = 1; j <= num - i; j++)
            printf(" ");
        // Loop for printing numbers
        for (k = 1; k <= 2 * i - 1; k++) {
            // If the number is a palindrome, print X else print Y
            if (isPalindrome(k))
                printf("X");
            else
                printf("Y");
        }
        // Moving to the next line
        printf("\n");
    }
    return 0;
}