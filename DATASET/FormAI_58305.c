//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

typedef enum {
    JSON_UNDEFINED,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type_t;

typedef struct json_node_s {
    json_type_t type;
    union {
        char * string_val;
        double number_val;
        struct json_node_s ** children;
    };
    size_t child_count;
} json_node_t;

char * json_stringify(json_node_t * node) {
    char * buf = malloc(MAX_BUF_SIZE);
    if (node == NULL) {
        snprintf(buf, MAX_BUF_SIZE, "null");
    } else if (node->type == JSON_STRING) {
        snprintf(buf, MAX_BUF_SIZE, "\"%s\"", node->string_val);
    } else if (node->type == JSON_NUMBER) {
        snprintf(buf, MAX_BUF_SIZE, "%lf", node->number_val);
    } else if (node->type == JSON_TRUE) {
        snprintf(buf, MAX_BUF_SIZE, "true");
    } else if (node->type == JSON_FALSE) {
        snprintf(buf, MAX_BUF_SIZE, "false");
    } else if (node->type == JSON_NULL) {
        snprintf(buf, MAX_BUF_SIZE, "null");
    } else if (node->type == JSON_OBJECT) {
        char * sub_buf = malloc(MAX_BUF_SIZE);
        snprintf(buf, MAX_BUF_SIZE, "{");
        for (size_t i = 0; i < node->child_count; i++) {
            if (i > 0) {
                strncat(buf, ",", MAX_BUF_SIZE);
            }
            snprintf(sub_buf, MAX_BUF_SIZE, "\"%s\":%s", node->children[i]->string_val, json_stringify(node->children[i]));
            strncat(buf, sub_buf, MAX_BUF_SIZE);
        }
        strncat(buf, "}", MAX_BUF_SIZE);
        free(sub_buf);
    } else if (node->type == JSON_ARRAY) {
        char * sub_buf = malloc(MAX_BUF_SIZE);
        snprintf(buf, MAX_BUF_SIZE, "[");
        for (size_t i = 0; i < node->child_count; i++) {
            if (i > 0) {
                strncat(buf, ",", MAX_BUF_SIZE);
            }
            snprintf(sub_buf, MAX_BUF_SIZE, "%s", json_stringify(node->children[i]));
            strncat(buf, sub_buf, MAX_BUF_SIZE);
        }
        strncat(buf, "]", MAX_BUF_SIZE);
        free(sub_buf);
    }
    return buf;
}

json_node_t * json_parse(char * str) {
    if (str == NULL) {
        return NULL;
    }
    size_t len = strlen(str);
    if (len == 0) {
        return NULL;
    }
    json_node_t * root = malloc(sizeof(json_node_t));
    if (*str == '{') {
        root->type = JSON_OBJECT;
        root->child_count = 0;
        root->children = NULL;
        str++;
        len--;
        while (len > 0 && *str != '}') {
            char * key_start = str;
            while (len > 0 && *str != ':') {
                str++;
                len--;
            }
            if (len == 0 || *str != ':') {
                free(root);
                return NULL;
            }
            *str = '\0';
            json_node_t * val = json_parse(str + 1);
            if (val == NULL) {
                free(root);
                return NULL;
            }
            json_node_t ** new_children = realloc(root->children, (root->child_count + 1) * sizeof(json_node_t *));
            if (new_children == NULL) {
                free(root);
                return NULL;
            }
            root->children = new_children;
            root->children[root->child_count] = malloc(sizeof(json_node_t));
            root->children[root->child_count]->type = JSON_STRING;
            root->children[root->child_count]->string_val = strdup(key_start);
            root->child_count++;
            str++;
            len--;
            while (len > 0 && *str != ',' && *str != '}') {
                str++;
                len--;
            }
            if (len > 0 && *str == ',') {
                str++;
                len--;
            }
        }
        if (*str != '}') {
            free(root);
            return NULL;
        }
    } else if (*str == '[') {
        root->type = JSON_ARRAY;
        root->child_count = 0;
        root->children = NULL;
        str++;
        len--;
        while (len > 0 && *str != ']') {
            json_node_t * val = json_parse(str);
            if (val == NULL) {
                free(root);
                return NULL;
            }
            json_node_t ** new_children = realloc(root->children, (root->child_count + 1) * sizeof(json_node_t *));
            if (new_children == NULL) {
                free(root);
                return NULL;
            }
            root->children = new_children;
            root->children[root->child_count] = val;
            root->child_count++;
            while (len > 0 && *str != ',' && *str != ']') {
                str++;
                len--;
            }
            if (len > 0 && *str == ',') {
                str++;
                len--;
            }
        }
        if (*str != ']') {
            free(root);
            return NULL;
        }
    } else if (*str == '\"') {
        root->type = JSON_STRING;
        root->child_count = 0;
        root->children = NULL;
        char * end = strchr(str + 1, '\"');
        if (end == NULL) {
            free(root);
            return NULL;
        }
        *end = '\0';
        root->string_val = strdup(str + 1);
    } else if (*str == '-' || (*str >= '0' && *str <= '9')) {
        root->type = JSON_NUMBER;
        root->child_count = 0;
        root->children = NULL;
        char * end;
        double val = strtod(str, &end);
        root->number_val = val;
    } else if (strncmp(str, "true", 4) == 0) {
        root->type = JSON_TRUE;
        root->child_count = 0;
        root->children = NULL;
    } else if (strncmp(str, "false", 5) == 0) {
        root->type = JSON_FALSE;
        root->child_count = 0;
        root->children = NULL;
    } else if (strncmp(str, "null", 4) == 0) {
        root->type = JSON_NULL;
        root->child_count = 0;
        root->children = NULL;
    } else {
        free(root);
        return NULL;
    }
    return root;
}

int main() {
    char * input = "{\"name\":\"John Smith\",\"age\":30}";
    json_node_t * root = json_parse(input);
    if (root == NULL) {
        printf("Error: invalid JSON input\n");
        return 1;
    }
    printf("%s\n", json_stringify(root));
    return 0;
}