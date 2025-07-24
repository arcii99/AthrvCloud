//FormAI DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
  char company_name[50];
  float price;
  float open_price;
  float close_price;
  int volume;
  char change[20];
};

void display_data(struct stock data[], int size) {
  printf("\nCompany Name\tPrice\t\tOpen Price\tClose Price\tVolume\t\tChange\n");
  printf("---------------------------------------------------------------------------------\n");
  for (int i = 0; i < size; i++) {
    printf("%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%d\t\t%s\n", data[i].company_name, data[i].price, data[i].open_price, data[i].close_price, data[i].volume, data[i].change);
  }
}

void search_by_company_name(struct stock data[], int size) {
  char search_name[50];
  int flag = 0;
  printf("Enter a company name: ");
  scanf("%s", search_name);
  for (int i = 0; i < size; i++) {
    if (strcmp(search_name, data[i].company_name) == 0) {
      printf("\nCompany Name\tPrice\t\tOpen Price\tClose Price\tVolume\t\tChange\n");
      printf("---------------------------------------------------------------------------------\n");
      printf("%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%d\t\t%s\n", data[i].company_name, data[i].price, data[i].open_price, data[i].close_price, data[i].volume, data[i].change);
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    printf("\nNo data found for the entered company name.\n");
  }
}

void search_by_price_range(struct stock data[], int size) {
  float min_price, max_price;
  int flag = 0;
  printf("Enter minimum price: ");
  scanf("%f", &min_price);
  printf("Enter maximum price: ");
  scanf("%f", &max_price);
  printf("\nCompany Name\tPrice\t\tOpen Price\tClose Price\tVolume\t\tChange\n");
  printf("---------------------------------------------------------------------------------\n");
  for (int i = 0; i < size; i++) {
    if (data[i].price >= min_price && data[i].price <= max_price) {
      printf("%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%d\t\t%s\n", data[i].company_name, data[i].price, data[i].open_price, data[i].close_price, data[i].volume, data[i].change);
      flag = 1;
    }
  }
  if (flag == 0) {
    printf("\nNo data found for the entered price range.\n");
  }
}

int main() {
  int size = 5;
  struct stock data[size];
  strcpy(data[0].company_name, "Google");
  data[0].price = 2400.50;
  data[0].open_price = 2410.30;
  data[0].close_price = 2390.20;
  data[0].volume = 1000;
  strcpy(data[0].change, "+0.50%");
  strcpy(data[1].company_name, "Apple");
  data[1].price = 130.25;
  data[1].open_price = 132.30;
  data[1].close_price = 129.90;
  data[1].volume = 500;
  strcpy(data[1].change, "-1.20%");
  strcpy(data[2].company_name, "Microsoft");
  data[2].price = 240.70;
  data[2].open_price = 242.50;
  data[2].close_price = 238.50;
  data[2].volume = 700;
  strcpy(data[2].change, "-0.80%");
  strcpy(data[3].company_name, "Amazon");
  data[3].price = 3165.80;
  data[3].open_price = 3180.00;
  data[3].close_price = 3155.50;
  data[3].volume = 900;
  strcpy(data[3].change, "-0.70%");
  strcpy(data[4].company_name, "IBM");
  data[4].price = 141.30;
  data[4].open_price = 140.50;
  data[4].close_price = 141.80;
  data[4].volume = 300;
  strcpy(data[4].change, "+0.60%");
  int option;
  do {
    printf("\n1. Display all data\n2. Search by company name\n3. Search by price range\n4. Exit\n");
    printf("Enter an option: ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        display_data(data, size);
        break;
      case 2:
        search_by_company_name(data, size);
        break;
      case 3:
        search_by_price_range(data, size);
        break;
      case 4:
        printf("\nExiting...\n");
        break;
      default:
        printf("Invalid option! Try again.\n");
    }
  } while (option != 4);
  return 0;
}