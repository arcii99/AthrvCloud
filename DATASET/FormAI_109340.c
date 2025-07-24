//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef enum {
    JSON_TYPE_INVALID,
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY,
    JSON_TYPE_STRING,
    JSON_TYPE_NUMBER,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NULL,
} json_type_t;

typedef struct json_node_t {
    json_type_t type;
    char *key;
    char *value;
    int array_size;
    struct json_node_t **children;
} json_node_t;

json_node_t *json_parse_object(char *json_string, int length, int *position);
json_node_t *json_parse_array(char *json_string, int length, int *position);
json_node_t *json_parse_value(char *json_string, int length, int *position);
json_node_t *json_parse_string(char *json_string, int length, int *position);
json_node_t *json_parse_number(char *json_string, int length, int *position);
json_node_t *json_parse_boolean(char *json_string, int length, int *position);
json_node_t *json_parse_null(char *json_string, int length, int *position);
void json_delete_node(json_node_t *node);
void json_delete_children(json_node_t *node);

json_node_t *json_parse(char *json_string, int length) {
    int position = 0;
    return json_parse_value(json_string, length, &position);
}

json_node_t *json_parse_value(char *json_string, int length, int *position) {
    json_node_t *node = NULL;

    // Skip whitespace
    while (*position < length && json_string[*position] <= ' ') {
        (*position)++;
    }

    // Determine value type
    char c = json_string[*position];
    switch (c) {
        case '{':
            node = json_parse_object(json_string, length, position);
            break;
        case '[':
            node = json_parse_array(json_string, length, position);
            break;
        case '"':
            node = json_parse_string(json_string, length, position);
            break;
        case '-':
        case '0' ... '9':
            node = json_parse_number(json_string, length, position);
            break;
        case 't':
        case 'f':
            node = json_parse_boolean(json_string, length, position);
            break;
        case 'n':
            node = json_parse_null(json_string, length, position);
            break;
        default:
            fprintf(stderr, "Invalid value type at position %d\n", *position);
            break;
    }

    return node;
}

json_node_t *json_parse_object(char *json_string, int length, int *position) {
    (*position)++; // Skip '{'

    json_node_t *node = malloc(sizeof(json_node_t));
    node->type = JSON_TYPE_OBJECT;
    node->key = NULL;
    node->value = NULL;
    node->array_size = 0;
    node->children = NULL;

    int num_children = 0;
    while (*position < length && json_string[*position] != '}') {
        json_node_t *key_node = json_parse_string(json_string, length, position);

        // Ensure key/value pair separation by colon
        if (json_string[*position] != ':') {
            fprintf(stderr, "Invalid object format at position %d\n", *position);
            break;
        }
        (*position)++; // Skip ':'

        json_node_t *value_node = json_parse_value(json_string, length, position);

        // Add key/value pair to object node
        if (key_node && value_node) {
            num_children++;
            node->children = realloc(node->children, num_children * sizeof(json_node_t *));
            node->children[num_children-1] = key_node;
            node->children = realloc(node->children, num_children * sizeof(json_node_t *));
            node->children[num_children-1] = value_node;
        } else {
            json_delete_node(key_node);
            json_delete_node(value_node);
        }

        // Skip whitespace and commas
        while (*position < length && (json_string[*position] <= ' ' || json_string[*position] == ',')) {
            (*position)++;
        }
    }

    // If last character was not a '}', format was invalid
    if (json_string[*position] != '}') {
        fprintf(stderr, "Invalid object format at position %d\n", *position);
        json_delete_children(node);
        free(node);
        return NULL;
    }
    (*position)++; // Skip '}'

    node->array_size = num_children;
    return node;
}

json_node_t *json_parse_array(char *json_string, int length, int *position) {
    (*position)++; // Skip '['

    json_node_t *node = malloc(sizeof(json_node_t));
    node->type = JSON_TYPE_ARRAY;
    node->key = NULL;
    node->value = NULL;
    node->array_size = 0;
    node->children = NULL;

    int num_children = 0;
    while (*position < length && json_string[*position] != ']') {
        json_node_t *child_node = json_parse_value(json_string, length, position);

        // Add child to array node
        if (child_node) {
            num_children++;
            node->children = realloc(node->children, num_children * sizeof(json_node_t *));
            node->children[num_children-1] = child_node;
        } else {
            json_delete_node(child_node);
        }

        // Skip whitespace and commas
        while (*position < length && (json_string[*position] <= ' ' || json_string[*position] == ',')) {
            (*position)++;
        }
    }

    // If last character was not a ']', format was invalid
    if (json_string[*position] != ']') {
        fprintf(stderr, "Invalid array format at position %d\n", *position);
        json_delete_children(node);
        free(node);
        return NULL;
    }
    (*position)++; // Skip ']'

    node->array_size = num_children;
    return node;
}

