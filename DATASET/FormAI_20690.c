//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len, mid;
    int flag = 0;

    printf("Enter the string to check if it is a palindrome: ");
    fgets(str, sizeof(str), stdin);

    // remove newline character from fgets input
    str[strcspn(str, "\n")] = 0;
  
    len = strlen(str);
    mid = len/2;

    for(i = 0; i < mid; i++) {
        if(str[i] != str[len-1-i]) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        printf("%s is not a palindrome", str);
    }
    else {
        printf("%s is a palindrome", str);
    }

    return 0;
}