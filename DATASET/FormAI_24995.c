//FormAI DATASET v1.0 Category: Data structures visualization ; Style: grateful
#include <stdio.h>

struct person {
  char name[20];
  int age;
  char sex;
};

int main() {
  struct person ppl[5] = {{"Alice", 25, 'F'},
                          {"Bob", 36, 'M'},
                          {"Charlie", 42, 'M'},
                          {"Diana", 29, 'F'},
                          {"Eve", 18, 'F'}};

  printf("Name\t\tAge\tSex\n");
  for(int i = 0; i < 5; i++) {
    printf("%-10s\t%d\t%c\n", ppl[i].name, ppl[i].age, ppl[i].sex);
  }

  return 0;
}