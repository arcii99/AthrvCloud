//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
// Minimalist JSON Parser in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1000

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
} json_type;

typedef struct {
    json_type type;
    union {
        char *string;
        double number;
        struct {
            char *key;
            struct json_value_t *value;
        } object;
        struct json_value_t *array;
    } value;
    struct json_value_t *next;
} json_value_t;

json_value_t* parse_json(char *json) {
    char *start = json;
    char *end = json + strlen(json);
    json_value_t* root = malloc(sizeof(json_value_t));
    json_value_t* current = root;

    while (start < end) {
        switch (*start) {
            case '{': 
              current->type = JSON_OBJECT;
              current->value.object.key = NULL;
              current->value.object.value = parse_json(start+1);
              break;
            
            case '}':
              current->next = NULL;
              return root;

            case ':':
              current->value.object.key = malloc(sizeof(char) * 50);
              strncpy(current->value.object.key, json+1, start-json-2);
              current->value.object.key[start-json-2] = '\0';
              current->value.object.value = parse_json(start+1);
              current->next = malloc(sizeof(json_value_t));
              current = current->next;
              break;
            
            case ',':
              current->next = malloc(sizeof(json_value_t));
              current = current->next;
              current->type = JSON_OBJECT;
              current->value.object.key = NULL;
              current->value.object.value = parse_json(start+1);
              break;

            case '[':
              current->type = JSON_ARRAY;
              current->value.array = parse_json(start+1);
              break;

            case ']':
              current->next = NULL;
              return root;

            case '\"':
              char *start_str = start+1;
              while (*(++start) != '\"');
              int len_str = start - start_str;
              current->type = JSON_STRING;
              current->value.string = malloc(sizeof(char) * (len_str+1));
              strncpy(current->value.string, start_str, len_str);
              current->value.string[len_str] = '\0';
              break;

            case 't':
              current->type = JSON_TRUE;
              break;
              
            case 'f':
              current->type = JSON_FALSE;
              break;
              
            case 'n':
              current->type = JSON_NULL;
              break;

            default:
              char *start_num = start;
              while (*start != ',' && *start != ']' && *start != '}' && *start != '\0') {
                ++start;
              }
              int len_num = start - start_num;
              current->type = JSON_NUMBER;
              current->value.number = atof(start_num);
              break;
        }
        ++start;
    }

  current->next = NULL;
  return root;
}

int main() {
    char json_str[MAX_JSON_SIZE] = "{\"name\":\"John\", \"age\":30, \"married\":true, \"grades\":[75,80,90]}";
    json_value_t* parsed_json = parse_json(json_str);

    // Printing the parsed json
    while (parsed_json != NULL) {
        switch(parsed_json->type) {
            case JSON_STRING:
              printf("String: %s\n", parsed_json->value.string);
              break;

            case JSON_NUMBER:
              printf("Number: %f\n", parsed_json->value.number);
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

            case JSON_OBJECT:
              printf("Object:\n");
              json_value_t* object = parsed_json->value.object.value;
              while (object != NULL) {
                printf("%s: ", parsed_json->value.object.key);
                parsed_json = parsed_json->value.object.value;
              }
              break;

            case JSON_ARRAY:
              printf("Array:\n");
              json_value_t* array = parsed_json->value.array;
              while (array != NULL) {
                switch(array->type) {
                    case JSON_STRING:
                      printf("String: %s\n", array->value.string);
                      break;

                    case JSON_NUMBER:
                      printf("Number: %f\n", array->value.number);
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
                array = array->next;
              }
              break;
        }
        parsed_json = parsed_json->next;
    }

    return 0;
}