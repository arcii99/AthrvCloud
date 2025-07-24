//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

double factorial(double n){
    double res=1;
    for(int i=1;i<=n;i++){
        res=res*i;
    }
    return res;
} 

double sinx(double x){
  double res=0;
    for(int i=1;i<=100;i++){
        res=res+pow(-1,i-1)*pow(x,2*i-1)/factorial(2*i-1);
    }
    return res;
}

double cosx(double x){
  double res=0;
    for(int i=0;i<=100;i++){
        res=res+pow(-1,i)*pow(x,2*i)/factorial(2*i);
    }
    return res;
}

double tanx(double x){
    double res=sinx(x)/cosx(x);
    return res;
}

double cotx(double x){
    double res=cosx(x)/sinx(x);
    return res;
}

int main(){
    int choice;
    double n,x;
    printf("Welcome to Intelligent Scientific Calculator!\n");
    printf("Please select your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Sin\n");
    printf("7. Cos\n");
    printf("8. Tan\n");
    printf("9. Cot\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf",&n,&x);
            printf("Result: %.2lf",n+x);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf",&n,&x);
            printf("Result: %.2lf",n-x);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf",&n,&x);
            printf("Result: %.2lf",n*x);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf",&n,&x);
            if(x!=0){
              printf("Result: %.2lf",n/x);
            }else{
              printf("Error: Division by zero");
            }
            break;
        case 5:
            printf("Enter the number: ");
            scanf("%lf",&n);
            printf("Enter power: ");
            scanf("%lf",&x);
            printf("Result: %.2lf",pow(n,x));
            break;
        case 6:
            printf("Enter angle in radians: ");
            scanf("%lf",&x);
            printf("Result: %.2lf",sinx(x));
            break;
        case 7:
            printf("Enter angle in radians: ");
            scanf("%lf",&x);
            printf("Result: %.2lf",cosx(x));
            break;
        case 8:
            printf("Enter angle in radians: ");
            scanf("%lf",&x);
            printf("Result: %.2lf",tanx(x));
            break;
        case 9:
            printf("Enter angle in radians: ");
            scanf("%lf",&x);
            printf("Result: %.2lf",cotx(x));
            break;
        default:
            printf("Error: Invalid choice");
            break;
    }
    printf("\nThank you for using Intelligent Scientific Calculator!");
    return 0;
}