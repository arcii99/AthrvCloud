//FormAI DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>

struct Person {
  char name[50];
  int age;
};

int main() {
  struct Person person1 = {"John", 27};
  struct Person person2 = {"Sarah", 33};

  printf("*********************************\n");
  printf("*        PERSON STRUCTURE       *\n");
  printf("*********************************\n\n");

  printf("PERSON 1\n");
  printf("\tNAME: %s\n", person1.name);
  printf("\tAGE: %d\n\n", person1.age);

  printf("PERSON 2\n");
  printf("\tNAME: %s\n", person2.name);
  printf("\tAGE: %d\n\n", person2.age);

  printf("*********************************\n");
  printf("*          END PROGRAM          *\n");
  printf("*********************************\n\n");

  return 0;
}