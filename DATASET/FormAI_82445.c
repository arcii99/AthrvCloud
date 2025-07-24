//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold parsed JSON elements */
typedef struct {
    char* key;
    char* value;
} JSONElement;

/* Function to parse JSON */
JSONElement* parseJSON(char* json_string, int* num_elements) {
    JSONElement* elements = (JSONElement*) malloc(sizeof(JSONElement) * 10);
    char* token;
    char* key;
    char* value;
    int num_allocated = 10;
    int num_parsed = 0;

    /* Check if json_string is empty */
    if (strlen(json_string) == 0) {
        printf("Error: Empty JSON string\n");
        *num_elements = 0;
        return NULL;
    }

    /* Tokenize json_string */
    token = strtok(json_string, "{}\":,");

    /* Loop through tokens */
    while (token != NULL) {
        /* Allocate memory for key and value */
        key = (char*) malloc(strlen(token) + 1);
        value = (char*) malloc(strlen(token) + 1);

        /* Check if tokens are valid */
        if (strcmp(token, "{") == 0 || strcmp(token, "}") == 0 ||
            strcmp(token, ":") == 0 || strcmp(token, ",") == 0) {
            /* Invalid token, skip */
            free(key);
            free(value);
        } else {
            /* Valid token, parse key or value */
            if (num_parsed % 2 == 0) {
                /* Key */
                strcpy(key, token);
            } else {
                /* Value */
                strcpy(value, token);

                /* Check if array needs to be expanded */
                if (num_parsed >= num_allocated) {
                    num_allocated *= 2;
                    elements = (JSONElement*) realloc(elements, sizeof(JSONElement) * num_allocated);
                }

                /* Add key-value pair to elements array */
                elements[num_parsed / 2].key = key;
                elements[num_parsed / 2].value = value;
            }
            num_parsed++;
        }

        /* Get next token */
        token = strtok(NULL, "{}\":,");
    }

    *num_elements = num_parsed / 2;

    return elements;
}

int main() {

    char* json_string = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    int num_elements;
    JSONElement* elements = parseJSON(json_string, &num_elements);

    printf("Number of elements: %d\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Key: %s, Value: %s\n", elements[i].key, elements[i].value);
        free(elements[i].key);
        free(elements[i].value);
    }

    free(elements);

    return 0;
}