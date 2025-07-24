//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define D 2   // the B-tree order
#define N (2*D)

typedef struct node{
  int keys[N];
  struct node *childPtrs[N+1];
  int numKeys;
  int isLeaf;
} Node;

Node *root = NULL;

int search(Node *node, int key) {
  int i = 0;
  while(i < node->numKeys && key > node->keys[i])
    i++;
  if(i < node->numKeys && key == node->keys[i])
    return 1;
  if(node->isLeaf)
    return -1;
  return search(node->childPtrs[i], key);
}

void split(Node *node, int midIndex, Node **newNode) {
  *newNode = (Node*) malloc(sizeof(Node));
  (*newNode)->numKeys = D - 1;
  (*newNode)->isLeaf = node->isLeaf;

  for(int i = 0; i < D-1; i++) {
    (*newNode)->keys[i] = node->keys[i+midIndex+1];
  }

  if(!node->isLeaf) {
    for(int i = 0; i < D; i++) {
      (*newNode)->childPtrs[i] = node->childPtrs[i+midIndex+1];
    }
  }

  node->numKeys = D-1;
  for(int i = node->numKeys; i >= midIndex+1; i--) {
    node->childPtrs[i+1] = node->childPtrs[i];
  }

  node->childPtrs[midIndex+1] = *newNode;
  
  for(int i = node->numKeys-1; i >= midIndex; i--) {
    node->keys[i+1] = node->keys[i];
  }

  node->keys[midIndex] = (*newNode)->keys[0];
  node->numKeys += 1;
}

void insert(int key) {
  if(root == NULL) {
    root = (Node*) malloc(sizeof(Node));
    root->numKeys = 1;
    root->isLeaf = 1;
    root->keys[0] = key;
    return;
  }

  Node *node = root;
  Node *parent = NULL;

  while(!node->isLeaf) {
    parent = node;
    int i = 0;
    while(i < node->numKeys && key > node->keys[i])
      i++;
    node = node->childPtrs[i];
  }

  int i = 0;
  while(i < node->numKeys && key > node->keys[i])
    i++;
  
  for(int j = node->numKeys; j > i; j--) {
    node->keys[j] = node->keys[j-1];
  }

  node->keys[i] = key;
  node->numKeys += 1;

  if(node->numKeys == N) {
    Node *newNode = NULL;
    split(node, D, &newNode);
    if(parent == NULL) {
      root = (Node*) malloc(sizeof(Node));
      root->numKeys = 1;
      root->isLeaf = 0;
      root->keys[0] = newNode->keys[0];
      root->childPtrs[0] = node;
      root->childPtrs[1] = newNode;
    }
    else {
      insertNonFull(parent, newNode->keys[0], node, newNode);
    }
  }
}

void insertNonFull(Node *node, int key, Node *leftChild, Node *rightChild) {
  int i = node->numKeys - 1;

  if(node->isLeaf) {

    while(i >= 0 && key < node->keys[i]) {
      node->keys[i+1] = node->keys[i];
      i--;
    }

    node->keys[i+1] = key;
    node->numKeys += 1;

    for(int j = node->numKeys; j > i+2; j--) {
      node->childPtrs[j] = node->childPtrs[j-1];
    }

    node->childPtrs[i+1] = leftChild;
    node->childPtrs[i+2] = rightChild;
  }
  else {

    while(i >= 0 && key < node->keys[i]) {
      i--;
    }
    i += 1;

    if(node->childPtrs[i]->numKeys == N) {
      Node *newNode = NULL;
      split(node->childPtrs[i], D, &newNode);

      for(int j = node->numKeys; j > i; j--) {
        node->keys[j] = node->keys[j-1];
      }

      for(int j = node->numKeys+1; j > i+1; j--) {
        node->childPtrs[j] = node->childPtrs[j-1];
      }

      node->keys[i] = newNode->keys[0];
      node->numKeys += 1;

      node->childPtrs[i] = node->childPtrs[i];
      node->childPtrs[i+1] = node->childPtrs[i+1];

      if(key > node->keys[i])
        insertNonFull(newNode, key, leftChild, rightChild);
      else
        insertNonFull(node->childPtrs[i], key, leftChild, rightChild);
    }
    else {
      insertNonFull(node->childPtrs[i], key, leftChild, rightChild);
    }
  }
}

void printInOrder(Node *node) {
  if(node == NULL)
    return;
  for(int i = 0; i < node->numKeys; i++) {
    printInOrder(node->childPtrs[i]);
    printf("%d ", node->keys[i]);
  }
  printInOrder(node->childPtrs[node->numKeys]);
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50);
  insert(60);
  insert(70);
  insert(80);
  insert(90);
  insert(100);

  printInOrder(root);
  
  return 0;
}