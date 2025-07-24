//FormAI DATASET v1.0 Category: Compression algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** array;
} MinHeap;

typedef struct HuffmanNode {
  char data;
  int *codes;
  int top;
} HuffmanNode;

unsigned char read_byte(FILE* file);
void write_binary(FILE* file, unsigned char value, unsigned int len, unsigned int* bits_buf, unsigned char* buf_pos);
int read_binary(FILE* file, unsigned int len, unsigned int* bits_buf, unsigned char* buf_pos);

MinHeapNode* new_node(char data, unsigned freq) {
    MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

MinHeap* create_min_heap(unsigned capacity) {
    MinHeap* min_heap = (MinHeap*) malloc(sizeof(MinHeap));

    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (MinHeapNode**) malloc(min_heap->capacity * sizeof(MinHeapNode*));

    return min_heap;
}

void swap_node(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void min_heapify(MinHeap* min_heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != index) {
        swap_node(&min_heap->array[smallest], &min_heap->array[index]);
        min_heapify(min_heap, smallest);
    }
}

int is_size_one(MinHeap* min_heap) {
    return (min_heap->size == 1);
}

MinHeapNode* extract_min(MinHeap* min_heap) {
    MinHeapNode* temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    min_heapify(min_heap, 0);
    return temp;
}

void insert_min_heap(MinHeap* min_heap, MinHeapNode* min_heap_node) {
    ++min_heap->size;
    int i = min_heap->size - 1;

    while (i && min_heap_node->freq < min_heap->array[(i - 1) / 2]->freq) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    min_heap->array[i] = min_heap_node;
}

void build_min_heap(MinHeap* min_heap) {
    int n = min_heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        min_heapify(min_heap, i);
    }
}

int is_leaf(MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

MinHeap* create_and_build_min_heap(char* data, int* freq, int size) {
    MinHeap* min_heap = create_min_heap(size);

    for (int i = 0; i < size; ++i) {
        min_heap->array[i] = new_node(data[i], freq[i]);
    }

    min_heap->size = size;
    build_min_heap(min_heap);

    return min_heap;
}

MinHeapNode* build_huffman_tree(char* data, int* freq, int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* min_heap = create_and_build_min_heap(data, freq, size);

    while (!is_size_one(min_heap)) {
        left = extract_min(min_heap);
        right = extract_min(min_heap);

        top = new_node('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insert_min_heap(min_heap, top);
    }

    return extract_min(min_heap);
}

void print_codes(MinHeapNode* root, int* arr, int top, HuffmanNode* huff_tree[]) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1, huff_tree);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1, huff_tree);
    }

    if (is_leaf(root)) {
        huff_tree[root->data] = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        huff_tree[root->data]->codes = (int*)malloc(top * sizeof(int));
        memcpy(huff_tree[root->data]->codes, arr, top * sizeof(int));
        huff_tree[root->data]->top = top;
    }
}

void compress(char* data, int* freq, int n, char* file_in_name, char* file_out_name, HuffmanNode* huff_tree[]) {
  FILE* file_in = fopen( file_in_name , "rb");
  FILE* file_out = fopen( file_out_name, "wb+");
  unsigned int bits_buf = 0;
  unsigned char buf_pos = 8;
  int i;

  for(i = 0; i < n; ++i){
    huff_tree[data[i]] = (HuffmanNode*)malloc(sizeof(HuffmanNode));
  }
  
  MinHeapNode* root = build_huffman_tree(data, freq, n);
  int arr[MAX_TREE_HT];
  print_codes(root, arr, 0, huff_tree);

  fwrite(&n, sizeof(int), 1, file_out);
  fwrite(freq, sizeof(int), n, file_out);

  fseek(file_in, 0, SEEK_END);
  long int size = ftell(file_in);
  fseek(file_in, 0, SEEK_SET);

  fwrite(&size, sizeof(long int), 1, file_out);

  unsigned char byte;
  while((byte = read_byte(file_in)) != EOF) {
    for(i = 0; i < huff_tree[byte]->top; ++i) {
      buf_pos--;
      unsigned int bit = (huff_tree[byte]->codes)[i];
      bits_buf |= bit << buf_pos;
      if(buf_pos == 0) {
        buf_pos = 8;
        fwrite(&bits_buf, sizeof(unsigned char), 1, file_out);
        bits_buf = 0;
      }
    }
  }

  if(buf_pos != 8)
    fwrite(&bits_buf, sizeof(unsigned char), 1, file_out);

  fclose(file_in);
  fclose(file_out);
}

