//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    JSON_TYPE_NULL,
    JSON_TYPE_BOOL,
    JSON_TYPE_NUMBER,
    JSON_TYPE_STRING,
    JSON_TYPE_ARRAY,
    JSON_TYPE_OBJECT
} json_type_t;

typedef struct _json_value json_value_t;

typedef struct _json_object {
    char* key;
    json_value_t* value;
    struct _json_object* next;
} json_object_t;

typedef struct _json_array {
    json_value_t** values;
    size_t size;
} json_array_t;

typedef struct _json_value {
    json_type_t type;
    union {
        bool _bool;
        double number;
        char* string;
        json_array_t array;
        json_object_t* object;
    } data;
} json_value_t;

char* string_copy(const char* str) {
    size_t size = strlen(str);
    char* result = malloc(size + 1);
    if (!result) {
        return NULL;
    }
    memcpy(result, str, size + 1);
    return result;
}

json_value_t* json_parse(char* json);

void json_free(json_value_t* value) {
    if (!value) {
        return;
    }

    switch (value->type) {
        case JSON_TYPE_STRING:
            free(value->data.string);
            break;

        case JSON_TYPE_ARRAY:
            for (size_t i = 0; i < value->data.array.size; ++i) {
                json_free(value->data.array.values[i]);
            }
            free(value->data.array.values);
            break;

        case JSON_TYPE_OBJECT:
            while (value->data.object) {
                json_object_t* next = value->data.object->next;
                free(value->data.object->key);
                json_free(value->data.object->value);
                free(value->data.object);
                value->data.object = next;
            }
            break;

        default:
            break;
    }

    free(value);
}

json_object_t* json_parse_object(char** pos) {
    json_object_t* head = NULL, *tail = NULL;
    ++(*pos); // skip '{'
    while (**pos != '}') {
        if (head == NULL) {
            head = tail = malloc(sizeof(json_object_t));
            if (!head) {
                return NULL;
            }
        } else {
            tail->next = malloc(sizeof(json_object_t));
            if (!tail->next) {
                return false;
            }
            tail = tail->next;
        }

        // parse key
        char* key_start = *pos + 1;
        while (**pos != '"') {
            ++(*pos);
        }
        (*pos)++; // skip '"'
        size_t key_len = *pos - key_start;

        tail->key = malloc(key_len + 1);
        if (!tail->key) {
            return NULL;
        }
        memcpy(tail->key, key_start, key_len);
        tail->key[key_len] = '\0';

        // parse value
        ++(*pos); // skip ':'
        tail->value = json_parse(*pos);
        if (!tail->value) {
            return NULL;
        }
        while (**pos != ',' && **pos != '}') {
            ++(*pos);
        }
        if (**pos == ',') {
            ++(*pos);
        }
        tail->next = NULL;
    }
    ++(*pos); // skip '}'
    return head;
}

json_value_t* json_parse_array(char** pos) {
    json_value_t* result = malloc(sizeof(json_value_t));
    if (!result) {
        return NULL;
    }

    result->type = JSON_TYPE_ARRAY;
    json_array_t* array = &result->data.array;

    ++(*pos); // skip '['
    size_t size = 0;
    while (**pos != ']') {
        json_value_t* value = json_parse(*pos);
        if (!value) {
            json_free(result);
            return NULL;
        }

        array->values = realloc(array->values, sizeof(json_value_t*) * (size + 1));
        if (!array->values) {
            json_free(value);
            json_free(result);
            return NULL;
        }

        array->values[size++] = value;
        while (**pos != ',' && **pos != ']') {
            ++(*pos);
        }
        if (**pos == ',') {
            ++(*pos);
        }
    }
    ++(*pos); // skip ']'
    array->size = size;
    return result;
}

json_value_t* json_parse_number(char** pos) {
    char* end = *pos;
    double number = strtod(*pos, &end);
    if (end == *pos) {
        return NULL;
    }

    json_value_t* result = malloc(sizeof(json_value_t));
    if (!result) {
        return NULL;
    }

    result->type = JSON_TYPE_NUMBER;
    result->data.number = number;
    *pos = end;
    return result;
}

