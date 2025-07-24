//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char str[MAX_SIZE];
    int len, i, j, flag = 0;
    
    printf("Enter a string: ");
    scanf("%[^\n]", str);   // Reading the whole line of text

    len = strlen(str);      // Getting the length of the string

    // Removing all non-alphabetic characters & converting upper case to lower case
    for(i=0; i<len; i++) {
        if(!isalpha(str[i])) {
            for(j=i; j<len; j++)
                str[j] = str[j+1];
            
            len--;
            i--;
        }
        else {
            str[i] = tolower(str[i]);
        }
    }

    // Palindrome checking
    for(i=0, j=len-1; i<=j; i++, j--) {
        if(str[i] != str[j]) {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("\n\"%s\" is a palindrome string.\n\n", str);
    else
        printf("\n\"%s\" is not a palindrome string.\n\n", str);

    return 0;
}