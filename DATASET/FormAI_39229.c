//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JSON_OBJECTS 50
#define MAX_JSON_OBJECT_LENGTH 1024

typedef struct {
    char key[MAX_JSON_OBJECT_LENGTH];
    char value[MAX_JSON_OBJECT_LENGTH];
} JsonObject;

void parseJson(char* json) {
    JsonObject jsonObjects[MAX_JSON_OBJECTS];
    int numObjects = 0;

    char* token = strtok(json, "{");
    while (token != NULL) {
        JsonObject newObject;

        // find the key
        char* keyToken = strtok(token, ":");
        strncpy(newObject.key, keyToken, MAX_JSON_OBJECT_LENGTH);

        // find the value
        char* valueToken = strtok(NULL, ",");
        strncpy(newObject.value, valueToken, MAX_JSON_OBJECT_LENGTH);

        // add the object to the array
        jsonObjects[numObjects++] = newObject;

        // get next object
        token = strtok(NULL, "{");
    }

    // print out all objects
    for (int i = 0; i < numObjects; i++) {
        printf("Key: %s  |  Value: %s\n", jsonObjects[i].key, jsonObjects[i].value);
    }
}

int main() {
    char* jsonData = "{\"name\":\"John\",\"age\":\"30\",\"city\":\"New York\"}";

    printf("Parsing JSON data:\n%s\n", jsonData);
    parseJson(jsonData);

    return 0;
}