//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json {
    char *key;
    char *value;
    struct json *next;
} JSON;

void add_json(JSON **head, char *key, char *value) {
    JSON *new_json = (JSON *) malloc(sizeof(JSON));
    new_json->key = key;
    new_json->value = value;
    new_json->next = NULL;

    if (*head == NULL) {
        *head = new_json;
    }
    else {
        JSON *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_json;
    }
}

void print_json(JSON *head) {
    printf("{\n");
    while (head != NULL) {
        printf("\t\"%s\": \"%s\",\n", head->key, head->value);
        head = head->next;
    }
    printf("}\n");
}

void parse_json(char *json_string, JSON **head) {
    char *token = strtok(json_string, "{}\":,\n ");
    int i = 0;
    char *key;
    char *value;
    while (token != NULL) {
        if (i % 2 == 0) {
            key = token;
        }
        else {
            value = token;
            add_json(head, key, value);
        }
        token = strtok(NULL, "{}\":,\n ");
        i++;
    }
}

int main() {
    char json_string[] = "{\"name\": \"John Doe\", \"age\": \"30\", \"city\": \"New York\"}";
    JSON *head = NULL;
    parse_json(json_string, &head);
    print_json(head);
    return 0;
}