json_value_t* json_parse_string(char** pos) {
    ++(*pos); // skip '"'
    char* start = *pos;
    while (**pos != '"') {
        // handle escape characters
        if (**pos == '\\') {
            ++(*pos);
            if (**pos == '\0') {
                return NULL;
            }
        }
        ++(*pos);
    }
    size_t len = *pos - start;

    json_value_t* result = malloc(sizeof(json_value_t));
    if (!result) {
        return NULL;
    }

    result->type = JSON_TYPE_STRING;
    result->data.string = malloc(len + 1);
    if (!result->data.string) {
        free(result);
        return NULL;
    }
    memcpy(result->data.string, start, len);
    result->data.string[len] = '\0';
    ++(*pos); // skip closing '"'
    return result;
}

json_value_t* json_parse_bool(char** pos) {
    json_value_t* result = malloc(sizeof(json_value_t));
    if (!result) {
        return NULL;
    }

    result->type = JSON_TYPE_BOOL;
    if (strncmp(*pos, "true", 4) == 0) {
        result->data._bool = true;
        *pos += 4;
    } else if (strncmp(*pos, "false", 5) == 0) {
        result->data._bool = false;
        *pos += 5;
    } else {
        free(result);
        return NULL;
    }

    return result;
}

json_value_t* json_parse_null(char** pos) {
    json_value_t* result = malloc(sizeof(json_value_t));
    if (!result) {
        return NULL;
    }

    result->type = JSON_TYPE_NULL;
    if (strncmp(*pos, "null", 4) == 0) {
        *pos += 4;
    } else {
        free(result);
        return NULL;
    }

    return result;
}

json_value_t* json_parse(char* json) {
    json_value_t* result = NULL;
    char* pos = json;

    switch (*pos) {
        case '{':
            result = malloc(sizeof(json_value_t));
            if (!result) {
                return NULL;
            }

            result->type = JSON_TYPE_OBJECT;
            result->data.object = json_parse_object(&pos);
            if (!result->data.object) {
                json_free(result);
                return NULL;
            }
            break;

        case '[':
            result = json_parse_array(&pos);
            break;

        case '"':
            result = json_parse_string(&pos);
            break;

        case 't':
        case 'f':
            result = json_parse_bool(&pos);
            break;

        case 'n':
            result = json_parse_null(&pos);
            break;

        default: // assume it's a number
            result = json_parse_number(&pos);
            break;
    }

    // parse trailing whitespace
    while (*pos != '\0') {
        if (*pos != ' ' && *pos != '\t' && *pos != '\n' && *pos != '\r') {
            break;
        }
        ++pos;
    }

    if (*pos != '\0') {
        json_free(result);
        return NULL;
    }

    return result;
}

