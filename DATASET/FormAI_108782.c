//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct HuffmanNode{
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
}HuffmanNode;

typedef struct MinHeap{
    unsigned size;
    unsigned capacity;
    HuffmanNode **array;
}MinHeap;

typedef struct CodeTable{
    char data;
    int freq;
    char *code;
}CodeTable;

HuffmanNode* create_node(char data, unsigned freq){
    HuffmanNode* node = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

MinHeap* create_min_heap(unsigned capacity){
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HuffmanNode**) malloc(minHeap->capacity * sizeof(HuffmanNode*));
    return minHeap;
}

void swap(HuffmanNode **x, HuffmanNode **y){
    HuffmanNode* temp = *x;
    *x = *y;
    *y = temp;
}

void min_heapify(MinHeap* minHeap, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq){
        smallest = left;
    }

    if(right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq){
        smallest = right;
    }

    if(smallest != index){
        swap(&minHeap->array[smallest], &minHeap->array[index]);
        min_heapify(minHeap, smallest);
    }
}

int is_size_one(MinHeap* minHeap){
    return (minHeap->size == 1);
}

HuffmanNode* extract_min(MinHeap* minHeap){
    HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    min_heapify(minHeap, 0);
    return temp;
}

void insert_min_heap(MinHeap* minHeap, HuffmanNode* node){
    ++minHeap->size;
    int i = minHeap->size - 1;
    while(i && node->freq < minHeap->array[(i - 1) / 2]->freq){
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

void build_min_heap(MinHeap* minHeap){
    int n = minHeap->size - 1;
    for(int i = (n - 1) / 2; i >= 0; --i){
        min_heapify(minHeap, i);
    }
}

void print_array(int* arr, int n){
    for(int i = 0; i < n; ++i){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int get_leaf_node(HuffmanNode* root){
    return !(root->left) && !(root->right);
}

void generate_code_table(HuffmanNode* root, int arr[], int top, CodeTable** table, int* code_table_size){
    if(root->left){
        arr[top] = 0;
        generate_code_table(root->left, arr, top + 1, table, code_table_size);
    }

    if(root->right){
        arr[top] = 1;
        generate_code_table(root->right, arr, top + 1, table, code_table_size);
    }

    if(get_leaf_node(root)){
        (*table) = (CodeTable*) realloc(*table, (*code_table_size + 1) * sizeof(CodeTable));
        (*table)[*code_table_size].data = root->data;
        (*table)[*code_table_size].freq = root->freq;
        (*table)[*code_table_size].code = (char*) malloc((top + 1) * sizeof(char));
        for(int i = 0; i < top; ++i){
            (*table)[*code_table_size].code[i] = arr[i] + '0';
        }
        (*table)[*code_table_size].code[top] = '\0';
        ++(*code_table_size);
    }
}

void print_code_table(CodeTable* table, int size){
    printf("Data\tFrequency\tCode\n");
    for(int i = 0; i < size; ++i){
        printf("%c\t%d\t\t%s\n", table[i].data, table[i].freq, table[i].code);
    }
}

CodeTable* huffman_code(char* string, int* code_table_size){
    int freq[256] = {0};
    for(int i = 0; string[i]; ++i){
        ++freq[string[i]];
    }

    MinHeap* minHeap = create_min_heap(256);
    for(int i = 0; i < 256; ++i){
        if(freq[i]){
            insert_min_heap(minHeap, create_node(i, freq[i]));
        }
    }

    while(!is_size_one(minHeap)){
        HuffmanNode* left = extract_min(minHeap);
        HuffmanNode* right = extract_min(minHeap);
        HuffmanNode* node = create_node('$', left->freq + right->freq);
        node->left = left;
        node->right = right;
        insert_min_heap(minHeap, node);
    }

    HuffmanNode* root = extract_min(minHeap);

    int arr[MAX_TREE_HT], top = 0;
    CodeTable* code_table = NULL;
    generate_code_table(root, arr, top, &code_table, code_table_size);

    return code_table;
}

int main(){
    char string[] = "Artistic Programming with Huffman Coding";
    int code_table_size;
    CodeTable* table = huffman_code(string, &code_table_size);
    print_code_table(table, code_table_size);
    return 0;
}