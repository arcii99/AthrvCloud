//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json {
    char *key;
    char *value;
    struct json *next;
} Json;

void parse_json(char *json_string, Json **head_ptr) {
    int len = strlen(json_string);
    char *key = NULL, *value = NULL;
    Json *current_json = NULL;
    for (int i = 0; i < len; i++) {
        if (json_string[i] == '{') { // new json object
            current_json = malloc(sizeof(Json));
            current_json->key = NULL;
            current_json->value = NULL;
            current_json->next = *head_ptr;
            *head_ptr = current_json;
        } else if (json_string[i] == '}') { // end of current json object
            if (current_json->key != NULL && current_json->value != NULL) {
                current_json->next = NULL;
            } else { // malformed json object
                free(current_json);
            }
            current_json = NULL;
        } else if (json_string[i] == ':') { // key-value separator
            if (key == NULL) {
                free(current_json);
                current_json = NULL;
                continue;
            }
            current_json->key = strdup(key);
            key = NULL;
        } else if (json_string[i] == ',') { // next key-value pair
            if (current_json->key == NULL || value == NULL) {
                free(current_json);
                current_json = NULL;
                continue;
            }
            current_json->value = strdup(value);
            value = NULL;
        } else if (json_string[i] == '"') { // key or value

            // remember if we're currently inside a key or a value
            int is_key = (key == NULL);

            // parse the key or value string
            int j;
            for (j = i + 1; j < len && json_string[j] != '"'; j++) {
                // handle escaped double quotes
                if (json_string[j] == '\\' && j + 1 < len && json_string[j + 1] == '"') {
                    j++;
                }
            }
            if (j == len) {
                free(current_json);
                current_json = NULL;
                continue;
            }
            char *str = strndup(json_string + i + 1, j - i - 1);
            i = j;

            // store the key or value string
            if (is_key) {
                key = str;
            } else {
                value = str;
            }
        }
    }
}

void print_json(Json *json_object) {
    while (json_object != NULL) {
        printf("\"%s\": %s\n", json_object->key, json_object->value);
        json_object = json_object->next;
    }
}

int main() {
    char json_string[] = "{\"name\": \"John Smith\", \"age\": 27, \"isMarried\": false}";
    Json *head = NULL;
    parse_json(json_string, &head);
    print_json(head);
    return 0;
}