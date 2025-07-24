//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, flag;

    printf("Enter a string: ");
    scanf("%s", str);

    i = 0;
    j = strlen(str) - 1;
    flag = 1;

    while(i < j) {
        if(str[i] != str[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if(flag == 1) {
        printf("%s is a palindrome!\n", str);
    }
    else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}