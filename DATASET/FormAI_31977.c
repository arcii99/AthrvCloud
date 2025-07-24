//FormAI DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
  char name[MAX_SIZE];
  int age;
  char gender;
} Person;

int main() {
  int num_persons = 0;
  Person persons[MAX_SIZE];
  
  // Add new persons to the database
  printf("Enter the number of persons to add: ");
  scanf("%d", &num_persons);
  
  for (int i = 0; i < num_persons; i++) {
    printf("Enter person %d's name: ", i+1);
    scanf("%s", persons[i].name);
    
    printf("Enter person %d's age: ", i+1);
    scanf("%d", &persons[i].age);
    
    printf("Enter person %d's gender (M/F): ", i+1);
    scanf(" %c", &persons[i].gender);
  }
  
  // Print all persons in the database
  printf("\nHere are all the persons in the database:\n");
  for (int i = 0; i < num_persons; i++) {
    printf("Name: %s\n", persons[i].name);
    printf("Age: %d\n", persons[i].age);
    printf("Gender: %c\n", persons[i].gender);
  }
  
  return 0;
}