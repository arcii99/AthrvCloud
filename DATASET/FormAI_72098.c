//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Romeo and Juliet
#include<stdio.h>

int main(){

    printf("O Romeo, what mortgage rate would you like to set? \n");
    float mortgageRate;
    scanf("%f",&mortgageRate);

    printf("It is the East, and House Capulet, how much is the mortgage amount? \n");
    float mortgageAmount;
    scanf("%f",&mortgageAmount);

    printf("Arise, fair sun, and kill the envious moon. What is the term of your mortgage (in years)? \n");
    int mortgageTerm;
    scanf("%d",&mortgageTerm); 

    float monthlyRate = mortgageRate /(100*12); 
    float termInMonths = mortgageTerm*12;

    float c = (monthlyRate*mortgageAmount*pow((1+monthlyRate),termInMonths))/(pow((1+monthlyRate),termInMonths)-1);

    printf("But soft! What light through yonder window breaks, the monthly payment is $%.2f \n",c);

    return 0;
}