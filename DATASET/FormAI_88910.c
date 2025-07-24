//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_OBJECT_MAX_LENGTH 100

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type;

typedef struct json_value {
    json_type type;
    char *key;
    union {
        char *string_value;
        double number_value;
        int boolean_value;
    };
    struct json_value *next;
    struct json_value *child;
} json_value;

json_value *json_parse_object(char *json_string, int *index);

int is_delimiter(char c) {
    return c == ',' || c == '}' || c == ']' || c == '{' || c == '[' || c == ':' || c == '"' || c == '\'' || c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

char *json_read_string(char *json_string, int *index) {
    int start = *index + 1;
    int end = start;
    int length = strlen(json_string);
    while (end < length && json_string[end] != '"') {
        if (json_string[end] == '\\' && end + 1 < length) {
            end += 2;
        }
        else {
            end++;
        }
    }
    if (end == length) {
        return NULL;
    }
    char *result = malloc(sizeof(char) * (end - start + 1));
    int i, j;
    for (i = start, j = 0; i < end; i++) {
        if (json_string[i] == '\\' && i + 1 < length) {
            switch (json_string[i + 1]) {
                case '"':
                case '\\':
                case '/':
                    result[j++] = json_string[i + 1];
                    i++;
                    break;
                case 'b':
                    result[j++] = '\b';
                    i++;
                    break;
                case 'f':
                    result[j++] = '\f';
                    i++;
                    break;
                case 'n':
                    result[j++] = '\n';
                    i++;
                    break;
                case 'r':
                    result[j++] = '\r';
                    i++;
                    break;
                case 't':
                    result[j++] = '\t';
                    i++;
                    break;
                case 'u': {
                    if (i + 5 < length) {
                        char unicode[5];
                        int k;
                        for (k = 0; k < 4; k++) {
                            unicode[k] = json_string[i + k + 2];
                        }
                        unicode[4] = '\0';
                        result[j++] = (char)strtol(unicode, NULL, 16);
                        i += 5;
                    }
                    else {
                        free(result);
                        return NULL;
                    }
                    break;
                }
                default:
                    free(result);
                    return NULL;
            }
        }
        else {
            result[j++] = json_string[i];
        }
    }
    result[j] = '\0';
    *index = end;
    return result;
}

json_value *json_parse_string(char *json_string, int *index) {
    char *value = json_read_string(json_string, index);
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_STRING;
    result->string_value = value;
    result->next = NULL;
    result->child = NULL;
    return result;
}

double json_read_number(char *json_string, int *index) {
    int start = *index;
    int end = start;
    int length = strlen(json_string);
    while (end < length && !is_delimiter(json_string[end])) {
        end++;
    }
    char *number_string = malloc(sizeof(char) * (end - start + 1));
    strncpy(number_string, json_string + start, end - start);
    number_string[end - start] = '\0';
    double number = atof(number_string);
    free(number_string);
    *index = end - 1;
    return number;
}

json_value *json_parse_number(char *json_string, int *index) {
    double value = json_read_number(json_string, index);
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_NUMBER;
    result->number_value = value;
    result->next = NULL;
    result->child = NULL;
    return result;
}

int json_read_boolean(char *json_string, int *index) {
    int start = *index;
    int end = start;
    int length = strlen(json_string);
    if (strncmp(json_string + start, "true", 4) == 0) {
        end = start + 4;
        *index = end - 1;
        return 1;
    }
    else if (strncmp(json_string + start, "false", 5) == 0) {
        end = start + 5;
        *index = end - 1;
        return 0;
    }
    else {
        return -1;
    }
}

json_value *json_parse_boolean(char *json_string, int *index) {
    int value = json_read_boolean(json_string, index);
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_BOOLEAN;
    result->boolean_value = value;
    result->next = NULL;
    result->child = NULL;
    return result;
}

json_value *json_parse_null(char *json_string, int *index) {
    char *value = json_read_string(json_string, index);
    if (strcmp(value, "null") != 0) {
        free(value);
        return NULL;
    }
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_NULL;
    result->next = NULL;
    result->child = NULL;
    return result;
}

json_value *json_parse_array(char *json_string, int *index) {
    json_value *result_head = NULL;
    json_value *result_tail = NULL;
    int length = strlen(json_string);
    int i = *index + 1;
    while (i < length && json_string[i] != ']') {
        json_value *value = json_parse_object(json_string, &i);
        if (value == NULL) {
            return NULL;
        }
        if (result_head == NULL) {
            result_head = value;
            result_tail = value;
        }
        else {
            result_tail->next = value;
            result_tail = value;
        }
        if (i >= length) {
            return NULL;
        }
        if (json_string[i] == ',') {
            i++;
        }
    }
    if (json_string[i] == ']') {
        *index = i;
        json_value *result = malloc(sizeof(json_value));
        result->type = JSON_ARRAY;
        result->child = result_head;
        result_tail->next = NULL;
        result->next = NULL;
        return result;
    }
    else {
        return NULL;
    }
}

json_value *json_parse_object(char *json_string, int *index) {
    json_value *result_head = NULL;
    json_value *result_tail = NULL;
    int length = strlen(json_string);
    int i = *index + 1;
    while (i < length && json_string[i] != '}') {
        if (json_string[i] != '"') {
            return NULL;
        }
        char *key = json_read_string(json_string, &i);
        if (key == NULL) {
            return NULL;
        }
        if (i >= length || json_string[i] != ':') {
            return NULL;
        }
        i++;
        json_value *value = json_parse_object(json_string, &i);
        if (value == NULL) {
            free(key);
            return NULL;
        }
        value->key = key;
        if (result_head == NULL) {
            result_head = value;
            result_tail = value;
        }
        else {
            result_tail->next = value;
            result_tail = value;
        }
        if (i >= length) {
            return NULL;
        }
        if (json_string[i] == ',') {
            i++;
        }
    }
    if (json_string[i] == '}') {
        *index = i;
        json_value *result = malloc(sizeof(json_value));
        result->type = JSON_OBJECT;
        result->child = result_head;
        result_tail->next = NULL;
        result->next = NULL;
        return result;
    }
    else {
        return NULL;
    }
}

json_value *json_parse(char *json_string) {
    if (json_string == NULL || strlen(json_string) == 0) {
        return NULL;
    }
    int index = -1;
    return json_parse_object(json_string, &index);
}

void json_print(json_value *value) {
    switch (value->type) {
        case JSON_OBJECT: {
            printf("{\n");
            json_value *child = value->child;
            while (child != NULL) {
                json_print(child);
                child = child->next;
                if (child != NULL) {
                    printf(",\n");
                }
            }
            printf("\n}");
            break;
        }
        case JSON_ARRAY: {
            printf("[\n");
            json_value *child = value->child;
            while (child != NULL) {
                json_print(child);
                child = child->next;
                if (child != NULL) {
                    printf(",\n");
                }
            }
            printf("\n]");
            break;
        }
        case JSON_STRING: {
            printf("\"%s\"", value->string_value);
            break;
        }
        case JSON_NUMBER: {
            printf("%lf", value->number_value);
            break;
        }
        case JSON_BOOLEAN: {
            printf("%s", value->boolean_value ? "true" : "false");
            break;
        }
        case JSON_NULL: {
            printf("null");
            break;
        }
    }
    if (value->key != NULL) {
        printf(": ");
    }
}

int main() {
    char json_string[JSON_OBJECT_MAX_LENGTH] = "{  \n\
   \"name\": \"John\",  \n\
   \"age\": 31,  \n\
   \"city\": \"New York\",  \n\
   \"happy\": true,  \n\
   \"grades\": [  \n\
      85,  \n\
      90,  \n\
      100  \n\
   ],  \n\
   \"pet\": {  \n\
      \"name\": \"Spot\",  \n\
      \"species\": \"dog\"  \n\
   }  \n\
}";
    json_value *value = json_parse(json_string);
    json_print(value);
    printf("\n");
    return 0;
}