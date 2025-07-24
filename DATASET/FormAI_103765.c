//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *key;
    char *value;
} json_node;

typedef struct {
    json_node *nodes;
    int size;
} json_object;

void parse_json(char *json_text, json_object *obj) {
    char *key = NULL;
    char *value = NULL;
    char *p = json_text;
    int i = 0;

    while (*p != '\0') {
        if (*p == '\"') {
            p++;
            if (key == NULL) {
                key = p;
            } else {
                value = p;
            }
            while (*p != '\"') {
                p++;
            }
            *p = '\0';
        } else if (*p == ':') {
            *p = '\0';
        } else if (*p == ',') {
            *p = '\0';
            obj->nodes[i].key = strdup(key);
            obj->nodes[i].value = strdup(value);
            i++;
            key = NULL;
            value = NULL;
        } else if (*p == '{') {
            obj->nodes = malloc(sizeof(json_node) * 1024);
            obj->size = 0;
            key = NULL;
            value = NULL;
        } else if (*p == '}') {
            obj->nodes[i].key = strdup(key);
            obj->nodes[i].value = strdup(value);
            obj->size = i + 1;
            key = NULL;
            value = NULL;
        } else if (!isspace(*p) && key != NULL && value == NULL) {
            value = p;
        }
        p++;
    }
}

int main() {
    char *value = "{ \"name\":\"John\", \"age\":30, \"city\":\"New York\" }";
    json_object obj;
    parse_json(value, &obj);
    printf("Size: %d\n", obj.size);
    for (int i = 0; i < obj.size; i++) {
        printf("Key: %s, Value: %s\n", obj.nodes[i].key, obj.nodes[i].value);
    }
    return 0;
}