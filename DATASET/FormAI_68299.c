//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: statistical
#include<stdio.h>
#include<math.h>

int main(){
    float principle, rate, term, monthly, interest, total_interest, total_amount;
    int choice;

    printf("-------Welcome to the Mortgage Calculator-------\n");
    printf("Please select an option:\n");
    printf("1. Calculate Monthly Payment\n");
    printf("2. Calculate Total Interest and Total Amount\n");
    printf("Enter choice(1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("\nEnter Principle Amount: ");
        scanf("%f", &principle);
        printf("Enter Interest Rate: ");
        scanf("%f", &rate);
        printf("Enter Term (in years): ");
        scanf("%f", &term);

        rate = rate/100.0; //converting interest rate to decimal

        //calculating monthly payment
        monthly = (principle * rate *(pow(1+rate, term*12))) / ((pow(1+rate, term*12)) -1);

        printf("\nMonthly Payment = $%.2f", monthly);
    }
    else if(choice == 2){
        printf("\nEnter Principle Amount: ");
        scanf("%f", &principle);
        printf("Enter Interest Rate: ");
        scanf("%f", &rate);
        printf("Enter Term (in years): ");
        scanf("%f", &term);

        rate = rate/100.0; //converting interest rate to decimal

        //calculating total interest and total amount
        interest = (principle * rate * term);
        total_interest = interest;
        total_amount = principle + interest;
        printf("\nYear\tInterest\tTotal Amount");

        for(int i=1; i<=term; i++){
            interest = (total_amount * rate);
            total_interest += interest;
            total_amount += interest;
            printf("\n%d\t$%.2f\t\t$%.2f", i, interest, total_amount);
        }

        printf("\n\nTotal Interest = $%.2f", total_interest);
        printf("\nTotal Amount = $%.2f", total_amount);
    }
    else{
        printf("\nInvalid choice! Please select either 1 or 2");
    }

    return 0;
}