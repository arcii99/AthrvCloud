//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to represent a JSON object */
typedef struct json_object_t {
    char *name;
    char *value;
    struct json_object_t *next;
} json_object_t;

/* Function to create a new JSON object */
json_object_t *create_json_object(char *name, char *value) {
    json_object_t *new_object = (json_object_t*) malloc(sizeof(json_object_t));
    new_object->name = (char*) malloc(strlen(name) + 1);
    new_object->value = (char*) malloc(strlen(value) + 1);
    strcpy(new_object->name, name);
    strcpy(new_object->value, value);
    new_object->next = NULL;
    return new_object;
}

/* Function to parse a JSON string and create a linked list of JSON objects */
json_object_t *parse_json(char *json_string) {
    json_object_t *head = NULL;
    json_object_t *current = NULL;

    /* Loop through the JSON string */
    char *tok = strtok(json_string, "{:,}");
    while (tok != NULL) {
        if (strcmp(tok, "\"") == 0) {
            /* We have found a new JSON object */
            char *name = strtok(NULL, "\"");
            strtok(NULL, ":");
            char *value = strtok(NULL, ",}");
            if (head == NULL) {
                /* First JSON object */
                head = create_json_object(name, value);
                current = head;
            } else {
                /* Add a new JSON object to the linked list */
                json_object_t *new_object = create_json_object(name, value);
                current->next = new_object;
                current = new_object;
            }
        }
        tok = strtok(NULL, "{:,}");
    }

    return head;
}

int main(void) {
    char json_string[] = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    json_object_t *json_object_list = parse_json(json_string);

    /* Print out the linked list of JSON objects */
    json_object_t *current = json_object_list;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->value);
        current = current->next;
    }

    /* Free memory */
    while (json_object_list != NULL) {
        json_object_t *to_free = json_object_list;
        json_object_list = json_object_list->next;
        free(to_free->name);
        free(to_free->value);
        free(to_free);
    }

    return 0;
}