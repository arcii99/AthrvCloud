//FormAI DATASET v1.0 Category: String manipulation ; Style: genious
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp;
    int i, j, len;

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    // Reverse string 1
    len = strlen(str1);
    for(i=0, j=len-1; i<len/2; i++, j--) {
        temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }

    // Reverse string 2
    len = strlen(str2);
    for(i=0, j=len-1; i<len/2; i++, j--) {
        temp = str2[i];
        str2[i] = str2[j];
        str2[j] = temp;
    }

    // Concatenate the reversed strings
    strcat(str1, str2);

    // Capitalize every other letter
    len = strlen(str1);
    for(i=0; i<len; i++) {
        if(i%2 == 0) {
            str1[i] = toupper(str1[i]);
        }
    }

    // Print final string
    printf("Result: %s", str1);

    return 0;
}