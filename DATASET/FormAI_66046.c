//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_object_t {
    char *key;
    char *value;
    struct json_object_t *next;
} json_object;

void parse_json(char *json_string) {
    int len = strlen(json_string);
    int start_index = -1;
    int end_index = -1;
    int i = 0;
    json_object *head = NULL;
    json_object *current = NULL;
    while (i < len) {
        if (json_string[i] == '"') {
            if (start_index == -1) {
                start_index = i + 1;
            } else if (end_index == -1) {
                end_index = i;
                if (current == NULL) {
                    head = current = (json_object *) malloc(sizeof(json_object));
                } else {
                    current = current->next = (json_object *) malloc(sizeof(json_object));
                }
                int key_len = end_index - start_index;
                current->key = (char *) malloc(key_len + 1);
                strncpy(current->key, json_string + start_index, key_len);
                current->key[key_len] = '\0';
                start_index = -1;
                end_index = -1;
            }
        } else if (json_string[i] == ':') {
            start_index = -1;
            end_index = -1;
        } else if (json_string[i] == ',' || json_string[i] == '}') {
            end_index = i;
            int value_len = end_index - start_index;
            current->value = (char *) malloc(value_len + 1);
            strncpy(current->value, json_string + start_index, value_len);
            current->value[value_len] = '\0';
            start_index = -1;
            end_index = -1;
            if (json_string[i] == ',') {
                current = current->next = (json_object *) malloc(sizeof(json_object));
            }
        }
        i++;
    }
    printf("{\n");
    current = head;
    while (current != NULL) {
        printf("    \"%s\": \"%s\",\n", current->key, current->value);
        current = current->next;
    }
    printf("}\n");
}

int main() {
    char *json_string = "{ \"name\": \"John\", \"age\": 31, \"city\": \"New York\" }";
    parse_json(json_string);
    return 0;
}