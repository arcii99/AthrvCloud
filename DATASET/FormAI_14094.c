//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a JSON object
typedef struct {
    char *key;
    char *value;
} JsonObject;

// Define a struct to represent a JSON array
typedef struct {
    char **items;
    int length;
} JsonArray;

// Define a function to parse a JSON object
JsonObject* parseObject(char *json) {
    // Allocate memory for the object
    JsonObject *object = malloc(sizeof(JsonObject));
    
    // Extract the key and value
    char *colon = strstr(json, ":");
    int key_length = colon - json;
    object->key = calloc(key_length + 1, sizeof(char));
    strncpy(object->key, json, key_length);
    object->value = calloc(strlen(json) - key_length + 1, sizeof(char));
    strncpy(object->value, colon + 1, strlen(json) - key_length);
    
    return object;
}

// Define a function to parse a JSON array
JsonArray* parseArray(char *json) {
    // Allocate memory for the array
    JsonArray *array = malloc(sizeof(JsonArray));
    
    // Count the number of items in the array
    int count = 0;
    int in_string = 0;
    for (int i = 0; i < strlen(json); i++) {
        if (json[i] == ',' && !in_string) {
            count++;
        } else if (json[i] == '"' && (i == 0 || json[i - 1] != '\\')) {
            in_string = !in_string;
        }
    }
    array->length = count + 1;
    
    // Extract the items from the array
    array->items = calloc(array->length, sizeof(char*));
    int item_start = 1;
    int item_length = 0;
    in_string = 0;
    for (int i = 1; i < strlen(json) - 1; i++) {
        if (json[i] == ',' && !in_string) {
            char *item = calloc(item_length + 1, sizeof(char));
            strncpy(item, json + item_start, item_length);
            array->items[count--] = item;
            item_start = i + 1;
            item_length = 0;
        } else if (json[i] == '"' && (i == 1 || json[i - 1] != '\\')) {
            in_string = !in_string;
        } else {
            item_length++;
        }
    }
    char *item = calloc(item_length + 1, sizeof(char));
    strncpy(item, json + item_start, item_length);
    array->items[count] = item;
    
    return array;
}

// Define a function to parse a JSON string
void parseJson(char *json) {
    // Remove any whitespace from the input
    char *clean_json = calloc(strlen(json) + 1, sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(json); i++) {
        if (json[i] != ' ' && json[i] != '\n' && json[i] != '\r' && json[i] != '\t') {
            clean_json[j++] = json[i];
        }
    }
    
    // Determine the type of JSON object and parse it accordingly
    if (clean_json[0] == '{' && clean_json[strlen(clean_json) - 1] == '}') {
        // Object
        char *object_json = calloc(strlen(clean_json) - 1, sizeof(char));
        strncpy(object_json, clean_json + 1, strlen(clean_json) - 2);
        JsonObject *object = parseObject(object_json);
        printf("Parsed JSON object:\n");
        printf("Key: %s\nValue: %s\n", object->key, object->value);
    } else if (clean_json[0] == '[' && clean_json[strlen(clean_json) - 1] == ']') {
        // Array
        char *array_json = calloc(strlen(clean_json) - 1, sizeof(char));
        strncpy(array_json, clean_json + 1, strlen(clean_json) - 2);
        JsonArray *array = parseArray(array_json);
        printf("Parsed JSON array:\n");
        printf("Length: %d\nItems:\n", array->length);
        for (int i = 0; i < array->length; i++) {
            printf("- %s\n", array->items[i]);
        }
    } else {
        printf("Invalid JSON string\n");
    }
    
    // Free allocated memory
    free(clean_json);
}

int main() {
    // Define some sample JSON strings to parse
    char *object_json = "{ \"name\": \"John\", \"age\": 30 }";
    char *array_json = "[ \"apple\", \"banana\", \"cherry\" ]";
    char *invalid_json = "This is not JSON";
    
    // Parse the sample JSON strings
    parseJson(object_json);
    printf("\n");
    parseJson(array_json);
    printf("\n");
    parseJson(invalid_json);
    
    return 0;
}