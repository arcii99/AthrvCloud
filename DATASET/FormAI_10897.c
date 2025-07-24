//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int secret_num, guess, attempts=0;
    srand(time(0));
    secret_num = rand()%50 + 1;
    printf("Welcome to the Guessing Game!\n");
    printf("Guess a number between 1 and 50: ");

    do{
        scanf("%d", &guess);
        if(guess<1 || guess>50){
            printf("Invalid guess. Enter a number between 1 and 50: ");
            continue;
        }
        attempts++;
        if(guess>secret_num){
            printf("Too high. Guess again: ");
        }else if(guess<secret_num){
            printf("Too low. Guess again: ");
        }else{
            printf("Congratulations! You guessed the secret number in %d attempts.\n", attempts);
        }
    }while(guess!=secret_num);

    return 0;
}