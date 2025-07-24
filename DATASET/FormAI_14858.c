//FormAI DATASET v1.0 Category: Math exercise ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

    printf("Welcome to the Math Exercise program! Let's test your math skills with some fun exercises.\n");

    int choice;
    float answer, user_ans;
    float num1, num2;
    float radius, area, circumference;

    //Menu
    while(1){
        printf("\nMENU:\n");
        printf("1. Addition Exercise\n");
        printf("2. Multiplication Exercise\n");
        printf("3. Find the square root of a number\n");
        printf("4. Calculate the area and circumference of a circle\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            //Addition exercise
            case 1:
                num1 = rand() % 100 + 1;
                num2 = rand() % 100 + 1;
                answer = num1 + num2;
                printf("\nAdd %0.2f and %0.2f: ",num1, num2);
                scanf("%f", &user_ans);
                if(user_ans == answer){
                    printf("\nWell done! Your answer is correct.\n");
                }
                else{
                    printf("\nSorry, your answer is incorrect. The correct answer is: %0.2f\n", answer);
                }
                break;

            //Multiplication exercise
            case 2:
                num1 = rand() % 10 + 1;
                num2 = rand() % 10 + 1;
                answer = num1 * num2;
                printf("\nMultiply %0.2f and %0.2f: ",num1, num2);
                scanf("%f", &user_ans);
                if(user_ans == answer){
                    printf("\nWell done! Your answer is correct.\n");
                }
                else{
                    printf("\nSorry, your answer is incorrect. The correct answer is: %0.2f\n", answer);
                }
                break;

            //Square root exercise
            case 3:
                printf("\nEnter a number to find its square root: ");
                scanf("%f", &num1);
                answer = sqrt(num1);
                printf("The square root of %0.2f is: %0.2f\n", num1, answer);
                break;

            //Circle exercise
            case 4:
                printf("\nEnter the radius of the circle: ");
                scanf("%f", &radius);
                area = M_PI * pow(radius,2);
                circumference = 2 * M_PI * radius;
                printf("The area of the circle is: %0.2f\n", area);
                printf("The circumference of the circle is: %0.2f\n", circumference);
                break;

            //Exit program
            case 5:
                printf("\nThank you for using the Math Exercise program!\n");
                exit(0);

            //Invalid choice
            default:
                printf("\nInvalid choice, please select again.\n");
                break;
        }
    }

    return 0;
}