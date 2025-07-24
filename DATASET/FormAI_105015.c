//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_SIZE 100

int main(){
    char input[MAX_SIZE], temp[MAX_SIZE];
    int length = 0, i = 0, flag = 0, j = 0;

    printf("Greetings traveler, I am the Palindrome Checker 9000!\n\n");
    printf("Please enter a string (less than 100 characters): ");
    fgets(input, MAX_SIZE, stdin);
    length = strlen(input)-1;
    printf("\nHmm, let me check if %s is a palindrome!\n\n", input);

    for(i=0; i<length; i++){
        if(isalpha(input[i])){
            temp[j] = tolower(input[i]);
            j++;
        }
    }

    length = strlen(temp);
    for(i=0; i<length/2; i++){
        if(temp[i] != temp[length-i-1]){
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        printf("Congrats, %s is a palindrome!\n", input);
    }
    else{
        printf("Oh no, %s is not a palindrome!\n", input);
    }

    printf("\nThank you for using the Palindrome Checker 9000! Goodbye!\n");

    return 0;
}