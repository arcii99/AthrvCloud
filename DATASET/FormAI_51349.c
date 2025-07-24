//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct node {
  char* key;
  char* value;
  struct node* next;
};

struct node* hashtable[HASHSIZE];

// hash function for given key
unsigned int hash(char* key) {
  unsigned int hashvalue = 0;
  while (*key != '\0') {
    hashvalue = *key + (hashvalue << 5) - hashvalue;
    key++;
  }
  return hashvalue % HASHSIZE;
}

// lookup for key in hashtable
struct node* lookup(char* key) {
  unsigned int hashvalue = hash(key);
  struct node* np = hashtable[hashvalue];

  while (np != NULL) {
    if (strcmp(key, np->key) == 0) {
      return np;
    }
    np = np->next;
  }
  return NULL;
}

// insert new key-value pair in hashtable
void insert(char* key, char* value) {
  unsigned int hashvalue = hash(key);
  struct node* np = hashtable[hashvalue];
  struct node* new_node;

  if ((new_node = malloc(sizeof(struct node))) == NULL) {
    printf("Memory allocation error\n");
    return;
  }

  new_node->key = key;
  new_node->value = value;
  new_node->next = NULL;

  // insert new node at the beginning of linked list
  if (np == NULL) {
    hashtable[hashvalue] = new_node;
  } else {
    new_node->next = hashtable[hashvalue];
    hashtable[hashvalue] = new_node;
  }
}

// main function to test
int main() {
  char* keys[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape"};
  char* values[] = {"A", "B", "C", "D", "E", "F", "G"};
  int i;

  for (i = 0; i < sizeof(keys) / sizeof(char*); i++) {
    insert(keys[i], values[i]);
  }

  struct node* np = lookup("banana");
  if (np != NULL) {
    printf("The value for key %s is %s\n", np->key, np->value);
  } else {
    printf("Key not found\n");
  }

  return 0;
}