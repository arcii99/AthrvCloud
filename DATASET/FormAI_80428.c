//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 500

typedef struct {
    char *key;
    char *value;
} JSONPair;

typedef struct {
    JSONPair *pairs;
    int num_pairs;
} JSONObject;

// Function to parse JSON string and return a JSON object
JSONObject* parseJSON(char *string) {
    JSONObject *object = malloc(sizeof(JSONObject));
    int num_pairs = 0;
    // Find the number of pairs in the string
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ':') {
            num_pairs++;
        }
    }
    object->num_pairs = num_pairs;
    object->pairs = malloc(sizeof(JSONPair) * num_pairs);
    char *key = malloc(sizeof(char) * MAX_CHARACTERS);
    char *value = malloc(sizeof(char) * MAX_CHARACTERS);
    int key_index = 0, value_index = 0;
    int in_key = 0, in_value = 0;
    // Parse the string and store the key-value pairs in the JSON object
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '{' || string[i] == '\"' || string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
            // Do nothing
        }
        else if (string[i] == ':') {
            key[key_index] = '\0';
            in_key = 0;
            value_index = 0;
        }
        else if (string[i] == ',' || string[i] == '}') {
            value[value_index] = '\0';
            in_value = 0;
            object->pairs[num_pairs - 1].key = malloc(sizeof(char) * (strlen(key) + 1));
            object->pairs[num_pairs - 1].value = malloc(sizeof(char) * (strlen(value) + 1));
            strcpy(object->pairs[num_pairs - 1].key, key);
            strcpy(object->pairs[num_pairs - 1].value, value);
            num_pairs--;
            if (num_pairs == 0) {
                break;
            }
            memset(key, 0, sizeof(char) * MAX_CHARACTERS);
            memset(value, 0, sizeof(char) * MAX_CHARACTERS);
            key_index = 0;
            value_index = 0;
        }
        else {
            if (in_key) {
                key[key_index++] = string[i];
            }
            else if (in_value) {
                value[value_index++] = string[i];
            }
            else {
                if (string[i - 1] == '\"') {
                    memset(key, 0, sizeof(char) * MAX_CHARACTERS);
                    key_index = 0;
                    in_key = 1;
                    key[key_index++] = string[i];
                }
                else {
                    in_value = 1;
                    value[value_index++] = string[i];
                }
            } 
        }
    }
    free(key);
    free(value);
    return object;
}

// Function to print the JSON object
void printJSON(JSONObject *object) {
    for (int i = 0; i < object->num_pairs; i++) {
        printf("%s: %s\n", object->pairs[i].key, object->pairs[i].value);
    }
}

int main() {
    char *json_string = "{\"name\": \"John Smith\",\"age\": 25,\"address\": \"15 Penny Lane, Liverpool\",\"phone number\": \"+1 555-1234\"}";
    JSONObject *json_object = parseJSON(json_string);
    printJSON(json_object);
    return 0;
}