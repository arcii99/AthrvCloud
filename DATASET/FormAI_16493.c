//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_OBJECTS 1000

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} json_type;

typedef struct {
    json_type type;
    char *key;
    union {
        char *str_value;
        double num_value;
        int bool_value;
        int null_value;
        struct json_obj *json_value;
    } value;
} json_obj;

json_obj json_objects[MAX_JSON_OBJECTS];
int json_object_count = 0;

int parse_object(char *, int);
int parse_array(char *, int);
int parse_string(char *, int);
int parse_number(char *, int);
int parse_bool(char *, int);
int parse_null(char *, int);

int parse_object(char *json_str, int index) {
    int start_index = index;
    int obj_index = json_object_count;

    json_objects[obj_index].type = JSON_OBJECT;
    json_object_count++;

    while (json_str[index] != '}') {
        index++;

        if (json_str[index] == ',') {
            index++;
        }

        while (json_str[index] == ' ') {
            index++;
        }

        char *key = strtok(&json_str[index], ":");
        index += strlen(key);

        json_objects[json_object_count].key = (char *)malloc(strlen(key) + 1);
        strcpy(json_objects[json_object_count].key, key);

        if (json_str[index + 1] == '{') {
            index = parse_object(json_str, index + 1);
        } else if (json_str[index + 1] == '[') {
            index = parse_array(json_str, index + 1);
        } else if (json_str[index + 1] == '\"') {
            index = parse_string(json_str, index + 1);
        } else if (json_str[index + 1] == '-' || (json_str[index + 1] >= '0' && json_str[index + 1] <= '9')) {
            index = parse_number(json_str, index + 1);
        } else if (json_str[index + 1] == 't' || json_str[index + 1] == 'f') {
            index = parse_bool(json_str, index + 1);
        } else if (json_str[index + 1] == 'n') {
            index = parse_null(json_str, index + 1);
        }
    }

    return index;
}

int parse_array(char *json_str, int index) {
    int start_index = index;
    int obj_index = json_object_count;

    json_objects[obj_index].type = JSON_ARRAY;
    json_object_count++;

    while (json_str[index] != ']') {
        index++;

        if (json_str[index] == ',') {
            index++;
        }

        while (json_str[index] == ' ') {
            index++;
        }

        if (json_str[index + 1] == '{') {
            index = parse_object(json_str, index + 1);
        } else if (json_str[index + 1] == '[') {
            index = parse_array(json_str, index + 1);
        } else if (json_str[index + 1] == '\"') {
            index = parse_string(json_str, index + 1);
        } else if (json_str[index + 1] == '-' || (json_str[index + 1] >= '0' && json_str[index + 1] <= '9')) {
            index = parse_number(json_str, index + 1);
        } else if (json_str[index + 1] == 't' || json_str[index + 1] == 'f') {
            index = parse_bool(json_str, index + 1);
        } else if (json_str[index + 1] == 'n') {
            index = parse_null(json_str, index + 1);
        }
    }

    return index;   
}

int parse_string(char *json_str, int index) {
    int start_index = index;
    int obj_index = json_object_count;

    json_objects[obj_index].type = JSON_STRING;
    json_object_count++;

    char *str_value = strtok(&json_str[index], "\"");
    index += strlen(str_value) + 1;

    json_objects[obj_index].value.str_value = (char *)malloc(strlen(str_value) + 1);
    strcpy(json_objects[obj_index].value.str_value, str_value);

    return index;
}

int parse_number(char *json_str, int index) {
    int start_index = index;
    int obj_index = json_object_count;

    json_objects[obj_index].type = JSON_NUMBER;
    json_object_count++;

    char *num_str = strtok(&json_str[index], ",}");
    index += strlen(num_str);

    json_objects[obj_index].value.num_value = atof(num_str);

    return index;
}

int parse_bool(char *json_str, int index) {
    int start_index = index;
    int obj_index = json_object_count;

    json_objects[obj_index].type = JSON_BOOL;
    json_object_count++;

    char *bool_str = strtok(&json_str[index], ",");
    index += strlen(bool_str);

    json_objects[obj_index].value.bool_value = 0;

    if (strcmp(bool_str, "true") == 0) {
        json_objects[obj_index].value.bool_value = 1;
    }

    return index;
}

int parse_null(char *json_str, int index) {
    int start_index = index;
    int obj_index = json_object_count;

    json_objects[obj_index].type = JSON_NULL;
    json_object_count++;

    char *null_str = strtok(&json_str[index], ",");
    index += strlen(null_str);

    json_objects[obj_index].value.null_value = 0;

    return index;
}

int main() {
    char json_string[1000] = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";

    parse_object(json_string, 0);

    printf("Parsed JSON Objects:\n");

    for (int i = 0; i < json_object_count; i++) {
        printf("%s: ", json_objects[i].key);

        switch (json_objects[i].type) {
            case JSON_OBJECT:
                printf("(object)\n");
                break;
            case JSON_ARRAY:
                printf("(array)\n");
                break;
            case JSON_STRING:
                printf("(string) %s\n", json_objects[i].value.str_value);
                break;
            case JSON_NUMBER:
                printf("(number) %f\n", json_objects[i].value.num_value);
                break;
            case JSON_BOOL:
                printf("(bool) %d\n", json_objects[i].value.bool_value);
                break;
            case JSON_NULL:
                printf("(null)\n");
                break;
        }
    }

    return 0;
}