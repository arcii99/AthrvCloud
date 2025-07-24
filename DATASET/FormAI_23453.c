//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
} json_type;

typedef struct json_value_t json_value_t;

struct json_value_t {
    json_type type;
    union {
        struct {
            char *key;
            json_value_t *value;
        } object;
        struct {
            json_value_t **items;
            size_t size;
        } array;
        char *string;
        double number;
    } data;
};

json_value_t *
parse_json(char *json_str, size_t len)
{
    json_value_t *value = NULL;
    char *p = json_str;
    char *end;

    if (*p == '{') {
        value = (json_value_t *) malloc(sizeof(json_value_t));
        value->type = JSON_OBJECT;
        value->data.object.key = NULL;
        value->data.object.value = NULL;

        p++;
        while (*p != '}') {
            if (*p == ',') {
                p++;
            }
            p = strtok(p, "\"");
            end = strtok(NULL, "\"");
            value->data.object.key = (char *) malloc(strlen(end) + 1);
            strcpy(value->data.object.key, end);
            p = strtok(NULL, ":");
            value->data.object.value = parse_json(p, len - (p - json_str));
        }
    } else if (*p == '[') {
        value = (json_value_t *) malloc(sizeof(json_value_t));
        value->type = JSON_ARRAY;
        value->data.array.items = (json_value_t **) malloc(sizeof(json_value_t *) * 10);
        value->data.array.size = 0;

        p++;
        while (*p != ']') {
            if (*p == ',') {
                p++;
            }
            value->data.array.items[value->data.array.size++] = parse_json(p, len - (p - json_str));
        }
    } else if (*p == '"') {
        char *end = strchr(p + 1, '"');
        value = (json_value_t *) malloc(sizeof(json_value_t));
        value->type = JSON_STRING;
        value->data.string = (char *) malloc(end - p);
        strncpy(value->data.string, p + 1, end - p - 1);
        value->data.string[end - p - 1] = '\0';
    } else if (isdigit(*p) || *p == '-') {
        value = (json_value_t *) malloc(sizeof(json_value_t));
        value->type = JSON_NUMBER;
        value->data.number = strtod(p, &end);
        p = end;
    } else if (strncmp(p, "true", 4) == 0) {
        value = (json_value_t *) malloc(sizeof(json_value_t));
        value->type = JSON_TRUE;
        p += 4;
    } else if (strncmp(p, "false", 5) == 0) {
        value = (json_value_t *) malloc(sizeof(json_value_t));
        value->type = JSON_FALSE;
        p += 5;
    } else if (strncmp(p, "null", 4) == 0) {
        value = (json_value_t *) malloc(sizeof(json_value_t));
        value->type = JSON_NULL;
        p += 4;
    } else {
        fprintf(stderr, "Invalid JSON format near %s\n", p);
        return NULL;
    }

    return value;
}

int
main(int argc, char **argv)
{
    char *json_str =
        "{\"name\": \"John Doe\", \"age\": 30, "
        "\"address\": {\"street\": \"123 Main St\", \"city\": \"Los Angeles\", \"state\": \"CA\"}, "
        "\"hobbies\": [\"reading\", \"swimming\", \"playing video games\"]}";

    json_value_t *json = parse_json(json_str, strlen(json_str));
    if (json) {
        printf("Parsed JSON:\n");
        printf("name: %s\n", json->data.object.value->data.string);
        printf("age: %f\n", json->data.object.value->data.number);
        printf("street: %s\n", json->data.object.value->data.object.value->data.object.value->data.string);
        printf("city: %s\n", json->data.object.value->data.object.value->data.object.value->data.string);
        printf("state: %s\n", json->data.object.value->data.object.value->data.object.value->data.string);
        printf("hobbies: %s, %s, %s\n",
               json->data.object.value->data.object.value->data.object.value->data.array.items[0]->data.string,
               json->data.object.value->data.object.value->data.object.value->data.array.items[1]->data.string,
               json->data.object.value->data.object.value->data.object.value->data.array.items[2]->data.string);
    }

    return 0;
}