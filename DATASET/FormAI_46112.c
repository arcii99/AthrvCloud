//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JSON_SIZE 1024

/* JSON Value Types: */
enum json_value_type {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
};

/* JSON Value Struct: */
typedef struct _json_value {
    enum json_value_type type;
    union {
        char* string_val;
        double number_val;
        struct _json_object* obj_val;
        struct _json_array* arr_val;
        bool bool_val;
    };
} json_value;

/* JSON Object Struct: */
typedef struct _json_object {
    char name[100];
    json_value* value;
    struct _json_object* next;
} json_object;

/* JSON Array Struct: */
typedef struct _json_array {
    json_value* values[MAX_JSON_SIZE];
    int size;
} json_array;

/* JSON Parser Function Prototype: */
void parse_json(char* json_str, json_value* root_val);

/* Helper Functions: */
json_value* parse_value(char** json_str);
json_object* parse_object(char** json_str);
json_array* parse_array(char** json_str);
char* parse_string(char** json_str);
double parse_number(char** json_str);
char* strip_white_space(char* str);
void print_json_value(json_value* val);
void free_json_value(json_value* val);

/* Main Function: */
int main() {
    /* Example JSON string to parse: */
    char json_str[MAX_JSON_SIZE] = "{\"name\": \"John Doe\", \"age\": 32, \"isMarried\": false, \"hobbies\": [\"reading\", \"writing\", \"running\"]}";

    /* Parse JSON String: */
    json_value* root_val = malloc(sizeof(json_value));
    parse_json(json_str, root_val);

    /* Print JSON Value: */
    print_json_value(root_val);

    /* Free JSON Value: */
    free_json_value(root_val);

    return 0;
}

/* JSON Parser Function Definitions: */
void parse_json(char* json_str, json_value* root_val) {
    /* Strip White Space: */
    json_str = strip_white_space(json_str);

    /* Check if JSON Object or JSON Array: */
    if (json_str[0] == '{') {
        root_val->type = JSON_OBJECT;
        root_val->obj_val = parse_object(&json_str);
    }
    else if (json_str[0] == '[') {
        root_val->type = JSON_ARRAY;
        root_val->arr_val = parse_array(&json_str);
    }
}

json_value* parse_value(char** json_str) {
    /* Strip White Space: */
    *json_str = strip_white_space(*json_str);

    /* Determine Value Type: */
    json_value* val = malloc(sizeof(json_value));
    switch ((*json_str)[0]) {
        case '\"':
            val->type = JSON_STRING;
            val->string_val = parse_string(json_str);
            break;
        case '{':
            val->type = JSON_OBJECT;
            val->obj_val = parse_object(json_str);
            break;
        case '[':
            val->type = JSON_ARRAY;
            val->arr_val = parse_array(json_str);
            break;
        case 't':
            val->type = JSON_TRUE;
            val->bool_val = true;
            *json_str += 4; /* skip 'true' */
            break;
        case 'f':
            val->type = JSON_FALSE;
            val->bool_val = false;
            *json_str += 5; /* skip 'false' */
            break;
        case 'n':
            val->type = JSON_NULL;
            *json_str += 4; /* skip 'null' */
            break;
        default:
            val->type = JSON_NUMBER;
            val->number_val = parse_number(json_str);
            break;
    }

    return val;
}

json_object* parse_object(char** json_str) {
    /* Strip White Space: */
    *json_str = strip_white_space(*json_str);

    /* Create Object: */
    json_object* obj = NULL;
    json_object* cur_obj = NULL;
    while (**json_str && **json_str != '}') {
        /* Parse Object Name: */
        char* name = parse_string(json_str);

        /* Create Object Value: */
        *json_str = strip_white_space(*json_str);
        if (**json_str != ':') {
            /* Error: Expected ':' */
            printf("Error: Expected ':'\n");
            return NULL;
        }
        (*json_str)++;
        json_value* val = parse_value(json_str);

        /* Add Object to List: */
        if (obj == NULL) {
            obj = malloc(sizeof(json_object));
            strcpy(obj->name, name);
            obj->value = val;
            obj->next = NULL;
            cur_obj = obj;
        }
        else {
            cur_obj->next = malloc(sizeof(json_object));
            cur_obj = cur_obj->next;
            strcpy(cur_obj->name, name);
            cur_obj->value = val;
            cur_obj->next = NULL;
        }

        /* Strip White Space: */
        *json_str = strip_white_space(*json_str);

        /* Check if End of Object or Next Object: */
        if (**json_str == '}') {
            break;
        }
        else if (**json_str != ',') {
            /* Error: Expected ',' */
            printf("Error: Expected ','\n");
            return NULL;
        }
        (*json_str)++;
    }

    /* Move to Next Char: */
    (*json_str)++;

    return obj;
}

