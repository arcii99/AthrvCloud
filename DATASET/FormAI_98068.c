//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkPalindrome(char *str){
    char c;
    int len = strlen(str);
    int i = 0, j = len - 1;
    while(i < j){
        if(tolower(str[i]) != tolower(str[j]))
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main(){
    char str[1000], choice;
    do{
        printf("\nEnter a string to check if it's palindrome: ");
        fgets(str, 1000, stdin);
        str[strcspn(str, "\n")] = '\0';
        if(checkPalindrome(str))
            printf("\n%s is a palindrome\n", str);
        else
            printf("\n%s is not a palindrome\n", str);
        printf("\nDo you want to check again? (Y/N): ");
        getchar();
        choice = getchar();
    } while(choice == 'Y' || choice == 'y');
    return 0;
}