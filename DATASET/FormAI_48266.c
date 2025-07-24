//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to store a person's information */
typedef struct {
    char name[50];
    int age;
    char city[50];
} Person;

/* Define a function to parse the JSON data and store it in an array of Person structures */
Person* parseJSON(char* jsonData, int* numPersons) {
    /* Allocate memory for an array of Person structures */
    Person* persons = (Person*)malloc(sizeof(Person)*10);
    int index = 0;

    /* Begin parsing the JSON data */
    char* token = strtok(jsonData, "{\":,\"}");
    while (token != NULL) {
        if (strcmp(token, "name") == 0) {
            /* Get the person's name and store it in the array */
            token = strtok(NULL, "{\":,\"}");
            strcpy(persons[index].name, token);
        }
        else if (strcmp(token, "age") == 0) {
            /* Get the person's age and store it in the array */
            token = strtok(NULL, "{\":,\"}");
            persons[index].age = atoi(token);
        }
        else if (strcmp(token, "city") == 0) {
            /* Get the person's city and store it in the array */
            token = strtok(NULL, "{\":,\"}");
            strcpy(persons[index].city, token);
            index++;
        }
        token = strtok(NULL, "{\":,\"}");
    }

    /* Return the array of Person structures and the number of persons */
    *numPersons = index;
    return persons;
}

int main() {
    /* Define the JSON data as a string */
    char jsonData[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"},{\"name\":\"Jane\",\"age\":25,\"city\":\"Los Angeles\"}";

    /* Parse the JSON data */
    int numPersons;
    Person* persons = parseJSON(jsonData, &numPersons);

    /* Print the data for each person in the array */
    for (int i = 0; i < numPersons; i++) {
        printf("Name: %s\n", persons[i].name);
        printf("Age: %d\n", persons[i].age);
        printf("City: %s\n", persons[i].city);
        printf("\n");
    }

    /* Free the memory allocated for the array of Person structures */
    free(persons);

    return 0;
}