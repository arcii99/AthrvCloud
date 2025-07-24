//FormAI DATASET v1.0 Category: Computer Biology ; Style: happy
#include <stdio.h>

// Declare a struct called "Organism"
struct Organism {
  char* name;   // Name of the organism
  int age;      // Age of the organism
  float weight; // Weight of the organism
};

// Declare a function to create and return a new Organism
struct Organism* createOrganism(char* name, int age, float weight) {
  // Allocate memory for a new Organism struct
  struct Organism* organism = malloc(sizeof(struct Organism));

  // If memory allocation fails, return NULL
  if (organism == NULL) {
    return NULL;
  }

  // Set the fields of the new Organism struct
  organism->name = name;
  organism->age = age;
  organism->weight = weight;

  // Return the new Organism struct
  return organism;
}

int main() {
  // Create a new organism called "Fluffy"
  struct Organism* fluffy = createOrganism("Fluffy", 2, 2.3);

  // Print out Fluffy's information
  printf("Name: %s\n", fluffy->name);
  printf("Age: %d years old\n", fluffy->age);
  printf("Weight: %.1f kg\n", fluffy->weight);

  // Free the memory allocated for Fluffy
  free(fluffy);

  // Exit the program
  return 0;
}