//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    int mid = len/2;

    int i;

    for(i = 0; i < mid; i++) {
        if(str[i] != str[len - i - 1]) {
            printf("Not a palindrome.\n");
            break;
        }
    }

    if(i == mid) {
        printf("Palindrome!\n");
    }

    return 0;
}