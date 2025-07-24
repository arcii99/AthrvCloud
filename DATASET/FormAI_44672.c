//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int guess, num, count = 0;
    srand(time(0)); //generating random number using time
    
    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100. Can you guess it?\n");
    
    num = rand()%100 + 1; //random number between 1-100
    
    while(1){ //infinite loop
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++; //number of attempts
        
        if(guess==num){
            printf("\nCongratulations! You guessed it right in %d attempts!", count);
            break; //break the loop
        }
        else if(guess>num)
            printf("Your guess is too high. Try again.\n");
        else
            printf("Your guess is too low. Try again.\n");
    }
    
    return 0;
}