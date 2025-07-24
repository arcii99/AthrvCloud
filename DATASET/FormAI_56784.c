//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 100 // Maximum length of our JSON object

int main() {
    char json[MAX_JSON_SIZE] = "{ \"name\": \"John Smith\", \"age\": 30, \"city\": \"New York\" }"; // Our example JSON object
    int name_start = 0, age_start = 0, city_start = 0;
    int name_end = 0, age_end = 0, city_end = 0;

    // Find the starting and ending positions of each key-value pair in the JSON object
    for (int i=0; i<MAX_JSON_SIZE; i++) {
        if (strncmp(&json[i], "name", 4) == 0 && json[i+4] == ':') {
            name_start = i+6;
        }
        else if (strncmp(&json[i], "age", 3) == 0 && json[i+3] == ':') {
            age_start = i+5;
        }
        else if (strncmp(&json[i], "city", 4) == 0 && json[i+4] == ':') {
            city_start = i+6;
        }
        else if (json[i] == '\0') {
            break;
        }
    }

    name_end = strchr(&json[name_start], '\"') - &json[0];
    age_end = strchr(&json[age_start], ',') - &json[0];
    city_end = strchr(&json[city_start], '\"') - &json[0];

    // Extract the values from the JSON object
    char name[20], city[20];
    int age;
    strncpy(name, &json[name_start], name_end - name_start);
    name[name_end - name_start] = '\0';
    age = strtol(&json[age_start], NULL, 10);
    strncpy(city, &json[city_start], city_end - city_start);
    city[city_end - city_start] = '\0';

    // Print the extracted values
    printf("Name: %s\nAge: %d\nCity: %s\n", name, age, city);

    return 0;
}