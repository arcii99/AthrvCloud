//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int chances=5,guess,correct_num,count=0; //number of turns given
    srand(time(0)); //to set the seed for random number generation
    correct_num = rand()%20 + 1; //generate random number between 1 and 20
    printf("Guess the number between 1 and 20:\n");
    while(chances>0){ //loop until chances become 0
        scanf("%d",&guess);
        if(guess<1 || guess>20){ //check if guess is between 1 and 20
            printf("Invalid input. The number is between 1 and 20. Please try again.\n");
            continue; //skip to next iteration
        }
        if(guess==correct_num){ //check if guess is correct
            printf("Congratulations! You guessed the number in %d tries.\n",count+1);
            break; //break the loop
        }
        else if(guess<correct_num){
            printf("Oops! Your guess is too low. Please try again.\n");
            chances--;
        }
        else{
            printf("Oops! Your guess is too high. Please try again.\n");
            chances--;
        }
        count++; //increment count after each guess
    }
    if(chances==0)
        printf("Sorry! You have used all your chances. The correct number was %d.\n",correct_num);
    return 0;
}