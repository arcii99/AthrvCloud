//FormAI DATASET v1.0 Category: Game ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int num, guess, chance = 5;
    srand(time(0)); //This line ensures different random numbers for different runs of the program
    num = rand()%100 + 1; //random number between 1 and 100 is generated
    printf("Welcome to the guessing game!\n");
    printf("You have 5 chances to guess the number!\n");
    
    do{ //while loop runs until number of chances are exhausted or guessed correctly
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);
        if(guess == num){
            printf("Congratulations! Your guess is correct!\n");
            break;
        }
        else if(guess < num){
            printf("Your guess is less than the number. Try again!\n");
        }
        else{
            printf("Your guess is more than the number. Try again!\n");
        }
        chance--; //decrease number of chances by 1
        printf("You have %d chances left.\n", chance);
    }while(chance > 0);
    if(chance == 0){
        printf("Sorry, you have exhausted all your chances. The correct number was %d.\n", num);
    }
    return 0;
}