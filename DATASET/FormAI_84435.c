//FormAI DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STOCKS 100  // maximum number of stocks in the tracker
#define MAX_NAME_LEN 20  // maximum length of stock name
#define MAX_DATE_LEN 11  // maximum length of date in format YYYY-MM-DD
#define MAX_PRICE_LEN 10 // maximum length of stock price

struct stock {
  char name[MAX_NAME_LEN];
  char date[MAX_DATE_LEN];
  float price;
};

// function prototypes
void add_stock(struct stock stocks[], int *num_stocks);
void remove_stock(struct stock stocks[], int *num_stocks);
void view_all_stocks(struct stock stocks[], int num_stocks);
void view_stock_details(struct stock stocks[], int num_stocks);
void save_stocks(struct stock stocks[], int num_stocks);
void load_stocks(struct stock stocks[], int *num_stocks);

int main() {
  struct stock stocks[MAX_STOCKS];
  int num_stocks = 0;
  char choice;

  load_stocks(stocks, &num_stocks);

  do {
    printf("\nStock Market Tracker Menu\n");
    printf("----------------------------\n");
    printf("1. Add new stock\n");
    printf("2. Remove stock\n");
    printf("3. View all stocks\n");
    printf("4. View stock details\n");
    printf("5. Save stocks to file\n");
    printf("6. Load stocks from file\n");
    printf("7. Exit program\n");

    printf("Enter your choice: ");
    scanf(" %c", &choice);
    getchar(); // consume newline character

    switch (choice) {
      case '1':
        add_stock(stocks, &num_stocks);
        break;
      case '2':
        remove_stock(stocks, &num_stocks);
        break;
      case '3':
        view_all_stocks(stocks, num_stocks);
        break;
      case '4':
        view_stock_details(stocks, num_stocks);
        break;
      case '5':
        save_stocks(stocks, num_stocks);
        break;
      case '6':
        load_stocks(stocks, &num_stocks);
        break;
      case '7':
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != '7');

  return 0;
}

// function to add a new stock to the tracker
void add_stock(struct stock stocks[], int *num_stocks) {
  if (*num_stocks == MAX_STOCKS) {
    printf("No more space in stock tracker.\n");
    return;
  }

  struct stock s;

  printf("Enter stock name: ");
  fgets(s.name, MAX_NAME_LEN, stdin);
  strtok(s.name, "\n");

  printf("Enter date (YYYY-MM-DD): ");
  fgets(s.date, MAX_DATE_LEN, stdin);
  strtok(s.date, "\n");

  printf("Enter price: ");
  scanf("%f", &s.price);
  getchar(); // consume newline character

  stocks[*num_stocks] = s;
  (*num_stocks)++;

  printf("Stock added successfully.\n");
}

// function to remove a stock from the tracker
void remove_stock(struct stock stocks[], int *num_stocks) {
  if (*num_stocks == 0) {
    printf("No stocks to remove.\n");
    return;
  }

  char name[MAX_NAME_LEN];

  printf("Enter stock name to remove: ");
  fgets(name, MAX_NAME_LEN, stdin);
  strtok(name, "\n");

  int i;
  for (i = 0; i < *num_stocks; i++) {
    if (strcmp(stocks[i].name, name) == 0) {
      // found the stock, shift all the remaining stocks left
      int j;
      for (j = i + 1; j < *num_stocks; j++) {
        stocks[j - 1] = stocks[j];
      }

      (*num_stocks)--;

      printf("Stock removed successfully.\n");
      return;
    }
  }

  // stock not found
  printf("Stock not found in tracker.\n");
}

// function to view all stocks in the tracker
void view_all_stocks(struct stock stocks[], int num_stocks) {
  if (num_stocks == 0) {
    printf("No stocks to view.\n");
    return;
  }

  printf("Stocks in tracker:\n");
  printf("-------------------\n");
  int i;
  for (i = 0; i < num_stocks; i++) {
    printf("[%d] %s (%s) - $%.2f\n", i + 1, stocks[i].name, stocks[i].date, stocks[i].price);
  }
}

// function to view details of a specific stock
void view_stock_details(struct stock stocks[], int num_stocks) {
  if (num_stocks == 0) {
    printf("No stocks to view details.\n");
    return;
  }

  char name[MAX_NAME_LEN];

  printf("Enter stock name to view details: ");
  fgets(name, MAX_NAME_LEN, stdin);
  strtok(name, "\n");

  int i;
  for (i = 0; i < num_stocks; i++) {
    if (strcmp(stocks[i].name, name) == 0) {
      printf("Stock details:\n");
      printf("--------------\n");
      printf("Name: %s\n", stocks[i].name);
      printf("Date: %s\n", stocks[i].date);
      printf("Price: $%.2f\n", stocks[i].price);
      return;
    }
  }

  // stock not found
  printf("Stock not found in tracker.\n");
}

// function to save stocks to file
void save_stocks(struct stock stocks[], int num_stocks) {
  if (num_stocks == 0) {
    printf("No stocks to save.\n");
    return;
  }

  char filename[MAX_NAME_LEN];

  printf("Enter filename to save stocks to: ");
  fgets(filename, MAX_NAME_LEN, stdin);
  strtok(filename, "\n");

  FILE *f = fopen(filename, "w");
  if (f == NULL) {
    printf("Unable to open file %s for writing.\n", filename);
    return;
  }

  int i;
  for (i = 0; i < num_stocks; i++) {
    fprintf(f, "%s,%s,%.2f\n", stocks[i].name, stocks[i].date, stocks[i].price);
  }

  fclose(f);
  printf("Stocks saved to file successfully.\n");
}

// function to load stocks from file
void load_stocks(struct stock stocks[], int *num_stocks) {
  char filename[MAX_NAME_LEN];

  printf("Enter filename to load stocks from: ");
  fgets(filename, MAX_NAME_LEN, stdin);
  strtok(filename, "\n");

  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Unable to open file %s for reading.\n", filename);
    return;
  }

  // clear the current stocks
  *num_stocks = 0;

  char line[MAX_NAME_LEN + MAX_DATE_LEN + MAX_PRICE_LEN + 3];
  while (fgets(line, sizeof(line), f) != NULL) {
    char *name = strtok(line, ",");
    char *date = strtok(NULL, ",");
    float price = atof(strtok(NULL, ","));

    struct stock s;
    strcpy(s.name, name);
    strcpy(s.date, date);
    s.price = price;

    stocks[*num_stocks] = s;
    (*num_stocks)++;
  }

  fclose(f);
  printf("Stocks loaded from file successfully.\n");
}