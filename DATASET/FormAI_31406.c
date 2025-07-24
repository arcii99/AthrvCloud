//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JSON_SIZE 1024

typedef struct json_object {
    char key[25];
    char value[100];
    struct json_object* next;
} json_object;

json_object* parse_json(const char* json_str);

int main() {
    char json_str[MAX_JSON_SIZE] = "{\"name\":\"John Doe\",\"age\":30,\"city\":\"New York\"}";
    json_object* json = parse_json(json_str);

    // Print the parsed JSON objects
    if (json != NULL) {
        json_object* curr = json;
        while (curr != NULL) {
            printf("%s: %s\n", curr->key, curr->value);
            curr = curr->next;
        }
    }

    return 0;
}

json_object* parse_json(const char* json_str) {
    json_object* head = NULL;
    json_object* curr = NULL;
    char* token = NULL;
    bool is_key = true;

    // Parsing JSON string
    char* copy = malloc(strlen(json_str) + 1); // Extra byte for null character
    strcpy(copy, json_str);
    token = strtok(copy, "{}\":, ");
    while (token != NULL) {
        if (is_key) {
            // Create new JSON object for key
            json_object* obj = malloc(sizeof(json_object));
            strcpy(obj->key, token);
            obj->next = NULL;
            if (curr == NULL) { // First object
                head = obj;
                curr = obj;
            } else {
                curr->next = obj;
                curr = curr->next;
            }
            is_key = false;
        } else {
            // Add value to last JSON object
            if (curr != NULL) {
                strcpy(curr->value, token);
            }
            is_key = true;
        }
        token = strtok(NULL, "{}\":, ");
    }

    free(copy);

    return head;
}