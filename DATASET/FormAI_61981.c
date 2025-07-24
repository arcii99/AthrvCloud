//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include<stdio.h>
#include<math.h>

int main()
{
    char operation;
    float num1,num2,result;
    
    printf("\nWelcome to the Energetic Scientific Calculator!\n");
    printf("\nEnter the First Number: ");
    scanf("%f",&num1);
    
    printf("\nEnter the Second Number: ");
    scanf("%f",&num2);
    
    printf("\nOperations available:\n");
    printf("+ for Addition\n- for Subtraction\n* for Multiplication\n/ for Division\n^ for Power(a^b)\ns for Square Root\nr for Remainder(a%b)\n");
    printf("\nEnter the Operation that you want to Perform: ");
    scanf(" %c",&operation);
    
    switch(operation)
    {
        case '+': result=num1+num2;
                  printf("\nThe Sum of %.2f and %.2f is %.2f\n",num1,num2,result);
                  break;
        
        case '-': result=num1-num2;
                  printf("\nThe Difference between %.2f and %.2f is %.2f\n",num1,num2,result);
                  break;
                  
        case '*': result=num1*num2;
                  printf("\nThe Multiplication of %.2f and %.2f is %.2f\n",num1,num2,result);
                  break;
                  
        case '/': if(num2!=0)
                  {
                      result=num1/num2;
                      printf("\nThe Division of %.2f and %.2f is %.2f\n",num1,num2,result);
                  }
                  else
                      printf("\nError! Cannot Divide by Zero!\n");
                  break;
                  
        case '^': result=pow(num1,num2);
                  printf("\n%.2f raised to the power of %.2f is %.2f\n",num1,num2,result);
                  break;
                  
        case 's': result=sqrt(num1);
                  printf("\nThe Square Root of %.2f is %.2f\n",num1,result);
                  break;
                  
        case 'r': if(num2!=0)
                  {
                      result=fmod(num1,num2);
                      printf("\nThe Remainder when %.2f is divided by %.2f is %.2f\n",num1,num2,result);
                  }
                  else
                      printf("\nError! Cannot Find the Remainder When Dividing by Zero!\n");
                  break;
        
        default : printf("Invalid Operation entered!\n");         
    }
    
    return 0;
}