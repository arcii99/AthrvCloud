//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

int main(){

    char input[MAX_SIZE], rev_input[MAX_SIZE];
    int length = 0, i;

    printf("Enter a string to reverse:\n");
    gets(input); //takes user input

    length = strlen(input);
    //string reverse loop
    for(i = 0; i < length; i++){
        rev_input[i] = input[length-i-1];
    }

    printf("Reversed string is: %s", rev_input);
    
    return 0;
}