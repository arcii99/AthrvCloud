//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000

// struct to hold data for each person
typedef struct {
  char name[50];
  int age;
  char gender;
} person;

// function to generate random data
person generate_person() {
  person new_person;
  char genders[3] = "MF";
  char name[10];
  int age = rand() % 100;
  char gender = genders[rand() % 2];

  // generate random name
  for (int i = 0; i < 10; i++) {
    name[i] = (char)((rand() % 26) + 65);
  }
  strcpy(new_person.name, name);
  new_person.age = age;
  new_person.gender = gender;

  return new_person;
}

// function to insert person into hash table
void insert_person(person *table, person new_person) {
  int index = (((new_person.age * 10) + new_person.gender) * SIZE) % SIZE;
  while (table[index].age != 0) {
    index = (index + 1) % SIZE;
  }
  table[index] = new_person;
}

// function to search for person in hash table
int search_person(person *table, char *name) {
  for (int i = 0; i < SIZE; i++) {
    if (strcmp(table[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  person hash_table[SIZE] = {0};
  srand(0);

  // generate 10000 random people and insert into hash table
  for (int i = 0; i < 10000; i++) {
    person new_person = generate_person();
    insert_person(hash_table, new_person);
  }

  // search for a person with a given name
  char name[50];
  printf("Enter name to search: ");
  scanf("%s", name);
  int index = search_person(hash_table, name);
  if (index == -1) {
    printf("Person not found.\n");
  } else {
    person found_person = hash_table[index];
    printf("Name: %s\nAge: %d\nGender: %c\n", found_person.name, found_person.age, found_person.gender);
  }

  return 0;
}