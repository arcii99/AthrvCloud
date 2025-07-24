//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    int len, i, j, flag;
    
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    
    flag = 1;
    for(i=0, j=len-1; i < len/2; i++, j--) {
        if(str[i] != str[j]) {
            flag = 0;
            break;
        }
    }
    
    if(flag)
        printf("The string is a palindrome.");
    else
        printf("The string is not a palindrome.");

    return 0;
}