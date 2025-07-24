//FormAI DATASET v1.0 Category: Calculator ; Style: funny
#include <stdio.h>

int main(){
printf("Welcome to the world's first funny C Calculator!\n");
int num1, num2, choice;
float result;

printf("Enter your first number: ");
scanf("%d",&num1);
printf("Enter your second number: ");
scanf("%d",&num2);

printf("\n");

printf("Please select an option from the menu below\n");
printf("1. Add\n");
printf("2. Subtract\n");
printf("3. Multiply\n");
printf("4. Divide\n");
scanf("%d",&choice);

switch(choice){
    case 1:
        result = num1 + num2;
        printf("\n");
        printf("Congratulations! You just added %d and %d to get %f, the answer the meaning of life, the universe and everything!\n",num1,num2,result);
        break;
    case 2:
        result = num1 - num2;
        printf("\n");
        printf("Wow, you just subtracted %d from %d and got %f. That's like removing your ex's number from your phonebook. Let's move on!\n",num2,num1,result);
        break;
    case 3:
        result = num1 * num2;
        printf("\n");
        printf("That's awesome! You just multiplied %d by %d to get %f, which is the cutest puppy in the world(even cuter than a Golden Retriever)\n",num1,num2,result);
        break;
    case 4:
        result = (float)num1 / (float)num2;
        printf("\n");
        printf("So you decided to divide %d by %d? You must be a rebel. You've got %f, which is like dividing a pizza between friends who can't say the size of their appetite. Cheers!\n",num1,num2,result);
        break;
    default:
        printf("\nInvalid option selected. Please try again!\n");
        break;
}

return 0;
}