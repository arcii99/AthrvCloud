//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_OBJECTS 100
#define MAX_OBJECT_SIZE 100

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} JSONType;

typedef struct JSONValue {
    JSONType type;
    union {
        char string[MAX_OBJECT_SIZE];
        float number;
        struct JSONValue *object[MAX_OBJECTS];
    };
    size_t size;
} JSONValue;

static size_t parse_json_value(const char *json, JSONValue *out);
static size_t parse_json_pair(const char *json, char *key, JSONValue *value);
static size_t parse_json_string(const char *json, char *out);
static size_t parse_json_number(const char *json, char *out);
static size_t parse_json_boolean(const char *json, JSONValue *out);

static bool is_whitespace(char c);
static bool is_digit(char c);
static bool is_decimal(char c);

int main() {
    const char *json = "{\"name\": \"John\", \"age\": 25, \"isMarried\": true}";

    JSONValue root;
    memset(&root, 0, sizeof(JSONValue));

    parse_json_value(json, &root);

    printf("Name: %s\n", root.object[0]->string);
    printf("Age: %f\n", root.object[1]->number);
    printf("Is Married? %c\n", root.object[2]->type == JSON_TRUE ? 'Y' : 'N');

    return 0;
}

static size_t parse_json_value(const char *json, JSONValue *out) {
    memset(out, 0, sizeof(JSONValue));

    size_t i = 0;
    while (is_whitespace(json[i])) i++;

    switch (json[i]) {
        case '\"': {
            out->type = JSON_STRING;
            out->size = parse_json_string(json + i, out->string);
            return i + out->size + 2;
        }
        case '[': {
            out->type = JSON_ARRAY;
            size_t size = 0;
            i++;
            while (json[i] != ']') {
                size += parse_json_value(json + i, out->object[size]);
                i += size;
                out->size++;
            }
            return i + 1;
        }
        case '{': {
            out->type = JSON_OBJECT;
            size_t size = 0;
            i++;
            while (json[i] != '}') {
                size += parse_json_pair(json + i, out->object[size]->string, out->object[size]);
                i += size;
                out->size++;
            }
            return i + 1;
        }
        case 't':
        case 'f': {
            return parse_json_boolean(json, out);
        }
        case 'n': {
            out->type = JSON_NULL;
            out->size = 4;
            return i + 4;
        }
        default: {
            out->type = JSON_NUMBER;
            out->size = parse_json_number(json + i, out->string);
            return i + out->size;
        }
    }
}

static size_t parse_json_pair(const char *json, char *key, JSONValue *value) {
    size_t i = 0;
    while (is_whitespace(json[i])) i++;

    i += parse_json_string(json + i, key);

    while (is_whitespace(json[i])) i++;

    i++; // Skip the colon

    i += parse_json_value(json + i, value);

    return i;
}

static size_t parse_json_string(const char *json, char *out) {
    size_t i = 1;
    char *start = out;

    while (json[i] != '\"') {
        if (json[i] == '\\') i++;
        *out++ = json[i++];
    }

    *out = '\0';

    return i;
}

static size_t parse_json_number(const char *json, char *out) {
    size_t i = 0;
    bool is_float = false;

    if (json[i] == '-') {
        *out++ = '-';
        i++;
    }

    while (is_digit(json[i])) {
        *out++ = json[i++];
    }

    if (json[i] == '.') {
        is_float = true;

        *out++ = '.';
        i++;

        while (is_digit(json[i])) {
            *out++ = json[i++];
        }
    }

    if (tolower(json[i]) == 'e') {
        is_float = true;

        *out++ = 'e';
        i++;

        if (json[i] == '+' || json[i] == '-') {
            *out++ = json[i++];
        }

        while (is_digit(json[i])) {
            *out++ = json[i++];
        }
    }

    if (!is_float) {
        *out = '\0';
        return i;
    }

    *out = '\0';
    return i;
}

static size_t parse_json_boolean(const char *json, JSONValue *out) {
    out->type = tolower(json[0]) == 't' ? JSON_TRUE : JSON_FALSE;
    out->size = out->type == JSON_TRUE ? 4 : 5;
    return out->size;
}

static bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

static bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

static bool is_decimal(char c) {
    return c == '.';
}