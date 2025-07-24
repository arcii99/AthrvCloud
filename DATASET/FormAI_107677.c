//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
#include <stdio.h>
#include <string.h>

void removeNonAlphaNum(char str[]);
void toLowercase(char str[]);
int isPalindrome(char str[], int length);

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character from user input

    removeNonAlphaNum(str);
    toLowercase(str);

    int length = strlen(str);
    if(isPalindrome(str, length)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome!\n", str);
    }

    return 0;
}

// removes non-alphanumeric characters from string
void removeNonAlphaNum(char str[]) {
    int i, j;
    for(i=0; str[i]!='\0'; i++) {
        while(!( (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9') || str[i]=='\0' )) {
            for(j=i; str[j]!='\0'; j++) {
                str[j] = str[j+1];
            }
            str[j] = '\0';
        }
    }
}

// converts string to lowercase
void toLowercase(char str[]) {
    int i;
    for(i=0; str[i]!='\0'; i++) {
        if(str[i]>='A' && str[i]<='Z') {
            str[i] += 32;
        }
    }
}

// checks if string is a palindrome
int isPalindrome(char str[], int length) {
    int i;
    for(i=0; i<length/2; i++) {
        if(str[i] != str[length-i-1]) {
            return 0;
        }
    }
    return 1;
}