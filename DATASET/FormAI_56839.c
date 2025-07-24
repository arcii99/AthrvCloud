//FormAI DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock{
    char company[50];
    float value;
    float change;
} Stock;

int main(){
    Stock stocks[5];
    strcpy(stocks[0].company, "Apple Inc.");
    strcpy(stocks[1].company, "Microsoft Corporation");
    strcpy(stocks[2].company, "Amazon.com, Inc.");
    strcpy(stocks[3].company, "Facebook, Inc.");
    strcpy(stocks[4].company, "Alphabet Inc.");

    stocks[0].value = 150.2;
    stocks[0].change = 2.5;
    stocks[1].value = 125.6;
    stocks[1].change = -0.6;
    stocks[2].value = 3105.4;
    stocks[2].change = -1.1;
    stocks[3].value = 341.3;
    stocks[3].change = 1.6;
    stocks[4].value = 2751.0;
    stocks[4].change = 0.3;

    printf("\nCurrent Stock Market Values:\n\n");
    printf("Company\t\t\tValue\t\tChange\n");
    printf("------------------------------------------------\n");
    for(int i=0; i<5; i++){
        printf("%s\t\t$%.2f\t\t%.2f%%\n", stocks[i].company, stocks[i].value, stocks[i].change);
    }

    return 0;
}