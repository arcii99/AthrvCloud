//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include<stdio.h>

// Function to calculate Simple Interest
float simple_interest(float p, float r, float t) {
    return (p*r*t)/100;
}

// Function to calculate Compound Interest
float compound_interest(float p, float r, float t) {
    float ci = p;
    for(int i=0; i<t; i++) {
        ci += (ci*r)/100;
    }
    return ci-p;
}

int main() {

    // Taking Input
    float principle, rate, time;
    printf("Enter Principle Amount: ");
    scanf("%f", &principle);
    printf("Enter Rate of Interest: ");
    scanf("%f", &rate);
    printf("Enter Time period (in years): ");
    scanf("%f", &time);
    printf("\n");

    // Calculating Simple Interest
    float si = simple_interest(principle, rate, time);
    printf("Simple Interest for %0.2f years: %0.2f\n", time, si);

    // Calculating Compound Interest
    float ci = compound_interest(principle, rate, time);
    printf("Compound Interest for %0.2f years: %0.2f\n", time, ci);

    // Calculating Future Value
    float fv = principle + ci;
    printf("Future Value after %0.2f years: %0.2f\n", time, fv);

    // Calculating Present Value
    float pv = principle/(1+(rate/100)*time);
    printf("Present Value: %0.2f\n", pv);

    // Calculating Annuity or Annual Payment
    float annuity = (principle*rate*(pow(1+(rate/100),time)))/((pow(1+(rate/100),time))-1);
    printf("Annual Payment for %0.2f years: %0.2f\n", time, annuity);

    return 0;
}