//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>

int main()
{
    float principal, rate, time, emi, interest;
    int choice;

    printf("\nWelcome to the Mortgage Calculator!\n");

    while (1)
    {
        // Display menu
        printf("\nChoose an option:\n");
        printf("1. Calculate EMI\n");
        printf("2. Calculate Interest\n");
        printf("3. Exit\n");

        // Get the user's choice
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Calculate EMI
                printf("\nEnter the Principal Amount: ");
                scanf("%f", &principal);
                printf("Enter the Rate of Interest (per year): ");
                scanf("%f", &rate);
                printf("Enter the Time Period (in years): ");
                scanf("%f", &time);

                rate /= 1200; // Convert annual rate to monthly rate
                time *= 12; // Convert years to months

                // Calculate EMI
                emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

                // Print the EMI
                printf("\nYour Monthly EMI: Rs. %.2f\n", emi);
                break;

            case 2:
                // Calculate Interest
                printf("\nEnter the Principal Amount: ");
                scanf("%f", &principal);
                printf("Enter the Rate of Interest (per year): ");
                scanf("%f", &rate);
                printf("Enter the Time Period (in years): ");
                scanf("%f", &time);

                // Calculate Interest
                interest = principal * rate * time;

                // Print the Interest
                printf("\nYour Total Interest Amount: Rs. %.2f\n", interest);
                break;

            case 3:
                // Exit the program
                printf("\nThank you for using the Mortgage Calculator! Goodbye.\n");
                return 0;

            default:
                // Invalid choice
                printf("\nInvalid choice. Please try again!\n");
        }
    }
}