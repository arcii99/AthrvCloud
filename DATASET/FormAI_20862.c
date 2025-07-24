//FormAI DATASET v1.0 Category: Computer Biology ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Define the biological structures for our example program
typedef struct _organism {
  int num_cells;
} organism;

typedef struct _cell {
  int health;
} cell;

// 2. Create a function to initialize an organism
void initialize_organism(organism* o) {
  o->num_cells = 1;
}

// 3. Create a function to initialize a cell
void initialize_cell(cell* c) {
  c->health = 100;
}

// 4. Create a function to simulate the growth of an organism
void grow_organism(organism* o) {
  int new_cells = rand() % 10 + 1;
  printf("The organism is growing! %d new cells have been added.\n", new_cells);
  o->num_cells += new_cells;
}

// 5. Create a function to simulate the health of a cell
void check_cell_health(cell* c) {
  if (c->health <= 0) {
    printf("This cell is dead!\n");
  } else if (c->health <= 30) {
    printf("This cell is unhealthy!\n");
  } else if (c->health <= 70) {
    printf("This cell is okay.\n");
  } else {
    printf("This cell is healthy!\n");
  }
}

// 6. Create the main function
int main() {
  srand(time(NULL));
  organism o;
  initialize_organism(&o);
  printf("Welcome to our cheerful biology program!\n");
  printf("Our organism has %d cells to start with.\n", o.num_cells);

  for (int i = 0; i < 10; i++) {
    printf("Checking the health of cell %d...\n", i+1);
    cell c;
    initialize_cell(&c);
    check_cell_health(&c);
    c.health -= rand() % 101;
  }

  printf("Let's grow our organism!\n");
  grow_organism(&o);
  printf("Our organism now has %d cells.\n", o.num_cells);

  return 0;
}