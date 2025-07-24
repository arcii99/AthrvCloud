//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>

//function to calculate compound interest
float compound_interest(float principle, float rate, float time){
    float ci = principle * (pow((1 + (rate/100)), time));
    return ci;
}

//function to calculate simple interest
float simple_interest(float principle, float rate, float time){
    float si = (principle * rate * time) / 100;
    return si;
}

//function to calculate future value
float future_value(float principle, float rate, float time){
    float fv = principle * pow((1 + rate), time);
    return fv;
}

//function to calculate present value
float present_value(float future_value, float rate, float time){
    float pv = future_value / pow(1 + rate, time);
    return pv;
}

//function to calculate monthly payment
float monthly_payment(float principle, float rate, float time){
    float n = time * 12;
    float r = rate / (12*100);

    float mp = (principle * r * pow(1+r, n)) / ((pow(1+r, n)) - 1);
    return mp;
}

int main(){
    int choice;
    float principle, rate, time;

    printf("***** PERSONAL FINANCE PLANNER *****\n\n");
    printf("1. Calculate Compound Interest\n");
    printf("2. Calculate Simple Interest\n");
    printf("3. Calculate Future Value\n");
    printf("4. Calculate Present Value\n");
    printf("5. Calculate Monthly Payment\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    printf("Enter Principle Amount: $");
    scanf("%f", &principle);

    printf("Enter Interest Rate (in percentage): ");
    scanf("%f", &rate);

    printf("Enter Time (in years): ");
    scanf("%f", &time);

    switch(choice){
        case 1:
            printf("Compound Interest: $%.2f\n", compound_interest(principle, rate, time));
            break;

        case 2:
            printf("Simple Interest: $%.2f\n", simple_interest(principle, rate, time));
            break;

        case 3:
            printf("Future Value: $%.2f\n", future_value(principle, rate, time));
            break;

        case 4:
            printf("Present Value: $%.2f\n", present_value(principle, rate, time));
            break;

        case 5:
            printf("Monthly Payment: $%.2f\n", monthly_payment(principle, rate, time));
            break;

        default:
            printf("Invalid Choice!\n");
            break;
    }

    return 0;
}