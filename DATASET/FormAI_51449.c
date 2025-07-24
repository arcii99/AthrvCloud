//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_VALUE_LEN 50

struct json_value {
    char key[MAX_VALUE_LEN];
    char value[MAX_VALUE_LEN];
    struct json_value* next;
};

typedef struct json_value json_value;

void add_to_list(json_value** head, char* key, char* value) {
    json_value* new_node = (json_value*)malloc(sizeof(json_value));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = (*head);
    (*head) = new_node;
}

json_value* parse_json(char* json_str) {
    json_value* head = NULL;

    char* token = strtok(json_str, ",");
    while (token != NULL) {
        char* key = strtok(token, ":");
        char* value = strtok(NULL, ":");
        add_to_list(&head, key, value);
        token = strtok(NULL, ",");
    }

    return head;
}

void print_json(json_value* head) {
    printf("{");
    while (head != NULL) {
        printf("%s:\"%s\"", head->key, head->value);
        head = head->next;
        if (head != NULL) {
            printf(",");
        }
    }
    printf("}");
}

int main() {
    char* test_json = "name:John,age:25,email:john@example.com";
    json_value* json_obj = parse_json(test_json);
    print_json(json_obj);

    return 0;
}