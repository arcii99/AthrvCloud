//FormAI DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum values for string and file names
#define MAX_STR_LEN 100
#define MAX_FILE_NAME_LEN 50

// function to remove trailing newline character from a string
void remove_newline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

// function to read ticker symbols from file and store in an array
int read_tickers(char *file_name, char **tickers) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", file_name);
        exit(1);
    }

    // read ticker symbols from file and store in array
    int count = 0;
    char ticker[MAX_STR_LEN];
    while (fgets(ticker, MAX_STR_LEN, fp)) {
        remove_newline(ticker);
        tickers[count] = malloc(sizeof(char) * (strlen(ticker) + 1));
        strcpy(tickers[count], ticker);
        count++;
    }

    fclose(fp);
    return count;
}

// function to get current price of a stock
float get_price(char *ticker) {
    // code to retrieve stock price using an API or web scraping
    // this is just a placeholder for demonstration purposes
    return (float)(rand() % 1000) / 100.0;
}

// function to update prices of all stocks in array
void update_prices(char **tickers, float *prices, int count) {
    for (int i = 0; i < count; i++) {
        prices[i] = get_price(tickers[i]);
    }
}

// function to calculate average price of all stocks in array
float calc_average_price(float *prices, int count) {
    if (count == 0) {
        return 0.0;
    }

    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += prices[i];
    }

    return sum / count;
}

// main function
int main() {
    // read ticker symbols from file
    char file_name[MAX_FILE_NAME_LEN];
    printf("Enter file name containing ticker symbols: ");
    fgets(file_name, MAX_FILE_NAME_LEN, stdin);
    remove_newline(file_name);

    char *tickers[MAX_STR_LEN];
    int count = read_tickers(file_name, tickers);

    // allocate prices array dynamically
    float *prices = malloc(sizeof(float) * count);

    // initialize prices with current prices of stocks
    update_prices(tickers, prices, count);

    // loop to display and update prices continuously
    printf("Ticker symbols and current prices:\n");
    while (1) {
        for (int i = 0; i < count; i++) {
            printf("%s: %.2f\n", tickers[i], prices[i]);
        }

        float avg_price = calc_average_price(prices, count);
        printf("Average price: %.2f\n", avg_price);

        printf("Press enter to update prices, or q to quit: ");
        char input[MAX_STR_LEN];
        fgets(input, MAX_STR_LEN, stdin);
        remove_newline(input);
        if (strcmp(input, "q") == 0) {
            break;
        }

        update_prices(tickers, prices, count);
    }

    // free dynamically allocated memory
    for (int i = 0; i < count; i++) {
        free(tickers[i]);
    }
    free(prices);

    return 0;
}