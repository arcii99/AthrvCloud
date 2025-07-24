//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a JSON value or key
#define MAX_JSON_LEN 100

// Define the maximum number of key-value pairs in a JSON object
#define MAX_JSON_OBJECT_SIZE 100

// Define the token types for the JSON parser
typedef enum {
    TOKEN_NONE,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_OBJECT_START,
    TOKEN_OBJECT_END,
    TOKEN_ARRAY_START,
    TOKEN_ARRAY_END,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL
} token_type;

// Define a struct to hold a single key-value pair
typedef struct {
    char key[MAX_JSON_LEN];
    char value[MAX_JSON_LEN];
} json_key_value_pair;

// Define a struct to hold a JSON object
typedef struct {
    json_key_value_pair values[MAX_JSON_OBJECT_SIZE];
    int num_values;
} json_object;

// Define a struct to hold a single JSON token
typedef struct {
    token_type type;
    char value[MAX_JSON_LEN];
} json_token;

// Define a function to parse a JSON string and return a JSON object
json_object parse_json_string(char* json_string) {
    json_object obj;
    obj.num_values = 0;
    json_token current_token;
    int i = 0;
    while (json_string[i] != '\0') {
        current_token.type = TOKEN_NONE;
        if (isspace(json_string[i])) {
            // Ignore whitespace
            i++;
            continue;
        } else if (json_string[i] == '{') {
            // Start of JSON object
            current_token.type = TOKEN_OBJECT_START;
            current_token.value[0] = json_string[i];
            current_token.value[1] = '\0';
            i++;
        } else if (json_string[i] == '}') {
            // End of JSON object
            current_token.type = TOKEN_OBJECT_END;
            current_token.value[0] = json_string[i];
            current_token.value[1] = '\0';
            i++;
        } else if (json_string[i] == '[') {
            // Start of JSON array
            current_token.type = TOKEN_ARRAY_START;
            current_token.value[0] = json_string[i];
            current_token.value[1] = '\0';
            i++;
        } else if (json_string[i] == ']') {
            // End of JSON array
            current_token.type = TOKEN_ARRAY_END;
            current_token.value[0] = json_string[i];
            current_token.value[1] = '\0';
            i++;
        } else if (json_string[i] == ':') {
            // Key-value separator
            current_token.type = TOKEN_COLON;
            current_token.value[0] = json_string[i];
            current_token.value[1] = '\0';
            i++;
        } else if (json_string[i] == ',') {
            // Value separator
            current_token.type = TOKEN_COMMA;
            current_token.value[0] = json_string[i];
            current_token.value[1] = '\0';
            i++;
        } else if (json_string[i] == '\"') {
            // JSON string value
            current_token.type = TOKEN_STRING;
            int j = 0;
            i++;
            while (json_string[i] != '\"' && j < MAX_JSON_LEN) {
                current_token.value[j] = json_string[i];
                i++;
                j++;
            }
            current_token.value[j] = '\0';
            i++;
        } else if (isdigit(json_string[i]) || json_string[i] == '-') {
            // JSON number value
            current_token.type = TOKEN_NUMBER;
            int j = 0;
            while (isdigit(json_string[i]) || json_string[i] == '-' || json_string[i] == '.' || json_string[i] == 'e' || json_string[i] == 'E') {
                current_token.value[j] = json_string[i];
                i++;
                j++;
            }
            current_token.value[j] = '\0';
        } else {
            // Boolean or null value
            switch (json_string[i]) {
                case 't':
                    current_token.type = TOKEN_TRUE;
                    strncpy(current_token.value, "true", MAX_JSON_LEN);
                    i += 4;
                    break;
                case 'f':
                    current_token.type = TOKEN_FALSE;
                    strncpy(current_token.value, "false", MAX_JSON_LEN);
                    i += 5;
                    break;
                case 'n':
                    current_token.type = TOKEN_NULL;
                    strncpy(current_token.value, "null", MAX_JSON_LEN);
                    i += 4;
                    break;
                default:
                    // Invalid token
                    printf("Invalid token at position %d", i);
                    exit(1);
            }
        }

        // Add the token to the JSON object
        if (current_token.type == TOKEN_STRING || current_token.type == TOKEN_NUMBER || current_token.type == TOKEN_TRUE || current_token.type == TOKEN_FALSE || current_token.type == TOKEN_NULL) {
            if (obj.num_values >= MAX_JSON_OBJECT_SIZE) {
                printf("Maximum object size exceeded");
                exit(1);
            }
            strcpy(obj.values[obj.num_values].value, current_token.value);
            obj.num_values++;
        } else if (current_token.type == TOKEN_COLON) {
            // Key-value pair separator - grab the key from the previous token and add it to the object
            if (obj.num_values == 0 || strlen(current_token.value) > MAX_JSON_LEN) {
                printf("Invalid key at position %d", i);
                exit(1);
            }
            strncpy(obj.values[obj.num_values - 1].key, obj.values[obj.num_values - 1].value, MAX_JSON_LEN);
            obj.values[obj.num_values - 1].key[strlen(obj.values[obj.num_values - 1].key) - 1] = '\0';
        } else if (current_token.type == TOKEN_OBJECT_END) {
            // Finished parsing the JSON object
            break;
        }
    }
    return obj;
}

int main() {
    char* json_string = "{ \"name\": \"John\", \"age\": 30, \"single\": true }";
    json_object obj = parse_json_string(json_string);
    printf("Name: %s\nAge: %s\nSingle: %s\n", obj.values[0].value, obj.values[1].value, obj.values[2].value);
    return 0;
}