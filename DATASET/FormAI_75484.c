//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float x,y,result;
    int choice;
    
    printf("\t\t\tWelcome to the Surrealist Scientific Calculator\n\n");
    printf("Please choose a function from the following:\n");
    printf("1. Take the derivative of your favorite color\n");
    printf("2. Calculate the cosmic weight of your dreams\n");
    printf("3. Measure the imaginary number of your personality\n");
    printf("4. Determine the real and surreal roots of your emotions\n");
    printf("5. Exit\n");
  
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("\nPlease enter your favorite color code (in hex): ");
            scanf("%x",&x);
            
            result = x;
            printf("\nThe derivative of your favorite color (#%x) is: %f\n", (int)x, result);
            break;
        
        case 2:
            printf("\nEnter the weight of your dreams (in grams): ");
            scanf("%f",&x);
            
            result = x * (10.0/7.0) * (1.0/137.0) * (-1.0/2.0) * (1.0/9.0) * (3.14/2.71) * (1.0/6.0);
            printf("\nThe cosmic weight of your dreams is: %f Planck masses\n", result);
            break;
        
        case 3:
            printf("\nEnter the imaginary component of your personality: ");
            scanf("%f",&x);
            
            result = sqrt(fabs(x)) * log(fabs(x));
            printf("\nThe imaginary number of your personality (%f) is: %f\n", x, result);
            break;
        
        case 4:
            printf("\nEnter the real and surreal components of your emotions (in float and imaginary form respectively): ");
            scanf("%f%f",&x,&y);
            
            result = sqrt(fabs(x)) + y/(2*x);
            printf("\nThe real and surreal roots of your emotions (%f + %fi) are: %f and %f\n", x, y, result, -1.0*result);
            break;
        
        case 5:
            printf("\nThank you for using the Surrealist Scientific Calculator. Have a surreal day!\n");
            exit(0);
            break;
        
        default:
            printf("\nInvalid choice. Please select from the given options.\n");
            break;
    }
    
    return 0;
}