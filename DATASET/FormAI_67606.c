//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j, rand_num, guess;
    int arr[5][5]; //A 5x5 table game
    srand(time(NULL)); //Seeding the random number generator
    printf("Welcome to the Table Game\n");
    //Initializing the table with random numbers
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            rand_num = rand() % 10 + 1; //Generating a random number from 1 to 10
            arr[i][j] = rand_num;
        }
    }
    //Displaying the table
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
    //Getting user input and checking if the guess is correct or not
    printf("\nGuess the sum of all the numbers in the table: ");
    scanf("%d", &guess);
    int sum = 0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            sum += arr[i][j]; //Adding all the numbers in the table
        }
    }
    if(guess == sum){
        printf("Congratulations! Your guess is correct.\n");
    }
    else{
        printf("Oops! Your guess is incorrect. The correct answer is %d.\n", sum);
    }
    return 0;
}