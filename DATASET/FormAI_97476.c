//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a JSON object.
typedef struct {
    char *key;
    char *value;
} JsonObject;

// Define a function to parse a JSON string and return an array of JSON objects.
JsonObject* parseJson(char *jsonString) {
    int objectCount = 0;
    char *token = strtok(jsonString, ",{}[]\":\n\t\r\f");
    JsonObject *jsonObjects = malloc(sizeof(JsonObject));

    while (token != NULL) {
        if (strcmp(token, "{") == 0) {
            token = strtok(NULL, ",{}[]\":\n\t\r\f");
            while (strcmp(token, "}") != 0) {
                if (objectCount > 0) {
                    jsonObjects = realloc(jsonObjects, (objectCount + 1) * sizeof(JsonObject));
                }
                jsonObjects[objectCount].key = token;
                token = strtok(NULL, ",{}[]\":\n\t\r\f");
                jsonObjects[objectCount].value = token;
                token = strtok(NULL, ",{}[]\":\n\t\r\f");
                objectCount++;
            }
        }
        token = strtok(NULL, ",{}[]\":\n\t\r\f");
    }

    return jsonObjects;
}

int main() {
    char jsonString[] = "{\"key1\":\"value1\",\"key2\":{\"nestedKey\":\"nestedValue\"}}";

    JsonObject *jsonObjects = parseJson(jsonString);
    printf("Parsed JSON:\n");
    for (int i = 0; i < 2; i++) {
        printf("%s: %s\n", jsonObjects[i].key, jsonObjects[i].value);
    }

    free(jsonObjects);

    return 0;
}