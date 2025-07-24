//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: single-threaded
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){

    char input[50];
    int i,j,length;
    int flag = 1;   // flag variable to check palindrome
    
    printf("Enter a string: ");
    scanf("%[^\n]",input); // getting input from user

    length = strlen(input);

    for(i=0,j=length-1;i<=j;i++,j--){

        while(!(isalpha(input[i]) || isdigit(input[i])))
            i++;            //Skipping non alphanumeric characters
        while(!(isalpha(input[j]) || isdigit(input[j])))
            j--;            //Skipping non alphanumeric characters 
        
        if(tolower(input[i]) != tolower(input[j])){
            flag = 0;       //Not a Palindrome.
            break;
        }
    }

    if(flag == 1)
        printf("The Input String is a Palindrome!");
    else
        printf("The Input String is NOT a Palindrome!");

    return 0;
}