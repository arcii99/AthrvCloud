//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: irregular
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
    JSON_NULL
} json_type;

struct json_item {
    json_type type;
    union {
        char* str_value;
        double num_value;
        struct json_item* items;
    } value;
};

int skip_whitespace(char* input, int pos) {
    while (isspace(input[pos])) {
        pos++;
    }
    return pos;
}

int parse_string(char* input, int pos, char** str) {
    int len = 0;
    int start = pos + 1;
    while (input[start + len] != '\"') {
        if (input[start + len] == '\\') {
            len++;
        }
        len++;
    }
    *str = malloc(len + 1);
    int index = 0;
    for (int i = start; i < start + len; i++) {
        if (input[i] == '\\') {
            i++;
            switch (input[i]) {
                case 'n':
                    (*str)[index++] = '\n';
                    break;
                case 't':
                    (*str)[index++] = '\t';
                    break;
                case 'r':
                    (*str)[index++] = '\r';
                    break;
                default:
                    (*str)[index++] = input[i];
                    break;
            }
        } else {
            (*str)[index++] = input[i];
        }
    }
    (*str)[index] = '\0';
    return start + len + 1;
}

int parse_number(char* input, int pos, double* num) {
    char* end;
    *num = strtod(input + pos, &end);
    return end - input;
}

int parse_literal(char* input, int pos, json_type type) {
    char* literals[] = {"true", "false", "null"};
    int literal_lens[] = {4, 5, 4};
    int i;
    for (i = 0; i < 3; i++) {
        if (strncmp(input + pos, literals[i], literal_lens[i]) == 0) {
            break;
        }
    }
    if (i < 3) {
        return pos + literal_lens[i];
    } else {
        return -1;
    }
}

struct json_item parse(char* input, int pos) {
    pos = skip_whitespace(input, pos);
    struct json_item item;
    switch (input[pos]) {
        case '{':
            item.type = JSON_OBJECT;
            pos++;
            item.value.items = malloc(sizeof(struct json_item));
            int num_items = 0;
            while (input[pos] != '}') {
                pos = skip_whitespace(input, pos);
                if (input[pos] == ',') {
                    pos = skip_whitespace(input, pos + 1);
                }
                pos = parse_string(input, pos, &(item.value.items[num_items].value.str_value));
                pos = skip_whitespace(input, pos);
                if (input[pos] != ':') {
                    fprintf(stderr, "colon expected\n");
                    exit(1);
                }
                pos = skip_whitespace(input, pos + 1);
                item.value.items[num_items] = parse(input, pos);
                num_items++;
                item.value.items = realloc(item.value.items, sizeof(struct json_item) * (num_items + 1));
            }
            pos++;
            break;
        case '[':
            item.type = JSON_ARRAY;
            pos++;
            item.value.items = malloc(sizeof(struct json_item));
            int num_elements = 0;
            while (input[pos] != ']') {
                pos = skip_whitespace(input, pos);
                if (input[pos] == ',') {
                    pos = skip_whitespace(input, pos + 1);
                }
                item.value.items[num_elements] = parse(input, pos);
                num_elements++;
                item.value.items = realloc(item.value.items, sizeof(struct json_item) * (num_elements + 1));
            }
            pos++;
            break;
        case '\"':
            item.type = JSON_STRING;
            pos = parse_string(input, pos, &(item.value.str_value));
            break;
        case '-':
        case '0'...'9':
            item.type = JSON_NUMBER;
            pos += parse_number(input, pos, &(item.value.num_value));
            break;
        default:
            int new_pos = parse_literal(input, pos, JSON_TRUE);
            if (new_pos != -1) {
                item.type = JSON_TRUE;
                pos = new_pos;
                break;
            }
            new_pos = parse_literal(input, pos, JSON_FALSE);
            if (new_pos != -1) {
                item.type = JSON_FALSE;
                pos = new_pos;
                break;
            }
            new_pos = parse_literal(input, pos, JSON_NULL);
            if (new_pos != -1) {
                item.type = JSON_NULL;
                pos = new_pos;
                break;
            }
            fprintf(stderr, "invalid input");
            exit(1);
    }
    return item;
}

int main() {
    char* input = "{\"name\":\"John\",\"age\":30,\"car\":null,\"numbers\":[1,2,3,4],\"fruits\":{\"apple\":10,\"banana\":5,\"orange\":23},\"isStudent\":true}";
    struct json_item result = parse(input, 0);
    printf("JSON object parsed successfully!\n");
    return 0;
}