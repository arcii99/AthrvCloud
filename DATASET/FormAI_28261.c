//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_JSON_DEPTH 100
#define MAX_JSON_ARRAY_SIZE 4096
#define MAX_JSON_OBJECT_SIZE 1024

enum json_value_type {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT,
};

typedef struct _json_value json_value;

typedef struct _json_object_entry {
    char *key;
    json_value *value;
} json_object_entry;

struct _json_value {
    enum json_value_type type;

    union {
        int boolean_value;
        float number_value;
        char *string_value;

        struct {
            json_value **value;
            int count;
        } array;

        struct {
            json_object_entry *entries;
            int count;
        } object;
    } data;
};

void json_parse(json_value *value, char **json);
void json_parse_array(json_value *value, char **json);
void json_parse_object(json_value *value, char **json);

json_value *json_create_value();
void json_free_value(json_value *value);

int main() {
    char *json_string = "{ \"name\":\"John\", \"age\":30, \"city\":\"New York\" }";
    char **json_ptr = &json_string;
    json_value *json = json_create_value();
    json_parse(json, json_ptr);

    printf("User: %s\n", json->data.object.entries[0].value->data.string_value);
    printf("Age: %d\n", (int)json->data.object.entries[1].value->data.number_value);
    printf("City: %s\n", json->data.object.entries[2].value->data.string_value);

    json_free_value(json);
    return 0;
}

void json_parse(json_value *value, char **json) {
    switch(**json) {
        case '\0':
            value->type = JSON_NULL;
            break;

        case '[':
            value->type = JSON_ARRAY;
            json_parse_array(value, json);
            break;

        case '{':
            value->type = JSON_OBJECT;
            json_parse_object(value, json);
            break;

        case '\"':
            value->type = JSON_STRING;
            value->data.string_value = (char*) malloc(MAX_JSON_OBJECT_SIZE);
            memset(value->data.string_value, '\\0', MAX_JSON_OBJECT_SIZE);
            strncpy(value->data.string_value, ++(*json), strcspn(*json, "\""));
            *json += strcspn(*json, "\"");
            break;

        case 't':
        case 'f':
            value->type = JSON_BOOLEAN;
            value->data.boolean_value = (**json == 't');
            *json += (value->data.boolean_value ? 4 : 5);
            break;

        default:
            if(isdigit(**json) || **json == '-') {
                value->type = JSON_NUMBER;
                char *end;
                value->data.number_value = strtof(*json, &end);
                *json = end;
            }
    }
}

void json_parse_array(json_value *value, char **json) {
    json_value **values = (json_value**) malloc(sizeof(json_value*) * MAX_JSON_ARRAY_SIZE);
    memset(values, NULL, sizeof(json_value*) * MAX_JSON_ARRAY_SIZE);
    value->data.array.value = values;

    int count = 0;
    while(**json && **json != ']') {
        values[count] = json_create_value();
        json_parse(values[count], json);

        count++;
        (*json)++;
    }
    value->data.array.count = count;
    (*json)++;
}

void json_parse_object(json_value *value, char **json) {
    json_object_entry *entries = (json_object_entry*) malloc(sizeof(json_object_entry) * MAX_JSON_OBJECT_SIZE);
    memset(entries, NULL, sizeof(json_object_entry) * MAX_JSON_OBJECT_SIZE);
    value->data.object.entries = entries;

    int count = 0;
    while(**json && **json != '}') {
        (*json)++;
        entries[count].key = (char*) malloc(MAX_JSON_OBJECT_SIZE);
        memset(entries[count].key, '\\0', MAX_JSON_OBJECT_SIZE);
        strncpy(entries[count].key, *json, strcspn(*json, ":"));
        *json += strcspn(*json, ":")+2;

        entries[count].value = json_create_value();
        json_parse(entries[count].value, json);

        count++;
    }
    value->data.object.count = count;
    (*json)++;
}

json_value *json_create_value() {
    json_value *value = (json_value*) malloc(sizeof(json_value));
    memset(value, NULL, sizeof(json_value));
    return value;
}

void json_free_value(json_value *value) {
    if(!value) {
        return;
    }

    switch(value->type) {
        case JSON_STRING:
            free(value->data.string_value);
            break;

        case JSON_ARRAY:
            for(int i=0; i<value->data.array.count; i++) {
                json_free_value(value->data.array.value[i]);
            }
            free(value->data.array.value);
            break;

        case JSON_OBJECT:
            for(int i=0; i<value->data.object.count; i++) {
                free(value->data.object.entries[i].key);
                json_free_value(value->data.object.entries[i].value);
            }
            free(value->data.object.entries);
            break;

        default:
            break;
    }
    free(value);
}