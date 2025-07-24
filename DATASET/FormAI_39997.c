//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define JSON type constants
#define JSON_TYPE_NULL 0
#define JSON_TYPE_BOOL 1
#define JSON_TYPE_NUMBER 2
#define JSON_TYPE_STRING 3
#define JSON_TYPE_ARRAY 4
#define JSON_TYPE_OBJECT 5

typedef struct json_value_s {
    int type;
    union {
        int boolean;
        double number;
        char *string;
        struct json_value_s *array;
        struct {
            char *key;
            struct json_value_s *value;
        } object;
    } data;
} json_value_t;

json_value_t *json_parse(char *json_string);
void json_print(json_value_t *json);

int main() {
    char *json_string = "{ \"name\": \"John\", \"age\": 30, \"isMarried\": false, \"hobbies\": [\"reading\", \"swimming\", \"playing guitar\"] }";

    // parse JSON string
    json_value_t *json = json_parse(json_string);

    // print JSON value
    json_print(json);

    // clean up
    free(json);

    return 0;
}

json_value_t *json_parse(char *json_string) {
    // TODO: implement JSON parser
    return NULL;
}

void json_print(json_value_t *json) {
    if (json == NULL) {
        printf("null");
    } else {
        switch (json->type) {
            case JSON_TYPE_NULL:
                printf("null");
                break;
            case JSON_TYPE_BOOL:
                printf("%s", json->data.boolean ? "true" : "false");
                break;
            case JSON_TYPE_NUMBER:
                printf("%g", json->data.number);
                break;
            case JSON_TYPE_STRING:
                printf("\"%s\"", json->data.string);
                break;
            case JSON_TYPE_ARRAY:
                printf("[");
                for (int i = 0; i < sizeof(json->data.array) / sizeof(json_value_t); i++) {
                    if (i > 0) {
                        printf(", ");
                    }
                    json_print(&json->data.array[i]);
                }
                printf("]");
                break;
            case JSON_TYPE_OBJECT:
                printf("{");
                json_print(&json->data.object.value);
                printf("}");
                break;
        }
    }
}