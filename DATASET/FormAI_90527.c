//FormAI DATASET v1.0 Category: String manipulation ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
    char string1[50], string2[50], temp[50];
    printf("Enter string 1: ");
    fgets(string1, 50, stdin);
    printf("Enter string 2: ");
    fgets(string2, 50, stdin);

    // remove newline character from fgets input
    string1[strcspn(string1, "\n")] = 0;
    string2[strcspn(string2, "\n")] = 0;

    printf("\nStrings before manipulation:\n");
    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);

    // reverse string 1
    int len = strlen(string1);
    for(int i=0; i<len/2; i++){
        temp[i] = string1[len-i-1];
        string1[len-i-1] = string1[i];
        string1[i] = temp[i];
    }

    // concatenate string 2 to string 1
    strcat(string1, string2);

    // convert string 1 to uppercase
    for(int i=0; i<strlen(string1); i++){
        if(string1[i]>='a' && string1[i]<='z'){
            string1[i] = string1[i] - 32;
        }
    }

    printf("\nStrings after manipulation:\n");
    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);

    return 0;
}