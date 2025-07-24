//FormAI DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>

struct student {
  int id;
  char name[20];
  int age;
};

int main() {
  struct student database[5];

  //populate the database with dummy data
  for (int i = 0; i < 5; i++) {
    database[i].id = i + 1;
    snprintf(database[i].name, 20, "Student %d", i + 1);
    database[i].age = 18 + i;
  }

  //print the database content
  printf("Database Contents:\n");
  printf("--------------------\n");
  for (int i = 0; i < 5; i++) {
    printf("| ID:%d | Name:%s | Age:%d |\n", database[i].id, database[i].name, database[i].age);
  }
  printf("--------------------\n");

  return 0;
}