//FormAI DATASET v1.0 Category: Data mining ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

bool contains(int* array, int size, int value) {
  for(int i = 0; i < size; i++) {
    if(array[i] == value) {
      return true;
    }
  }
  
  return false;
}

int main() {
  int data[NUM_ROWS][NUM_COLUMNS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
  
  int support = 2;
  int itemset1[] = {1, 3};
  int itemset2[] = {2, 3};
  
  int num_transactions = NUM_ROWS;
  int num_items = NUM_COLUMNS;
  
  int itemset1_count = 0;
  int itemset2_count = 0;
  for(int i = 0; i < num_transactions; i++) {
    int* transaction = data[i];
    
    if(contains(transaction, num_items, itemset1[0]) && contains(transaction, num_items, itemset1[1])) {
      itemset1_count++;
    }
    
    if(contains(transaction, num_items, itemset2[0]) && contains(transaction, num_items, itemset2[1])) {
      itemset2_count++;
    }
  }
  
  if(itemset1_count >= support) {
    printf("Itemset {1, 3} has sufficient support.\n");
  }
  
  if(itemset2_count >= support) {
    printf("Itemset {2, 3} has sufficient support.\n");
  }
  
  return 0;
}