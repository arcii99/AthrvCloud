//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { STRING, NUMBER, OBJECT, ARRAY, BOOLEAN, NULL_VAL } json_type;

typedef struct json_item json_item;
struct json_item {
    char *key;  // may be null if omitted
    json_type type;
    union {
        char *s_val;  // valid for string
        double d_val; // valid for number
        json_item *o_val; // valid for object
        json_item **a_val; // valid for array
        int b_val; // valid for boolean
    } val;
    json_item *next; // valid for object and array
};

json_item* parse_object_or_array(char **json_str_ptr, json_type type) {
    json_item *head = NULL, *prev = NULL;
    int in_quote = 0;
    char c;
    int len;

    while ((c = **json_str_ptr) != '\0') {
        if (type == OBJECT && c == '}') {
            (*json_str_ptr)++;
            return head;
        } else if (type == ARRAY && c == ']') {
            (*json_str_ptr)++;
            return head;
        } else if (c == '"') {
            in_quote = !in_quote;
        } else if (!in_quote && (c == ',' || c == ':')) {
            (*json_str_ptr)++;
            continue;
        } else {
            json_item *current = malloc(sizeof(json_item));
            len = strcspn(*json_str_ptr, ",:{[]}\"");
            current->next = NULL;
            if (type == OBJECT) {
                current->key = strndup(*json_str_ptr, len-1);
                *json_str_ptr += len + 1; // skip '":'
            } else {
                current->key = NULL;
                *json_str_ptr += len;
            }
            c = **json_str_ptr;
            if (c == '"') { // string
                current->type = STRING;
                (*json_str_ptr)++;
                len = strcspn(*json_str_ptr, "\"");
                current->val.s_val = strndup(*json_str_ptr, len);
                (*json_str_ptr) += len + 1; // skip ending "
            } else if (c == '-' || (c >= '0' && c <= '9')) { // number
                current->type = NUMBER;
                current->val.d_val = atof(*json_str_ptr);
                while ((c = **json_str_ptr) == '-' || (c >= '0' && c <= '9') || c == '.') {
                    (*json_str_ptr)++;
                }
            } else if (c == '{') { // object
                current->type = OBJECT;
                (*json_str_ptr)++; // move on from '{'
                current->val.o_val = parse_object_or_array(json_str_ptr, OBJECT);
            } else if (c == '[') { // array
                current->type = ARRAY;
                (*json_str_ptr)++; // move on from '['
                char *substr = strndup(*json_str_ptr, strlen(*json_str_ptr));
                char *substr_ptr = substr;
                int count = 0;
                while ((c = *substr_ptr) != '\0') {
                    if (c == ',' || c == ']') {
                        count++;
                    }
                    substr_ptr++;
                }
                current->val.a_val = malloc(sizeof(json_item*) * (count + 1)); // count + 1 for null terminator
                count = 0;
                while (**json_str_ptr != '\0' && **json_str_ptr != ']') {
                    current->val.a_val[count++] = parse_object_or_array(json_str_ptr, ARRAY);
                }
                current->val.a_val[count] = NULL; // add null terminator
                (*json_str_ptr)++; // move on from ']'
                free(substr);
            } else if (strncasecmp(*json_str_ptr, "true", 4) == 0 ||
                    strncasecmp(*json_str_ptr, "false", 5) == 0) { // boolean
                current->type = BOOLEAN;
                current->val.b_val = strncasecmp(*json_str_ptr, "true", 4) == 0;
                (*json_str_ptr) += current->val.b_val ? 4 : 5;
            } else if (strncasecmp(*json_str_ptr, "null", 4) == 0) { // null
                current->type = NULL_VAL;
                current->val.s_val = NULL;
                (*json_str_ptr) += 4;
            }
            if (type == OBJECT) { // add to object
                if (prev != NULL) {
                    prev->next = current;
                } else {
                    head = current;
                }
                prev = current;
            } else { // add to array
                if (prev != NULL) {
                    prev->next = current;
                } else {
                    head = current;
                }
                prev = current;
            }
        }
    }
    return head;
}

json_item* parse_json(char *json_str) {
    if (json_str == NULL) {
        return NULL;
    }
    int len = strlen(json_str);
    if (len == 0) {
        return NULL;
    }
    char *json_str_ptr = json_str;
    json_item *root = parse_object_or_array(&json_str_ptr, json_str_ptr[0] == '{' ? OBJECT : ARRAY);
    return root;
}

void print_json(json_item *item, int indent) {
    if (item == NULL) {
        printf("null\n");
        return;
    }
    for (int i = 0; i < indent; i++) {
        putchar(' ');
    }
    if (item->type == OBJECT) {
        printf("{\n");
        json_item *child = item->val.o_val;
        while (child != NULL) {
            for (int i = 0; i < indent + 2; i++) {
                putchar(' ');
            }
            printf("\"%s\": ", child->key);
            print_json(child, indent + 2);
            child = child->next;
        }
        for (int i = 0; i < indent; i++) {
            putchar(' ');
        }
        printf("}\n");
    } else if (item->type == ARRAY) {
        printf("[\n");
        json_item **children = item->val.a_val;
        while (*children != NULL) {
            print_json(*children, indent + 2);
            children++;
        }
        for (int i = 0; i < indent; i++) {
            putchar(' ');
        }
        printf("]\n");
    } else if (item->type == STRING) {
        printf("\"%s\"\n", item->val.s_val);
    } else if (item->type == NUMBER) {
        printf("%f\n", item->val.d_val);
    } else if (item->type == BOOLEAN) {
        printf("%s\n", item->val.b_val ? "true" : "false");
    } else {
        printf("null\n");
    }
}

int main() {
    char json_str[] = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\", \"array\": [1, 2, 3], \"obj\": {\"key\": \"value\"}}";
    json_item *root = parse_json(json_str);
    print_json(root, 0);
    return 0;
}