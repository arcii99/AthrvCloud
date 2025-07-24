//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int value;
    char key;
    struct node *left, *right;
} Node;

typedef struct frequency {
    int value;
    char key;
    struct frequency *next;
} Freq;

Freq *createFreqList(char *text) {
    int len = strlen(text);
    Freq *head = NULL, *last = NULL;

    for (int i = 0; i < len; i++) {
        char c = text[i];
        Freq *new = (Freq*)malloc(sizeof(Freq));
        new->value = 1;
        new->key = c;
        new->next = NULL;

        if (head == NULL) {
            head = last = new;
        } else {
            if (c == last->key) {
                last->value++;
                free(new);
            } else {
                last = last->next = new;
            }
        }
    }

    return head;
}

Node *createNode(int value, char key) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->value = value;
    new->key = key;
    new->left = new->right = NULL;
    return new;
}

void addNode(Node **nodes, int *n, Node *new) {
    int i = (*n)++;
    while (i > 0 && nodes[(i-1)/2]->value > new->value) {
        nodes[i] = nodes[(i-1)/2];
        i = (i-1)/2;
    }
    nodes[i] = new;
}

Node *pollNode(Node **nodes, int *n) {
    Node *root = nodes[0];
    Node *lastNode = nodes[--(*n)];

    int i = 0;
    while (2*i+1 < *n) {
        int j = 2*i+1;
        if (j+1 < *n && nodes[j+1]->value < nodes[j]->value) j++;
        if (lastNode->value <= nodes[j]->value) break;
        nodes[i] = nodes[j];
        i = j;
    }

    nodes[i] = lastNode;
    return root;
}

Node *buildTree(Freq *freqList) {
    int n = 0;
    Node *nodes[128] = {0};

    while (freqList != NULL) {
        addNode(nodes, &n, createNode(freqList->value, freqList->key));
        freqList = freqList->next;
    }

    while (n > 1) {
        Node *left = pollNode(nodes, &n);
        Node *right = pollNode(nodes, &n);

        addNode(nodes, &n, createNode(left->value + right->value, 0));
        nodes[n-1]->left = left;
        nodes[n-1]->right = right;
    }

    return nodes[0];
}

void buildCodes(Node *node, char *prefix, char **codes) {
    if (node == NULL) return;
    if (node->key != 0) codes[node->key] = strdup(prefix);

    int len = strlen(prefix);
    char *newPrefix = (char*)malloc(len+2);
    memcpy(newPrefix, prefix, len);
    newPrefix[len] = '0'; newPrefix[len+1] = 0;
    buildCodes(node->left, newPrefix, codes);

    newPrefix[len] = '1';
    buildCodes(node->right, newPrefix, codes);

    free(newPrefix);
}

void compress(char *text, char **codes) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        printf("%s", codes[text[i]]);
    }
    putchar('\n');
}

void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void freeFreqList(Freq *head) {
    while (head != NULL) {
        Freq *next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    char text1[] = "happyhappy";
    Freq *freqList1 = createFreqList(text1);
    Node *root1 = buildTree(freqList1);
    char *codes1[128] = {0};
    buildCodes(root1, "", codes1);
    printf("Text1: %s\n", text1);
    compress(text1, codes1);
    freeTree(root1);
    freeFreqList(freqList1);

    char text2[] = "let's celebrate with some happy code!";
    Freq *freqList2 = createFreqList(text2);
    Node *root2 = buildTree(freqList2);
    char *codes2[128] = {0};
    buildCodes(root2, "", codes2);
    printf("Text2: %s\n", text2);
    compress(text2, codes2);
    freeTree(root2);
    freeFreqList(freqList2);

    return 0;
}