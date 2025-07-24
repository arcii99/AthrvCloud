//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define maximum length of JSON string and object */
#define MAX_JSON_LEN 100
#define MAX_OBJECTS 10

/**
 * Struct for a single object in the JSON string
 * Stores the key-value pair as strings
 */ 
typedef struct {
    char key[MAX_JSON_LEN];
    char value[MAX_JSON_LEN];
} JsonObj;

/**
 * Function to parse a JSON string and store the objects in a JsonObj array
 */ 
int parseJson(char *jsonStr, JsonObj *jsonObjs) {
    // Initialize variables
    int numObjects = 0;
    char *token, *key, *value;
    
    // Tokenize the string
    token = strtok(jsonStr, "{}\",:");
    while (token != NULL) {
        // If the token is a key
        if (token[0] == '\"') {
            // Store the key
            strcpy(jsonObjs[numObjects].key, token);
            // Tokenize the value
            token = strtok(NULL, "{}\",:");
            // Store the value (as a string)
            sprintf(jsonObjs[numObjects].value, "\"%s\"", token);
            // Increment number of objects
            numObjects++;
        }
        // Get the next token
        token = strtok(NULL, "{}\",:");
    }
    return numObjects;
}

int main() {
    // Initialize variables
    char jsonStr[MAX_JSON_LEN];
    JsonObj jsonObjs[MAX_OBJECTS];
    int numObjects;
    
    // Example JSON string
    strcpy(jsonStr, "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}");
    
    // Parse the JSON string
    numObjects = parseJson(jsonStr, jsonObjs);
    
    // Print the objects
    printf("Number of objects: %d\n", numObjects);
    for (int i = 0; i < numObjects; i++) {
        printf("%s: %s\n", jsonObjs[i].key, jsonObjs[i].value);
    }
    
    return 0;
}