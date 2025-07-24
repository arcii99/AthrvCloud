//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef struct {
    char* key;
    char* value;
} json_node;

void trim_whitespace(char** str) {
    int len = strlen(*str);
    int start = 0, end = len - 1;

    while ((*str)[start] == ' ')
        start++;
    while ((*str)[end] == ' ')
        end--;

    (*str)[end+1] = '\0';
    *str = &(*str)[start];
}

json_node* parse_object(char* obj_str) {
    int key_len, val_len, num_nodes = 0, i = 0;
    char *key, *val;
    char* temp_str = (char*) malloc(strlen(obj_str) + 1);
    json_node* nodes = (json_node*) malloc(sizeof(json_node) * 10);
    memset(temp_str, 0, strlen(obj_str) + 1);

    // Remove curly braces from obj_str
    strncpy(temp_str, &obj_str[1], strlen(obj_str) - 2);
    trim_whitespace(&temp_str);

    while (temp_str[i] != '\0') {
        // Parse key
        key_len = strcspn(&temp_str[i], ":") + 1;
        key = (char*) malloc(key_len);
        strncpy(key, &temp_str[i], key_len - 1);
        key[key_len - 1] = '\0';

        i += key_len;

        // Parse value
        if (temp_str[i] == '{') {
            int start_index = i, open_braces = 1, close_braces = 0;
            while (open_braces != close_braces) {
                i++;
                if (temp_str[i] == '{')
                    open_braces++;
                else if (temp_str[i] == '}')
                    close_braces++;
            }
            val_len = i - start_index + 1;
            val = (char*) malloc(val_len);
            strncpy(val, &temp_str[start_index], val_len);
            val[val_len] = '\0';
        } else {
            val_len = strcspn(&temp_str[i], ",") + 1;
            val = (char*) malloc(val_len);
            strncpy(val, &temp_str[i], val_len - 1);
            val[val_len - 1] = '\0';
        }

        i += val_len;

        // Add node to array
        nodes[num_nodes].key = key;
        nodes[num_nodes].value = val;
        num_nodes++;

        if (temp_str[i] == ',')
            i++;
    }

    free(temp_str);
    return nodes;
}

int main() {
    char* json_str = "{ \"name\": { \"first\": \"John\", \"last\": \"Doe\" }, \"age\": 30 }";
    char* temp_str = (char*) malloc(strlen(json_str) + 1);
    memset(temp_str, 0, strlen(json_str) + 1);
    strncpy(temp_str, json_str, strlen(json_str));
    trim_whitespace(&temp_str);

    if (temp_str[0] == '{') {
        json_node* nodes = parse_object(temp_str);
        printf("Name: %s %s\nAge: %s\n", nodes[0].value, nodes[1].value, nodes[2].value);
        free(nodes);
    }

    free(temp_str);
    return 0;
}