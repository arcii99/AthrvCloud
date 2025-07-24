//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the data structure
#define MAX_SIZE 10

// Define a struct to hold the data structure
typedef struct {
  int data[MAX_SIZE];
  int size;
} DataStructure;

// Generate a random integer between minimum and maximum values
int random_int(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Display the data structure in a visual way
void display(DataStructure ds) {
  printf("Data Structure: ");
  for (int i = 0; i < ds.size; i++) {
    printf("[%d]", ds.data[i]);
  }
  printf("\n\n");
}

// Add a new element to the data structure
void add(DataStructure* ds, int element) {
  if (ds->size >= MAX_SIZE) {
    printf("Data Structure is full\n\n");
    return;
  }
  ds->data[ds->size++] = element;
}

// Remove an element from the data structure at the specified index
void remove_at(DataStructure* ds, int index) {
  if (index < 0 || index >= ds->size) {
    printf("Invalid index\n\n");
    return;
  }
  for (int i = index; i < ds->size - 1; i++) {
    ds->data[i] = ds->data[i+1];
  }
  ds->size--;
}

// Search for an element in the data structure
int search(DataStructure ds, int element) {
  for (int i = 0; i < ds.size; i++) {
    if (ds.data[i] == element) {
      return i;
    }
  }
  return -1;
}

int main() {

  // Seed the random number generator
  srand(time(NULL));

  // Initialize the data structure
  DataStructure ds = { .data = {0}, .size = 0 };

  // Add random elements to the data structure
  for (int i = 0; i < MAX_SIZE; i++) {
    int element = random_int(0, 9);
    add(&ds, element);
  }

  // Display the initial state of the data structure
  display(ds);

  // Remove an element at a random index
  int index = random_int(0, MAX_SIZE-1);
  remove_at(&ds, index);

  // Display the new state of the data structure
  display(ds);

  // Search for a random element in the data structure
  int element = random_int(0, 9);
  int result = search(ds, element);
  if (result != -1) {
    printf("Element %d found at index %d\n", element, result);
  } else {
    printf("Element %d not found\n", element);
  }

  return 0;
}