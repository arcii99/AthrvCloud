//FormAI DATASET v1.0 Category: Computer Biology ; Style: lively
#include <stdio.h>

struct animal {
  char name[20];
  int age;
  char species[20];
  char habitat[20];
};

int main() {
  struct animal cat = {"Whiskers", 4, "Felis catus", "House"};
  struct animal dog = {"Rex", 2, "Canis lupus familiaris", "Backyard"};
  
  printf("Meet %s the %s!\n", cat.name, cat.species);
  printf("He is %d years old and lives in a %s.\n", cat.age, cat.habitat);
  
  printf("\nMeet %s the %s!\n", dog.name, dog.species);
  printf("He is %d years old and lives in the %s.\n", dog.age, dog.habitat);
  
  printf("\nBoth animals have some things in common:\n");
  printf("-They are both animals.\n");
  printf("-They are both considered pets.\n");
  printf("-They both have names and ages.\n");
  printf("-They both have a species and a habitat.\n");
  
  printf("\nHowever, they are different from each other in some ways:\n");
  printf("-Their species are different.\n");
  printf("-Their habitats are different.\n");
  
  return 0;
}