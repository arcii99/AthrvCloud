//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_JSON_SIZE 1000

typedef struct {
    char key[50];
    char value[50];
} KeyValue;

void trim(char* str) {
    int i, j;
    // Trim leading whitespace
    i = 0;
    while (isspace(str[i])) {
        i++;
    }
    if (i > 0) {
        memmove(str, str + i, strlen(str));
    }
    // Trim trailing whitespace
    j = strlen(str) - 1;
    while (j > 0 && isspace(str[j])) {
        j--;
    }
    str[j + 1] = '\0';
}

KeyValue parseKeyValuePair(char* str) {
    KeyValue keyValue;
    int i, j;
    i = 0;
    // Find the key
    while (isspace(str[i])) {
        i++;
    }
    j = i;
    while (str[j] != ':') {
        j++;
    }
    strncpy(keyValue.key, str + i, j-i);
    keyValue.key[j-i] = '\0';
    trim(keyValue.key);
    // Find the value
    i = j + 1;
    j = strlen(str) - 1;
    while (isspace(str[j])) {
        j--;
    }
    strncpy(keyValue.value, str + i, j-i+1);
    keyValue.value[j-i+1] = '\0';
    trim(keyValue.value);
    return keyValue;
}

bool parseJSONObject(char* str, KeyValue* keyValueArray, int* size) {
    int i, j, k;
    KeyValue keyValue;
    if (strlen(str) < 2 || str[0] != '{' || str[strlen(str) - 1] != '}') {
        return false;
    }
    i = 1;
    j = 0;
    while (i < strlen(str) - 1) {
        k = i;
        while (str[k] != ',' && k < strlen(str) - 1) {
            k++;
        }
        strncpy(keyValue.key, str + i, k-i);
        keyValue.key[k-i] = '\0';
        trim(keyValue.key);
        keyValue = parseKeyValuePair(keyValue.key);
        keyValueArray[j] = keyValue;
        j++;
        i = k + 1;
    }
    *size = j;
    return true;
}

int main() {
    char jsonString[MAX_JSON_SIZE] = "{\"firstName\": \"John\",\"lastName\": \"Doe\",\"age\": 30,\"email\": \"john.doe@example.com\"}";
    KeyValue keyValueArray[10];
    int size = 0;
    bool success = parseJSONObject(jsonString, keyValueArray, &size);
    if (success) {
        printf("JSON Object key-value pairs:\n");
        for (int i = 0; i < size; i++) {
            printf("%s: %s\n", keyValueArray[i].key, keyValueArray[i].value);
        }
    } else {
        printf("Invalid JSON string\n");
    }
    return 0;
}