//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    KeyValuePair **pairs;
    int count;
} Json;

// Function to parse JSON and return a Json struct
Json parseJson(char *jsonString) {

    Json json;
    json.pairs = malloc(sizeof(KeyValuePair));
    json.count = 0;

    // Get rid of whitespaces in the JSON string
    char *buffer = malloc(strlen(jsonString) + 1);
    int i, j = 0;
    for (i = 0; i < strlen(jsonString); i++) {
        if (jsonString[i] != ' ') {
            buffer[j++] = jsonString[i];
        }
    }
    buffer[j] = '\0';

    // Check if the JSON string is properly formatted
    if (buffer[0] != '{' || buffer[strlen(buffer) - 1] != '}') {
        printf("Error: Invalid JSON format.\n");
        exit(1);
    }

    // Remove the outer braces
    buffer[strlen(buffer) - 1] = '\0';
    buffer++;

    // Loop through the string and parse each key-value pair
    char *token;
    char *savePtr;

    token = strtok_r(buffer, ",", &savePtr);
    while (token != NULL) {
        char *key = strtok(token, ":");
        char *value = strtok(NULL, ":");

        // Remove beginning and ending quotations from key
        key[strlen(key) - 1] = '\0';
        key++;

        // Remove beginning and ending quotations from value
        value[strlen(value) - 1] = '\0';
        value++;

        // Add the key-value pair to the Json struct
        json.pairs = realloc(json.pairs, sizeof(KeyValuePair) * (json.count + 1));
        json.pairs[json.count] = malloc(sizeof(KeyValuePair));
        json.pairs[json.count]->key = malloc(strlen(key) + 1);
        json.pairs[json.count]->value = malloc(strlen(value) + 1);
        strcpy(json.pairs[json.count]->key, key);
        strcpy(json.pairs[json.count]->value, value);
        json.count++;

        token = strtok_r(NULL, ",", &savePtr);
    }

    free(buffer);

    return json;
}

int main(void) {

    char *jsonString = "{ \"name\": \"John Smith\", \"age\": 30, \"isMarried\": true }";

    Json json = parseJson(jsonString);

    // Print out the key-value pairs
    for (int i = 0; i < json.count; i++) {
        printf("%s: %s\n", json.pairs[i]->key, json.pairs[i]->value);
    }

    // Free memory
    for (int i = 0; i < json.count; i++) {
        free(json.pairs[i]->key);
        free(json.pairs[i]->value);
        free(json.pairs[i]);
    }
    free(json.pairs);

    return 0;
}