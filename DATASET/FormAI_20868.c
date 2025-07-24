//FormAI DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

//define database structure
typedef struct database {
  char name[20];
  int age;
} Database;

//function to randomly generate database records
Database generateRecord() {
  Database record;
  int randNum = rand() % 20; //generate random number between 0 and 19
  //assign name based on random number
  switch(randNum) {
    case 0:
      strcpy(record.name, "Octopus");
      break;
    case 1:
      strcpy(record.name, "Banana");
      break;
    case 2:
      strcpy(record.name, "Toilet");
      break;
    case 3:
      strcpy(record.name, "Umbrella");
      break;
    case 4:
      strcpy(record.name, "Noodle");
      break;
    case 5:
      strcpy(record.name, "Mushroom");
      break;
    case 6:
      strcpy(record.name, "Zombie");
      break;
    case 7:
      strcpy(record.name, "Robot");
      break;
    case 8:
      strcpy(record.name, "Giraffe");
      break;
    case 9:
      strcpy(record.name, "Dragon");
      break;
    case 10:
      strcpy(record.name, "Butterfly");
      break;
    case 11:
      strcpy(record.name, "Elephant");
      break;
    case 12:
      strcpy(record.name, "Moon");
      break;
    case 13:
      strcpy(record.name, "Sunflower");
      break;
    case 14:
      strcpy(record.name, "Penguin");
      break;
    case 15:
      strcpy(record.name, "Taco");
      break;
    case 16:
      strcpy(record.name, "Rain");
      break;
    case 17:
      strcpy(record.name, "Cloud");
      break;
    case 18:
      strcpy(record.name, "Fire");
      break;
    case 19:
      strcpy(record.name, "Ice");
      break;
  }
  //assign random age between 1 and 100
  record.age = (rand() % 100) + 1;
  return record;
}

int main() {
  //initialize database with 10 records
  Database database[10];
  int i;
  for(i=0; i<10; i++) {
    database[i] = generateRecord();
  }
  //print out database records
  printf("DATABASE RECORDS:\n");
  for(i=0; i<10; i++) {
    printf("Name: %s, Age: %d\n", database[i].name, database[i].age);
  }
  return 0;
}