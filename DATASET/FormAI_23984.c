//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define JSON_OBJECT_MAX_SIZE 100
#define JSON_VALUE_MAX_SIZE 50

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL,
} json_type_t;

typedef struct {
    char key[JSON_VALUE_MAX_SIZE];
    json_type_t type;
    void *value;
} json_element_t;

typedef struct {
    int size;
    json_element_t elements[JSON_OBJECT_MAX_SIZE];
} json_object_t;

static json_object_t *json_object_new();
static void json_object_free(json_object_t *obj);
static json_element_t *json_object_get(json_object_t *obj, const char *key);
static int json_parse_object(const char *str, int length, json_object_t *obj);
static int json_parse_string(const char *str, int length, char *out, int out_size);
static int json_parse_number(const char *str, int length, double *out);
static int json_parse_bool(const char *str, int length, bool *out);
static int json_parse_null(const char *str, int length);

static json_object_t *json_object_new() {
    json_object_t *obj = (json_object_t *)malloc(sizeof(json_object_t));
    if (obj == NULL) {
        return NULL;
    }
    obj->size = 0;
    return obj;
}

static void json_object_free(json_object_t *obj) {
    if (obj == NULL) {
        return;
    }
    for (int i = 0; i < obj->size; i++) {
        json_element_t *element = &obj->elements[i];
        free(element->value);
    }
    free(obj);
}

static json_element_t *json_object_get(json_object_t *obj, const char *key) {
    if (obj == NULL || key == NULL) {
        return NULL;
    }
    for (int i = 0; i < obj->size; i++) {
        json_element_t *element = &obj->elements[i];
        if (strcmp(element->key, key) == 0) {
            return element;
        }
    }
    return NULL;
}

static int json_parse_object(const char *str, int length, json_object_t *obj) {
    if (str[0] != '{') {
        return -1;
    }
    str++;
    length--;
    obj->size = 0;
    while (true) {
        if (length == 0) {
            return -1;
        }
        char key[JSON_VALUE_MAX_SIZE] = {0};
        int size = json_parse_string(str, length, key, JSON_VALUE_MAX_SIZE);
        if (size <= 0) {
            return -1;
        }
        str += size;
        length -= size;
        if (length == 0 || str[0] != ':') {
            return -1;
        }
        str++;
        length--;
        json_element_t *element = &obj->elements[obj->size];
        strncpy(element->key, key, JSON_VALUE_MAX_SIZE);
        if (str[0] == '{') {
            element->type = JSON_OBJECT;
            element->value = json_object_new();
            if (element->value == NULL) {
                return -1;
            }
            size = json_parse_object(str, length, (json_object_t *)element->value);
            if (size < 0) {
                json_object_free((json_object_t *)element->value);
                return -1;
            }
            str += size;
            length -= size;
        } else if (str[0] == '[') {
            element->type = JSON_ARRAY;
            // TODO: parse array
        } else if (str[0] == '"') {
            element->type = JSON_STRING;
            element->value = malloc(JSON_VALUE_MAX_SIZE);
            if (element->value == NULL) {
                return -1;
            }
            size = json_parse_string(str, length, (char *)element->value, JSON_VALUE_MAX_SIZE);
            if (size < 0) {
                free(element->value);
                return -1;
            }
            str += size;
            length -= size;
        } else if (isdigit(str[0]) || str[0] == '-') {
            element->type = JSON_NUMBER;
            element->value = malloc(sizeof(double));
            if (element->value == NULL) {
                return -1;
            }
            size = json_parse_number(str, length, (double *)element->value);
            if (size < 0) {
                free(element->value);
                return -1;
            }
            str += size;
            length -= size;
        } else if (strncmp(str, "true", 4) == 0 || strncmp(str, "false", 5) == 0) {
            element->type = JSON_BOOL;
            element->value = malloc(sizeof(bool));
            if (element->value == NULL) {
                return -1;
            }
            size = json_parse_bool(str, length, (bool *)element->value);
            if (size < 0) {
                free(element->value);
                return -1;
            }
            str += size;
            length -= size;
        } else if (strncmp(str, "null", 4) == 0) {
            element->type = JSON_NULL;
            size = json_parse_null(str, length);
            if (size < 0) {
                return -1;
            }
            str += size;
            length -= size;
        } else {
            return -1;
        }
        obj->size++;
        if (length == 0) {
            return -1;
        }
        if (str[0] == '}') {
            break;
        }
        if (str[0] != ',') {
            return -1;
        }
        str++;
        length--;
    }
    return length + 1;
}

static int json_parse_string(const char *str, int length, char *out, int out_size) {
    if (str[0] != '"') {
        return -1;
    }
    str++;
    length--;
    int pos = 0;
    while (pos < out_size - 1) {
        if (length == 0) {
            return -1;
        }
        if (str[0] == '\\') {
            str++;
            length--;
            if (length == 0) {
                return -1;
            }
            switch (str[0]) {
                case '"':
                case '\\':
                case '/':
                    out[pos++] = str[0];
                    str++;
                    length--;
                    break;
                case 'b':
                    out[pos++] = '\b';
                    str++;
                    length--;
                    break;
                case 'f':
                    out[pos++] = '\f';
                    str++;
                    length--;
                    break;
                case 'n':
                    out[pos++] = '\n';
                    str++;
                    length--;
                    break;
                case 'r':
                    out[pos++] = '\r';
                    str++;
                    length--;
                    break;
                case 't':
                    out[pos++] = '\t';
                    str++;
                    length--;
                    break;
                default:
                    return -1;
            }
        } else if (str[0] == '"') {
            str++;
            length--;
            break;
        } else {
            out[pos++] = str[0];
            str++;
            length--;
        }
    }
    out[pos] = 0;
    return pos + 2;
}

static int json_parse_number(const char *str, int length, double *out) {
    char *endptr;
    double val = strtod(str, &endptr);
    if (endptr == str) {
        return -1;
    }
    *out = val;
    return endptr - str;
}

static int json_parse_bool(const char *str, int length, bool *out) {
    if (strncmp(str, "true", 4) == 0) {
        *out = true;
        return 4;
    } else if (strncmp(str, "false", 5) == 0) {
        *out = false;
        return 5;
    } else {
        return -1;
    }
}

static int json_parse_null(const char *str, int length) {
    if (strncmp(str, "null", 4) == 0) {
        return 4;
    } else {
        return -1;
    }
}

int main() {
    const char *json_str = "{\"name\": \"Tom\", \"age\": 20}";
    json_object_t *obj = json_object_new();
    if (obj == NULL) {
        printf("Failed to create object");
        return EXIT_FAILURE;
    }
    int ret = json_parse_object(json_str, strlen(json_str), obj);
    if (ret < 0) {
        printf("Failed to parse object");
        json_object_free(obj);
        return EXIT_FAILURE;
    }
    json_element_t *name_element = json_object_get(obj, "name");
    if (name_element != NULL) {
        printf("name: %s\n", (char *)name_element->value);
    }
    json_element_t *age_element = json_object_get(obj, "age");
    if (age_element != NULL) {
        printf("age: %f\n", *(double *)age_element->value);
    }
    json_object_free(obj);
    return EXIT_SUCCESS;
}