json_node_t *json_parse_string(char *json_string, int length, int *position) {
    (*position)++; // Skip opening '"'

    // Find end of string
    int start = *position;
    int end = start;
    while (end < length && json_string[end] != '"') {
        if (json_string[end] == '\\' && end < length-1) {
            end++; // Skip over escape sequence
        }
        end++;
    }
    *position = end+1; // Skip closing '"'

    if (end >= length) {
        fprintf(stderr, "Invalid string format at position %d\n", *position);
        return NULL;
    }

    // Extract string and create string node
    char *str = malloc((end-start+1) * sizeof(char));
    strncpy(str, json_string+start, end-start);
    str[end-start] = '\0';

    json_node_t *node = malloc(sizeof(json_node_t));
    node->type = JSON_TYPE_STRING;
    node->key = NULL;
    node->value = str;
    node->array_size = 0;
    node->children = NULL;

    return node;
}

json_node_t *json_parse_number(char *json_string, int length, int *position) {
    // Find end of number
    int start = *position;
    int end = start;
    while (end < length) {
        char c = json_string[end];
        if (c == '-' || c == '+' || c == 'e' || c == 'E' || c == '.' || (c >= '0' && c <= '9')) {
            end++;
        } else {
            break;
        }
    }

    // Extract number and create number node
    char *str = malloc((end-start+1) * sizeof(char));
    strncpy(str, json_string+start, end-start);
    str[end-start] = '\0';

    json_node_t *node = malloc(sizeof(json_node_t));
    node->type = JSON_TYPE_NUMBER;
    node->key = NULL;
    node->value = str;
    node->array_size = 0;
    node->children = NULL;

    *position = end;
    return node;
}

json_node_t *json_parse_boolean(char *json_string, int length, int *position) {
    // Determine boolean value
    char c = json_string[*position];
    int end = (*position) + 1;
    if (c == 't' && length > end + 2 && strncmp(json_string+end, "rue", 3) == 0) {
        end += 3;
    } else if (c == 'f' && length > end + 3 && strncmp(json_string+end, "alse", 4) == 0) {
        end += 4;
    } else {
        fprintf(stderr, "Invalid boolean format at position %d\n", *position);
        return NULL;
    }

    // Extract boolean value and create boolean node
    char *str = malloc((end-(*position)) * sizeof(char));
    strncpy(str, json_string+(*position), end-(*position));
    str[end-(*position)] = '\0';

    json_node_t *node = malloc(sizeof(json_node_t));
    node->type = JSON_TYPE_BOOLEAN;
    node->key = NULL;
    node->value = str;
    node->array_size = 0;
    node->children = NULL;

    *position = end;
    return node;
}

json_node_t *json_parse_null(char *json_string, int length, int *position) {
    // Determine null value
    if (length < (*position) + 4 || strncmp(json_string+(*position), "null", 4) != 0) {
        fprintf(stderr, "Invalid null format at position %d\n", *position);
        return NULL;
    }

    // Extract null value and create null node
    char *str = malloc(5 * sizeof(char));
    strcpy(str, "null");

    json_node_t *node = malloc(sizeof(json_node_t));
    node->type = JSON_TYPE_NULL;
    node->key = NULL;
    node->value = str;
    node->array_size = 0;
    node->children = NULL;

    *position += 4;
    return node;
}

void json_delete_node(json_node_t *node) {
    if (!node) {
        return;
    }

    free(node->key);
    free(node->value);
    json_delete_children(node);
    free(node);
}

void json_delete_children(json_node_t *node) {
    if (!node || !node->children) {
        return;
    }

    for (int i = 0; i < node->array_size; i++) {
        json_delete_node(node->children[i]);
    }
    free(node->children);
}

int main(int argc, char *argv[]) {
    char json_string[MAX_JSON_SIZE];
    fgets(json_string, MAX_JSON_SIZE, stdin);
    json_node_t *root = json_parse(json_string, strlen(json_string));
    if (root) {
        printf("JSON parsed successfully!\n");
    } else {
        printf("Failed to parse JSON.\n");
    }
    json_delete_node(root);
    return 0;
}