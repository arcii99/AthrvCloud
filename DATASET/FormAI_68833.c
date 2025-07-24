//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_ELEMENTS 50
#define MAX_KEY_LENGTH 20
#define MAX_VALUE_LENGTH 100
#define MAX_TOKEN_LENGTH 100

// The data structure used to represent a key-value pair in JSON
typedef struct json_pair {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} json_pair;

// The data structure used to represent a complete JSON object
typedef struct json_object {
    int num_elements;
    json_pair elements[MAX_JSON_ELEMENTS];
} json_object;

// Adds a new key-value pair to a JSON object
void add_json_element(json_object* json, const char* key, const char* value) {
    if (json->num_elements < MAX_JSON_ELEMENTS) {
        json_pair* new_element = &(json->elements[json->num_elements]);
        strncpy(new_element->key, key, MAX_KEY_LENGTH);
        strncpy(new_element->value, value, MAX_VALUE_LENGTH);
        ++(json->num_elements);
    }
}

// Parses a JSON object from a string of raw JSON data
void parse_json(const char* json_str, json_object* json) {
    int json_str_index = 0;
    int token_start_index = -1;
    char token[MAX_TOKEN_LENGTH];
    char curr_char;

    while ((curr_char = json_str[json_str_index]) != '\0') {
        ++json_str_index;

        if (token_start_index == -1) {
            if (curr_char == '{') {
                memset(json, 0, sizeof(json_object));
            }
            else if (curr_char == '}') {
                return;
            }
            else if (curr_char == '\"') {
                token_start_index = json_str_index;
            }
        }
        else {
            if (curr_char == '\"') {
                int token_length = json_str_index - token_start_index - 1;
                if (token_length > 0 && token_length <= MAX_KEY_LENGTH) {
                    strncpy(token, json_str + token_start_index, token_length);
                    token[token_length] = '\0';

                    if (json_str[json_str_index] == ':') {
                        token_start_index = -1;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    token_start_index = -1;
                }
            }

            if (token_start_index == -1) {
                if (curr_char == '\"') {
                    token_start_index = json_str_index;
                }
                else if (curr_char == ',') {
                    add_json_element(json, token, "");
                    token_start_index = -1;
                }
            }
            else {
                if (curr_char == '\"') {
                    int token_length = json_str_index - token_start_index - 1;
                    if (token_length > 0 && token_length <= MAX_VALUE_LENGTH) {
                        strncpy(token, json_str + token_start_index, token_length);
                        token[token_length] = '\0';

                        add_json_element(json, json->elements[json->num_elements-1].key, token);
                        token_start_index = -1;
                    }
                    else {
                        token_start_index = -1;
                    }
                }
            }
        }
    }
}

int main() {
    char example_json[] = "{\"name\": \"John Smith\", \"age\": 25, \"email\": \"john.smith@gmail.com\", \"address\": {\"street\": \"123 Main St.\", \"city\": \"Anytown\", \"state\": \"IL\"}}";
    json_object my_json;

    parse_json(example_json, &my_json);

    printf("The JSON object contains %d elements:\n", my_json.num_elements);
    for (int i = 0; i < my_json.num_elements; ++i) {
        printf("%s: %s\n", my_json.elements[i].key, my_json.elements[i].value);
    }

    return 0;
}