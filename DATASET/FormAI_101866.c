//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

struct Item {
  char name[50];
  int quantity;
  float price;
};

float calculateTotal(struct Item items[], int count) {
  float total = 0;
  for(int i = 0; i< count; i++) {
    total += items[i].quantity * items[i].price;
  }
  return total;
}

void printItems(struct Item items[], int count) {
  printf("Items:\n");
  for(int i = 0; i < count; i++) {
    printf("%s\t %d\t %.2f\n", items[i].name, items[i].quantity, items[i].price);
  }
}

int main() {
  int itemCount;
  printf("Enter the number of items you want to order: ");
  scanf("%d", &itemCount);
  struct Item items[itemCount];
  for(int i = 0; i < itemCount; i++) {
    printf("Enter item %d's name, quantity and price(separated by spaces): ", i+1);
    scanf("%s %d %f", items[i].name, &items[i].quantity, &items[i].price);
  }
  printItems(items, itemCount);
  printf("Total: %.2f", calculateTotal(items, itemCount));
  return 0;
}