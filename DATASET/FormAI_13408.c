//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    int start, end, flag = 0;
    
    printf("Enter a string: ");
    scanf("%s", string);
    
    end = strlen(string) - 1;
    
    for(start = 0; start < end; start++) {
        if(string[start] != string[end]) {
            flag = 1;
            break;
        }
        
        end--;
    }
    
    if(flag) {
        printf("%s is not a palindrome\n", string);
    } else {
        printf("%s is a palindrome\n", string);
    }
    
    return 0;
}