//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct to store JSON objects
typedef struct json_object {
    char* key;
    char* value;
} json_object;

// Function to parse JSON string
json_object* parse_json(char* json_str) {
    json_object* obj = (json_object*)malloc(sizeof(json_object));
    char* key = strtok(json_str, ":");
    char* value = strtok(NULL, ",}");
    obj->key = key;
    obj->value = value;
    return obj;
}

int main() {
    char* json_str = "{\"name\": \"John\", \"age\": 30}";
    json_object* obj = parse_json(json_str);
    printf("Key: %s\nValue: %s\n", obj->key, obj->value);
    free(obj);
    return 0;
}