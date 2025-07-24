//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure of XML tree */
typedef struct TreeNode {
    char* tag;
    char* text;
    struct TreeNode* children;
    struct TreeNode* next;
} TreeNode;

/* Function to create a new node */
TreeNode* newNode(char* tag, char* text) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->tag = tag;
    node->text = text;
    node->children = NULL;
    node->next = NULL;
    return node;
}

/* Function to parse XML and build the tree recursively */
TreeNode* parseXML(char* xml, int start, int end, int* idx) {
    /* Base case */
    if (start > end) {
        return NULL;
    }

    /* Find the start of XML tag */
    while (start <= end && xml[start] != '<') {
        start++;
    }

    /* Find the end of XML tag */
    int curr = start + 1;
    while (curr <= end && xml[curr] != '>' && xml[curr] != ' ') {
        curr++;
    }

    /* Create new node with tag name */
    char* tag = (char*)malloc((curr - start) * sizeof(char));
    strncpy(tag, xml + start + 1, curr - start - 1);
    tag[curr - start - 1] = '\0';
    TreeNode* node = newNode(tag, "");

    /* Find the end tag */
    curr = start + 1;
    int endTag = 0;
    while (!endTag && curr <= end) {
        int next = curr + 1;
        if (xml[curr] == '<' && xml[next] == '/') {
            /* End tag found */
            next += 1;
            while (xml[next] != '>') {
                next++;
            }
            /* Recursively parse children */
            node->children = parseXML(xml, curr, next, idx);
            *idx = next+1;
            endTag = 1;
        } else if (xml[curr] == '<') {
            /* Recursively parse children */
            node->children = parseXML(xml, curr, end, idx);
            curr = *idx;
        } else {
            /* Add to node text */
            next = curr + 1;
            while (xml[next] != '<') {
                next++;
            }
            char* text = (char*)malloc((next - curr) * sizeof(char));
            strncpy(text, xml + curr, next - curr);
            text[next - curr] = '\0';
            node->text = text;
            curr = next;
        }
    }

    /* Find next XML node */
    if (curr <= end) {
        node->next = parseXML(xml, curr, end, idx);
    }

    /* Return root node */
    return node;
}

/* Function to print XML tree */
void printTree(TreeNode* node, int depth) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("<%s>", node->tag);
    if (strcmp(node->text, "") != 0) {
        printf("%s", node->text);
    }
    printf("\n");
    printTree(node->children, depth+1);
    printTree(node->next, depth);
}

int main() {
    char* xml = "<html><head><title>Page Title</title></head><body><h1>Header 1</h1><p>Paragraph 1</p><h2>Header 2</h2><p>Paragraph 2</p></body></html>";
    int idx = 0;
    TreeNode* root = parseXML(xml, 0, strlen(xml)-1, &idx);
    printTree(root, 0);
    return 0;
}