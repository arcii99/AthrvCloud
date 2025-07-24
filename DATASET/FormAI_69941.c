//FormAI DATASET v1.0 Category: Math exercise ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//Function to generate a random number between a range
int random_number(int min,int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){
    srand(time(0)); //Seed the random number generator
    int choice, num1, num2, answer, user_answer, num_questions = 0, num_correct = 0;

    printf("Welcome to Math Exercise Generator!\n");

    do{
        printf("\nChoose the type of exercise you would like to practice:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 4){ //Validation for valid choices
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
            continue;
        }

        printf("\nEnter the range of numbers for the exercises:\n");
        printf("Enter the smallest number: ");
        scanf("%d", &num1);
        printf("Enter the largest number: ");
        scanf("%d", &num2);

        if(num1 > num2){ //Validation for valid ranges
            printf("Invalid range! The smallest number should be less than or equal to the largest number.\n");
            continue;
        }

        printf("\nHow many exercises would you like to generate?\n");
        printf("Enter the number of exercises: ");
        scanf("%d", &num_questions);

        if(num_questions <= 0){ //Validation for number of exercises
            printf("Invalid number of exercises! Please enter a number greater than 0.\n");
            continue;
        }

        num_correct = 0; //Reset correct answers count

        for(int i = 0; i < num_questions; i++){
            //Generate random numbers based on the range and choice of exercise
            switch(choice){
                case 1: //Addition
                    num1 = random_number(num1, num2);
                    num2 = random_number(num1, num2);
                    answer = num1 + num2;
                    printf("\nQuestion %d: %d + %d = ", i+1, num1, num2);
                    break;
                case 2: //Subtraction
                    num1 = random_number(num1, num2);
                    num2 = random_number(num1, num2);
                    answer = num1 - num2;
                    printf("\nQuestion %d: %d - %d = ", i+1, num1, num2);
                    break;
                case 3: //Multiplication
                    num1 = random_number(num1, num2);
                    num2 = random_number(num1, num2);
                    answer = num1 * num2;
                    printf("\nQuestion %d: %d x %d = ", i+1, num1, num2);
                    break;
                case 4: //Division
                    do{
                        num1 = random_number(num1, num2);
                        num2 = random_number(num1, num2);
                    }while(num1 % num2 != 0); //Generate numbers such that they are divisible
                    answer = num1 / num2;
                    printf("\nQuestion %d: %d / %d = ", i+1, num1, num2);
                    break;
            }
            scanf("%d", &user_answer);

            if(user_answer == answer){ //Check if user answer is correct
                printf("Correct!\n");
                num_correct++;
            }
            else
                printf("Incorrect! The correct answer is %d.\n", answer);
        }

        printf("\nYou answered %d out of %d questions correctly!\n", num_correct, num_questions);

        printf("\nDo you want to generate more exercises? (Y/N) ");
        char c;
        scanf(" %c", &c);

        if(c == 'N' || c == 'n')
            break;

    }while(1);

    return 0;
}