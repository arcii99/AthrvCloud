//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct Item {
  char name[20];
  int quantity;
  float price;
};

int main() {
  FILE *fp;
  char filename[20];
  scanf("%s", filename);
  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Unable to open file\n");
    exit(1);
  }

  struct Item items[100];
  int i = 0;

  while (fscanf(fp, "%[^,],%d,%f\n", items[i].name, &items[i].quantity, &items[i].price) == 3) {
    i++;
  }

  fclose(fp);

  printf("Name\tQuantity\tPrice\n");

  for (int j = 0; j < i; j++) {
    printf("%s\t%.2d\t\t%.2f\n", items[j].name, items[j].quantity, items[j].price);
  }

  return 0;
}