void decompress(char* file_in_name, char* file_out_name) {
  FILE* file_in = fopen(file_in_name, "rb");
  FILE* file_out = fopen(file_out_name, "wb+");
  unsigned int bits_buf = 0;
  unsigned char buf_pos = 8;
  int freq[256];
  int i, n;

  fread(&n,sizeof(int),1,file_in);
  fread(freq,sizeof(int),256,file_in);

  int huff_tree_size = n<<1;
  HuffmanNode* huff_tree[256];
  for(i; i < 256; ++i){
    huff_tree[i] = NULL;
  }
  int j,tp,root;
  for(i = 0; i < huff_tree_size ; i+=2){
    j = 0;
    do{
      tp = read_binary(file_in, 1, &bits_buf, &buf_pos);
      j |= tp;
      if(i != huff_tree_size - 2)
        j = j << 1;
    } while(tp == 0 || tp == 1);
    huff_tree[i >> 1] = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    huff_tree[i >> 1]->codes = (int*)malloc(j * sizeof(int));
    huff_tree[i >> 1]->top = j;
    for(j = 0; j < huff_tree[i >> 1]->top; ++j) {
        tp = read_binary(file_in, 1, &bits_buf, &buf_pos);
        huff_tree[i >> 1]->codes[j] = tp;
    }
  }

  int size;
  fread(&size,sizeof(long int),1,file_in);

  root = i = 0;
  while(i < size){
    HuffmanNode* node = huff_tree[root];
    while(node->codes[(bits_buf>>(buf_pos - 1)) & 1] == 0 || node->codes[(bits_buf>>(buf_pos - 1)) & 1] == 1){
      node = huff_tree[node->codes[(bits_buf>>(buf_pos - 1)) & 1]];
      buf_pos--;
      if(buf_pos == 0){
        buf_pos = 8;
        bits_buf = read_byte(file_in);
      }
    }
    fwrite(&(node->data), sizeof(char), 1, file_out);
    root = 0;
    ++i;
  }

  fclose(file_in);
  fclose(file_out);
}

unsigned char read_byte(FILE* file) {
  char byte;
  if (!fread(&byte, sizeof(char), 1, file)) {
    return EOF;
  }
  return byte;
}

void write_binary(FILE* file, unsigned char value, unsigned int len, unsigned int* bits_buf, unsigned char* buf_pos) {
  for (int i=len-1; i>=0; --i) {
    *bits_buf |= ((value >> i) & 1) << (*buf_pos - 1);
    (*buf_pos)--;
    if (*buf_pos == 0) {
      fwrite(bits_buf, sizeof(unsigned char), 1, file);
      *bits_buf = 0;
      *buf_pos = 8;
    }
  }
}

int read_binary(FILE* file, unsigned int len, unsigned int* bits_buf, unsigned char* buf_pos) {
  int res = 0;
  for (int i=len-1; i>=0; --i) {
    res |= read_byte(file) << i;
  }
  *bits_buf = res;
  *buf_pos = 0;
  return res;
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    HuffmanNode* huff_tree[256];
    memset(huff_tree, 0, sizeof(huff_tree));

    compress(data, freq, 6, "test.txt", "compressed.bin", huff_tree);
    decompress("compressed.bin", "decompressed.txt");

    return 0;
}