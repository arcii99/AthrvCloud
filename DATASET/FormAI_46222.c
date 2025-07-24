//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a JSON object
typedef struct {
    char *key;
    char *value;
} JSON;

// A function to parse a JSON object
JSON* parse(char *input) {
    JSON *json = malloc(sizeof(JSON));
    char *key = strtok(input, ":");
    char *value = strtok(NULL, ",");

    json->key = key;
    json->value = value;

    return json;
}

int main() {
    char input[] = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";

    JSON *name = parse(input);
    printf("Name: %s\n", name->value);

    JSON *age = parse(NULL);
    printf("Age: %s\n", age->value);

    JSON *city = parse(NULL);
    printf("City: %s\n", city->value);

    return 0;
}