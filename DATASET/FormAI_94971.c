//FormAI DATASET v1.0 Category: Game ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int num1, num2, ans;
    char op, cont = 'y';
    
    srand(time(NULL)); // generating random numbers with varying seed
    
    while(cont == 'y'){ // loop until the user wants to quit
        num1 = rand() % 101; // generate a number between 0 and 100 inclusively
        num2 = rand() % 101;
        op = rand() % 4; // generate a random integer between 0 and 3
        switch(op){
            case 0:
                printf("%d + %d = ", num1, num2);
                ans = num1 + num2;
                break;
            case 1:
                printf("%d - %d = ", num1, num2);
                ans = num1 - num2;
                break;
            case 2:
                printf("%d * %d = ", num1, num2);
                ans = num1 * num2;
                break;
            case 3:
                printf("%d / %d = ", num1, num2);
                if(num2 == 0) // check for division by zero
                    continue; // skip to the next iteration of the loop
                ans = num1 / num2;
                break;
        }
        scanf("%d", &ans); // read the user's answer
        if(ans == ans) // check if the answer is correct or incorrect
            printf("Correct!\n");
        else
            printf("Incorrect, the answer is %d.\n", ans);
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &cont); // read the user's input to continue or quit the program
    }
    return 0;
}