//FormAI DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>

/* Function to print the length of the input string */
void printLength(char *str){
    int len = 0;
    while(*str != '\0') {
        len++;
        str++;
    }
    printf("Length of the string is: %d\n", len);
}

/* Function to check if the string is a Palindrome or not */
int isPalindrome(char *str){
    int len = 0;
    while(*str != '\0') {
        len++;
        str++;
    }
    str--;
    int i = 0;
    while(i < len/2) {
        if(*str != *(str-i-1)) {
            return 0;
        }
        i++;
        str--;
    }
    return 1;
}

int main() {
    /* Declare a buffer to store input */
    char input[100];

    /* Get input from user */
    printf("Enter a string: ");
    scanf("%s", input);

    /* Call functions to print length and check if its a Palindrome */
    printLength(input);
    if(isPalindrome(input)) {
        printf("The entered string is a Palindrome\n");
    } else {
        printf("The entered string is not a Palindrome\n");
    }
    return 0;
}