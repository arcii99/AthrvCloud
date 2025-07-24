//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LEN 256

typedef struct {
    char key[MAX_CHAR_LEN];
    char value[MAX_CHAR_LEN];
} JSON;

int parse_json(const char *text, JSON **json) {
    // Determine number of objects in text
    int num_objects = 0;
    char *ptr = (char*)text;
    while (*ptr != '\0') {
        if (*ptr == '{') num_objects++;
        ptr++;
    }   

    // Allocate memory for JSON objects
    *json = (JSON*)malloc(num_objects * sizeof(JSON));
    if (*json == NULL) {
        printf("Error: Unable to allocate memory for %d JSON objects.\n", num_objects);
        return -1;
    }

    // Parse text into JSON objects
    ptr = (char*)text;
    int object_count = 0;
    while (*ptr != '\0') {
        if (*ptr == '{') {
            ptr++;
            char *key_ptr = (*json)[object_count].key;
            char *value_ptr = (*json)[object_count].value;
            while (*ptr != '}') {
                if (*ptr == ':') {
                    *key_ptr = '\0';
                    key_ptr = (*json)[object_count].value;
                    ptr++;
                    while (*ptr == ' ') ptr++;
                } else if (*ptr == ',') {
                    *value_ptr = '\0';
                    key_ptr = (*json)[object_count].key;
                    value_ptr = (*json)[object_count].value;
                    ptr++;
                    while (*ptr == ' ') ptr++;
                } else {
                    *value_ptr = *ptr;
                    value_ptr++;
                    ptr++;
                }
            }
            *value_ptr = '\0';
            object_count++;
            ptr++;
        } else {
            ptr++;
        }
    }
    return num_objects;
}

int main(void) {
    const char *json_text = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" } { \"name\": \"Alice\", \"age\": 25, \"city\": \"Chicago\" }";
    JSON *json_objects;
    int num_objects = parse_json(json_text, &json_objects);
    if (num_objects > 0) {
        printf("Parsed %d JSON objects.\n", num_objects);
        for (int i = 0; i < num_objects; i++) {
            printf("Object %d:\n\tKey: %s\n\tValue: %s\n", i+1, json_objects[i].key, json_objects[i].value);
        }
    }
    free(json_objects);
    return 0;
}