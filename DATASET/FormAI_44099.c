//FormAI DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to get random number between min and max range(inclusive)
int randomNumber(int min, int max){
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

int main(){
    int min_range, max_range, numbers_to_guess;
    printf("Welcome to the number guessing game!\nEnter the minimum range: ");
    scanf("%d", &min_range);
    printf("Enter the maximum range: ");
    scanf("%d", &max_range);
    printf("How many numbers would you like to guess? ");
    scanf("%d", &numbers_to_guess);
    printf("You will have a total of %d tries to guess the numbers\n", numbers_to_guess);

    //generate random numbers and store them in an array
    int random_numbers[numbers_to_guess];
    for(int i = 0; i < numbers_to_guess; i++){
        random_numbers[i] = randomNumber(min_range, max_range);
    }

    //check user's guesses against random numbers
    int tries = 0;
    int user_guess;
    int correct_guesses = 0;
    while(tries < numbers_to_guess){
        printf("\nEnter your guess: ");
        scanf("%d", &user_guess);
        for(int i = 0; i < numbers_to_guess; i++){
            if(user_guess == random_numbers[i]){
                printf("Congratulations! You guessed one of the numbers correctly\n");
                correct_guesses++;
            }
        }
        tries++;
        printf("You have %d tries remaining\n", numbers_to_guess-tries);
    }

    //print results
    printf("\nGAME OVER!\nNumber of correct guesses: %d/%d", correct_guesses, numbers_to_guess);
    return 0;
}