//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include<stdio.h> // Header file for standard input output
#include<math.h> //Header file for mathematical operations

int main()
{
    int choice,n;
    float num1,num2,result;

    printf("\n\t\tCyberCalculator++\n"); //Calculator Title
    printf("\nWelcome to the world of potentials- enter your choices to expand them!");

    printf("\n\nBelow is the list of possible mathematical operations:\n\n");

    printf("\n[1] Addition \t\t [2] Subtraction \n[3] Multiplication \t [4] Division \n[5] Sine \t\t [6] Cosine \n[7] Tangent \t\t [8] Square Root\n[9] Power \t\t [10] Logarithm\n[11] Quit");

    while(1) // Infinite loop unless exit requested
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        
        if(choice<=0||choice>11)
        {
            printf("\nInvalid selection! Please enter again from the above options.");
            continue;
        }
        
        if(choice==11) // Exit Menu Option
        {
            printf("\nThank you for using CyberCalculator++. We look forward to your reopening!");
            break;
        }

        if(choice>4&&choice<11) //Single Input Operations
        {
            printf("\nEnter number: ");
            scanf("%f",&num1);

            switch(choice)
            {
                case 5:
                    result=sin(num1);
                    printf("\nThe value of sin(%0.2f) is: %0.2f",num1,result);
                    break;

                case 6:
                    result=cos(num1);
                    printf("\nThe value of cos(%0.2f) is: %0.2f",num1,result);
                    break;

                case 7:
                    result=tan(num1);
                    printf("\nThe value of tan(%0.2f) is: %0.2f",num1,result);
                    break;

                case 8:
                    result=sqrt(num1);
                    printf("\nThe square root of %0.2f is: %0.2f",num1,result);
                    break;

                case 9:
                    printf("\nEnter power: ");
                    scanf("%f",&num2);
                    result=pow(num1,num2);
                    printf("\n%0.2f raised to the power of %0.2f is: %0.2f",num1,num2,result);
                    break;

                case 10:
                    result=log(num1);
                    printf("\nThe natural logarithm of %0.2f is: %0.2f",num1,result);
                    break;
            }
        }
        else //Double Input Operations
        {
            printf("\nEnter first number: ");
            scanf("%f",&num1);
            printf("\nEnter second number: ");
            scanf("%f",&num2);

            switch(choice)
            {
                case 1:
                    result=num1+num2;
                    printf("\nThe sum of %0.2f and %0.2f is: %0.2f",num1,num2,result);
                    break;
                case 2:
                    result=num1-num2;
                    printf("\nThe difference of %0.2f and %0.2f is: %0.2f",num1,num2,result);
                    break;
                case 3:
                    result=num1*num2;
                    printf("\nThe product of %0.2f and %0.2f is: %0.2f",num1,num2,result);
                    break;
                case 4:
                    if(num2==0)
                        printf("\nNuclear Detonation Imminent- attempting divided by infinity. System slowdown required to avoid global impact!");
                    else
                    {
                        result=num1/num2;
                        printf("\nThe division of %0.2f by %0.2f is: %0.2f",num1,num2,result);
                    }
                    break;
            }
        }
    }
    return 0;
}