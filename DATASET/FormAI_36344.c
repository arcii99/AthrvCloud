//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

int main() {
    char str[100];
    int i, len, flag = 0;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    len = strlen(str);
    
    for(i = 0; i < len; i++) {
        if(str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }
    
    if(flag) {
        printf("I'm sorry, my dear Watson, but \"%s\" is not a palindrome.\n", str);
    }
    else {
        printf("Elementary, my dear Watson! \"%s\" is indeed a palindrome.\n", str);
    }
    
    return 0;
}