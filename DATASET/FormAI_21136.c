//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Sherlock Holmes
#include<stdio.h>
#include<math.h>

int main()
{
    int choice,a,b,c;
    float x,y,result;
    printf("\n\t Scientific Calculator");
    printf("\n\n Available Operations:");
    printf("\n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division \n 5. Square Root \n 6. Power \n 7. Exit");

    do{
        printf("\n\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\n Enter two numbers: ");
                    scanf("%d%d",&a,&b);
                    result=a+b;
                    printf("\n Result: %d+%d=%f",a,b,result);
                    break;
                    
            case 2: printf("\n Enter two numbers: ");
                    scanf("%d%d",&a,&b);
                    result=a-b;
                    printf("\n Result: %d-%d=%f",a,b,result);
                    break;
                    
            case 3: printf("\n Enter two numbers: ");
                    scanf("%d%d",&a,&b);
                    result=a*b;
                    printf("\n Result: %d*%d=%f",a,b,result);
                    break;
                    
            case 4: printf("\n Enter two numbers: ");
                    scanf("%d%d",&a,&b);
                    result=a/b;
                    printf("\n Result: %d/%d=%f",a,b,result);
                    break;
                    
            case 5: printf("\n Enter a number: ");
                    scanf("%f",&x);
                    result=sqrt(x);
                    printf("\n Result: Square Root of %f=%f",x,result);
                    break;
                    
            case 6: printf("\n Enter two numbers: ");
                    scanf("%d%d",&a,&b);
                    result=pow(a,b);
                    printf("\n Result: %d^%d=%f",a,b,result);
                    break;
            
            case 7: printf("\n\n Thank You for using Scientific Calculator!");
                    printf("\n\t Goodbye!");
                    break;
                    
            default:printf("\n Invalid Choice!");
                    break;
        }
        
    }while(choice!=7);

    return 0;
}