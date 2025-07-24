//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the Introspective Typing Speed Test\n");
    printf("Type the following sentence as quickly as possible: \n");

    //the sentence that will be typed
    char sentence[] = "The quick brown fox jumps over the lazy dog";

    //variable declarations for user input and time management
    char user_input[100];
    time_t start_timer, end_timer;
    double time_taken;

    //getting start time
    time(&start_timer);

    //taking user input
    scanf("%[^\n]%*c", &user_input);

    //getting end time
    time(&end_timer);

    //calculating time taken to type
    time_taken = difftime(end_timer, start_timer);

    //checking if user input matches sentence
    if(strcmp(sentence, user_input) == 0){
        printf("\nCongratulations! You typed the sentence correctly.\n");
        printf("Time taken: %.2f seconds\n", time_taken);
    }
    else{
        printf("\nSorry, your input did not match the sentence.\n");
        printf("The correct sentence is: %s\n", sentence);
    }

    return 0;
}