//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct for JSON object
typedef struct {
    char* key;
    char* value;
} JSON_Object;

// Define a function to parse a JSON string and return an array of JSON objects
JSON_Object* parseJSON(char* jsonString, int* numObjects) {
    // Initialize an array to store JSON objects
    JSON_Object* jsonObjects = NULL;
    *numObjects = 0;
    
    // Check if JSON string is not null
    if (jsonString != NULL) {
        // Calculate the number of JSON objects in the string
        int numBraces = 0;
        for (int i = 0; i < strlen(jsonString); i++) {
            if (jsonString[i] == '{')
                numBraces++;
        }

        // Check if there are any JSON objects in the string
        if (numBraces > 0) {
            // Allocate memory for the array of JSON objects
            jsonObjects = (JSON_Object*)malloc(numBraces * sizeof(JSON_Object));
            
            // Initialize variables used for parsing
            char* token;
            char* key;
            char* value;
            bool insideObject = false;
            int objectIndex = 0;

            // Start parsing the JSON string
            token = strtok(jsonString, "{}\":,");
            while (token != NULL) {
                if (strcmp(token, "{") == 0) {
                    insideObject = true;
                }
                else if (strcmp(token, "}") == 0) {
                    insideObject = false;
                    objectIndex++;
                }
                else if (strcmp(token, "\"") == 0) {
                    if (insideObject) {
                        token = strtok(NULL, "\"");
                        if (key == NULL)
                            key = token;
                        else {
                            value = token;
                            jsonObjects[objectIndex].key = key;
                            jsonObjects[objectIndex].value = value;
                            key = NULL;
                            value = NULL;
                            (*numObjects)++;
                        }
                    }
                }

                token = strtok(NULL, "{}\":,");
            }
        }
    }
    
    return jsonObjects;
}

// Define a function to print the array of JSON objects
void printJSONObjects(JSON_Object* jsonObjects, int numObjects) {
    if (jsonObjects != NULL) {
        for (int i = 0; i < numObjects; i++) {
            printf("Key: %s, Value: %s\n", jsonObjects[i].key, jsonObjects[i].value);
        }
    }
}

int main() {
    // Define a JSON string
    char jsonString[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    // Parse the JSON string
    int numObjects;
    JSON_Object* jsonObjects = parseJSON(jsonString, &numObjects);
    
    // Print the array of JSON objects
    printJSONObjects(jsonObjects, numObjects);

    // Free memory used by the array of JSON objects
    free(jsonObjects);

    return 0;
}