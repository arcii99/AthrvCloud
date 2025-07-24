//FormAI DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  printf("Welcome to the post-apocalyptic wasteland. Let's search for some valuable resources.\n");

  int num_items = 6;
  char items[num_items][10];
  int quantities[num_items];

  //initialize items and quantities
  strcpy(items[0], "water");
  quantities[0] = 10;
  strcpy(items[1], "food");
  quantities[1] = 5;
  strcpy(items[2], "ammo");
  quantities[2] = 15;
  strcpy(items[3], "medical supplies");
  quantities[3] = 8;
  strcpy(items[4], "weapons");
  quantities[4] = 3;
  strcpy(items[5], "fuel");
  quantities[5] = 20;

  printf("Here are the resources we have:\n");
  for(int i = 0; i < num_items; i++) {
      printf("%s (%d)\n", items[i], quantities[i]);
  }

  char search_item[10];
  printf("What are you searching for? ");
  scanf("%s", search_item);

  int found = 0;
  for(int i = 0; i < num_items; i++) {
      if(strcmp(search_item, items[i]) == 0) {
          printf("Found %s! Quantity: %d\n", items[i], quantities[i]);
          found = 1;
          break;
      }
  }

  if(!found) {
      printf("Sorry, we don't have any %s.\n", search_item);
  }

  return 0;
}