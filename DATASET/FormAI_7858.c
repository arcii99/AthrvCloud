//FormAI DATASET v1.0 Category: Stock market tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    
    // Declare and initialize variables    
    int stock_prices[5] = {100, 200, 50, 75, 150};
    int day_counter = 1;
    int disaster_day = rand() % 5 + 1; // random day when a disaster will occur
    int sold_price = 0;
    int total_sold = 0;
    
    // Print initial stock prices
    printf("Day %d Stock Prices: [", day_counter);
    for (int i = 0; i < 5; i++) {
        printf("%d ", stock_prices[i]);
    }
    printf("]\n");
    
    // Loop through each day
    for (int day = 1; day <= 5; day++) {
        
        // Determine if a disaster will occur on this day
        if (day == disaster_day) {
            // Disaster occurs, stock prices decrease by 50%
            printf("\nDisaster has struck on Day %d!\n", disaster_day);
            for (int i = 0; i < 5; i++) {
                stock_prices[i] = stock_prices[i] / 2;
            }
            printf("Day %d Stock Prices: [", day_counter);
            for (int i = 0; i < 5; i++) {
                printf("%d ", stock_prices[i]);
            }
            printf("]\n");
        } else {
            // Normal trading day, stock prices randomly increase or decrease by up to 20%
            printf("\nDay %d Stock Prices: [", day_counter);
            for (int i = 0; i < 5; i++) {
                int fluctuation = rand() % 41 - 20; // random number between -20 and 20
                stock_prices[i] = stock_prices[i] + (stock_prices[i] * fluctuation / 100);
                printf("%d ", stock_prices[i]);
            }
            printf("]\n");
            
            // Ask user if they want to sell their stock on this day
            char sell;
            printf("Would you like to sell your stock today? (Y/N) ");
            scanf(" %c", &sell);
            if (sell == 'Y' || sell == 'y') {
                // User sells their stock
                printf("Which stock would you like to sell? (1-5) ");
                int stock_choice;
                scanf("%d", &stock_choice);
                sold_price = stock_prices[stock_choice - 1];
                total_sold = total_sold + sold_price;
                printf("You sold your stock for $%d on Day %d\n", sold_price, day_counter);
            }
        }
        
        // Increment day counter and update disaster day
        day_counter++;
        if (day_counter == disaster_day) {
            disaster_day = rand() % 5 + day_counter + 1;
        }
    }
    
    // Print total sold and average sell price
    printf("\nYou sold your stock for a total of $%d\n", total_sold);
    if (total_sold != 0) {
        float avg_sell_price = (float) total_sold / 5;
        printf("Your average sell price was $%0.2f\n", avg_sell_price);
    }
    
    return 0;
}