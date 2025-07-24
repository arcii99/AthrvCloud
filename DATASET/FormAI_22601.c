//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

// Function to check if a character is a whitespace
int is_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

// Function to check if a string is a valid number
int is_number(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Struct to represent a JSON object
typedef struct json_object {
    char* key;
    char* value;
    struct json_object* next;
} json_object;

// Function to create a new JSON object
json_object* new_json_object(char* key, char* value) {
    json_object* obj = (json_object*) malloc(sizeof(json_object));
    obj->key = key;
    obj->value = value;
    obj->next = NULL;
    return obj;
}

// Function to free the memory used by a JSON object
void free_json_object(json_object* obj) {
    free(obj->key);
    free(obj->value);
    free(obj);
}

// Function to parse a JSON string into a linked list of JSON objects
json_object* parse_json(char* str) {
    json_object* head = NULL;
    json_object* current = NULL;
    int i = 0;
    while (i < strlen(str)) {
        // Get the key
        int start = i;
        while (!is_whitespace(str[i]) && str[i] != ':') {
            i++;
        }
        char* key = (char*) malloc(sizeof(char) * (i - start + 1));
        strncpy(key, &str[start], i - start);
        key[i - start] = '\0';
        i++; // skip the ':'
        // Get the value
        while (is_whitespace(str[i])) {
            i++;
        }
        char* value = "";
        if (str[i] == '{') { // the value is a nested object
            int start = i;
            int count = 1; // to keep track of nested objects
            while (count > 0) {
                i++;
                if (str[i] == '{') {
                    count++;
                } else if (str[i] == '}') {
                    count--;
                }
            }
            value = (char*) malloc(sizeof(char) * (i - start + 1));
            strncpy(value, &str[start], i - start + 1);
            value[i - start] = '\0';
        } else { // the value is a string or a number
            int start = i;
            while (!is_whitespace(str[i]) && str[i] != ',' && str[i] != '}') {
                i++;
            }
            value = (char*) malloc(sizeof(char) * (i - start + 1));
            strncpy(value, &str[start], i - start);
            value[i - start] = '\0';
            if (is_number(value)) { // convert number to integer
                int num = atoi(value);
                sprintf(value, "%d", num);
            }
        }
        // Add the JSON object to the linked list
        json_object* obj = new_json_object(key, value);
        if (head == NULL) {
            head = obj;
            current = obj;
        } else {
            current->next = obj;
            current = obj;
        }
        // Skip the comma if there's more JSON objects to be parsed
        while (is_whitespace(str[i])) {
            i++;
        }
        if (str[i] == ',') {
            i++;
        }
    }
    return head;
}

int main() {
    printf("Hello, I can parse JSON strings!\n");
    char json_str[MAX_LENGTH] = "{\"name\": \"John\", \"age\": 30, \"city\": {\"name\": \"New York\", \"population\": 8398748}}";
    printf("Parsing JSON string: %s\n\n", json_str);
    json_object* obj = parse_json(json_str);
    printf("Parsed JSON objects:\n");
    while (obj != NULL) {
        printf("%s: %s\n", obj->key, obj->value);
        obj = obj->next;
    }
    printf("\nThank you for using my program!\n");
    return 0;
}