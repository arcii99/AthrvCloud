//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* function to calculate factorial recursively */
int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main(){
    srand(time(0));
    int num1, num2, ans, userAns, i, correct = 0;
    /* generate two random numbers between 1 to 10 */
    num1 = rand()%10 + 1;
    num2 = rand()%10 + 1;
    /* print the math equation */
    printf("Calculate %d! / %d! + %d\n", num1, num2, num2);

    for(i=1; i<=5; i++){
        printf("Attempt %d: ", i);
        /* take user input */
        scanf("%d", &userAns);
        /* calculate the correct answer */
        ans = factorial(num1)/(factorial(num2)+num2);
        /* compare user answer with correct answer */
        if(userAns == ans){
            correct++;
            printf("Correct! You have solved %d out of 5 problems.\n", correct);
            /* generate new random numbers */
            num1 = rand()%10 + 1;
            num2 = rand()%10 + 1;
            printf("Calculate %d! / %d! + %d\n", num1, num2, num2);
        }
        else{
            printf("Incorrect. Please try again.\n");
        }
    }

    printf("You have solved %d out of 5 problems. Goodbye!\n", correct);

    return 0;
}