//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: secure
#include<stdio.h>
#include<string.h>

void toLowerCase(char *str){
    int i;
    for(i=0; str[i]; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

int isPalindrome(char *str){
    int len = strlen(str);
    for(int i=0, j=len-1; i<j; i++, j--){
        if(str[i] != str[j])
            return 0;
    }
    return 1;
}

int main(){
    char input[100];
    printf("Enter a string to check if it's a palindrome: ");
    fgets(input, 100, stdin);

    // convert to lower case
    toLowerCase(input);

    // remove newline character from string
    input[strlen(input)-1] = '\0';

    // check if palindrome
    if(isPalindrome(input))
        printf("Congratulations! You entered a palindrome.\n");
    else
        printf("Sorry, the string you entered is not a palindrome.\n");

    return 0;
}