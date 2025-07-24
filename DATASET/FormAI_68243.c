//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom struct to store key value pairs
struct KeyVal {
    char* key;
    char* value;
};

// Define a struct to store the JSON object
struct JSONObject {
    int numPairs;
    struct KeyVal** keyvals;
};

// Helper function to strip whitespace from a string
char* stripWhitespace(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (isspace(str[i])) i++;
    while (isspace(str[j])) j--;
    char* newStr = malloc((j - i + 2) * sizeof(char));
    strncpy(newStr, &str[i], j - i + 1);
    newStr[j - i + 1] = '\0';
    return newStr;
}

// Helper function to parse a JSON object from a string
struct JSONObject* parseJSONObject(char* str) {
    // Strip leading and trailing whitespace
    char* strippedStr = stripWhitespace(str);
    // Ensure the string starts and ends with braces
    if (strippedStr[0] != '{' || strippedStr[strlen(strippedStr)-1] != '}') {
        fprintf(stderr, "Invalid JSON string: %s\n", str);
        exit(1);
    }
    // Create the JSONObject struct
    struct JSONObject* jsonObj = malloc(sizeof(struct JSONObject));
    jsonObj->numPairs = 0;
    jsonObj->keyvals = NULL;
    // Iterate through the key-value pairs
    char* pairStr = strtok(strippedStr+1, ",");
    while (pairStr) {
        // Ensure the pair starts and ends with quotes
        if (pairStr[0] != '"' || pairStr[strlen(pairStr)-1] != '"') {
            fprintf(stderr, "Invalid JSON pair string: %s\n", pairStr);
            exit(1);
        }
        // Split the pair string into key and value
        char* keyStr = strtok(pairStr+1, ":");
        char* valueStr = strtok(NULL, ":");
        // Strip the key and value of whitespace and quotes
        char* strippedKey = stripWhitespace(keyStr+1);
        char* strippedValue = stripWhitespace(valueStr);
        // Allocate memory for the new keyval struct
        struct KeyVal* newKeyVal = malloc(sizeof(struct KeyVal));
        newKeyVal->key = strippedKey;
        newKeyVal->value = strippedValue;
        // Append the new keyval to the JSON object
        jsonObj->numPairs++;
        jsonObj->keyvals = realloc(jsonObj->keyvals, jsonObj->numPairs*sizeof(struct KeyVal*));
        jsonObj->keyvals[jsonObj->numPairs-1] = newKeyVal;
        // Move on to the next pair
        pairStr = strtok(NULL, ",");
    }
    free(strippedStr);
    return jsonObj;
}

// Main function to demonstrate the JSON parser in action
int main() {
    char* jsonString = "{\"name\": \"Alan\", \"age\": 25, \"isStudent\": true}";
    struct JSONObject* jsonObj = parseJSONObject(jsonString);
    printf("Parsed JSON object with %d key-value pairs:\n", jsonObj->numPairs);
    for (int i = 0; i < jsonObj->numPairs; i++) {
        printf("%s: %s\n", jsonObj->keyvals[i]->key, jsonObj->keyvals[i]->value);
    }
    // Clean up memory
    for (int i = 0; i < jsonObj->numPairs; i++) {
        free(jsonObj->keyvals[i]->key);
        free(jsonObj->keyvals[i]->value);
        free(jsonObj->keyvals[i]);
    }
    free(jsonObj->keyvals);
    free(jsonObj);
    return 0;
}