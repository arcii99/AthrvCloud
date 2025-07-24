//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 20
#define MAX_STRING 200

// Define JSON struct
typedef struct json {
    char *keys[MAX_KEYS];
    char *values[MAX_KEYS];
    int count;
} JSON;

// Parse JSON string
JSON parse_json(char *json_string) {
    JSON data;
    // Initialize count
    data.count = 0;
    char *token;
    // Parse json string
    token = strtok(json_string, ":,");
    while (token != NULL) {
        // Alternate tokens should be keys and values
        if (data.count % 2 == 0) {
            data.keys[data.count] = token;
        } else {
            data.values[data.count-1] = token;
        }
        // Increment count
        data.count++;
        // Get next token
        token = strtok(NULL, ":,");
    }
    return data;
}

// Print JSON data
void print_json(JSON data) {
    printf("{\n");
    for (int i = 0; i < data.count; i += 2) {
        printf("\t%s: %s\n", data.keys[i], data.values[i]);
    }
    printf("}\n");
}

int main() {
    // Example JSON string
    char json_string[] = "{\"name\": \"John Smith\", \"age\": 28, \"city\": \"New York\"}";
    // Parse JSON string
    JSON data = parse_json(json_string);
    // Print JSON data
    print_json(data);
    return 0;
}