int main() {
    char* json = "{\"test\":{\"array\":[1,2,3],\"bool\":true,\"null\":null,\"number\":123.4,\"object\":{\"key\":\"value\"},\"string\":\"Hello, World!\"}}";
    json_value_t* value = json_parse(json);
    if (!value) {
        printf("Error parsing JSON\n");
        return 1;
    }

    json_object_t* obj = value->data.object;
    while (obj) {
        printf("Key: %s, ", obj->key);
        switch (obj->value->type) {
            case JSON_TYPE_NULL:
                printf("Value: null\n");
                break;
            case JSON_TYPE_BOOL:
                printf("Value: %s\n", obj->value->data._bool ? "true" : "false");
                break;
            case JSON_TYPE_NUMBER:
                printf("Value: %g\n", obj->value->data.number);
                break;
            case JSON_TYPE_STRING:
                printf("Value: %s\n", obj->value->data.string);
                break;
            case JSON_TYPE_ARRAY:
                printf("Value: [");
                for (size_t i = 0; i < obj->value->data.array.size; ++i) {
                    switch (obj->value->data.array.values[i]->type) {
                        case JSON_TYPE_NULL:
                            printf("null");
                            break;
                        case JSON_TYPE_BOOL:
                            printf("%s", obj->value->data.array.values[i]->data._bool ? "true" : "false");
                            break;
                        case JSON_TYPE_NUMBER:
                            printf("%g", obj->value->data.array.values[i]->data.number);
                            break;
                        case JSON_TYPE_STRING:
                            printf("\"%s\"", obj->value->data.array.values[i]->data.string);
                            break;
                        default:
                            break;
                    }
                    if (i != obj->value->data.array.size - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;
            case JSON_TYPE_OBJECT:
                printf("Value: {\n");

                json_object_t* nested_obj = obj->value->data.object;
                while (nested_obj) {
                    printf("\tKey: %s, ", nested_obj->key);
                    switch (nested_obj->value->type) {
                        case JSON_TYPE_NULL:
                            printf("Value: null\n");
                            break;
                        case JSON_TYPE_BOOL:
                            printf("Value: %s\n", nested_obj->value->data._bool ? "true" : "false");
                            break;
                        case JSON_TYPE_NUMBER:
                            printf("Value: %g\n", nested_obj->value->data.number);
                            break;
                        case JSON_TYPE_STRING:
                            printf("Value: %s\n", nested_obj->value->data.string);
                            break;
                        case JSON_TYPE_ARRAY:
                            printf("Value: [");
                            for (size_t i = 0; i < nested_obj->value->data.array.size; ++i) {
                                switch (nested_obj->value->data.array.values[i]->type) {
                                    case JSON_TYPE_NULL:
                                        printf("null");
                                        break;
                                    case JSON_TYPE_BOOL:
                                        printf("%s", nested_obj->value->data.array.values[i]->data._bool ? "true" : "false");
                                        break;
                                    case JSON_TYPE_NUMBER:
                                        printf("%g", nested_obj->value->data.array.values[i]->data.number);
                                        break;
                                    case JSON_TYPE_STRING:
                                        printf("\"%s\"", nested_obj->value->data.array.values[i]->data.string);
                                        break;
                                    default:
                                        break;
                                }
                                if (i != nested_obj->value->data.array.size - 1) {
                                    printf(", ");
                                }
                            }
                            printf("]\n");
                            break;
                        case JSON_TYPE_OBJECT:
                            printf("Value: {\n");
                            // recursively print nested objects
                            json_object_t* nested_nested_obj = nested_obj->value->data.object;
                            while (nested_nested_obj) {
                                printf("\t\tKey: %s, ", nested_nested_obj->key);
                                switch (nested_nested_obj->value->type) {
                                    case JSON_TYPE_NULL:
                                        printf("Value: null\n");
                                        break;
                                    case JSON_TYPE_BOOL:
                                        printf("Value: %s\n", nested_nested_obj->value->data._bool ? "true" : "false");
                                        break;
                                    case JSON_TYPE_NUMBER:
                                        printf("Value: %g\n", nested_nested_obj->value->data.number);
                                        break;
                                    case JSON_TYPE_STRING:
                                        printf("Value: %s\n", nested_nested_obj->value->data.string);
                                        break;
                                    case JSON_TYPE_ARRAY:
                                        printf("Value: [");
                                        for (size_t i = 0; i < nested_nested_obj->value->data.array.size; ++i) {
                                            switch (nested_nested_obj->value->data.array.values[i]->type) {
                                                case JSON_TYPE_NULL:
                                                    printf("null");
                                                    break;
                                                case JSON_TYPE_BOOL:
                                                    printf("%s", nested_nested_obj->value->data.array.values[i]->data._bool ? "true" : "false");
                                                    break;
                                                case JSON_TYPE_NUMBER:
                                                    printf("%g", nested_nested_obj->value->data.array.values[i]->data.number);
                                                    break;
                                                case JSON_TYPE_STRING:
                                                    printf("\"%s\"", nested_nested_obj->value->data.array.values[i]->data.string);
                                                    break;
                                                default:
                                                    break;
                                            }
                                            if (i != nested_nested_obj->value->data.array.size - 1) {
                                                printf(", ");
                                            }
                                        }
                                        printf("]\n");
                                        break;
                                    case JSON_TYPE_OBJECT:
                                        printf("Value: {\n");
                                        printf("\t\t\t// Nested objects not supported\n");
                                        printf("\t\t}\n");
                                        break;
                                    default:
                                        break;
                                }
                                nested_nested_obj = nested_nested_obj->next;
                            }
                            printf("\t\t}\n");
                            break;
                        default:
                            break;
                    }
                    nested_obj = nested_obj->next;
                }
                printf("\t}\n");
                break;
            default:
                break;
        }
        obj = obj->next;
    }

    json_free(value);
    return 0;
}