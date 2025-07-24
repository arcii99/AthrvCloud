//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i,len;
    char user_input[100];
    printf("Enter your input:");
    fgets(user_input,100,stdin); //reading user input
    len=strlen(user_input); //calculating length of user's input
    for(i=0;i<len;i++){ //iterating through the user's input
        user_input[i]=user_input[i]+3; //adding 3 to each character of the user's input
    }
    printf("Your sanitized input is:");
    puts(user_input); //displaying the sanitized input
    return 0;
}