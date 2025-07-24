//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: medieval
#include<stdio.h>
#include<string.h>

int main() {
    char word[100];
    int length, i, j, flag = 0;

    printf("Greetings, noble sir/madam! Enter the word that you want to check for palindrome: \n");
    scanf("%s", word);

    length = strlen(word);

    for(i=0, j=length-1; i<=length/2; i++,j--){
        if(word[i]!=word[j]){
            flag=1;
            break;
        }
    }

    if(flag==0){
        printf("Huzzah! The word \"%s\" is a palindrome.\n", word);
    }
    else{
        printf("Alas! The word \"%s\" is not a palindrome.\n", word);
    }

    return 0;
}