//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //initialize the random number generator with the current time
    int num1, num2, userAnswer, correctAnswer, score = 0;
    char operator;
    printf("Welcome to the Math Quiz!\n");
    printf("You will be presented with simple math problems and you need to answer them correctly.\n");
    printf("Let's start!\n");
    for(int i=1; i<=10; i++){
        num1 = rand() % 100; //generate a random number between 0 and 99
        num2 = rand() % 100; //generate another random number between 0 and 99
        if(i%2 == 0){ //half of the questions will be multiplication
            operator = '*';
            correctAnswer = num1 * num2;
        }else{ //the other half will be addition
            operator = '+';
            correctAnswer = num1 + num2;
        }
        printf("\nQuestion %d: %d %c %d = ?\n", i, num1, operator, num2);
        printf("Answer: ");
        scanf("%d", &userAnswer);
        if(userAnswer == correctAnswer){
            printf("Correct!\n");
            score++;
        }else{
            printf("Wrong. The correct answer is %d.\n", correctAnswer);
        }
    }
    printf("\nYou answered %d out of 10 questions correctly.\n", score);
    if(score == 10){
        printf("Congratulations! You got a perfect score!\n");
    }else if(score >= 7){
        printf("Good job! You did well.\n");
    }else if(score >= 4){
        printf("Not bad, but you can do better!\n");
    }else{
        printf("Maybe you should practice more!\n");
    }
    return 0;
}