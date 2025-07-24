//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define maximum length of a JSON string
#define MAX_LEN 100000

// declare a struct for a JSON object
typedef struct json_obj {
    char *key;
    char *value;
} json_obj;

// function to trim whitespace from a string
char* trim_whitespace(char *str) {
    int left = 0, right = strlen(str)-1;
    while (isspace(str[left])) left++;
    while (isspace(str[right])) right--;
    str[right+1] = '\0';
    return &str[left];
}

// function to parse a single key-value pair from a JSON string
json_obj* parse_key_value(char *str) {
    char *key_start = strchr(str, '"') + 1;
    char *key_end = strchr(key_start, '"');
    char *value_start = strchr(key_end, ':') + 1;
    char *value_end;
    if (*value_start == '{') {
        int bracket_count = 1;
        value_start++;
        while (bracket_count > 0) {
            if (*value_start == '{') bracket_count++;
            else if (*value_start == '}') bracket_count--;
            value_start++;
        }
        value_end = value_start;
    } else if (*value_start == '[') {
        int bracket_count = 1;
        value_start++;
        while (bracket_count > 0) {
            if (*value_start == '[') bracket_count++;
            else if (*value_start == ']') bracket_count--;
            value_start++;
        }
        value_end = value_start;
    } else {
        value_end = strchr(value_start, ',') - 1;
        if (*value_end == '}') value_end--;
        if (*value_end == ']') value_end--;
    }
    json_obj *pair = malloc(sizeof(json_obj));
    pair->key = strndup(key_start, key_end - key_start);
    pair->value = strndup(value_start, value_end - value_start + 1);
    return pair;
}

// function to parse a JSON string into an array of key-value pairs
json_obj** parse_json(char *str) {
    json_obj **pairs = malloc(MAX_LEN * sizeof(json_obj*));
    int count = 0;
    char *sub_str = NULL;
    while ((sub_str = strstr(str, "{")) != NULL) {
        sub_str++;
        int bracket_count = 1;
        while (bracket_count > 0) {
            if (*sub_str == '{') bracket_count++;
            else if (*sub_str == '}') bracket_count--;
            sub_str++;
        }
        sub_str--;
        char *json_str = strndup(str, sub_str - str + 1);
        pairs[count++] = parse_key_value(json_str);
        free(json_str);
        str = sub_str + 1;
    }
    pairs[count] = NULL;
    return pairs;
}

// function to print a single key-value pair
void print_pair(json_obj *pair) {
    printf("'%s': '%s'\n", pair->key, trim_whitespace(pair->value));
}

// function to print an array of key-value pairs
void print_pairs(json_obj **pairs) {
    for (int i = 0; pairs[i] != NULL; i++) {
        printf("Object %d:\n", i+1);
        print_pair(pairs[i]);
        printf("\n");
    }
}

int main() {
    char json_string[] = "{ \"name\": \"John Doe\", \"age\": 42, \"address\": { \"street\": \"123 Main St\", \"city\": \"Anytown\", \"state\": \"CA\", \"zip\": \"12345\" }, \"hobbies\": [ \"reading\", \"swimming\", \"hiking\" ] }";
    
    json_obj **pairs = parse_json(json_string);
    print_pairs(pairs);
    
    return 0;
}