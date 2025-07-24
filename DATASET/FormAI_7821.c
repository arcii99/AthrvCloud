//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_JSON_ELEMENTS 10

typedef struct {
    char *key;
    char *value;
} json_element;

char input[MAX_INPUT_LENGTH];
json_element json_elements[MAX_JSON_ELEMENTS];
int num_elements = 0;

void parse_json(char *input);
void add_element(char *key, char *value);
void print_parsed_json();

int main() {
    // Get input from user
    printf("Enter JSON string:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Parse JSON
    parse_json(input);

    // Print parsed JSON
    print_parsed_json();

    return 0;
}

void parse_json(char *input) {
    char *token;
    char *prev_token;
    char *key;
    bool is_key = true;
    bool is_value = false;

    token = strtok(input, "{}:,\"");
    while (token != NULL) {
        if (is_key) {
            key = token;
            is_key = false;
            is_value = true;
        } else if (is_value) {
            add_element(key, token);
            is_key = true;
            is_value = false;
        }

        prev_token = token;
        token = strtok(NULL, "{}:,\"");
    }

    // Check for unfinished elements
    if (is_key || prev_token[0] == ':') {
        printf("Error parsing JSON\n");
        exit(1);
    }
}

void add_element(char *key, char *value) {
    // Allocate memory for JSON element
    json_element *element = (json_element*)malloc(sizeof(json_element));
    element->key = (char*)malloc(strlen(key) + 1);
    element->value = (char*)malloc(strlen(value) + 1);

    // Copy key and value into element
    strcpy(element->key, key);
    strcpy(element->value, value);

    // Add element to array of JSON elements
    json_elements[num_elements] = *element;
    num_elements++;

    // Free memory allocated for element
    free(element->key);
    free(element->value);
    free(element);
}

void print_parsed_json() {
    printf("Parsed JSON:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s: %s\n", json_elements[i].key, json_elements[i].value);
    }
}