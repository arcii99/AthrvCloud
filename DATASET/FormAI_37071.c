//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/* Function to check if a character is a digit */
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

/* Structure to represent JSON object */
typedef struct JSON {
    char* key;
    char* value;
} JSON;

/* Function to parse JSON object from string */
JSON* parseJSON(char* jsonString) {
    JSON* jsonObject = (JSON*)malloc(sizeof(JSON));
    int i = 0, j = 0;
    char c;

    /* Read the key */
    while(jsonString[i] != ':') {
        jsonObject->key[j++] = jsonString[i++];
    }
    jsonObject->key[j] = '\0';
    i++; // Skip the colon

    /* Skip the whitespace */
    while(jsonString[i] == ' ') {
        i++;
    }

    /* Read the value */
    j = 0;
    while(jsonString[i] != '\0') {
        if(jsonString[i] == ',') {
            break;
        }
        jsonObject->value[j++] = jsonString[i++];
    }
    jsonObject->value[j] = '\0';

    return jsonObject;
}

int main() {
    /* Valid JSON string */
    char jsonString[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    /* Parse each JSON object */
    char* ptr = strtok(jsonString, "{}");
    while(ptr != NULL) {
        printf("JSON Object: %s\n", ptr);
        JSON* jsonObject = parseJSON(ptr);
        printf("Key: %s | Value: %s\n", jsonObject->key, jsonObject->value);
        ptr = strtok(NULL, "{}");
    }

    return 0;
}