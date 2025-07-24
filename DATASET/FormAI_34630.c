//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold key-value pairs in JSON object
struct JSONKeyValue {
    char key[100];
    char value[100];
};

// Structure to hold JSON object
struct JSONObject {
    int numKeyValuePairs;
    struct JSONKeyValue keyValuePairs[50];
};

// Function to parse JSON object from string representation
struct JSONObject parseJSON(char* jsonString) {
    struct JSONObject jsonObject;

    // Skip first '{'
    char* curChar = jsonString + 1;

    // Loop through key-value pairs
    while (*curChar != '}') {
        // Skip whitespace
        while (*curChar == ' ' || *curChar == '\n' || *curChar == '\t') {
            curChar++;
        }

        // Get key
        char* keyStart = curChar;
        while (*curChar != ':') {
            curChar++;
        }
        char* keyEnd = curChar - 1;
        strncpy(jsonObject.keyValuePairs[jsonObject.numKeyValuePairs].key, keyStart, keyEnd - keyStart + 1);
        jsonObject.keyValuePairs[jsonObject.numKeyValuePairs].key[keyEnd - keyStart + 1] = '\0';
        curChar++;

        // Get value
        char* valueStart = curChar;
        while (*curChar != ',' && *curChar != '}') {
            curChar++;
        }
        char* valueEnd = curChar - 1;
        strncpy(jsonObject.keyValuePairs[jsonObject.numKeyValuePairs].value, valueStart, valueEnd - valueStart + 1);
        jsonObject.keyValuePairs[jsonObject.numKeyValuePairs].value[valueEnd - valueStart + 1] = '\0';
        jsonObject.numKeyValuePairs++;

        curChar++;
    }

    return jsonObject;
}

int main() {
    char jsonString[1000] = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";

    struct JSONObject jsonObject = parseJSON(jsonString);

    printf("Parsed JSON object:\n");
    for (int i = 0; i < jsonObject.numKeyValuePairs; i++) {
        printf("%s: %s\n", jsonObject.keyValuePairs[i].key, jsonObject.keyValuePairs[i].value);
    }

    return 0;
}