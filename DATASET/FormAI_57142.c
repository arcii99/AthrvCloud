//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void clrscr(){
    system("@cls||clear");
}

int main(){
    
    srand(time(NULL));
    int num = 1 + rand()%100;
    int guess;
    int attempts = 0;
    int max_attempts = 10;
    
    clrscr();
    printf("\n\n\n\t\t\tWelcome to the Guessing Game!\n");
    printf("\t\t\t------------------------------\n\n\n");
    printf("\t\t\tGuess the number between 1 and 100\n\n\n");
    
    while(attempts < max_attempts){
        
        printf("\t\t\tGuess %d: ", attempts+1);
        scanf("%d", &guess);
        clrscr();
        
        if(guess == num){
            printf("\n\n\n\t\t\tCongratulations! You guessed the number %d in %d attempts.\n", num, attempts+1);
            return 0;
        }
        else if(guess < num){
            printf("\n\n\n\t\t\tHmmm... your guess is too low. Try again!\n\n\n");
        }
        else{
            printf("\n\n\n\t\t\tWhoops... your guess is too high. Try again!\n\n\n");
        }
        
        attempts++;
    }
    
    printf("\n\n\n\t\t\tGame Over! You ran out of attempts. The number was %d.\n", num);
    
    return 0;
}