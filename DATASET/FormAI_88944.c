//FormAI DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int num1, num2, correct_ans, user_ans, max_range;

    printf("Enter the maximum range for numbers: ");
    scanf("%d", &max_range);

    while(1){
        num1 = rand() % max_range + 1;
        num2 = rand() % max_range + 1;
        correct_ans = num1 + num2;

        printf("What is %d + %d?\n", num1, num2);
        scanf("%d", &user_ans);

        if(user_ans == correct_ans){
            printf("Correct! You are a math genius!\n\n");
        }else{
            printf("Incorrect. The correct answer is %d.\n\n", correct_ans);
        }
    }
    return 0;
}