//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    int value;
} Pair;

// Function to parse a JSON string
Pair* parse_json(char* json_string) {
    int len = strlen(json_string);
    char current_char;

    // Check for validity of JSON string
    if (json_string[0] != '{' || json_string[len-1] != '}') {
        printf("Invalid JSON string!\n");
        exit(1);
    }

    // Remove outer curly braces
    char* inner_string = (char*) malloc(sizeof(char) * (len-1));
    strncpy(inner_string, json_string+1, len-2);
    inner_string[len-2] = '\0';

    // Count number of key-value pairs
    int count = 1;
    for (int i = 0; i < len-2; i++) {
        if (inner_string[i] == ',') {
            count++;
        }
    }

    // Allocate memory for array of key-value pairs
    Pair* pairs = (Pair*) malloc(sizeof(Pair) * count);

    // Parse each key-value pair
    char* context;
    char* token = strtok_r(inner_string, ",", &context);

    for (int i = 0; i < count; i++) {
        char* key_value = (char*) malloc(sizeof(char) * strlen(token));
        strncpy(key_value, token, strlen(token));
        key_value[strlen(token)] = '\0';

        // Separate key and value
        int colon_index;
        for (int j = 0; j < strlen(key_value); j++) {
            if (key_value[j] == ':') {
                colon_index = j;
                break;
            }
        }

        char* key = (char*) malloc(sizeof(char) * colon_index);
        strncpy(key, key_value, colon_index);
        key[colon_index] = '\0';

        int value = atoi(key_value+colon_index+1);

        pairs[i].key = key;
        pairs[i].value = value;

        // Free allocated memory
        free(key_value);

        // Move on to next token
        token = strtok_r(NULL, ",", &context);
    }

    // Free allocated memory
    free(inner_string);

    return pairs;
}

int main() {
    char json_string[] = "{x: 5, y: 10, z: 15}";

    Pair* pairs = parse_json(json_string);

    printf("%s\n", pairs[0].key);
    printf("%d\n", pairs[0].value);

    printf("%s\n", pairs[1].key);
    printf("%d\n", pairs[1].value);

    printf("%s\n", pairs[2].key);
    printf("%d\n", pairs[2].value);

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        free(pairs[i].key);
    }
    free(pairs);

    return 0;
}