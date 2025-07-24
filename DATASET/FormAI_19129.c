//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
struct node {
    char *key;
    char *value;
    Node *next;
};

Node *parse_json(char *json_string){
    Node *head = NULL;
    Node *tail = NULL;

    char *token = strtok(json_string, "{},\"");
    while(token != NULL) {
        if(strncmp(token, ":", 1) == 0){
            if(head == NULL){
                printf("Error: JSON format is incorrect");
                exit(0);
            }
            tail->value = strdup(strtok(NULL, "{},\""));
        } else {
            // add key-value pair to linked list
            Node *new_node = malloc(sizeof(Node));
            new_node->key = strdup(token);
            new_node->next = NULL;
            if(head == NULL){
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        token = strtok(NULL, "{},\"");
    }
    return head;
}

int main(){
    char *json_str = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    Node *json_obj = parse_json(json_str);

    Node *curr = json_obj;
    while(curr != NULL){
        printf("%s: %s\n", curr->key, curr->value);
        curr = curr->next;
    }
    return 0;
}