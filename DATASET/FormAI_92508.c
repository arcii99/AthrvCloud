//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants for JSON datatypes */
enum json_type {JSON_STRING, JSON_NUMBER, JSON_OBJECT, JSON_ARRAY, JSON_TRUE, JSON_FALSE, JSON_NULL};

/* Define a struct to represent a JSON object */
struct json_object {
    enum json_type type;
    char *key;
    union {
        char *sval;
        double dval;
        struct json_object *child;
    } value;
    struct json_object *next;
};

/* Function prototypes */
struct json_object* json_parse(char *json);
void json_print(struct json_object *json);

/* Entry point of the program */
int main() {
    char json[] = "{\"name\":\"John Smith\",\"age\":25,\"city\":\"New York\"}";
    struct json_object *obj = json_parse(json);
    if (obj) {
        json_print(obj);
    }
    return 0;
}

/* Function to parse JSON string */
struct json_object* json_parse(char *json) {
    struct json_object *head = NULL;
    struct json_object *tail = NULL;
    char *token, *key, *value;
    int is_key = 1, is_val = 0;
    token = strtok(json, "{}\":,");
    while (token != NULL) {
        if (is_key) {
            key = token;
            is_key = 0;
            is_val = 1;
        } else if (is_val) {
            value = token;
            is_key = 1;
            is_val = 0;
            struct json_object *obj = (struct json_object*) malloc(sizeof(struct json_object));
            obj->key = strdup(key);
            if (strcmp(value, "true") == 0) {
                obj->type = JSON_TRUE;
            } else if (strcmp(value, "false") == 0) {
                obj->type = JSON_FALSE;
            } else if (strcmp(value, "null") == 0) {
                obj->type = JSON_NULL;
            } else if (value[0] == '{') {
                obj->type = JSON_OBJECT;
                obj->value.child = json_parse(value);
            } else if (value[0] == '[') {
                obj->type = JSON_ARRAY;
                // TODO: parse array
            } else {
                obj->type = JSON_NUMBER;
                obj->value.dval = strtod(value, NULL);
            }
            if (head == NULL) {
                head = tail = obj;
            } else {
                tail->next = obj;
                tail = obj;
            }
        }
        token = strtok(NULL, "{}\":,");
    }
    return head;
}

/* Function to print JSON */
void json_print(struct json_object *json) {
    while (json != NULL) {
        printf("%s: ", json->key);
        switch (json->type) {
            case JSON_STRING:
                printf("%s\n", json->value.sval);
                break;
            case JSON_NUMBER:
                printf("%f\n", json->value.dval);
                break;
            case JSON_OBJECT:
                printf("{\n");
                json_print(json->value.child);
                printf("}\n");
                break;
            case JSON_ARRAY:
                printf("[\n");
                // TODO: print array
                printf("]\n");
                break;
            case JSON_TRUE:
                printf("true\n");
                break;
            case JSON_FALSE:
                printf("false\n");
                break;
            case JSON_NULL:
                printf("null\n");
                break;
        }
        json = json->next;
    }
}