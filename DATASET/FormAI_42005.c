//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20
#define MAX_AGE 120

typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
} Record;

int main() {
  Record database[MAX_RECORDS];
  int num_records = 0;
  char input[MAX_NAME_LENGTH + 4];
  
  printf("Welcome to My Database Simulation Program!\n");
  printf("Type 'ADD <name> <age>' to add a record.\n");
  printf("Type 'SEARCH <name>' to search for a record.\n");
  printf("Type 'DISPLAY' to display all records.\n");
  printf("Type 'EXIT' to exit the program.\n");

  while (1) {
    printf("> ");
    fgets(input, MAX_NAME_LENGTH + 3, stdin);
    char *command = strtok(input, " ");
    if (!command) continue;
    if (strcmp(command, "ADD") == 0) {
      char *name = strtok(NULL, " ");
      if (!name) {
        printf("Invalid command.\n");
        continue;
      }
      int age;
      if (scanf("%d", &age) != 1 || age < 0 || age > MAX_AGE) {
        printf("Invalid age.\n");
        continue;
      }
      if (num_records == MAX_RECORDS) {
        printf("Database is full.\n");
        continue;
      }
      strcpy(database[num_records].name, name);
      database[num_records].age = age;
      num_records++;
      printf("Record added.\n");
    } else if (strcmp(command, "SEARCH") == 0) {
      char *name = strtok(NULL, " ");
      if (!name) {
        printf("Invalid command.\n");
        continue;
      }
      int found = 0;
      for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
          printf("%s is %d years old.\n", database[i].name, database[i].age);
          found = 1;
          break;
        }
      }
      if (!found) {
        printf("Record not found.\n");
      }
    } else if (strcmp(command, "DISPLAY") == 0) {
      for (int i = 0; i < num_records; i++) {
        printf("%s is %d years old.\n", database[i].name, database[i].age);
      }
    } else if (strcmp(command, "EXIT") == 0) {
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  printf("Goodbye!\n");
  
  return 0;
}