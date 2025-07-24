//FormAI DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    double STOCK_A, STOCK_B, STOCK_C, STOCK_D, STOCK_E;
    double P_CHANGE_A, P_CHANGE_B, P_CHANGE_C, P_CHANGE_D, P_CHANGE_E;
    double C_PRICE_A, C_PRICE_B, C_PRICE_C, C_PRICE_D, C_PRICE_E;
    time_t t;

    // Initializing the stock prices, percentage change and current prices of all the stocks
    STOCK_A = 150.50;
    STOCK_B = 90.75;
    STOCK_C = 200.45;
    STOCK_D = 450.00;
    STOCK_E = 340.25;

    P_CHANGE_A = 1.5;
    P_CHANGE_B = -2.0;
    P_CHANGE_C = 3.0;
    P_CHANGE_D = 0.5;
    P_CHANGE_E = -1.0;

    C_PRICE_A = STOCK_A * (1 + (P_CHANGE_A / 100));
    C_PRICE_B = STOCK_B * (1 + (P_CHANGE_B / 100));
    C_PRICE_C = STOCK_C * (1 + (P_CHANGE_C / 100));
    C_PRICE_D = STOCK_D * (1 + (P_CHANGE_D / 100));
    C_PRICE_E = STOCK_E * (1 + (P_CHANGE_E / 100));

    // Generating random numbers for percentage change
    srand((unsigned) time(&t));
    int rand_1 = rand() % 9 + 1;
    int rand_2 = rand() % 9 + 1;
    int rand_3 = rand() % 9 + 1;
    int rand_4 = rand() % 9 + 1;
    int rand_5 = rand() % 9 + 1;
    P_CHANGE_A += (double) rand_1 / 10;
    P_CHANGE_B += (double) rand_2 / 10;
    P_CHANGE_C += (double) rand_3 / 10;
    P_CHANGE_D += (double) rand_4 / 10;
    P_CHANGE_E += (double) rand_5 / 10;

    C_PRICE_A = STOCK_A * (1 + (P_CHANGE_A / 100));
    C_PRICE_B = STOCK_B * (1 + (P_CHANGE_B / 100));
    C_PRICE_C = STOCK_C * (1 + (P_CHANGE_C / 100));
    C_PRICE_D = STOCK_D * (1 + (P_CHANGE_D / 100));
    C_PRICE_E = STOCK_E * (1 + (P_CHANGE_E / 100));

    // Printing the current prices of all the stocks
    printf("\nCurrent prices of all the stocks are:\n");
    printf("A: %.2lf\n", C_PRICE_A);
    printf("B: %.2lf\n", C_PRICE_B);
    printf("C: %.2lf\n", C_PRICE_C);
    printf("D: %.2lf\n", C_PRICE_D);
    printf("E: %.2lf\n", C_PRICE_E);

    // Checking the trend of the stocks
    if(C_PRICE_A > STOCK_A)
    {
        printf("Stock A is trending up.\n");
    }
    else if(C_PRICE_A < STOCK_A)
    {
        printf("Stock A is trending down.\n");
    }
    else
    {
        printf("Stock A is stable.\n");
    }

    if(C_PRICE_B > STOCK_B)
    {
        printf("Stock B is trending up.\n");
    }
    else if(C_PRICE_B < STOCK_B)
    {
        printf("Stock B is trending down.\n");
    }
    else
    {
        printf("Stock B is stable.\n");
    }

    if(C_PRICE_C > STOCK_C)
    {
        printf("Stock C is trending up.\n");
    }
    else if(C_PRICE_C < STOCK_C)
    {
        printf("Stock C is trending down.\n");
    }
    else
    {
        printf("Stock C is stable.\n");
    }

    if(C_PRICE_D > STOCK_D)
    {
        printf("Stock D is trending up.\n");
    }
    else if(C_PRICE_D < STOCK_D)
    {
        printf("Stock D is trending down.\n");
    }
    else
    {
        printf("Stock D is stable.\n");
    }

    if(C_PRICE_E > STOCK_E)
    {
        printf("Stock E is trending up.\n");
    }
    else if(C_PRICE_E < STOCK_E)
    {
        printf("Stock E is trending down.\n");
    }
    else
    {
        printf("Stock E is stable.\n");
    }

    return 0;
}