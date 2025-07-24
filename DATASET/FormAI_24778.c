//FormAI DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int stockValue = 1000 + rand() % 10000; //start stock value between 1000 and 11000
    int days = 0;
    
    printf("\nWelcome to the Happy Stock Market Tracker!\n");
    printf("Your starting stock value is $%d\n", stockValue);
    printf("Let's see how much you can earn!\n\n");
    
    while (stockValue > 1000) {
        int change = -50 + rand() % 100; //random change in value between -50 and 49
        stockValue += change;
        days++;
        
        printf("Day %d: ", days);
        
        if (change < 0) {
            printf("Oh no! Your stock value decreased by $%d. It is now at $%d.\n", abs(change), stockValue);
        } else if (change > 0) {
            printf("Yay! Your stock value increased by $%d. It is now at $%d.\n", change, stockValue);
        } else {
            printf("Your stock value remained the same. It is still at $%d.\n", stockValue);
        }
        
        int happiness = rand() % 5; //random level of happiness between 0 and 4
        
        switch (happiness) {
            case 0:
                printf("You are not very happy about this.\n");
                break;
            case 1:
                printf("You are somewhat happy about this.\n");
                break;
            case 2:
                printf("You are happy about this.\n");
                break;
            case 3:
                printf("You are very happy about this!\n");
                break;
            case 4:
                printf("You are ecstatic about this!!\n");
                break;
        }
        
        printf("\n");
    }
    
    printf("Your stock value has dropped below $1000!\n");
    printf("You lasted for %d days.\n", days);
    printf("Better luck next time!\n");
    
    return 0;
}