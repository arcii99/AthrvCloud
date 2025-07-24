//FormAI DATASET v1.0 Category: String manipulation ; Style: intelligent
#include<stdio.h>
#include<string.h>

// This program demonstrates how to manipulate a C string using intelligent methods.
// For example, we can convert a string to uppercase or reverse it.
// We can also compare two strings to see if they are equal.

int main() {

    // Part I: String to Uppercase
    char str1[100];
    printf("Please enter a string to convert to uppercase: ");
    fgets(str1, 100, stdin);
    for(int i=0; i<strlen(str1); i++) {
        if(str1[i]>='a' && str1[i]<='z') {
            str1[i] = str1[i] - 32;
        }
    }
    printf("Your uppercase string is: %s\n", str1);

    // Part II: String Reversal
    char str2[100];
    printf("Please enter a string to reverse: ");
    fgets(str2, 100, stdin);
    char temp;
    int l = strlen(str2);
    for(int i=0; i<l/2; i++) {
        temp = str2[i];
        str2[i] = str2[l-i-1];
        str2[l-i-1] = temp;
    }
    printf("Your reversed string is: %s\n", str2);

    // Part III: String Comparison
    char str3[100], str4[100];
    printf("Please enter two strings to compare: \n");
    fgets(str3, 100, stdin);
    fgets(str4, 100, stdin);
    int res = strcmp(str3, str4);
    if(res == 0) {
        printf("The two strings are equal.\n");
    } else if(res < 0) {
        printf("%s is less than %s\n", str3, str4);
    } else {
        printf("%s is greater than %s\n", str3, str4);
    }

    return 0;
}