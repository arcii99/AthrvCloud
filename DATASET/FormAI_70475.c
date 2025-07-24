//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* key;
    char* value;
} KeyValue;

int main() {

    // Let's start by defining our JSON string and initialize our variables
    char* json = "{ \"name\": \"John Doe\", \"age\": 25, \"city\": \"New York\" }";
    KeyValue keyValue[MAX_SIZE];
    int count = 0;
    char* token;

    // Let's tokenize our JSON string using strtok() function
    token = strtok(json, "{\":,}");

    // Iterate over our JSON string tokens and extract key-value pairs
    while (token != NULL) {
        // Store the key in our KeyValue struct
        keyValue[count].key = token;
        // Move the token pointer to the value
        token = strtok(NULL, "{\":,}");
        // Store the value in our KeyValue struct
        keyValue[count].value = token;
        // Increment the count
        count++;
        // Move the token pointer to the next key
        token = strtok(NULL, "{\":,}");
    }

    // Let's print out our key-value pairs
    printf("{\n");
    for (int i = 0; i < count; i++) {
        printf("    \"%s\": \"%s\",\n", keyValue[i].key, keyValue[i].value);
    }
    printf("}\n");

    return 0;
}