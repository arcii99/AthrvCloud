//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num1,num2,result;
    char op;
    srand(time(NULL));
    printf("Welcome to Math Mania! Let's see how good you are with numbers.\n");
    printf("You will be given random math problems to solve. Are you ready?\n");
    printf("Type y for Yes and n for No: ");
    scanf("%c",&op);
    while(op == 'y'){
        num1 = rand() % 100;
        num2 = rand() % 100;
        result = num1 + num2;
        printf("What is %d + %d?\n",num1,num2);
        int answer;
        scanf("%d",&answer);
        if(answer == result){
            printf("Great job! Your answer is correct.\n");
        }else{
            printf("Sorry, wrong answer! The correct answer is %d.\n",result);
        }
        printf("Do you want to try another problem? Type y for Yes and n for No: ");
        scanf(" %c",&op);
    }
    printf("Thank you for playing Math Mania!\n");
    return 0;
}