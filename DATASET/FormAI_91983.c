//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>

// define the structure
struct person {
  char name[20];
  int age;
  float height;
};

int main() {
  // initialize the structure
  struct person p1 = {"John", 30, 5.8};
  
  // print the structure using an immersive style
  printf("Meet %s, a person who is %d years old and stands at %.2f feet tall.\n", p1.name, p1.age, p1.height);
  
  return 0;
}