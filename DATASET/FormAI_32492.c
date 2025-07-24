//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, len, flag = 0;
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    len = strlen(str) - 1; // Exclude the newline character
    
    for(i = 0; i < len / 2; i++) {
        if(tolower(str[i]) != tolower(str[len - i - 1])) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        printf("%s is not a palindrome.\n", str);
    }
    else {
        printf("%s is a palindrome.\n", str);
    }

    return 0;
}