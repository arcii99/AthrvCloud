//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct that will store our parsed JSON data
typedef struct {
    int age;
    char name[50];
    int num_friends;
    char *friends[50];
} Person;

// Define the function that will parse our JSON data
void parse_json(char *json_data, Person *person) {
    // Use strtok to separate the JSON data into tokens
    char *token = strtok(json_data, "{\":,}");

    // Loop through the tokens and assign them to our struct
    while(token != NULL) {
        if(strcmp(token, "name") == 0) {
            token = strtok(NULL, "{\":,}");
            strcpy(person->name, token);
        }
        else if(strcmp(token, "age") == 0) {
            token = strtok(NULL, "{\":,}");
            person->age = atoi(token);
        }
        else if(strcmp(token, "num_friends") == 0) {
            token = strtok(NULL, "{\":,}");
            person->num_friends = atoi(token);
        }
        else if(strcmp(token, "friends") == 0) {
            token = strtok(NULL, "{\":,}");
            int i = 0;
            while(token != NULL && strcmp(token, "]") != 0) {
                token = strtok(NULL, "{\":,}");
                if(strcmp(token, "]") != 0) {
                    person->friends[i] = malloc(sizeof(char) * 50);
                    strcpy(person->friends[i], token);
                    i++;
                }
            }
        }
        token = strtok(NULL, "{\":,}");
    }
}

int main() {
    // Define our sample JSON data
    char *json_data = "{ \"name\": \"John\", \"age\": 25, \"num_friends\": 3, \"friends\": [\"Alice\", \"Bob\", \"Charlie\"] }";

    // Allocate memory for our Person struct
    Person *person = malloc(sizeof(Person));

    // Parse the JSON data and assign it to our Person struct
    parse_json(json_data, person);

    // Print out the parsed data
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Number of friends: %d\n", person->num_friends);
    printf("Friends: ");
    for(int i = 0; i < person->num_friends; i++) {
        printf("%s", person->friends[i]);
        if(i != person->num_friends - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // Free up memory
    for(int i = 0; i < person->num_friends; i++) {
        free(person->friends[i]);
    }
    free(person);

    return 0;
}