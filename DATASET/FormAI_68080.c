//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include<stdio.h>

int main(){
    int num1, num2, choice, result;
    printf("Hey there! Are you ready for some arithmetic action?\n");
    printf("Enter any two numbers:\n");
    scanf("%d%d", &num1, &num2);
    
    printf("Awesome! What would you like to do with these numbers?\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Modulus\n6. Exit\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            result = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("The difference of %d and %d is %d.\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, result);
            break;
        case 4:
            if(num2 == 0){
                printf("Sorry, cannot divide by 0!\n");
                break;
            }
            result = num1 / num2;
            printf("%d divided by %d is %d.\n", num1, num2, result);
            break;
        case 5:
            if(num2 == 0){
                printf("Sorry, cannot find modulus by 0!\n");
                break;
            }
            result = num1 % num2;
            printf("The modulus of %d and %d is %d.\n", num1, num2, result);
            break;
        case 6:
            printf("Okay, bye! Have a nice day.\n");
            break;
        default:
            printf("Invalid choice! Please choose again.\n");
    }
    return 0;
}