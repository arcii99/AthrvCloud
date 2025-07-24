//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// Define a struct to hold a JSON object
typedef struct {
  char name[MAX_LEN];
  int age;
  char sex[MAX_LEN];
} Person;

// A function to parse a JSON object and store it in a Person struct
Person parse_person(char *json) {
  Person person;
  
  // Use sscanf to extract the values from the JSON string and store them in the Person struct
  sscanf(json, "{\n\"name\":\"%[^\"]\",\n\"age\":%d,\n\"sex\":\"%[^\"]\"\n}", person.name, &person.age, person.sex);
  
  return person;
}

int main() {
  // Define a JSON string to parse
  char *json_string = "{\n\"name\":\"John Smith\",\n\"age\":30,\n\"sex\":\"male\"\n}";
  
  // Parse the JSON string and store it in a Person struct
  Person john = parse_person(json_string);
  
  // Print out the values of the Person struct
  printf("Name: %s\n", john.name);
  printf("Age: %d\n", john.age);
  printf("Sex: %s\n", john.sex);
  
  return 0;
}