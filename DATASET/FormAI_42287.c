//FormAI DATASET v1.0 Category: Math exercise ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function to generate a random integer between 1 and 100 */
int generateRandomNumber(){
    srand(time(NULL));
    return (rand() % 100) + 1;
}

int main(){
    int answer = generateRandomNumber();
    int guess;
    int attempt = 0;
    
    printf("Welcome to the Guessing Game!\n");
    printf("I have chosen a number between 1 and 100.\n");
    
    while(1){
        attempt++;
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        if(guess == answer){
            printf("Congratulations! You guessed the answer in %d attempts.\n", attempt);
            break;
        }
        else if(guess < answer){
            printf("Your guess is too low. Please try again.\n");
        }
        else{
            printf("Your guess is too high. Please try again.\n");
        }
    }
    
    return 0;
}