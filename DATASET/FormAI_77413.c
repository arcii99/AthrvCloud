//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define maximum length of JSON string */
#define MAX_JSON_LENGTH 10000

/* Define maximum number of JSON elements */
#define MAX_JSON_ELEMENTS 1000

/* Define maximum length of a JSON element key */
#define MAX_KEY_LENGTH 100

/* Define maximum length of a JSON element value */
#define MAX_VALUE_LENGTH 1000

/* Define a structure to hold a single JSON element */
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} json_elem_t;

/* Define a structure to hold an entire JSON object */
typedef struct {
    json_elem_t elems[MAX_JSON_ELEMENTS];
    int num_elems;
} json_obj_t;

/* Parse the JSON string and store the result in the provided json_obj_t struct */
void parse_json(char *json_str, json_obj_t *json_obj) {
    int i = 0;
    int j = 0;
    int len = strlen(json_str);
    int parsing_string = 0;
    int parsing_key = 0;
    int parsing_value = 0;
    int elem_start = 0;
    int key_start = 0;
    int value_start = 0;
    char current_char;
    json_elem_t current_elem;
    
    /* Initialize the JSON object */
    json_obj->num_elems = 0;
    
    /* Loop through the entire JSON string */
    while (i < len) {
        /* Get the current character */
        current_char = json_str[i];
        
        /* Check if we are currently parsing a string */
        if (parsing_string) {
            /* Check if the current character is an escape character */
            if (current_char == '\\') {
                /* Skip the next character */
                i++;
            }
            /* Check if the current character ends the string */
            else if (current_char == '"') {
                /* Stop parsing the string */
                parsing_string = 0;
            }
        }
        /* Check if we are currently parsing a key */
        else if (parsing_key) {
            /* Check if the current character ends the key */
            if (current_char == ':') {
                /* Stop parsing the key and start parsing the value */
                parsing_key = 0;
                parsing_value = 1;
                
                /* Save the start position of the value */
                value_start = i + 1;
            }
            /* Check if we have exceeded the maximum key length */
            else if (j >= MAX_KEY_LENGTH) {
                /* Report an error and stop parsing */
                printf("Error: JSON key exceeds maximum length");
                return;
            }
            /* Save the current character in the key */
            else {
                current_elem.key[j] = current_char;
                j++;
            }
        }
        /* Check if we are currently parsing a value */
        else if (parsing_value) {
            /* Check if the current character starts a new JSON element */
            if (current_char == ',') {
                /* Stop parsing the value and start parsing the next key */
                parsing_value = 0;
                parsing_key = 1;
                
                /* Save the current JSON element */
                strncpy(current_elem.value, json_str + value_start, i - value_start);
                current_elem.value[i - value_start] = '\0';
                json_obj->elems[json_obj->num_elems] = current_elem;
                json_obj->num_elems++;
                
                /* Save the start position of the next key */
                key_start = i + 1;
                j = 0;
            }
            /* Check if the current character ends the entire JSON object */
            else if (current_char == '}') {
                /* Stop parsing the value */
                parsing_value = 0;
                
                /* Save the current JSON element */
                strncpy(current_elem.value, json_str + value_start, i - value_start);
                current_elem.value[i - value_start] = '\0';
                json_obj->elems[json_obj->num_elems] = current_elem;
                json_obj->num_elems++;
            }
            /* Save the current character in the value */
            else {
                current_elem.value[j] = current_char;
                j++;
            }
        }
        else {
            /* Check if the current character starts a new JSON element */
            if (current_char == ',') {
                /* Save the current key */
                strncpy(current_elem.key, json_str + key_start, i - key_start);
                current_elem.key[i - key_start] = '\0';
                
                /* Start parsing the value */
                parsing_value = 1;
                
                /* Save the start position of the value */
                value_start = i + 1;
                j = 0;
            }
            /* Check if the current character starts a new string */
            else if (current_char == '"') {
                /* Start parsing the string */
                parsing_string = 1;
                
                /* Save the start position of the string */
                elem_start = i + 1;
            }
            /* Check if the current character starts the entire JSON object */
            else if (current_char == '{') {
                /* Start parsing the key */
                parsing_key = 1;
                
                /* Save the start position of the first key */
                key_start = i + 1;
            }
        }
        
        /* Move to the next character */
        i++;
    }
}

/* Test the JSON parser */
int main() {
    /* Define a JSON object */
    json_obj_t my_json;
    
    /* Define a JSON string */
    char *my_json_str = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    
    /* Parse the JSON string */
    parse_json(my_json_str, &my_json);
    
    /* Print out the resulting JSON object */
    printf("Parsed JSON object:\n");
    int i;
    for (i = 0; i < my_json.num_elems; i++) {
        printf("%s: %s\n", my_json.elems[i].key, my_json.elems[i].value);
    }
    
    return 0;
}