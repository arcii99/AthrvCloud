//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    char choice,c='y';
    float a,b,result;
  
    printf("*******************Scientific Calculator******************\n");
    while(c=='y')
    {
        printf("\nEnter '1' for Addition\nEnter '2' for Subtraction\nEnter '3' for Multiplication\nEnter '4' for Division\nEnter '5' for Square Root\nEnter '6' for Cube Root\nEnter '7' for Power\nEnter '8' for Sin\nEnter '9' for Cos\nEnter '10' for Tan\nEnter '11' for Log10\nEnter '12' for Natural Log\nEnter '13' for Modulus\n\nEnter your choice: ");
        
        scanf("%c",&choice);
        if(choice=='1'||choice=='2'||choice=='3'||choice=='4'||choice=='13')
        {
            printf("\nEnter first number: ");
            scanf("%f",&a);
            printf("\nEnter second number: ");
            scanf("%f",&b);
        }
        else if(choice>='5'&&choice<='13')
        {
            printf("\nEnter a number: ");
            scanf("%f",&a);
        }
        
        switch(choice)
        {
            case '1':
                result=a+b;
                printf("\nResult of (%.2f+%.2f): %.2f\n",a,b,result);
                break;
                
            case '2':
                result=a-b;
                printf("\nResult of (%.2f-%.2f): %.2f\n",a,b,result);
                break;
                
            case '3':
                result=a*b;
                printf("\nResult of (%.2f*%.2f): %.2f\n",a,b,result);
                break;
                
            case '4':
                if(b==0)
                    printf("\nCan't divide by 0\n");
                else
                {
                    result=a/b;
                    printf("\nResult of (%.2f/%.2f): %.2f\n",a,b,result);
                }
                break;
                
            case '5':
                if(a<0)
                    printf("\nInvalid number\n");
                else
                {
                    result=sqrt(a);
                    printf("\nSquare root of %.2f: %.2f\n",a,result);
                }
                break;
                
            case '6':
                if(a<0)
                    printf("\nInvalid number\n");
                else
                {
                    result=cbrt(a);
                    printf("\nCube root of %.2f: %.2f\n",a,result);
                }
                break;
                
            case '7':
                printf("\nEnter power: ");
                scanf("%f",&b);
                result=pow(a,b);
                printf("\nResult of (%.2f^%.2f): %.2f\n",a,b,result);
                break;
                
            case '8':
                result=sin(a);
                printf("\nSin(%.2f): %.2f\n",a,result);
                break;
                
            case '9':
                result=cos(a);
                printf("\nCos(%.2f): %.2f\n",a,result);
                break;
                
            case '10':
                result=tan(a);
                printf("\nTan(%.2f): %.2f\n",a,result);
                break;
                
            case '11':
                if(a<=0)
                    printf("\nInvalid input\n");
                else
                {
                    result=log10(a);
                    printf("\nLog10(%.2f): %.2f\n",a,result);
                }
                break;
                
            case '12':
                if(a<=0)
                    printf("\nInvalid input\n");
                else
                {
                    result=log(a);
                    printf("\nLn(%.2f): %.2f\n",a,result);
                }
                break;
                
            case '13':
                result=fmod(a,b);
                printf("\nResult of (%.2f%%%.2f): %.2f\n",a,b,result);
                break;
                
            default:
                printf("\nInvalid selection\n");
                break;
        }
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c",&c);
    }
    printf("Thank you for using our calculator.\n");
    return 0;
}