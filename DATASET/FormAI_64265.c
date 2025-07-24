//FormAI DATASET v1.0 Category: Database querying ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUERY_LENGTH 1000

typedef struct {
    int id;
    char name[50];
    int age;
    char country[30];
} Person;

// Database of persons
Person database[] = {
    {1, "John", 23, "USA"},
    {2, "Mary", 30, "Canada"},
    {3, "David", 45, "UK"},
    {4, "Sarah", 28, "Mexico"},
    {5, "Paula", 20, "Brazil"}
};

int db_size = sizeof(database) / sizeof(Person);

// Function to find a person by their id
Person *find_person_by_id(int id) {
    for (int i = 0; i < db_size; i++) {
        if (database[i].id == id) {
            return &database[i];
        }
    }
    return NULL;
}

// Function to find people from a specific country
Person **find_people_from_country(char *country, int *result_size) {
    Person **result = malloc(db_size * sizeof(Person*));
    int count = 0;
    for (int i = 0; i < db_size; i++) {
        if (strcmp(database[i].country, country) == 0) {
            result[count++] = &database[i];
        }
    }
    *result_size = count;
    return result;
}

int main() {
    // Example queries
    char query1[MAX_QUERY_LENGTH] = "SELECT name, age FROM people WHERE id=2";
    char query2[MAX_QUERY_LENGTH] = "SELECT * FROM people WHERE country='USA'";
    
    // Uncomment to test invalid query
    // char query3[] = "SELECT name FROM people WHERE age>30";
    
    // Tokenize the query to get the keywords and conditions
    char *keywords[MAX_QUERY_LENGTH];
    char *conditions[MAX_QUERY_LENGTH];
    int keyword_count = 0;
    int condition_count = 0;
    char *token = strtok(query1, " ");
    while (token != NULL) {
        if (strcmp(token, "SELECT") == 0 || strcmp(token, "FROM") == 0 || strcmp(token, "WHERE") == 0) {
            keywords[keyword_count++] = token;
        } else {
            conditions[condition_count++] = token;
        }
        token = strtok(NULL, " ");
    }
    
    // Check if the query is valid
    if (strcmp(keywords[0], "SELECT") != 0 || strcmp(keywords[1], "FROM") != 0 || 
        (condition_count > 0 && strcmp(keywords[2], "WHERE") != 0)) {
        printf("Invalid query.\n");
        return 1;
    }
    
    // Find matching records
    if (condition_count == 0) {
        // If no conditions are specified, return all records
        for (int i = 0; i < db_size; i++) {
            printf("ID: %d, Name: %s, Age: %d, Country: %s\n", database[i].id, database[i].name, database[i].age, database[i].country);
        }
    } else {
        char *condition_field = conditions[0];
        char *condition_value = conditions[2];
        if (strcmp(condition_field, "id") == 0) {
            // Find person by id
            int id = atoi(condition_value);
            Person *person = find_person_by_id(id);
            if (person != NULL) {
                printf("ID: %d, Name: %s, Age: %d, Country: %s\n", person->id, person->name, person->age, person->country);
            } else {
                printf("No record found with id=%d\n", id);
            }
        } else if (strcmp(condition_field, "country") == 0) {
            // Find people from country
            int result_size;
            Person **people = find_people_from_country(condition_value, &result_size);
            if (result_size > 0) {
                for (int i = 0; i < result_size; i++) {
                    printf("ID: %d, Name: %s, Age: %d, Country: %s\n", people[i]->id, people[i]->name, people[i]->age, people[i]->country);
                }
            } else {
                printf("No records found from %s\n", condition_value);
            }
            
            // Free the memory allocated for result
            free(people);
        } else {
            // Unsupported condition field
            printf("Unsupported condition field.\n");
            return 1;
        }
    }
    
    return 0;
}