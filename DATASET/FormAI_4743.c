//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    char tag[MAX_SIZE];
    char value[MAX_SIZE];
    struct Node* child;
};

void parseXML(char* xml) {
    struct Node* root = NULL;
    struct Node* curr = NULL;
    int idx = 0;

    while (xml[idx] != '\0') {
        if (xml[idx] == '<') {
            idx++;
            if (xml[idx] == '/') {
                curr = root;
                while (curr->child != NULL) {
                    curr = curr->child;
                }
            }
            else {
                struct Node* node = malloc(sizeof(struct Node));
                node->child = NULL;

                int i = 0;
                while (xml[idx] != '>' && i < MAX_SIZE - 1) {
                    node->tag[i++] = xml[idx++];
                }
                node->tag[i] = '\0';

                if (root == NULL) {
                    root = node;
                    curr = root;
                }
                else {
                    curr->child = node;
                    curr = node;
                }

                if (xml[idx] == '>') {
                    idx++;
                    int j = 0;
                    while (xml[idx] != '<' && j < MAX_SIZE - 1) {
                        node->value[j++] = xml[idx++];
                    }
                    node->value[j] = '\0';
                }
            }
        }
        else {
            idx++;
        }
    }

    curr = root;
    while (curr != NULL) {
        printf("<%s>%s</%s>\n", curr->tag, curr->value, curr->tag);
        curr = curr->child;
    }
}

int main() {
    char xml[] = "<root><person><name>John</name><age>22</age></person><person><name>Jane</name><age>25</age></person></root>";
    parseXML(xml);
    return 0;
}