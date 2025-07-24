//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1000
#define MAX_OBJECTS 100

typedef struct {
    char* key;
    char* value;
} KeyValue;

typedef struct {
    KeyValue* data;
    int count;
} Object;

static char json_string[MAX_JSON_SIZE];
static Object objects[MAX_OBJECTS];
static int object_count = 0;

static void parse_json_object(char* json_data, int data_length, Object* obj);
static void parse_json_key_value(char* json_data, int data_length, KeyValue* kv);
static void trim_json_string(char** json_data, int* data_length);

int main() {
    printf("Enter JSON string: ");
    fgets(json_string, MAX_JSON_SIZE, stdin);

    printf("Parsing JSON...\n");
    parse_json_object(json_string, strlen(json_string), &objects[object_count]);

    printf("Parsed JSON:\n");
    for (int i = 0; i < objects[object_count].count; i++) {
        printf("%s: %s\n", objects[object_count].data[i].key, objects[object_count].data[i].value);
    }

    return 0;
}

static void parse_json_object(char* json_data, int data_length, Object* obj) {
    trim_json_string(&json_data, &data_length);

    if (*json_data != '{' || *(json_data + data_length - 1) != '}') {
        printf("Error parsing JSON. Invalid JSON object.\n");
        return;
    }

    obj->data = malloc(sizeof(KeyValue) * MAX_JSON_SIZE);
    obj->count = 0;

    char* current_pointer = json_data + 1;
    int remaining_length = data_length - 2;

    while (remaining_length > 0) {
        trim_json_string(&current_pointer, &remaining_length);
        KeyValue* current_kv = &obj->data[obj->count++];
        parse_json_key_value(current_pointer, remaining_length, current_kv);

        // Find next comma
        char* next_comma = strchr(current_pointer, ',');
        if (next_comma != NULL) {
            remaining_length -= (next_comma - current_pointer + 1);
            current_pointer = next_comma + 1;
        } else {
            remaining_length = 0;
        }
    }
}

static void parse_json_key_value(char* json_data, int data_length, KeyValue* kv) {
    trim_json_string(&json_data, &data_length);

    // Extract key
    char* key_start = json_data + 1;
    char* key_end = strchr(json_data, ':');
    if (key_end == NULL) {
        printf("Error parsing JSON. Invalid key-value pairs.\n");
        return;
    }

    int key_length = (key_end - key_start);
    kv->key = malloc(key_length + 1);
    strncpy(kv->key, key_start, key_length);
    kv->key[key_length] = '\0';

    // Extract value
    char* val_start = key_end + 1;
    int val_length = (json_data + data_length) - val_start;

    // Trim value
    while (val_length > 0 && (*val_start == ' ' || *val_start == '\n')) {
        val_start++;
        val_length--;
    }

    while (val_length > 0 && (*(val_start + val_length - 1) == ' ' || *(val_start + val_length - 1) == '\n')) {
        val_length--;
    }

    kv->value = malloc(val_length + 1);
    strncpy(kv->value, val_start, val_length);
    kv->value[val_length] = '\0';
}

static void trim_json_string(char** json_data, int* data_length) {
    char* start = *json_data;
    char* end = *json_data + *data_length - 1;

    // Trim leading whitespaces and newlines
    while (*start == ' ' || *start == '\n') {
        start++;
    }

    // Trim trailing whitespaces and newlines
    while (*end == ' ' || *end == '\n') {
        end--;
    }

    *data_length = (end - start) + 1;
    *json_data = start;
}