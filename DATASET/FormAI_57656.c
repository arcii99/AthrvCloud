//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_BOOL,
    JSON_NULL
} json_type;

typedef struct _json_object {
    char *name;
    struct _json_item *items;
    struct _json_object *next;
} json_object;

typedef struct _json_array {
    struct _json_item *items;
    int length;
} json_array;

typedef struct _json_item {
    json_type type;
    union {
        char *string;
        int number;
        json_object *object;
        json_array *array;
        int bool_val;
    } value;
} json_item;

json_item parse_json(char *json_str, char **end_ptr) {
    json_item root = {0};
    char *p = json_str;

    if (*p == '{') {
        // parsing an object
        root.type = JSON_OBJECT;

        // skip opening brace
        p++;

        // read object properties
        while (*p != '}') {
            // read property name
            char *prop_name_start = p + 1;
            char *prop_name_end = strchr(prop_name_start, ':');
            int prop_name_len = prop_name_end - prop_name_start;
            char *prop_name = malloc(prop_name_len + 1);
            strncpy(prop_name, prop_name_start, prop_name_len);
            prop_name[prop_name_len] = '\0';
            p = prop_name_end;

            // skip colon
            p++;

            // read property value
            json_item prop_value = parse_json(p, &p);

            // add property to object
            json_object *obj = root.value.object;
            json_object *new_obj = malloc(sizeof(json_object));
            new_obj->name = prop_name;
            new_obj->items = &prop_value;
            new_obj->next = NULL;
            if (obj == NULL) {
                root.value.object = new_obj;
            } else {
                while (obj->next != NULL) {
                    obj = obj->next;
                }
                obj->next = new_obj;
            }

            // skip comma or closing brace
            if (*p == ',') {
                p++;
            }
        }

        // skip closing brace
        p++;

    } else if (*p == '[') {
        // parsing an array
        root.type = JSON_ARRAY;

        // skip opening bracket
        p++;

        json_array *arr = root.value.array;
        json_item *items = malloc(sizeof(json_item) * 10);
        int cap = 10;
        int len = 0;

        // read array items
        while (*p != ']') {
            // read item value
            json_item item = parse_json(p, &p);

            // add item to array
            if (len >= cap) {
                cap *= 2;
                items = realloc(items, sizeof(json_item) * cap);
            }
            items[len] = item;
            len++;
        }

        // skip closing bracket
        p++;

        // copy items to array struct
        arr->items = items;
        arr->length = len;

    } else if (*p == '\"') {
        // parsing a string
        root.type = JSON_STRING;

        char *str_start = p + 1;
        char *str_end = strchr(str_start, '\"');
        int str_len = str_end - str_start;
        char *str = malloc(str_len + 1);
        strncpy(str, str_start, str_len);
        str[str_len] = '\0';

        root.value.string = str;

        p = str_end + 1;

    } else if (*p >= '0' && *p <= '9') {
        // parsing a number
        root.type = JSON_NUMBER;

        int num = strtol(p, &p, 10);

        root.value.number = num;

    } else if (strstr(p, "true") == p) {
        // parsing a boolean value (true)
        root.type = JSON_BOOL;

        root.value.bool_val = 1;

        p += 4;

    } else if (strstr(p, "false") == p) {
        // parsing a boolean value (false)
        root.type = JSON_BOOL;

        root.value.bool_val = 0;

        p += 5;

    } else if (strstr(p, "null") == p) {
        // parsing a null value
        root.type = JSON_NULL;

        p += 4;

    }

    if (end_ptr != NULL) {
        *end_ptr = p;
    }

    return root;
}

int main(int argc, char **argv) {
    char *json_str = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    json_item root = parse_json(json_str, NULL);
    json_object *obj = root.value.object;
    while (obj != NULL) {
        printf("%s: %s\n", obj->name, obj->items->value.string);
        obj = obj->next;
    }
    return 0;
}