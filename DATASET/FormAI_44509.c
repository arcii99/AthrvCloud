//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* defining the maximum size of the JSON string */
#define MAX_STRING_SIZE 1000

/* structure to represent JSON object */
struct json_object_t {
    char *key;
    char *value;
};

/* function to check if a character is digit */
int is_digit(char c) {
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

/* function to check if a character is a valid key character */
int is_valid_key_char(char c) {
    if(isalpha(c))
        return 1;
    if(c == '_')
        return 1;
    return 0;
}

/* function to create a JSON object from the string */
struct json_object_t parse_json_string(char *json_string) {
    struct json_object_t json_obj;

    int i = 0;
    int j = 0;
    char key[MAX_STRING_SIZE];
    char value[MAX_STRING_SIZE];

    /* validating the starting and ending braces */
    if(json_string[0] != '{' || json_string[strlen(json_string)-1] != '}') {
        printf("Invalid JSON string.\n");
        exit(1);
    }

    /* skipping the starting brace */
    i++;

    while(json_string[i] != '}') {
        /* skipping any white spaces or commas */
        if(json_string[i] == ' ' || json_string[i] == ',') {
            i++;
            continue;
        }

        /* parsing the key */
        j = 0;
        while(is_valid_key_char(json_string[i])) {
            key[j++] = json_string[i++];
        }
        key[j] = '\0';

        /* skipping any white spaces */
        while(json_string[i] == ' ')
            i++;

        /* validating the colon */
        if(json_string[i] != ':') {
            printf("Invalid JSON string.\n");
            exit(1);
        }

        /* skipping the colon */
        i++;

        /* skipping any white spaces */
        while(json_string[i] == ' ')
            i++;

        /* parsing the value */
        j = 0;
        if(json_string[i] == '"' || is_digit(json_string[i])) {
            while(json_string[i] != ',' && json_string[i] != '}') {
                value[j++] = json_string[i++];
            }
        } else {
            printf("Invalid JSON string.\n");
            exit(1);
        }
        value[j] = '\0';

        /* adding the key value pair to the JSON object */
        json_obj.key = strdup(key);
        json_obj.value = strdup(value);

        /* skipping any remaining white spaces */
        while(json_string[i] == ' ')
            i++;

        /* validating the comma */
        if(json_string[i] == ',') {
            i++;
            continue;
        } else if(json_string[i] != '}') {
            printf("Invalid JSON string.\n");
            exit(1);
        }
    }

    return json_obj;
}

/* main function to test the JSON parser */
int main() {
    char json_string[MAX_STRING_SIZE] = "{\"name\": \"John Doe\", \"age\": 25, \"is_married\": true}";
    struct json_object_t json_obj = parse_json_string(json_string);

    printf("Key : %s\nValue : %s\n", json_obj.key, json_obj.value);

    return 0;
}