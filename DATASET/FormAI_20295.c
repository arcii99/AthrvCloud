//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COMPANY_NAME_LENGTH 20
#define MAX_STOCK_PRICE 100
#define MIN_STOCK_PRICE 10
#define MAX_NUM_OF_STOCKS 500
#define MIN_NUM_OF_STOCKS 10

struct Company {
    char name[MAX_COMPANY_NAME_LENGTH];
    int num_of_stocks;
    float stock_price;
};

typedef struct Company Company;

void initialize_companies(Company companies[], int num_of_companies);
void print_companies(Company companies[], int num_of_companies);

int main() {
    srand(time(NULL)); // Seed for random numbers
    int num_of_companies = rand() % 9 + 2; // Random number between 2 and 10
    Company companies[num_of_companies];
    initialize_companies(companies, num_of_companies);
    printf("Stock Prices for Today:\n");
    print_companies(companies, num_of_companies);
    return 0;
}

void initialize_companies(Company companies[], int num_of_companies) {
    char* company_names[] = {"Apple", "Microsoft", "Amazon", "Facebook", "Google", "Tesla", "Nvidia", "Intel", "AMD", "Netflix"};
    for (int i = 0; i < num_of_companies; i++) {
        Company company;
        int name_index = rand() % 10;
        int num_of_stocks = rand() % (MAX_NUM_OF_STOCKS + 1 - MIN_NUM_OF_STOCKS) + MIN_NUM_OF_STOCKS;
        float stock_price = (float)(rand() % (MAX_STOCK_PRICE * 100 + 1 - MIN_STOCK_PRICE * 100) + MIN_STOCK_PRICE * 100) / 100.0;
        sprintf(company.name, "%s", company_names[name_index]);
        company.num_of_stocks = num_of_stocks;
        company.stock_price = stock_price;
        companies[i] = company;
    }
}

void print_companies(Company companies[], int num_of_companies) {
    for (int i = 0; i < num_of_companies; i++) {
        printf("%s: %d Stocks at $%.2f per stock\n", companies[i].name, companies[i].num_of_stocks, companies[i].stock_price);
    }
}