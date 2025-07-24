//FormAI DATASET v1.0 Category: Image compression ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BYTE_SIZE 8

// A Huffman tree node
struct huff_node {
  unsigned char data;
  unsigned freq;
  struct huff_node *left, *right;
};

// A priority queue node
struct pq_node {
  struct huff_node *huff;
  struct pq_node *next;
};

// A priority queue
struct pq {
  struct pq_node *front, *rear;
};

// Create a new Huffman node
struct huff_node* new_huff_node(unsigned char data, unsigned freq) {
  struct huff_node* node =
      (struct huff_node*) malloc(sizeof(struct huff_node));
  node->data = data;
  node->freq = freq;
  node->left = node->right = NULL;
  return node;
}

// Create a new priority queue node
struct pq_node* new_pq_node(struct huff_node *huff) {
  struct pq_node *node =
      (struct pq_node*) malloc(sizeof(struct pq_node));
  node->huff = huff;
  node->next = NULL;
  return node;
}

// Create a new priority queue
struct pq* new_pq() {
  struct pq *q = (struct pq*) malloc(sizeof(struct pq));
  q->front = q->rear = NULL;
  return q;
}

// Check if the priority queue is empty
bool is_pq_empty(struct pq *q) {
  return (q->front == NULL);
}

// Enqueue a priority queue node
void pq_enqueue(struct pq *q, struct pq_node *node) {
  if (is_pq_empty(q)) {
    q->front = q->rear = node;
  } else {
    struct pq_node *current = q->front, *prev = NULL;
    while (current != NULL && current->huff->freq <= node->huff->freq) {
      prev = current;
      current = current->next;
    }
    if (prev == NULL) {
      node->next = current;
      q->front = node;
    } else {
      node->next = current;
      prev->next = node;
    }
    if (node->next == NULL) {
      q->rear = node;
    }
  }
}

// Dequeue a priority queue node
struct pq_node* pq_dequeue(struct pq *q) {
  if (is_pq_empty(q)) {
    return NULL;
  } else {
    struct pq_node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
      q->rear = NULL;
    }
    return temp;
  }
}

// Create a Huffman tree from given character frequencies
struct huff_node* create_huffman_tree(unsigned char *data, unsigned *freq, unsigned size) {
  struct pq *q = new_pq();
  for (unsigned i = 0; i < size; i++) {
    pq_enqueue(q, new_pq_node(new_huff_node(data[i], freq[i])));
  }
  while (!is_pq_empty(q) && q->front->next != NULL) {
    struct pq_node *node1 = pq_dequeue(q);
    struct pq_node *node2 = pq_dequeue(q);
    struct huff_node *h1 = node1->huff, *h2 = node2->huff;
    pq_enqueue(q, new_pq_node(new_huff_node(
        '\0', h1->freq + h2->freq)));
    struct pq_node *new_node = q->rear;
    new_node->huff->left = h1;
    new_node->huff->right = h2;
    free(node1);
    free(node2);
  }
  struct huff_node *tree = q->front->huff;
  free(q->front);
  free(q);
  return tree;
}

// Convert a decimal number to a binary string
void to_binary(unsigned char num, unsigned char *s) {
  for (int i = BYTE_SIZE - 1; i >= 0; i--) {
    s[BYTE_SIZE - 1 - i] = ((num & (1 << i)) ? '1' : '0');
  }
  s[BYTE_SIZE] = '\0';
}

// Traverse the Huffman tree and generate codes for each character
void generate_codes(struct huff_node *tree, unsigned char *code, int depth,
                    unsigned char **codes) {
  if (tree->left == NULL && tree->right == NULL) {
    codes[tree->data] = (unsigned char*) malloc((depth + 1) * sizeof(unsigned char));
    memcpy(codes[tree->data], code, depth + 1);
  } else {
    code[depth] = '0';
    generate_codes(tree->left, code, depth + 1, codes);
    code[depth] = '1';
    generate_codes(tree->right, code, depth + 1, codes);
  }
}

// Compress the image using the generated codes
void compress_image(unsigned char *img, unsigned img_size,
                    unsigned char **codes, unsigned *code_lens,
                    unsigned char **compressed_img, unsigned *compressed_size) {
  *compressed_img = (unsigned char*) malloc(img_size * sizeof(unsigned char));
  unsigned bits_written = 0, byte_index = 0;
  unsigned char cur_byte = 0;
  for (unsigned i = 0; i < img_size; i++) {
    unsigned char *code = codes[img[i]];
    unsigned code_len = code_lens[img[i]];
    for (unsigned j = 0; j < code_len; j++) {
      if (code[j] == '1') {
        cur_byte |= (1 << (BYTE_SIZE - 1 - bits_written));
      }
      bits_written++;
      if (bits_written == BYTE_SIZE) {
        (*compressed_img)[byte_index++] = cur_byte;
        bits_written = 0;
        cur_byte = 0;
      }
    }
  }
  if (bits_written != 0) {
    (*compressed_img)[byte_index] = cur_byte;
    *compressed_size = byte_index + 1;
  } else {
    *compressed_size = byte_index;
  }
}

int main() {
  // Read in the image data
  unsigned char img[] = {255, 255, 255, 0, 0, 0, 255, 255};
  unsigned img_size = 8;

  // Calculate character frequencies
  unsigned char data[256] = {0};
  unsigned freq[256] = {0};
  for (unsigned i = 0; i < img_size; i++) {
    freq[img[i]]++;
  }
  unsigned num_chars = 0;
  for (unsigned i = 0; i < 256; i++) {
    if (freq[i] != 0) {
      data[num_chars++] = i;
    }
  }

  // Create the Huffman tree
  struct huff_node *tree = create_huffman_tree(data, freq, num_chars);

  // Generate codes for each character
  unsigned char **codes = (unsigned char**) malloc(256 * sizeof(unsigned char*));
  unsigned *code_lens = (unsigned*) malloc(256 * sizeof(unsigned));
  unsigned char code[BYTE_SIZE + 1] = {0};
  generate_codes(tree, code, 0, codes);
  for (unsigned i = 0; i < 256; i++) {
    if (codes[i] != NULL) {
      code_lens[i] = strlen((const char*) codes[i]);
    }
  }

  // Compress the image data using the generated codes
  unsigned char *compressed_img;
  unsigned compressed_size;
  compress_image(img, img_size, codes, code_lens, &compressed_img, &compressed_size);

  // Print out the original image data and the compressed image data
  printf("Original Image: ");
  for (unsigned i = 0; i < img_size; i++) {
    printf("%u ", img[i]);
  }
  printf("\n");

  printf("Compressed Image: ");
  for (unsigned i = 0; i < compressed_size; i++) {
    printf("%u ", compressed_img[i]);
  }
  printf("\n");

  // Free memory
  for (unsigned i = 0; i < 256; i++) {
    if (codes[i] != NULL) {
      free(codes[i]);
    }
  }
  free(codes);
  free(code_lens);
  free(compressed_img);
  free(tree);

  return 0;
}