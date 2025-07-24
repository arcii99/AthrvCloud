//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/select.h>

#define MAX_STOCKS 10
#define STOCK_NAME_LEN 20

typedef struct {
    char name[STOCK_NAME_LEN];
    double price;
    double change;
} stock;

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval;

    stock stocks[MAX_STOCKS];
    int stock_count = 0;

    // add initial stocks to the tracker
    strcpy(stocks[0].name, "AAPL");
    stocks[0].price = 153.12;
    stocks[0].change = 1.23;

    strcpy(stocks[1].name, "GOOG");
    stocks[1].price = 850.67;
    stocks[1].change = -0.45;

    stock_count = 2;

    while (1) {
        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);

        // wait for user input or timeout of 5 seconds
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        retval = select(STDIN_FILENO+1, &rfds, NULL, NULL, &tv);
        if (retval == -1) {
            perror("select()");
            exit(EXIT_FAILURE);
        } else if (retval) {
            // user input detected, exit the program
            break;
        } else {
            // no user input, update the stock prices and display
            printf("\033[2J"); // clear the screen
            printf("\033[H"); // move cursor to top-left corner

            printf("STOCK TRACKER\n");
            printf("===============================\n");

            double total_change = 0;

            for (int i = 0; i < stock_count; i++) {
                // simulate change in stock price
                double change = (double)(rand() % 100 - 50) / 100.0;
                stocks[i].price += change;
                stocks[i].change = change;

                total_change += change;

                printf("%s: $%.2f    %.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
            }

            printf("===============================\n");
            printf("Total Change: %.2f%%\n", total_change);

            sleep(1); // pause for a second before redrawing screen
        }
    }

    return 0;
}