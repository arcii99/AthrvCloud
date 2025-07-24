//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, flag = 0;

    printf("Oh my love, please enter a string: \n");
    scanf("%s", str);

    int len = strlen(str);

    for (i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Oh my li'l dove, %s is not a Palindrome\n", str);
    }    
    else {
        printf("Oh my dear, %s is a Palindrome\n", str);
    }
    
    return 0;
}