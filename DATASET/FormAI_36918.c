//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: puzzling
#include<stdio.h>
#include<string.h>

void main(){
    char word[50],reverse_word[50];
    int i,j,length=0,flag=0;

    printf("Enter a word: ");
    scanf("%s",word); //Taking input from user

    length=strlen(word); //Calculating length of the word

    for(i=length-1,j=0;i>=0;i--,j++){
        reverse_word[j]=word[i]; //Reversing the word
    }

    for(i=0;i<length;i++){
        if(word[i]!=reverse_word[i]){
            flag=1; //Checking if the word is palindrome or not
            break;
        }
    }

    if(flag){
        printf("\n%s is not a palindrome",word);
    }
    else{
        printf("\n%s is a palindrome",word);
    }
}