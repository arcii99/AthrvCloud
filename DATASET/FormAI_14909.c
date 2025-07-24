//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition for holding JSON key-value pairs
typedef struct {
    char* key;
    char* value;
} json_pair;

// Function to parse the JSON string and return an array of key-value pairs
json_pair* parse_json(char* json_str, int* size) {
    // Initialize variables and allocate memory for the array
    json_pair* pairs = malloc(sizeof(json_pair));
    int pair_count = 0;
    char* key_start = NULL;
    int key_len = 0;
    char* value_start = NULL;
    int value_len = 0;
    int parsing_key = 0; // flag to indicate whether we're currently parsing a key or value

    // Loop through the characters of the JSON string
    for (int i = 0; i < strlen(json_str); i++) {
        // Check for key start
        if (json_str[i] == '"' && !parsing_key) {
            key_start = &json_str[i+1]; // Record the start of the key
            parsing_key = 1;
        }
        // Check for key end
        else if (json_str[i] == '"' && parsing_key) {
            key_len = &json_str[i] - key_start; // Calculate the length of the key
            parsing_key = 0;
        }
        // Check for value start
        else if (json_str[i] == ':' && !parsing_key) {
            value_start = &json_str[i+1]; // Record the start of the value
        }
        // Check for value end
        else if ((json_str[i] == ',' || json_str[i] == '}') && !parsing_key) {
            value_len = &json_str[i] - value_start; // Calculate the length of the value
            pairs[pair_count].key = malloc(key_len + 1); // Allocate memory for the key string
            pairs[pair_count].value = malloc(value_len + 1); // Allocate memory for the value string
            strncpy(pairs[pair_count].key, key_start, key_len); // Copy the key string
            strncpy(pairs[pair_count].value, value_start, value_len); // Copy the value string
            // Add null terminators to the end of the strings
            pairs[pair_count].key[key_len] = '\0';
            pairs[pair_count].value[value_len] = '\0';
            pair_count++; // Increment the pair count
            pairs = realloc(pairs, sizeof(json_pair) * (pair_count + 1)); // Resize the array for the next pair
            // Reset the key and value pointers and lengths
            key_start = NULL;
            key_len = 0;
            value_start = NULL;
            value_len = 0;
        }
    }

    *size = pair_count; // Set the size of the array
    return pairs; // Return the array of pairs
}

int main() {
    char* example_json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    int size;
    json_pair* pairs = parse_json(example_json, &size);

    // Print out the key-value pairs
    for (int i = 0; i < size; i++) {
        printf("Key: %s, Value: %s\n", pairs[i].key, pairs[i].value);
    }

    // Free the memory for the key-value pairs and array
    for (int i = 0; i < size; i++) {
        free(pairs[i].key);
        free(pairs[i].value);
    }
    free(pairs);
    return 0;
}