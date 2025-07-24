//FormAI DATASET v1.0 Category: Educational ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));  //initialize the random number generator with time
    int num1, num2, result, option, correct_ans=0, total_qs=0;
    char choice;
    do{
        printf("Enter difficulty level:\n1. Easy\n2. Medium\n3. Hard\n");
        scanf("%d", &option);
        switch(option){
            case 1: num1 = rand() % 10;  //generate random number between 0 and 9
                    num2 = rand() % 10;
                    break;
            case 2: num1 = rand() % 50;  //generate random number between 0 and 49
                    num2 = rand() % 50;
                    break;
            case 3: num1 = rand() % 100;  //generate random number between 0 and 99
                    num2 = rand() % 100;
                    break;
            default: printf("Invalid input. Please enter again.\n");
                     continue;
        }
        result = num1 + num2;
        printf("What is %d + %d ?\n", num1, num2);
        int answer;
        scanf("%d", &answer);
        total_qs++;
        if(answer == result){
            printf("Correct answer!\n");
            correct_ans++;
        }
        else{
            printf("Sorry, the correct answer is %d\n", result);
        }
        printf("Do you want to continue? (y/n)\n");
        scanf("%s",&choice);
    }while(choice=='y'|| choice=='Y');
    float accuracy = ((float)correct_ans/total_qs)*100;
    printf("Total questions: %d, Correct answers: %d\n", total_qs, correct_ans);
    printf("Accuracy: %.2f percent\n", accuracy);
    return 0;
}