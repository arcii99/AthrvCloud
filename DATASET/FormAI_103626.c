//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Company {
    char name[50];
    float current_price;
    float prev_closing_price;
};

int main() {
    int num_companies;
    printf("Enter the number of companies you want to track: ");
    scanf("%d", &num_companies);

    struct Company companies[num_companies];

    // Get company details
    for (int i=0; i<num_companies; i++) {
        printf("\nEnter details for company %d:\n", i+1);
        printf("Enter company name: ");
        scanf("%s", companies[i].name);
        printf("Enter current price: $");
        scanf("%f", &companies[i].current_price);
        printf("Enter previous closing price: $");
        scanf("%f", &companies[i].prev_closing_price);
    }

    // Print company details
    printf("\n\nCompany Details:\n");
    printf("---------------------------------------------------------------\n");
    printf("Company Name\tCurrent Price\tPrev. Closing Price\tChange\n");
    printf("---------------------------------------------------------------\n");
    for (int i=0; i<num_companies; i++) {
        printf("%s\t\t$%.2f\t\t$%.2f\t\t\t", companies[i].name, companies[i].current_price, companies[i].prev_closing_price);
        float change = companies[i].current_price - companies[i].prev_closing_price;
        if (change > 0) {
            printf("+%.2f", change);
        } else {
            printf("%.2f", change);
        }
        printf("\n");
    }
    printf("---------------------------------------------------------------\n");

    return 0;
}