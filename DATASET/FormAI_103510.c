//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int age;
  float height;
} Person;

int main() {
  char *json_str = "{ 'name': 'Alice', 'age': 25, 'height': 1.65 }";

  // Remove the single quotes from the JSON string
  for (int i = 0; i < strlen(json_str); i++) {
    if (json_str[i] == '\'') {
      json_str[i] = '\"';
    }
  }

  // Convert the JSON string to a Person object
  Person alice;
  char *name_token = strtok(json_str, "\"");
  alice.name = strdup(strtok(NULL, "\""));
  char *age_token = strtok(NULL, "\"");
  alice.age = atoi(strtok(NULL, "\""));
  char *height_token = strtok(NULL, "\"");
  alice.height = atof(strtok(NULL, "\""));

  printf("Name: %s\nAge: %d\nHeight: %f\n", alice.name, alice.age, alice.height);

  return 0;
}