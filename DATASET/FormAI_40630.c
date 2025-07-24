//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 5
#define MAX_KEY_LENGTH 20
#define MAX_VALUE_LENGTH 20

typedef enum {
    STRING,
    NUMBER,
    OBJECT,
    ARRAY,
    TRUE,
    FALSE,
    NULL_TYPE
} token_type;

typedef struct {
    token_type type;
    char* value;
} token;

typedef struct {
    char* key;
    token_type type;
    char* value;
} object_field;

typedef struct {
    object_field* fields;
    size_t num_fields;
} object;

typedef struct {
    token_type type;
    char* value;
    void* content; // pointer to the object or array that the token represents
} json_value;

typedef struct {
    json_value* values;
    size_t num_values;
} json_array;

typedef struct {
    object* values;
    size_t num_values;
} json_object;

// State variables
int depth = 0; // current depth of the parser
char* input; // string to parse
int input_len; // length of the input string
int input_pos = 0; // position within the input string
char c; // current character being read

// Functions to move the input cursor and check if we're at the end of the input
void next_char() {
    if (input_pos < input_len) {
        c = input[input_pos];
        input_pos++;
    } else {
        c = '\0';
    }
}

int at_end() {
    return c == '\0';
}

// Functions to read individual parts of the input
char* read_string() {
    char* str = malloc(MAX_VALUE_LENGTH * sizeof(char));
    int i = 0;
    next_char(); // skip starting quote
    while (!at_end() && c != '\"' && i < MAX_VALUE_LENGTH - 1) {
        str[i] = c;
        i++;
        next_char();
    }
    str[i] = '\0';
    next_char(); // skip ending quote
    return str;
}

char* read_number() {
    int i = 0;
    char* num_str = malloc(MAX_VALUE_LENGTH * sizeof(char));
    while (!at_end() && ((c >= '0' && c <= '9') || c == '.')) {
        num_str[i] = c;
        i++;
        next_char();
    }
    num_str[i] = '\0';
    return num_str;
}

char* read_key() {
    char* key = malloc(MAX_KEY_LENGTH * sizeof(char));
    int i = 0;
    next_char(); // skip beginning quote
    while (!at_end() && c != '\"' && i < MAX_KEY_LENGTH - 1) {
        key[i] = c;
        i++;
        next_char();
    }
    key[i] = '\0';
    next_char(); // skip ending quote
    return key;
}

token_type get_token_type() {
    switch (c) {
        case '{':
            return OBJECT;
        case '[':
            return ARRAY;
        case '\"':
            return STRING;
        case 't':
        case 'f':
            return TRUE;
        case 'n':
            return NULL_TYPE;
        default:
            return NUMBER;
    }
}

token read_token() {
    char* value;
    token_type type = get_token_type();
    if (type == STRING) {
        value = read_string();
    } else if (type == NUMBER) {
        value = read_number();
    } else {
        value = NULL;
    }
    token t = { type, value };
    return t;
}

object_field read_field() {
    object_field field;
    field.key = read_key();
    next_char(); // skip colon
    token t = read_token();
    field.type = t.type;
    field.value = t.value;
    return field;
}

object read_object() {
    object o;
    o.fields = malloc(sizeof(object_field) * MAX_KEY_LENGTH);
    int i = 0;
    next_char(); // skip opening brace
    while (!at_end() && c != '}' && i < MAX_KEY_LENGTH - 1) {
        o.fields[i] = read_field();
        next_char();
        i++;
    }
    o.fields[i].key = NULL;
    o.fields[i].type = NULL_TYPE;
    o.num_fields = i;
    return o;
}

json_array* read_array();

// Function to read a value from the input
json_value* read_value() {
    json_value* value = malloc(sizeof(json_value));
    token t = read_token();
    value->type = t.type;
    value->value = t.value;

    if (t.type == OBJECT) {
        value->content = malloc(sizeof(json_object));
        ((json_object*)value->content)->values = malloc(sizeof(object) * MAX_KEY_LENGTH);
        int i = 0;
        next_char(); // skip opening brace
        while (!at_end() && c != '}' && i < MAX_KEY_LENGTH - 1) {
            ((json_object*)value->content)->values[i] = read_object();
            next_char();
            i++;
        }
        ((json_object*)value->content)->values[i].fields = NULL;
        ((json_object*)value->content)->values[i].num_fields = 0;
    } else if (t.type == ARRAY) {
        value->content = read_array();
    } else {
        value->content = NULL;
    }

    return value;
}

json_array* read_array() {
    json_array* arr = malloc(sizeof(json_array));
    arr->values = malloc(sizeof(json_value) * MAX_VALUE_LENGTH);
    int i = 0;
    next_char(); // skip opening bracket
    while (!at_end() && c != ']' && i < MAX_VALUE_LENGTH - 1) {
        arr->values[i] = *read_value();
        next_char();
        i++;
    }
    arr->values[i].type = NULL_TYPE;
    arr->values[i].value = NULL;
    arr->values[i].content = NULL;
    arr->num_values = i;
    return arr;
}

json_value* parse_json(char* json_str) {
    input = json_str;
    input_len = strlen(json_str);
    next_char();
    json_value* root = read_value();
    if (!at_end()) {
        printf("Parsing error: unexpected character '%c' at position %d\n", c, input_pos);
        exit(EXIT_FAILURE);
    }
    return root;
}

// Example usage
int main() {
    char* json_str = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    json_value* value = parse_json(json_str);
    if (value->type == OBJECT) {
        printf("Parsed JSON object:\n");
        for (int i = 0; i < ((json_object*)value->content)->num_values; i++) {
            object o = ((json_object*)value->content)->values[i];
            for (int j = 0; j < o.num_fields; j++) {
                printf("%s: %s\n", o.fields[j].key, o.fields[j].value);
            }
        }
    }
    return 0;
}