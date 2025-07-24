//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold a JSON object
typedef struct {
    char* key;
    char* value;
} JSON_Object;

// Parse a JSON string and return an array of JSON objects
JSON_Object* parse_json(char* json_string, int* num_objects) {
    // Determine the number of objects in the JSON string
    int object_count = 0;
    char* current_char = json_string;
    while (*current_char != '\0') {
        if (*current_char == '{') {
            object_count++;
        }
        current_char++;
    }
    *num_objects = object_count;

    // Allocate memory for the array of JSON objects
    JSON_Object* objects = (JSON_Object*)malloc(object_count * sizeof(JSON_Object));

    // Parse each object in the JSON string
    char* object_start = strchr(json_string, '{');
    int i = 0;
    while (object_start != NULL) {
        char* object_end = strchr(object_start, '}');
        if (object_end == NULL) {
            fprintf(stderr, "Error: Invalid JSON string\n");
            exit(1);
        }

        // Copy the object into a new string
        int object_length = object_end - object_start + 1;
        char* object_string = (char*)malloc(object_length + 1);
        strncpy(object_string, object_start, object_length);
        object_string[object_length] = '\0';

        // Parse the key-value pairs in the object
        char* key_start = strchr(object_string, '\"') + 1;
        while (key_start != NULL && *key_start != '}') {
            char* key_end = strchr(key_start, '\"');
            if (key_end == NULL) {
                fprintf(stderr, "Error: Invalid JSON string\n");
                exit(1);
            }
            int key_length = key_end - key_start;
            char* key = (char*)malloc(key_length + 1);
            strncpy(key, key_start, key_length);
            key[key_length] = '\0';

            char* value_start = strchr(key_end, ':') + 1;
            while (*value_start == ' ') {
                value_start++;
            }
            char* value_end;
            if (*value_start == '\"') {
                value_start++;
                value_end = strchr(value_start, '\"');
                if (value_end == NULL) {
                    fprintf(stderr, "Error: Invalid JSON string\n");
                    exit(1);
                }
            } else {
                value_end = value_start;
                while (*value_end != ',' && *value_end != '}') {
                    value_end++;
                }
            }
            int value_length = value_end - value_start;
            char* value = (char*)malloc(value_length + 1);
            strncpy(value, value_start, value_length);
            value[value_length] = '\0';

            objects[i].key = key;
            objects[i].value = value;
            i++;

            // Find the next key-value pair in the object
            key_start = strchr(value_end, '\"') + 1;
        }

        // Find the next object in the JSON string
        object_start = strchr(object_end, '{');
    }

    return objects;
}

int main() {
    char json_string[] = "{\"name\": \"John Doe\", \"age\": 30, \"isEmployed\": true}";
    int num_objects;
    JSON_Object* objects = parse_json(json_string, &num_objects);
    for (int i = 0; i < num_objects; i++) {
        printf("%s: %s\n", objects[i].key, objects[i].value);
    }
    return 0;
}