//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct to hold JSON key-value pairs
typedef struct {
    char key[100];
    char value[100];
} JsonPair;

// Struct to hold JSON object
typedef struct {
    JsonPair pairs[100];
    int size;
} JsonObject;

// Function to parse JSON string and return a JSON object
JsonObject parseJson(char *jsonStr) {
    JsonObject obj;
    obj.size = 0;

    char *token = strtok(jsonStr, "{\":,}");
    bool isKey = true;

    while (token != NULL) {
        if (isKey) {
            strncpy(obj.pairs[obj.size].key, token, sizeof(obj.pairs[obj.size].key));
        } else {
            strncpy(obj.pairs[obj.size].value, token, sizeof(obj.pairs[obj.size].value));
            obj.size++;
        }
        isKey = !isKey;
        token = strtok(NULL, "{\":,}");
    }

    return obj;
}

int main() {
    char jsonStr[] = "{\"name\":\"John Smith\",\"age\":30,\"city\":\"New York\"}";

    JsonObject obj = parseJson(jsonStr);

    for (int i=0; i<obj.size; i++) {
        printf("%s: %s\n", obj.pairs[i].key, obj.pairs[i].value);
    }

    return 0;
}