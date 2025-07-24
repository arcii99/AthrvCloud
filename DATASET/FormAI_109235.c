//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JSON 1024

typedef struct json_object {
    char *key;
    char *value;
    struct json_object *next;
} JsonObject;

// Allocate memory for a new JSON object
JsonObject *create_json_object(char *key, char *value) {
    JsonObject *obj = malloc(sizeof(JsonObject));

    if(!obj) {
        fprintf(stderr, "Error: could not allocate memory for JSON object\n");
        exit(EXIT_FAILURE);
    }

    obj->key = strdup(key);
    obj->value = strdup(value);
    obj->next = NULL;

    return obj;
}

// Free the memory used by a JSON object
void free_json_object(JsonObject *obj) {
    if(!obj) {
        return;
    }

    free(obj->key);
    free(obj->value);
    free_json_object(obj->next);
    free(obj);
}

// Parse a string into a JSON object
JsonObject *parse_json(char *json) {
    JsonObject *obj = NULL;
    char key[MAX_JSON], value[MAX_JSON];
    bool in_key = false, in_value = false;

    for(int i = 0; i < strlen(json); i++) {
        if(json[i] == '"') {
            if(in_key) {
                in_key = false;
            }
            else if(in_value) {
                obj = create_json_object(key, value);
                in_value = false;
            }
            else {
                in_key = true;
            }
        }
        else if(json[i] == ':') {
            in_value = true;
        }
        else if(json[i] == ',' || json[i] == '}') {
            obj = create_json_object(key, value);
            in_value = false;
        }
        else if(in_key) {
            strncat(key, &json[i], 1);
        }
        else if(in_value) {
            strncat(value, &json[i], 1);
        }
    }

    return obj;
}

int main() {
    char json[MAX_JSON] = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    JsonObject *obj = parse_json(json);

    while(obj != NULL) {
        printf("%s: %s\n", obj->key, obj->value);
        obj = obj->next;
    }

    free_json_object(obj);
    return 0;
}