json_array* parse_array(char** json_str) {
    /* Strip White Space: */
    *json_str = strip_white_space(*json_str);

    /* Create Array: */
    json_array* arr = malloc(sizeof(json_array));
    int size = 0;
    while (**json_str && **json_str != ']') {
        /* Parse Array Value: */
        json_value* val = parse_value(json_str);

        /* Add Value to List: */
        arr->values[size++] = val;

        /* Strip White Space: */
        *json_str = strip_white_space(*json_str);

        /* Check if End of Array or Next Value: */
        if (**json_str == ']') {
            break;
        }
        else if (**json_str != ',') {
            /* Error: Expected ',' */
            printf("Error: Expected ','\n");
            return NULL;
        }
        (*json_str)++;
    }

    /* Move to Next Char: */
    (*json_str)++;

    /* Set Array Size: */
    arr->size = size;

    return arr;
}

char* parse_string(char** json_str) {
    int size = 0;
    char* str = malloc(MAX_JSON_SIZE);
    (*json_str)++; /* skip '\"' */
    while (**json_str && **json_str != '\"') {
        str[size++] = **json_str;
        (*json_str)++; /* move to next char */
    }
    (*json_str)++; /* skip '\"' */
    str[size] = '\0'; /* add terminating character */
    return str;
}

double parse_number(char** json_str) {
    int size = 0;
    char buffer[MAX_JSON_SIZE];
    while (**json_str && (**json_str == '-' || (**json_str >= '0' && **json_str <= '9') || **json_str == '.')) {
        buffer[size++] = **json_str;
        (*json_str)++; /* move to next char */
    }
    buffer[size] = '\0'; /* add terminating character */
    double num = atof(buffer);
    return num;
}

char* strip_white_space(char* str) {
    int size = strlen(str);
    char* new_str = malloc(MAX_JSON_SIZE);
    int new_size = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\r') {
            new_str[new_size++] = str[i];
        }
    }
    new_str[new_size] = '\0'; /* add terminating character */
    return new_str;
}

void print_json_value(json_value* val) {
    switch (val->type) {
        case JSON_STRING:
            printf("String: %s\n", val->string_val);
            break;
        case JSON_NUMBER:
            printf("Number: %f\n", val->number_val);
            break;
        case JSON_OBJECT:
            printf("Object:\n");
            json_object* obj = val->obj_val;
            while (obj != NULL) {
                printf("\tName: %s\n\tValue:\n", obj->name);
                print_json_value(obj->value);
                obj = obj->next;
            }
            break;
        case JSON_ARRAY:
            printf("Array:\n");
            json_array* arr = val->arr_val;
            for (int i = 0; i < arr->size; i++) {
                printf("\tValue:\n");
                print_json_value(arr->values[i]);
            }
            break;
        case JSON_TRUE:
            printf("Boolean: true\n");
            break;
        case JSON_FALSE:
            printf("Boolean: false\n");
            break;
        case JSON_NULL:
            printf("Null\n");
            break;
    }
}

void free_json_value(json_value* val) {
    switch (val->type) {
        case JSON_STRING:
            free(val->string_val);
            break;
        case JSON_OBJECT:
            json_object* obj = val->obj_val;
            while (obj != NULL) {
                free(obj->value);
                json_object* tmp_obj = obj;
                obj = obj->next;
                free(tmp_obj);
            }
            break;
        case JSON_ARRAY:
            json_array* arr = val->arr_val;
            for (int i = 0; i < arr->size; i++) {
                free_json_value(arr->values[i]);
            }
            break;
        default:
            break;
    }
    free(val);
}