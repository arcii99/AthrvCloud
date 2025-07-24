//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program demonstrates the building of a simple JSON parser */

typedef struct json_object {
    int number;
    char *string;
} JSON_Object;

JSON_Object *parse_json(char *json_string) {
    JSON_Object *json_obj = malloc(sizeof(JSON_Object));

    // Parse the JSON string
    // For this example, we will assume the JSON string is just a number
    // and store it in our JSON_Object
    int number = atoi(json_string);
    json_obj->number = number;

    return json_obj;
}

int main() {
    char *json_string = "{ \"number\": 42 }";
    JSON_Object *json_obj = parse_json(json_string);
    
    printf("Parsed JSON object:\n");
    printf("Number: %d\n", json_obj->number);

    return 0;
}