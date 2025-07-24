//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[20];
    char value[50];
    struct node *next;
} Node;

void parseXML(char *);
void printNodes(Node *);

int main() {
    char *xml = "<students><student><name>John</name><id>123</id></student><student><name>Jane</name><id>456</id></student></students>";
    parseXML(xml);
    return 0;
}

void parseXML(char *xml) {
    Node *head = NULL, *curr = NULL;
    char *token = NULL;
    const char *delim_start = "<";
    const char *delim_end = ">";

    token = strtok(xml, delim_start);
    while (token != NULL) {
        if (token[0] == '/') {
            // close tag
            curr = head;
            while (strcmp(curr->name, &token[1]) != 0) {
                curr = curr->next;
            }
            token = strtok(NULL, delim_start);
            strcpy(curr->value, token);

        } else {
            // open tag
            while (token[0] == ' ') {
                token++;
            }
            curr = (Node *) malloc(sizeof(Node));
            strcpy(curr->name, token);
            curr->next = NULL;

            if (head == NULL) {
                head = curr;
            } else {
                curr->next = head;
                head = curr;
            }
        }
        token = strtok(NULL, delim_end);
    }
    printNodes(head);
}

void printNodes(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("<%s>%s</%s>\n", curr->name, curr->value, curr->name);
        curr = curr->next;
    }
}