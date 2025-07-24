//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); //seeding random number generator with current time
    int choice, correct_answer, count = 0;
    printf("Welcome to the Math Adventure Game!\n");
    printf("You have entered a mysterious maze full of mathematical challenges.\n");
    printf("Be ready to face the challenges and succeed in the end!\n\n");

    while(count < 5){ //maze has 5 rooms
        printf("ROOM %d\n", count+1);
        int num1 = rand() % 10 + 1; //generating random number between 1 and 10
        int num2 = rand() % 10 + 1;
        int operator = rand() % 3; // 0 for addition, 1 for subtraction and 2 for multiplication
        switch(operator){
            case 0:
                printf("What is the answer to %d + %d?\n", num1, num2);
                correct_answer = num1 + num2;
                break;
            case 1:
                printf("What is the answer to %d - %d?\n", num1, num2);
                correct_answer = num1 - num2;
                break;
            case 2:
                printf("What is the answer to %d * %d?\n", num1, num2);
                correct_answer = num1 * num2;
                break;
        }
        printf("Enter your answer: ");
        scanf("%d", &choice);
        if(choice == correct_answer){
            printf("Correct answer!\n");
            count++;
        }
        else{
            printf("Incorrect answer, try again!\n");
        }
        printf("\n");
    }

    printf("Congratulations! You have successfully completed the math maze and reached the end.\n");
    printf("You are now a math champion!\n");

    return 0;
}