//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: relaxed
#include<stdio.h>

#define MAX_CAPACITY 1000
#define DELAY_MILLISECONDS 500

int main() {

  int i, j, num_of_bags;
  
  // Baggage storing in array
  int baggage[MAX_CAPACITY];
  printf("Enter the number of bags (maximum capacity: %d): ", MAX_CAPACITY);
  scanf("%d", &num_of_bags);
  
  for(i = 0; i < num_of_bags; i++) {
    printf("Enter the weight of bag %d (in kgs): ", i+1);
    scanf("%d", &baggage[i]);
  }

  printf("\nBaggage Loading Started...\n");

  // First in First Out (FIFO) approach used
  for(i = 0; i < num_of_bags; i++) {
    printf("Loading Bag %d of weight %d kg...\n", i+1, baggage[i]);
    for(j = 0; j < DELAY_MILLISECONDS*baggage[i]; j++);
    printf("Bag %d loaded successfully!\n\n", i+1);
  }

  printf("All the Bags are loaded\n");

  return 0;
}