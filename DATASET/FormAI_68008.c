//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {JSON_OBJECT, JSON_ARRAY, JSON_STRING, JSON_NUMBER, JSON_BOOLEAN, JSON_NULL} json_type;

typedef struct json_node {
    json_type type;
    union {
        char *string;
        double number;
        int boolean;
        struct json_node *child;
    } value;
    struct json_node *next;
    struct json_node *prev;
} json_node;

json_node *parse_json(char *input) {
    json_node *root = NULL;
    json_node *cur_node = NULL;
    char *token = strtok(input, "{}[],:\"");
    while(token != NULL) {
        if(*token == '{') {
            json_node *new_node = malloc(sizeof(json_node));
            new_node->type = JSON_OBJECT;
            new_node->value.child = NULL;
            if(root == NULL) {
                root = new_node;
                cur_node = new_node;
            } else {
                cur_node->value.child = new_node;
                new_node->prev = cur_node;
                cur_node = new_node;
            }
        } else if(*token == '}') {
            cur_node = cur_node->prev;
        } else if(*token == '[') {
            json_node *new_node = malloc(sizeof(json_node));
            new_node->type = JSON_ARRAY;
            new_node->value.child = NULL;
            if(cur_node == NULL) {
                cur_node = new_node;
            } else {
                cur_node->value.child = new_node;
            }
        } else if(*token == ']') {
            /* do nothing */
        } else if(*token == ':') {
            /* do nothing */
        } else if(*token == ',') {
            json_node *new_node = malloc(sizeof(json_node));
            new_node->prev = cur_node;
            new_node->next = NULL;
            cur_node->next = new_node;
            cur_node = new_node;
        } else if(strchr(token, '.') != NULL) {
            double num = atof(token);
            json_node *new_node = malloc(sizeof(json_node));
            new_node->type = JSON_NUMBER;
            new_node->value.number = num;
            if(cur_node == NULL) {
                cur_node = new_node;
            } else {
                cur_node->value.child = new_node;
            }
        } else if(strcmp(token, "true") == 0) {
            json_node *new_node = malloc(sizeof(json_node));
            new_node->type = JSON_BOOLEAN;
            new_node->value.boolean = 1;
            if(cur_node == NULL) {
                cur_node = new_node;
            } else {
                cur_node->value.child = new_node;
            }
        } else if(strcmp(token, "false") == 0) {
            json_node *new_node = malloc(sizeof(json_node));
            new_node->type = JSON_BOOLEAN;
            new_node->value.boolean = 0;
            if(cur_node == NULL) {
                cur_node = new_node;
            } else {
                cur_node->value.child = new_node;
            }
        } else if(strcmp(token, "null") == 0) {
            json_node *new_node = malloc(sizeof(json_node));
            new_node->type = JSON_NULL;
            if(cur_node == NULL) {
                cur_node = new_node;
            } else {
                cur_node->value.child = new_node;
            }
        } else {
            char *str = strdup(token);
            json_node *new_node = malloc(sizeof(json_node));
            new_node->type = JSON_STRING;
            new_node->value.string = str;
            if(cur_node == NULL) {
                cur_node = new_node;
            } else {
                cur_node->value.child = new_node;
            }
        }
        token = strtok(NULL, "{}[],:\"");
    }
    return root;
}

void print_json(json_node *root) {
    json_node *cur_node = root;
    while(cur_node != NULL) {
        switch(cur_node->type) {
            case JSON_OBJECT:
                printf("{ ");
                print_json(cur_node->value.child);
                printf(" }");
                break;
            case JSON_ARRAY:
                printf("[ ");
                print_json(cur_node->value.child);
                printf(" ]");
                break;
            case JSON_STRING:
                printf("\"%s\"", cur_node->value.string);
                break;
            case JSON_NUMBER:
                printf("%.2f", cur_node->value.number);
                break;
            case JSON_BOOLEAN:
                printf("%s", cur_node->value.boolean ? "true" : "false");
                break;
            case JSON_NULL:
                printf("null");
                break;
        }
        if(cur_node->next != NULL) {
            printf(", ");
        }
        cur_node = cur_node->next;
    }
}

int main() {
    char input[] = "{\"name\":\"John\",\"age\":25,\"city\":\"New York\",\"children\":[{\"name\":\"Mary\",\"age\":4},{\"name\":\"Mark\",\"age\":2},{\"name\":\"Peter\",\"age\":1}],\"employed\":true,\"salary\":3500.50,\"spouse\":null}";
    json_node *root = parse_json(input);
    print_json(root);
    return 0;
}