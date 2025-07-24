//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    STRING,
    NUMBER,
    OBJECT,
    ARRAY,
    TRUE,
    FALSE,
    NULL_VALUE
} json_type;

typedef union {
    char *string;
    double number;
    struct json_object *object;
    struct json_array *array;
} json_data;

struct json_node {
    json_type type;
    json_data data;
};

struct json_pair {
    char *key;
    struct json_node value;
};

struct json_object {
    int size;
    struct json_pair *pairs;
};

struct json_array {
    int size;
    struct json_node *values;
};

struct json_parser {
    char *data;
    unsigned int index;
    unsigned int size;
};

int is_whitespace(char c) {
    return c == '\n' || c == ' ' || c == '\t' || c == '\r';
}

int is_delimiter(char c) {
    return c == ',' || c == ':' || c == '{' || c == '}' || c == '[' || c == ']';
}

char *get_string(struct json_parser *parser) {
    char *string = malloc(parser->size);
    unsigned int i = 0;
    while (parser->data[parser->index] != '\"' && i < parser->size) {
        if (parser->data[parser->index] == '\\') {
            parser->index++;
            switch (parser->data[parser->index]) {
                case '\"':
                    string[i] = '\"';
                    break;
                case '\\':
                    string[i] = '\\';
                    break;
                case '/':
                    string[i] = '/';
                    break;
                case 'b':
                    string[i] = '\b';
                    break;
                case 'f':
                    string[i] = '\f';
                    break;
                case 'n':
                    string[i] = '\n';
                    break;
                case 'r':
                    string[i] = '\r';
                    break;
                case 't':
                    string[i] = '\t';
                    break;
                default:
                    break;
            }
        } else {
            string[i] = parser->data[parser->index];
        }
        parser->index++;
        i++;
    }
    string[i] = 0;
    parser->index++;
    return string;
}

double get_number(struct json_parser *parser) {
    char number[255];
    int i = 0;
    while (isdigit(parser->data[parser->index])) {
        number[i] = parser->data[parser->index];
        i++;
        parser->index++;
    }
    if (parser->data[parser->index] == '.') {
        number[i] = parser->data[parser->index];
        i++;
        parser->index++;
        while (isdigit(parser->data[parser->index])) {
            number[i] = parser->data[parser->index];
            i++;
            parser->index++;
        }
    }
    number[i] = 0;
    return atof(number);
}

struct json_node get_node(struct json_parser *parser);

struct json_object get_object(struct json_parser *parser) {
    struct json_object object;
    object.size = 0;
    object.pairs = NULL;

    parser->index++;
    while (!is_whitespace(parser->data[parser->index]) && parser->data[parser->index] != '}') {
        char *key = get_string(parser);
        parser->index++;

        struct json_node value = get_node(parser);

        object.size++;
        object.pairs = realloc(object.pairs, object.size * sizeof(struct json_pair));
        struct json_pair new_pair;
        new_pair.key = key;
        new_pair.value = value;

        object.pairs[object.size-1] = new_pair;

        if (parser->data[parser->index] == '}') {
            break;
        }

        parser->index++;
    }
    parser->index++;
    return object;
}

struct json_array get_array(struct json_parser *parser) {
    struct json_array array;
    array.size = 0;
    array.values = NULL;

    parser->index++;
    while (!is_whitespace(parser->data[parser->index]) && parser->data[parser->index] != ']') {
        struct json_node value = get_node(parser);

        array.size++;
        array.values = realloc(array.values, array.size * sizeof(struct json_node));

        array.values[array.size-1] = value;

        if (parser->data[parser->index] == ']') {
            break;
        }
        parser->index++;
    }
    parser->index++;
    return array;
}

struct json_node get_node(struct json_parser *parser) {
    struct json_node node;

    while (is_whitespace(parser->data[parser->index])) {
        parser->index++;
    }

    if (parser->data[parser->index] == '\"') {
        node.type = STRING;
        node.data.string = get_string(parser);
    } else if (isdigit(parser->data[parser->index])) {
        node.type = NUMBER;
        node.data.number = get_number(parser);
    } else if (parser->data[parser->index] == '{') {
        node.type = OBJECT;
        node.data.object = malloc(sizeof(struct json_object));
        *node.data.object = get_object(parser);
    } else if (parser->data[parser->index] == '[') {
        node.type = ARRAY;
        node.data.array = malloc(sizeof(struct json_array));
        *node.data.array = get_array(parser);
    } else if (parser->data[parser->index] == 't') {
        node.type = TRUE;
        parser->index += 4;
    } else if (parser->data[parser->index] == 'f') {
        node.type = FALSE;
        parser->index += 5;
    } else if (parser->data[parser->index] == 'n') {
        node.type = NULL_VALUE;
        parser->index += 4;
    } else {
        node.type = NULL_VALUE;
    }

    while (is_whitespace(parser->data[parser->index])) {
        parser->index++;
    }

    return node;
}

struct json_node parse_json(char *data) {
    struct json_parser parser;
    parser.data = data;
    parser.size = strlen(data);
    parser.index = 0;
    return get_node(&parser);
}

int main() {
    char *example = "{ \"greeting\" : \"hello\", \"number\" : 42, \"nested\" : { \"inner_greeting\" : \"hi\" }, \"array\" : [ 1, 2, 3 ] }";
    struct json_node root = parse_json(example);
    printf("%s\n", root.data.object->pairs[0].value.data.string);
    printf("%f\n", root.data.object->pairs[1].value.data.number);
    printf("%s\n", root.data.object->pairs[2].value.data.object->pairs[0].value.data.string);
    printf("%f\n", root.data.object->pairs[3].value.data.array->values[2].data.number);
    return 0;
}