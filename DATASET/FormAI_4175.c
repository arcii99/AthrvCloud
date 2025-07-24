//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LEN 50 // maximum length of a JSON string

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    int length;
    json_pair *pairs;
} json_object;

static char *json_string; // input JSON string

// Helper function to skip whitespace
static void skip_whitespace(char **str) {
    while (isspace(**str)) (*str)++;
}

// Helper function to get value of a string
static char *get_string(char **str) {
    char *string = malloc(MAX_STRING_LEN * sizeof(char));
    char *temp = string;

    (*str)++; // skip opening quote

    while (**str != '"') {
        *temp++ = **str;
        (*str)++;
    }

    *temp = '\0';
    (*str)++; // skip closing quote

    return string;
}

// Helper function to get value of a number
static double get_number(char **str) {
    double number = strtod(*str, str);
    return number;
}

// Helper function to get value of a boolean
static int get_boolean(char **str) {
    if (**str == 't') {
        *str += 4; // skip true
        return 1;
    }
    else {
        *str += 5; // skip false
        return 0;
    }
}

// Helper function to parse a JSON object
static json_object *parse_object(char **str) {
    json_object *json = malloc(sizeof(json_object));
    json->length = 0;
    json->pairs = NULL;

    (*str)++; // skip opening brace

    while (**str != '}') {
        skip_whitespace(str);

        // get key
        char *key = get_string(str);

        skip_whitespace(str);

        if (**str != ':') {
            printf("Error: Expected ':'\n");
            exit(1);
        }

        (*str)++; // skip colon

        skip_whitespace(str);

        // get value
        char value_type = **str;

        if (value_type == '"') { // value is a string
            char *value = get_string(str);
            json->length++;
            json->pairs = realloc(json->pairs, json->length * sizeof(json_pair));
            json->pairs[json->length - 1].key = key;
            json->pairs[json->length - 1].value = value;
        }
        else if (isdigit(value_type) || value_type == '-') { // value is a number
            double value = get_number(str);
            char *value_str = malloc(MAX_STRING_LEN * sizeof(char));
            snprintf(value_str, MAX_STRING_LEN, "%.2f", value);
            json->length++;
            json->pairs = realloc(json->pairs, json->length * sizeof(json_pair));
            json->pairs[json->length - 1].key = key;
            json->pairs[json->length - 1].value = value_str;
        }
        else if (value_type == 't' || value_type == 'f') { // value is a boolean
            int value = get_boolean(str);
            char *value_str = malloc(MAX_STRING_LEN * sizeof(char));
            snprintf(value_str, MAX_STRING_LEN, "%d", value);
            json->length++;
            json->pairs = realloc(json->pairs, json->length * sizeof(json_pair));
            json->pairs[json->length - 1].key = key;
            json->pairs[json->length - 1].value = value_str;
        }
        else if (value_type == '{') { // value is another object
            json_object *value = parse_object(str);
            json->length++;
            json->pairs = realloc(json->pairs, json->length * sizeof(json_pair));
            json->pairs[json->length - 1].key = key;
            json->pairs[json->length - 1].value = (char *) value;
        }
        else {
            printf("Error: Invalid value\n");
            exit(1);
        }

        skip_whitespace(str);

        if (**str != ',' && **str != '}') {
            printf("Error: Expected ',' or '}'\n");
            exit(1);
        }

        if (**str == ',') (*str)++; // skip comma
    }

    (*str)++; // skip closing brace

    return json;
}

// Main function
int main() {
    json_string = "{ \"name\": \"John\", \"age\": 30, \"isMarried\": false, \"address\": { \"street\": \"123 Main St\", \"city\": \"New York\", \"state\": \"NY\", \"zip\": \"10001\" } }";

    char *json_string_copy = malloc(strlen(json_string) * sizeof(char));
    strcpy(json_string_copy, json_string);

    json_object *json = parse_object(&json_string_copy);

    for (int i = 0; i < json->length; i++) {
        printf("%s: %s\n", json->pairs[i].key, json->pairs[i].value);
    }

    return 0;
}