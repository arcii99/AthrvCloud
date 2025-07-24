//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char str[]) {  
    int low = 0, high = strlen(str) - 1;  
    
    while (low < high) {    
        if (str[low] != str[high]) {    
            return false;    
        }    
        low++;    
        high--;    
    }    
    return true;    
}    

int main() {    
    char str[100];    
    printf("Enter a string to check if it is a palindrome: ");    
    scanf("%s", str);    
    
    if (is_palindrome(str)) {
        printf("\n%s is a palindrome.\n", str);
    }    
    else {    
        printf("\n%s is not a palindrome.\n", str);    
    }    
    return 0;    
}