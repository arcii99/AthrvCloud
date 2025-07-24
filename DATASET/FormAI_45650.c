//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to represent a JSON object
typedef struct JSON {
    char *name;
    char *value;
    struct JSON *next;
} JSON;

// function to parse a JSON object
JSON* parseJSON(char *jsonString) {
    JSON *head = NULL;
    JSON *tail = NULL;
    char *token = strtok(jsonString, "{}\",: ");
    int state = 0;
    char *name = NULL;
    char *value = NULL;
    while (token != NULL) {
        if (state == 0) {
            // looking for name of object
            if (strcmp(token, "\"name\"") == 0) {
                state = 1;
            }
        } else if (state == 1) {
            // looking for value of name
            if (strcmp(token, ":") == 0) {
                state = 2;
            }
        } else if (state == 2) {
            // found value of name
            name = strdup(token);
            state = 3;
        } else if (state == 3) {
            // looking for value of object
            if (strcmp(token, "\"value\"") == 0) {
                state = 4;
            }
        } else if (state == 4) {
            // looking for value of value
            if (strcmp(token, ":") == 0) {
                state = 5;
            }
        } else if (state == 5) {
            // found value of value
            value = strdup(token);
            state = 0;
            JSON *newJSON = (JSON*) malloc(sizeof(JSON));
            newJSON->name = name;
            newJSON->value = value;
            newJSON->next = NULL;
            if (head == NULL) {
                head = newJSON;
                tail = newJSON;
            } else {
                tail->next = newJSON;
                tail = newJSON;
            }
        }
        token = strtok(NULL, "{}\",: ");
    }
    return head;
}

int main() {
    char *jsonString = "{\"name\": \"firstName\", \"value\": \"John\"}, {\"name\": \"lastName\", \"value\": \"Doe\"}, {\"name\": \"age\", \"value\": \"30\"}";
    JSON *json = parseJSON(jsonString);
    while (json != NULL) {
        printf("%s: %s\n", json->name, json->value);
        json = json->next;
    }
    return 0;
}