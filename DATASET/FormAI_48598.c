//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char tag[50];
    char attributes[500];
    char content[500];
    struct Node* children[100];
    int num_children;
};

void add_child(struct Node* parent, struct Node* child) {
    parent->children[parent->num_children++] = child;
}

struct Node* parse_xml(char* xml) {
    int len = strlen(xml);
    int pos = 0;
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    memset(root, 0, sizeof(struct Node));
    while (pos < len) {
        if (xml[pos] == '<') {
            pos++;
            int i = pos;
            while (xml[i] != ' ' && xml[i] != '>') i++;
            memset(root->tag, 0, sizeof(root->tag));
            strncpy(root->tag, &xml[pos], i - pos);
            pos = i;
            while (xml[pos] != '>') {
                if (xml[pos] == '/') {
                    pos++;
                    root->content[0] = '\0';
                    return root;
                }
                else if (xml[pos] == ' ') {
                    pos++;
                    int j = pos;
                    while (xml[j] != ' ') j++;
                    char attr[100];
                    strncpy(attr, &xml[pos], j - pos);
                    strcat(root->attributes, " ");
                    strcat(root->attributes, attr);
                    pos = j + 1;
                }
                else {
                    pos++;
                    int j = pos;
                    while (xml[j] != '<') j++;
                    strncpy(root->content, &xml[pos], j - pos);
                    pos = j;
                }
            }
            pos++;
            struct Node* child = parse_xml(&xml[pos]);
            add_child(root, child);
            pos += strlen(child->tag) + strlen(child->attributes) + strlen(child->content) + 3;
        }
        else {
            pos++;
        }
    }
    return root;
}

void print_xml(struct Node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s%s>", node->tag, node->attributes);
    if (node->content[0] != '\0') {
        printf("%s", node->content);
    }
    printf("\n");
    for (int i = 0; i < node->num_children; i++) {
        print_xml(node->children[i], depth + 1);
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

int main() {
    char* xml = "<xml><person class=\"employee\"><name>John Doe</name><age>35</age></person></xml>";
    struct Node* root = parse_xml(xml);
    print_xml(root, 0);
    return 0;
}