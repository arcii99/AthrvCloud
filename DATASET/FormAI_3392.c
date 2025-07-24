//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the structure of each node in the Huffman tree
struct node{
    char ch; // The character
    int freq; // The frequency of the character
    struct node *left, *right; // Pointer to left and right child nodes in the Huffman tree
};

// Function to create a new node in the Huffman tree
struct node* createNode(char ch, int freq){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to sort the nodes in ascending order of their frequency
void sortNodes(struct node **nodes, int numNodes){
    int i, j;
    struct node *tempNode;
    for(i=0;i<numNodes;i++){
        for(j=i+1;j<numNodes;j++){
            if(nodes[i]->freq > nodes[j]->freq){
                tempNode = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = tempNode;
            }
        }
    }
}

// Function to build Huffman tree
struct node* buildTree(char *str){
    int i, j, len;
    len = strlen(str);
    struct node **nodes = (struct node **)malloc(sizeof(struct node)*len);
    for(i=0;i<len;i++){
        nodes[i] = createNode(str[i], 1);
        for(j=i+1;j<len;j++){
            if(str[i] == str[j]){
                nodes[i]->freq++;
                str[j] = -1;
            }
        }
    }

    int numNodes = 0;
    for(i=0;i<len;i++){
        if(nodes[i]->ch != -1){
            numNodes++;
        }
    }

    while(numNodes>1){
        sortNodes(nodes, len);
        struct node *leftChild, *rightChild, *parent;
        leftChild = nodes[0];
        rightChild = nodes[1];
        parent = createNode('$', leftChild->freq+rightChild->freq);
        parent->left = leftChild;
        parent->right = rightChild;
        nodes[0] = parent;
        nodes[1] = NULL;
        numNodes--;

        int index=1;
        for(i=2;i<len;i++){
            if(nodes[i] != NULL){
                nodes[index] = nodes[i];
                index++;
            }
        }
    }

    return nodes[0];
}

// Function to print Huffman code for each character recursively
void printHuffmanCode(struct node *root, char *code, int index){
    if(root->left){
        code[index] = '0';
        printHuffmanCode(root->left, code, index+1);
    }

    if(root->right){
        code[index] = '1';
        printHuffmanCode(root->right, code, index+1);
    }

    if(root->left == NULL && root->right == NULL){
        code[index] = '\0';
        printf("%c : %s\n", root->ch, code);
    }
}

int main(){
    char str[] = "The quick brown fox jumps over the lazy dog";
    struct node *huffmanTree = buildTree(str);
    char code[100];
    printf("Huffman Codes are :\n");
    printHuffmanCode(huffmanTree, code, 0);
    return 0;
}