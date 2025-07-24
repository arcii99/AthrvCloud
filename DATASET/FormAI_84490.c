//FormAI DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>

/* custom data structure */
struct person {
  char name[20];
  int age;
  float height;
};

int main() {
  /* initialize array of persons */
  struct person people[3] = {
    {"Alice", 25, 1.65},
    {"Bob", 35, 1.80},
    {"Charlie", 30, 1.75}
  };

  /* print header */
  printf("%-20s %5s %10s\n", "Name", "Age", "Height");

  /* iterate over array and print values */
  for (int i = 0; i < 3; i++) {
    printf("%-20s %5d %10.2f\n", people[i].name, people[i].age, people[i].height);
  }

  return 0;
}