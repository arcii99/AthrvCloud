//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CACHE_SIZE 1000

typedef struct node {
  struct node *prev;
  struct node *next;
  int key;
  int value;
} Node;

typedef struct cache {
  Node *head;
  Node *tail;
  int size;
  int capacity;
  Node **nodes;
} Cache;

Cache *cache_create(int capacity) {
  Cache *cache = (Cache *)malloc(sizeof(Cache));
  cache->size = 0;
  cache->capacity = capacity;
  cache->nodes = (Node **)calloc(capacity, sizeof(Node *));
  cache->head = (Node *)malloc(sizeof(Node));
  cache->tail = (Node *)malloc(sizeof(Node));
  cache->head->prev = NULL;
  cache->head->next = cache->tail;
  cache->tail->prev = cache->head;
  cache->tail->next = NULL;
  return cache;
}

void cache_delete(Cache *cache) {
  Node *node = cache->head->next;
  while (node != cache->tail) {
    Node *next = node->next;
    free(node);
    node = next;
  }
  free(cache->head);
  free(cache->tail);
  free(cache->nodes);
  free(cache);
}

void cache_move_to_front(Cache *cache, Node *node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  node->next = cache->head->next;
  node->prev = cache->head;
  cache->head->next->prev = node;
  cache->head->next = node;
}

void cache_remove_least_recently_used(Cache *cache) {
  Node *node = cache->tail->prev;
  node->prev->next = cache->tail;
  cache->tail->prev = node->prev;
  cache->nodes[node->key % cache->capacity] = NULL;
  free(node);
  cache->size--;
}

int cache_get(Cache *cache, int key) {
  Node *node = cache->nodes[key % cache->capacity];
  if (node == NULL) {
    return -1;
  }
  cache_move_to_front(cache, node);
  return node->value;
}

void cache_put(Cache *cache, int key, int value) {
  Node *node = cache->nodes[key % cache->capacity];
  if (node != NULL) {
    node->value = value;
    cache_move_to_front(cache, node);
    return;
  }
  node = (Node *)malloc(sizeof(Node));
  node->key = key;
  node->value = value;
  cache->nodes[key % cache->capacity] = node;
  node->next = cache->head->next;
  node->prev = cache->head;
  cache->head->next->prev = node;
  cache->head->next = node;
  cache->size++;
  if (cache->size > cache->capacity) {
    cache_remove_least_recently_used(cache);
  }
}

int main() {
  Cache *cache = cache_create(MAX_CACHE_SIZE);
  cache_put(cache, 1, 1);
  cache_put(cache, 2, 2);
  printf("%d\n", cache_get(cache, 1));
  cache_put(cache, 3, 3);
  printf("%d\n", cache_get(cache, 2));
  cache_put(cache, 4, 4);
  printf("%d\n", cache_get(cache, 1));
  printf("%d\n", cache_get(cache, 3));
  printf("%d\n", cache_get(cache, 4));
  cache_delete(cache);
  return 0;
}