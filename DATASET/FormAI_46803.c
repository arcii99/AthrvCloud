//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024 // Maximum size of a JSON Object
#define MAX_KEY_SIZE 128 // Maximum size of a JSON Key
#define MAX_VALUE_SIZE 256 // Maximum size of a JSON Value

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} JSONPair;

typedef struct {
    int count;
    JSONPair pairs[MAX_SIZE];
} JSONObject;

int parseJSON(char* jsonString, JSONObject* jsonObject) {
    int index = 0;
    int count = 0;
    int objectStarted = 0;
    int keyStarted = 0;
    int valueStarted = 0;
    int escaped = 0;
    char currentKey[MAX_KEY_SIZE];
    char currentValue[MAX_VALUE_SIZE];
    int currentKeyIndex = 0;
    int currentValueIndex = 0;

    while (jsonString[index] != '\0') {
        if (!objectStarted && !isspace(jsonString[index])) {
            if (jsonString[index] != '{') {
                return -1; // Not a JSON object
            }
            objectStarted = 1;
            continue;
        }

        if (objectStarted && jsonString[index] == '}') {
            objectStarted = 0;
            if (currentKeyIndex > 0 && currentValueIndex > 0) {
                memcpy(&(jsonObject->pairs[count].key), currentKey, currentKeyIndex);
                currentKey[currentKeyIndex] = '\0';
                memcpy(&(jsonObject->pairs[count].value), currentValue, currentValueIndex);
                currentValue[currentValueIndex] = '\0';
                currentKeyIndex = 0;
                currentValueIndex = 0;
                count++;
            }
            continue;
        }

        if (currentKeyIndex == 0 && jsonString[index] == '"') {
            keyStarted = 1;
            continue;
        }

        if (keyStarted && jsonString[index] == '"' && !escaped) {
            keyStarted = 0;
            continue;
        }

        if (currentValueIndex == 0 && !keyStarted && jsonString[index] == ':') {
            valueStarted = 1;
            continue;
        }

        if (valueStarted && jsonString[index] == '"' && !escaped) {
            escaped = 0;
            valueStarted = 0;
            continue;
        }

        if (valueStarted && jsonString[index] == '\\' && !escaped) {
            escaped = 1;
            continue;
        }

        if (escaped) {
            escaped = 0;
            currentValue[currentValueIndex] = jsonString[index];
            currentValueIndex++;
            continue;
        }

        if (keyStarted) {
            currentKey[currentKeyIndex] = jsonString[index];
            currentKeyIndex++; 
            continue;
        }

        if (valueStarted) {
            currentValue[currentValueIndex] = jsonString[index];
            currentValueIndex++;
            continue;
        }

        index++;
    }

    jsonObject->count = count;
    return 0;
}

void printJSONObject(JSONObject* jsonObject) {
    printf("{\n");
    for (int i = 0; i < jsonObject->count; i++) {
        printf("  \"%s\": \"%s\"", jsonObject->pairs[i].key, jsonObject->pairs[i].value);
        if (i < jsonObject->count - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("}\n");
}

int main() {
    char jsonString[] = "{\"name\": \"John Doe\", \"age\": \"25\", \"gender\": \"male\"}";
    JSONObject jsonObject;
    parseJSON(jsonString, &jsonObject);
    printJSONObject(&jsonObject);
    return 0;
}