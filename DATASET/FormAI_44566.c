//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: peaceful
#include<stdio.h>     //include standard input and output header file
#include<math.h>      //include math header file for the power function  

int main()      //start of main method
{
    float p, r, t, emi, ci;  //declare variables for principal, rate of interest, time period, EMI and compound interest
    int n;            //declare variables for number of years

    printf("Enter the principal amount: ");  //print statement to ask the user to input the principal amount
    scanf("%f", &p);                         //read the input from user in float data type

    printf("Enter the rate of interest: ");  //print statement to ask the user to input the rate of interest
    scanf("%f", &r);                         //read the input from user in float data type

    printf("Enter the time period in years: ");   //print statement to ask the user to input the time period
    scanf("%d", &n);                              //read the input from user in integer data type

    r = r/(12*100);          //convert the rate of interest from yearly to monthly
    n = n*12;                //convert the time period from annual to monthly

    emi = (p*r*pow(1+r,n))/(pow(1+r,n)-1);      //calculate the EMI using the formula

    printf("EMI = %f\n", emi);      //print statement to display the calculated EMI

    ci = p* pow((1+r),n) - p;           //calculate the compound interest 

    printf("The total amount payable = %f\n", (emi * n));         //print statement to display the total amount payable
    printf("The interest amount is = %f\n", (emi * n) - p);       //print statement to display the interest amount
    printf("The compound interest is = %f\n", ci);                //print statement to display the compound interest

    return 0;       //exit status
}