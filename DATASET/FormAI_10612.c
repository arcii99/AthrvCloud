//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct for a JSON object
typedef struct {
    char* key;
    char* value;
} JsonObject;

// define a function to parse a JSON object
void parseJsonObject(char* jsonString, JsonObject* jsonObject) {
    char* key = strtok(jsonString, "\""); // parse the key
    char* value = strtok(NULL, "\""); // parse the value

    // allocate memory for the key and value
    jsonObject->key = (char*) malloc(strlen(key) + 1);
    jsonObject->value = (char*) malloc(strlen(value) + 1);

    // copy the key and value into the struct
    strcpy(jsonObject->key, key);
    strcpy(jsonObject->value, value);
}

// define a function to print a JSON object
void printJsonObject(JsonObject* jsonObject) {
    printf("{\n");
    printf("\t\"%s\": \"%s\"\n", jsonObject->key, jsonObject->value);
    printf("}\n");
}

int main() {
    // create a sample JSON object
    char* jsonString = "{ \"name\": \"John\", \"age\": \"25\" }";
    JsonObject jsonObject;

    // parse the JSON object
    parseJsonObject(jsonString, &jsonObject);

    // print the JSON object
    printJsonObject(&jsonObject);

    // free the memory allocated for the key and value
    free(jsonObject.key);
    free(jsonObject.value);

    return 0;
}