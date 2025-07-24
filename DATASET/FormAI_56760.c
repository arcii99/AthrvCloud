//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include<stdio.h>
#include<string.h>

// function to check whether a given string is a palindrome or not
int check_palindrome(char *str){
    int length = strlen(str);
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--){
            if(str[i]!=str[j]){
                return 0;
            }
        }
        return 1;
}

int main(){
    char str[100];
    printf("Palindrome Checker\n");
    printf("------------------\n");
    printf("Enter a string to check whether it is a palindrome or not: ");
    scanf("%s",str);
    if(check_palindrome(str)==1){
        printf("\nCongratulations! The given string \"%s\" is a palindrome.\n",str);
    }else{
        printf("\nSorry! The given string \"%s\" is not a palindrome.\n",str);
    }
    return 0;
}