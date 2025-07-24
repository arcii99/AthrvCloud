//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include<stdio.h>
#include<string.h>

void main() {
    printf("Welcome to the Palindrome Checker! Please enter your string:\n");
    char str[100];
    fgets(str, sizeof(str), stdin);
    //removing the new line character from fgets
    str[strcspn(str, "\n")] = 0;

    //checking if the string is empty
    if (strlen(str) == 0) {
        printf("Error! Please enter a non-empty string.\n");
        return;
    }

    //reversing the string
    char rev[100];
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        rev[i] = str[len-i-1];
    }
    rev[len] = '\0';

    //checking if the reversed string is equal to the original string
    if (strcmp(str, rev) == 0) {
        printf("\n%s is a palindrome!", str);
        printf("\n");
        for (int i = 0; i < 50; i++) {
            printf("=");
        }
        printf("\n\n");
        //mind-bending twist - printing the binary representation of the string
        printf("Here is the binary representation of %s:\n\n", str);
        for (int i = 0; i < len; i++) {
            char bin[9] = {'\0'};
            int val = str[i];
            for (int j = 7; j >= 0; j--) {
                if (val % 2 == 0) {
                    bin[j] = '0';
                } else {
                    bin[j] = '1';
                }
                val /= 2;
            }
            printf("%s ", bin);
        }
        printf("\n\n");
        for (int i = 0; i < 50; i++) {
            printf("=");
        }
        printf("\n");
    } else {
        printf("\n%s is not a palindrome :(\n", str);
    }
}