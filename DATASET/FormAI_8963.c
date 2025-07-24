//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining structure for JSON object
typedef struct {
    char *key;
    char *value;
} json_obj;

// Function to parse the JSON object
void parse_json(char *json_str, json_obj *output, int *count) {
    char *token;
    const char *delim = ",:{}[]\"";
    int i = 0;

    // Splitting the JSON string into tokens
    token = strtok(json_str, delim);
    while(token != NULL) {
        // Checking for key
        if(token[0] == '"' && token[strlen(token) - 1] == '"') {
            output[i].key = malloc(strlen(token) - 1);
            strncpy(output[i].key, token + 1, strlen(token) - 2);
        }
        // Checking for value
        else if(token[0] != '"' && token[strlen(token) - 1] != '"') {
            output[i].value = malloc(strlen(token));
            strcpy(output[i].value, token);
            i++;
            (*count)++;
        }
        token = strtok(NULL, delim);
    }
}

int main() {
    char json_str[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    json_obj output[10];
    int count = 0;

    // Parsing the JSON object
    parse_json(json_str, output, &count);

    // Printing the parsed JSON object
    printf("Parsed JSON object:\n");
    for(int i = 0; i < count; i++) {
        printf("%s: %s\n", output[i].key, output[i].value);
    }

    return 0;
}