//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
// Welcome to the stock market tracker program!
// This program will allow you to track the current value of any stock symbol you enter
// You can input up to 10 stock symbols and the program will display their values in real-time

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SYMBOLS 10 //Maximum number of stock symbols that can be tracked
#define MAX_SYMBOL_LENGTH 6 //Maximum length of each stock symbol

void get_symbol_input(char symbols[MAX_SYMBOLS][MAX_SYMBOL_LENGTH], int* num_symbols);
void update_stock_values(char symbols[MAX_SYMBOLS][MAX_SYMBOL_LENGTH], int num_symbols, float values[MAX_SYMBOLS]);
void print_stock_values(char symbols[MAX_SYMBOLS][MAX_SYMBOL_LENGTH], float values[MAX_SYMBOLS], float prev_values[MAX_SYMBOLS], bool changed[MAX_SYMBOLS]);
void wait(int seconds);

int main()
{
    char symbols[MAX_SYMBOLS][MAX_SYMBOL_LENGTH]; //Array to hold stock symbols
    float values[MAX_SYMBOLS]; //Array to hold current stock values
    float prev_values[MAX_SYMBOLS]; //Array to hold previous stock values
    bool changed[MAX_SYMBOLS]; //Array to track if a value has changed

    //Set initial values for arrays
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        for (int j = 0; j < MAX_SYMBOL_LENGTH; j++) {
            symbols[i][j] = '\0';
        }
        values[i] = 0.0;
        prev_values[i] = 0.0;
        changed[i] = false;
    }

    int num_symbols = 0; //Number of stock symbols being tracked
    get_symbol_input(symbols, &num_symbols); //Get user input for stock symbols to track

    while (true) { //Continuously update and display stock values
        update_stock_values(symbols, num_symbols, values); //Update stock values
        print_stock_values(symbols, values, prev_values, changed); //Print stock values
        for (int i = 0; i < MAX_SYMBOLS; i++) {
            prev_values[i] = values[i]; //Save current values as previous values for next iteration
            changed[i] = false; //Reset changed array
        }
        wait(1); //Wait for 1 second before updating again
    }

    return 0;
}

void get_symbol_input(char symbols[MAX_SYMBOLS][MAX_SYMBOL_LENGTH], int* num_symbols) {
    printf("Welcome to the stock market tracker!\n\n");
    printf("Please enter up to %d stock symbols to track (type 'done' to finish):\n", MAX_SYMBOLS);
    char input[MAX_SYMBOL_LENGTH];
    while (*num_symbols < MAX_SYMBOLS) {
        printf("> ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) { //User is finished entering stock symbols
            break;
        }
        else if (strlen(input) > MAX_SYMBOL_LENGTH) { //Input is too long
            printf("Error: Maximum symbol length is %d\n", MAX_SYMBOL_LENGTH);
            continue;
        }
        else { //Add stock symbol to array
            strcpy(symbols[*num_symbols], input);
            (*num_symbols)++;
        }
    }
    printf("\n");
}

void update_stock_values(char symbols[MAX_SYMBOLS][MAX_SYMBOL_LENGTH], int num_symbols, float values[MAX_SYMBOLS]) {
    //Update stock values for each symbol
    for (int i = 0; i < num_symbols; i++) {
        //Generate a random value between 0.0 and 100.0 (for demonstration purposes)
        values[i] = ((float)rand()/(float)(RAND_MAX)) * 100.0;
    }
}

void print_stock_values(char symbols[MAX_SYMBOLS][MAX_SYMBOL_LENGTH], float values[MAX_SYMBOLS], float prev_values[MAX_SYMBOLS], bool changed[MAX_SYMBOLS]) {
    printf("Current Stock Values:\n");
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (strlen(symbols[i]) == 0) { //No symbol entered
            continue;
        }
        else {
            printf("%s: %.2f", symbols[i], values[i]);
            if (prev_values[i] != 0 && values[i] != prev_values[i]) { //Value has changed
                if (values[i] > prev_values[i]) { //Value increased
                    printf(" (+" "\033[1;32m" "%.2f%%" "\033[0m" ")", ((values[i] - prev_values[i])/prev_values[i])*100);
                }
                else if (values[i] < prev_values[i]) { //Value decreased
                    printf(" " "(\033[1;31m" "%.2f%%" "\033[0m" ")", ((prev_values[i] - values[i])/prev_values[i])*100);
                }
                changed[i] = true;
            }
            printf("\n");
        }
    }
    printf("\n");
}

void wait(int seconds) { //Function to wait for a specified number of seconds
    clock_t start_time = clock();
    while (clock() < start_time + (seconds*CLOCKS_PER_SEC));
}