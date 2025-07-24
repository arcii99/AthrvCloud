//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *json = "{\"name\":\"John Doe\", \"age\":30, \"city\":\"New York\"}";

typedef enum { STRING, NUMBER, OBJECT, ARRAY, BOOLEAN, NIL } json_type;

typedef struct json_value {
    json_type type;
    void *data;
    size_t size;
} json_value;

json_value *parse_json(char *json_string);
void free_json_value(json_value *value);
json_type get_json_type(char *json_string);

int main() {
    json_value *value = parse_json(json);
    if (value == NULL) {
        printf("Error parsing JSON");
        return 1;
    }

    char *name = (char *)value->data;
    int age = *(int *)value->data;
    char *city = (char *)(value->data + sizeof(int));

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("City: %s\n", city);

    free_json_value(value);
    return 0;
}

json_value *parse_json(char *json_string) {
    json_type type = get_json_type(json_string);
    if (type == OBJECT) {
        printf("Object parsing not implemented yet");
        return NULL;
    }
    if (type != ARRAY) {
        printf("JSON must start with an array");
        return NULL;
    }

    json_value *array = (json_value *)malloc(sizeof(json_value));
    array->type = ARRAY;
    array->size = 0;
    array->data = NULL;

    char *token;
    char *context;
    int i = 0;
    while ((token = strtok_r(json_string, ",", &context))) {
        i++;
        array->size = i;
        array->data = realloc(array->data, i * sizeof(json_value));

        json_type type = get_json_type(token);

        if (type == STRING) {
            json_value *string = (json_value *)malloc(sizeof(json_value));
            string->type = STRING;
            string->size = strlen(token) - 2;
            string->data = malloc(string->size + 1);
            strncpy((char *)string->data, token + 1, string->size);
            ((char *)string->data)[string->size] = '\0';

            ((json_value *)array->data)[i - 1] = *string;
            free_json_value(string);

        } else if (type == NUMBER) {
            json_value *number = (json_value *)malloc(sizeof(json_value));
            number->type = NUMBER;
            number->size = sizeof(int);
            number->data = malloc(number->size);
            *(int *)number->data = atoi(token);

            ((json_value *)array->data)[i - 1] = *number;
            free_json_value(number);
        } else {
            printf("Array elements must be strings or numbers");
            free_json_value(array);
            return NULL;
        }
        json_string = NULL;
    }
    return array;
}

json_type get_json_type(char *json_string) {
    if (*json_string == '{') return OBJECT;
    if (*json_string == '[') return ARRAY;
    if (*json_string == '\"') return STRING;
    if (*json_string == 't' || *json_string == 'f') return BOOLEAN;
    if (*json_string == 'n') return NIL;
    return NUMBER;
}

void free_json_value(json_value *value) {
    if (value->type == ARRAY) {
        json_value *array = (json_value *)value->data;
        for (int i = 0; i < value->size; i++) {
            free_json_value(&array[i]);
        }
        free(array);
    } else {
        free(value->data);
    }
    free(value);
}