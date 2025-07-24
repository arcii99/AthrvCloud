//FormAI DATASET v1.0 Category: Expense Tracker ; Style: genious
/*
  Genius Expense Tracker Program
  Author: Your Name
  Date: Today's Date
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum expense items for each category
#define MAX_FOOD_ITEMS 20
#define MAX_TRANSPORTATION_ITEMS 10
#define MAX_HOUSING_ITEMS 5

// define struct for expense item
struct ExpenseItem {
  char name[50];
  float amount;
};

// define struct for category
struct Category {
  char name[50];
  struct ExpenseItem items[MAX_FOOD_ITEMS + MAX_TRANSPORTATION_ITEMS + MAX_HOUSING_ITEMS];
  int num_items;
};

// declare global variables
struct Category food;
struct Category transportation;
struct Category housing;

// function to add item to category
void add_item(struct Category *category, char name[], float amount) {
  if (category->num_items < MAX_FOOD_ITEMS + MAX_TRANSPORTATION_ITEMS + MAX_HOUSING_ITEMS) {
    struct ExpenseItem item;
    strcpy(item.name, name);
    item.amount = amount;
    category->items[category->num_items] = item;
    category->num_items++;
    printf("Item added successfully!\n");
  } else {
    printf("Maximum number of items reached for category %s.\n", category->name);
  }
}

// function to display all items in category
void display_items(struct Category *category) {
  printf("Items in category: %s\n", category->name);
  for (int i = 0; i < category->num_items; i++) {
    printf("%d. %s: $%.2f\n", i+1, category->items[i].name, category->items[i].amount);
  }
}

// function to calculate total expense for category
float calculate_total_expense(struct Category *category) {
  float total = 0;
  for (int i = 0; i < category->num_items; i++) {
    total += category->items[i].amount;
  }
  return total;
}

// main function
int main() {
  // initialize categories
  strcpy(food.name, "Food");
  food.num_items = 0;

  strcpy(transportation.name, "Transportation");
  transportation.num_items = 0;

  strcpy(housing.name, "Housing");
  housing.num_items = 0;

  // add some items to categories
  add_item(&food, "Groceries", 50.25);
  add_item(&food, "Dining out", 35.50);
  add_item(&transportation, "Gas", 40.00);
  add_item(&housing, "Rent", 1000.00);

  // display all items in each category
  display_items(&food);
  display_items(&transportation);
  display_items(&housing);

  // calculate and display total expense for each category
  float food_total = calculate_total_expense(&food);
  printf("Total expense for Food category: $%.2f\n", food_total);

  float transportation_total = calculate_total_expense(&transportation);
  printf("Total expense for Transportation category: $%.2f\n", transportation_total);

  float housing_total = calculate_total_expense(&housing);
  printf("Total expense for Housing category: $%.2f\n", housing_total);

  return 0;
}