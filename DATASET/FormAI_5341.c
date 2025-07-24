//FormAI DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to reverse a given C string */
void reverse(char* str) {
    int length = strlen(str);
    if(length == 1) return;
    int i, j;
    for(i = 0, j = length - 1; i < j; ++i, --j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/* Function to convert a given C string to all uppercase characters */
void to_uppercase(char* str) {
    int length = strlen(str);
    int i;
    for(i = 0; i < length; ++i) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char str[100];

    /* Get input from the user */
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    /* Reverse and print the input string */
    reverse(str);
    printf("The reversed string is: %s\n", str);

     /* Convert the input string to uppercase and print it */
    to_uppercase(str);
    printf("The string in all uppercase is: %s", str);

    return 0;
}