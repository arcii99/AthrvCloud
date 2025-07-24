//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100
#define MAX_JSON_DEPTH 10

// Struct to store JSON value
typedef struct {
    int type; // 0:null, 1:boolean, 2:number, 3:string, 4:object, 5:array
    union {
        int boolean;
        double number;
        char string[MAX_STRING_LEN];
        struct {
            char *keys[MAX_STRING_LEN];
            struct json_value *values[MAX_STRING_LEN];
            int size;
        } object;
        struct {
            struct json_value *values[MAX_STRING_LEN];
            int size;
        } array;
    } data;
} json_value;

// Helper function to trim whitespace characters
char *trim(char *str) {
    if (str == NULL) {
        return NULL;
    }
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (*start && isspace(*start)) {
        start++;
    }
    while (end > start && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    return start;
}

// Parse JSON string recursively and returns a JSON value, only supports basic data types
json_value *parse_json(char *str, int depth) {
    if (depth > MAX_JSON_DEPTH) {
        printf("Error: Maximum JSON depth exceeded\n");
        return NULL;
    }
    json_value *value = (json_value *) malloc(sizeof(json_value));
    memset(value, 0, sizeof(json_value));
    char *trimmed_str = trim(str);
    if (strlen(trimmed_str) == 0) {
        value->type = 0;
        value->data.boolean = 0;
        return value;
    }
    switch (*trimmed_str) {
        case 'n':
            value->type = 0;
            value->data.boolean = 0;
            break;
        case 't':
            value->type = 1;
            value->data.boolean = 1;
            break;
        case 'f':
            value->type = 1;
            value->data.boolean = 0;
            break;
        case '{': {
            value->type = 4;
            char *end = strchr(str, '}');
            if (end == NULL) {
                printf("Error: Invalid JSON object\n");
                return NULL;
            }
            *end = '\0';
            char *token = strtok(str + 1, ",");
            while (token != NULL) {
                char *key = strtok(token, ":");
                char *val = strtok(NULL, ":");
                if (key != NULL && val != NULL) {
                    key = trim(key);
                    val = trim(val);
                    json_value *sub_val = parse_json(val, depth + 1);
                    value->data.object.keys[value->data.object.size] = key;
                    value->data.object.values[value->data.object.size] = sub_val;
                    value->data.object.size++;
                }
                token = strtok(NULL, ",");
            }
            break;
        }
        case '[': {
            value->type = 5;
            char *end = strchr(str, ']');
            if (end == NULL) {
                printf("Error: Invalid JSON array\n");
                return NULL;
            }
            *end = '\0';
            char *token = strtok(str + 1, ",");
            while (token != NULL) {
                json_value *sub_val = parse_json(token, depth + 1);
                value->data.array.values[value->data.array.size] = sub_val;
                value->data.array.size++;
                token = strtok(NULL, ",");
            }
            break;
        }
        case '\"': {
            value->type = 3;
            char *end = strchr(str + 1, '\"');
            if (end == NULL) {
                printf("Error: Invalid JSON string\n");
                return NULL;
            }
            strncpy(value->data.string, str + 1, end - str - 1);
            value->data.string[end - str - 1] = '\0';
            break;
        }
        default: {
            value->type = 2;
            value->data.number = atof(trimmed_str);
            break;
        }
    }
    return value;
}

// Helper function to print JSON value recursively
void print_json(json_value *value, int depth) {
    if (depth > MAX_JSON_DEPTH) {
        printf("Error: Maximum JSON depth exceeded\n");
        return;
    }
    switch (value->type) {
        case 0:
            printf("null");
            break;
        case 1:
            printf(value->data.boolean ? "true" : "false");
            break;
        case 2:
            printf("%g", value->data.number);
            break;
        case 3:
            printf("\"%s\"", value->data.string);
            break;
        case 4:
            printf("{\n");
            for (int i = 0; i < value->data.object.size; i++) {
                for (int j = 0; j < depth; j++) {
                    printf("  ");
                }
                printf("\"%s\": ", value->data.object.keys[i]);
                print_json(value->data.object.values[i], depth + 1);
                if (i < value->data.object.size - 1) {
                    printf(",\n");
                } else {
                    printf("\n");
                }
            }
            for (int j = 0; j < depth - 1; j++) {
                printf("  ");
            }
            printf("}");
            break;
        case 5:
            printf("[\n");
            for (int i = 0; i < value->data.array.size; i++) {
                for (int j = 0; j < depth; j++) {
                    printf("  ");
                }
                print_json(value->data.array.values[i], depth + 1);
                if (i < value->data.array.size - 1) {
                    printf(",\n");
                } else {
                    printf("\n");
                }
            }
            for (int j = 0; j < depth - 1; j++) {
                printf("  ");
            }
            printf("]");
            break;
        default:
            printf("Error: Invalid JSON value\n");
            break;
    }
}

int main() {
    char *input = "{\"name\":\"John\", \"age\":30, \"isMarried\":false, \"phones\":[\"123456\", \"7890\"]}";
    json_value *value = parse_json(input, 0);
    if (value != NULL) {
        print_json(value, 0);
        printf("\n");
    }
    return 0;
}