//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// User-defined data types
typedef enum {
    JSON_NULL,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN
} json_value_type;

typedef struct json_object_t json_object_t;
typedef struct json_array_t json_array_t;

typedef struct json_string_t {
    char* value;
    size_t len;
} json_string_t;

typedef struct json_number_t {
    int value;
    int is_fractional;
} json_number_t;

typedef struct json_boolean_t {
    int value;
} json_boolean_t;

typedef union json_value_t {
    json_object_t* object;
    json_array_t* array;
    json_string_t* string;
    json_number_t* number;
    json_boolean_t* boolean;
} json_value_t;

typedef struct json_node_t {
    char* key;
    json_value_type type;
    json_value_t value;
} json_node_t;

struct json_object_t {
    int size;
    json_node_t** nodes;
};

struct json_array_t {
    int size;
    json_node_t** nodes; 
};

// Global variables
char input[1000];
int input_pos = 0;
int input_len;

// Helper functions
void skip_whitespace() {
    while (isspace(input[input_pos])) {
        input_pos++;
    }
}

void parse_string(json_string_t* value) {
    char* buffer = calloc(input_len, sizeof(char));
    int i = 0;
    input_pos++; // skip the starting quotation mark

    while (input_pos < input_len) {
        if (input[input_pos] == '"') {
            input_pos++;
            break;
        }
        buffer[i++] = input[input_pos++];
    }

    value->value = buffer;
    value->len = i;
}

void parse_number(json_number_t* value) {
    // TODO: implement
}

void parse_boolean(json_boolean_t* value) {
    // TODO: implement
}

json_node_t* parse_node() {
    json_node_t* node = malloc(sizeof(json_node_t));
    skip_whitespace();

    if (input[input_pos] == '{') {
        node->type = JSON_OBJECT;
        // TODO: implement
    }
    else if (input[input_pos] == '[') {
        node->type = JSON_ARRAY;
        // TODO: implement
    }
    else if (input[input_pos] == '"') {
        node->type = JSON_STRING;
        json_string_t* value = malloc(sizeof(json_string_t));
        parse_string(value);
        node->value.string = value;
    }
    else if (isdigit(input[input_pos])) {
        node->type = JSON_NUMBER;
        json_number_t* value = malloc(sizeof(json_number_t));
        parse_number(value);
        node->value.number = value;
    }
    else if (input[input_pos] == 't' || input[input_pos] == 'f') {
        node->type = JSON_BOOLEAN;
        json_boolean_t* value = malloc(sizeof(json_boolean_t));
        parse_boolean(value);
        node->value.boolean = value;
    }
    else if (input[input_pos] == 'n') {
        node->type = JSON_NULL;
        input_pos += 4; // skip "null"
    }

    return node;
}

json_node_t** parse_nodes(int* size) {
    (*size) = 0;
    json_node_t** nodes = malloc(sizeof(json_node_t*));
    int capacity = 1;
    skip_whitespace();

    if (input[input_pos] != ']') { // empty array
        while (1) {
            if ((*size) == capacity) {
                capacity *= 2;
                nodes = realloc(nodes, sizeof(json_node_t*) * capacity);
            }

            nodes[(*size)++] = parse_node();
            skip_whitespace();

            if (input[input_pos] == ']') {
                break;
            }

            input_pos++; // skip comma
            skip_whitespace();
        }
    }

    return nodes;
}

json_node_t** parse_kv_nodes(int* size) {
    (*size) = 0;
    json_node_t** nodes = malloc(sizeof(json_node_t*));
    int capacity = 1;
    skip_whitespace();

    if (input[input_pos] != '}') { // empty object
        while (1) {
            if ((*size) == capacity) {
                capacity *= 2;
                nodes = realloc(nodes, sizeof(json_node_t*) * capacity);
            }

            json_string_t* key = malloc(sizeof(json_string_t));
            parse_string(key);
            input_pos++; // skip colon
            skip_whitespace();

            json_node_t* node = parse_node();
            node->key = key->value;
            nodes[(*size)++] = node;

            skip_whitespace();

            if (input[input_pos] == '}') {
                break;
            }

            input_pos++; // skip comma
            skip_whitespace();
        }
    }

    return nodes;
}

// Main function
int main() {
    printf("Enter JSON input:\n");
    fgets(input, 1000, stdin);
    input_len = strlen(input) - 1; // discard newline
    json_node_t* root = parse_node();

    printf("Parsed JSON:\n");
    switch (root->type) {
    case JSON_OBJECT:
        printf("Object\n");
        break;
    case JSON_ARRAY:
        printf("Array\n");
        break;
    case JSON_STRING:
        printf("String: %s\n", root->value.string->value);
        break;
    case JSON_NUMBER:
        printf("Number: %d\n", root->value.number->value);
        break;
    case JSON_BOOLEAN:
        printf("Boolean: %s\n", root->value.boolean->value ? "true" : "false");
        break;
    case JSON_NULL:
        printf("Null\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }

    return 0;
}