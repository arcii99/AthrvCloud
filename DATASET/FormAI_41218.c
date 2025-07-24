//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent a JSON object
struct json_object {
    char *key;
    char *value;
    struct json_object *next;
};

// Function to parse a JSON string and return the first object
struct json_object* parse_json(char* json_str) {
    struct json_object *head = NULL;
    struct json_object *tail = NULL;
    char *key = NULL;
    char *value = NULL;

    // Skip the first and last braces
    json_str++;
    json_str[strlen(json_str) - 1] = '\0';

    // Loop through the string and parse each key/value pair
    char *token = strtok(json_str, ",");
    while (token != NULL) {
        // Parse the key/value pair
        key = strtok(token, ":");
        value = strtok(NULL, ":");

        // Remove any double quotes from the key and value
        key++;
        key[strlen(key) - 1] = '\0';
        value++;
        value[strlen(value) - 1] = '\0';

        // Create a new JSON object and add it to the end of the linked list
        struct json_object *obj = malloc(sizeof(struct json_object));
        obj->key = strdup(key);
        obj->value = strdup(value);
        obj->next = NULL;

        if (head == NULL) {
            head = obj;
        } else {
            tail->next = obj;
        }
        tail = obj;

        token = strtok(NULL, ",");
    }

    return head;
}

// Function to print a JSON object
void print_json(struct json_object *obj) {
    while (obj != NULL) {
        printf("%s: %s\n", obj->key, obj->value);
        obj = obj->next;
    }
}

int main() {
    char json_str[] = "{ \"name\": \"John Doe\", \"age\": \"30\", \"city\": \"New York\" }";
    struct json_object *json_obj = parse_json(json_str);
    print_json(json_obj);

    return 0;
}