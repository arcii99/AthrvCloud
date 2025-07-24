//FormAI DATASET v1.0 Category: Compression algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000 // maximum length of input string

// function to perform run-length encoding compression
char* rle_compress(char* input)
{
    int len = strlen(input);

    // output string should not be larger than input string
    char* output = (char*) malloc(len * sizeof(char));
    int out_index = 0;

    for(int i = 0; i < len; i++)
    {
        int count = 1;
        while(i < len - 1 && input[i] == input[i + 1])
        {
            count++;
            i++;
        }
        output[out_index++] = input[i];
        output[out_index++] = count + '0';
    }
    output[out_index] = '\0';

    return output;
}

// function to perform huffman encoding compression
char* huffman_compress(char* input)
{
    int len = strlen(input);

    // count frequency of each character
    int freq[128] = {0};
    for(int i = 0; i < len; i++)
        freq[(int) input[i]]++;

    // construct the huffman tree
    // using array of nodes and min heap
    struct Node {
        char data;
        int freq;
        struct Node *left, *right;
    };

    struct Node* new_node(char data, int freq) 
    {
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->data = data;
        node->freq = freq;
        node->left = node->right = NULL;
        return node;
    }

    struct MinHeap {
        int size;
        struct Node** array;
    };

    struct MinHeap* create_min_heap(int capacity)
    {
        struct MinHeap* min_heap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
        min_heap->size = 0;
        min_heap->array = (struct Node**) malloc(capacity * sizeof(struct Node*));
        return min_heap;
    }

    void swap_nodes(struct Node** a, struct Node** b)
    {
        struct Node* temp = *a;
        *a = *b;
        *b = temp;
    }

    void min_heapify(struct MinHeap* min_heap, int index)
    {
        int smallest = index;
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;

        if(left_child < min_heap->size && min_heap->array[left_child]->freq < min_heap->array[smallest]->freq)
            smallest = left_child;

        if(right_child < min_heap->size && min_heap->array[right_child]->freq < min_heap->array[smallest]->freq)
            smallest = right_child;

        if(smallest != index)
        {
            swap_nodes(&(min_heap->array[smallest]), &(min_heap->array[index]));
            min_heapify(min_heap, smallest);
        }
    }

    int is_size_one(struct MinHeap* min_heap)
    {
        return (min_heap->size == 1);
    }

    struct Node* extract_min(struct MinHeap* min_heap)
    {
        struct Node* temp = min_heap->array[0];
        min_heap->array[0] = min_heap->array[min_heap->size - 1];
        min_heap->size--;
        min_heapify(min_heap, 0);
        return temp;
    }

    void insert_node(struct MinHeap* min_heap, struct Node* node)
    {
        min_heap->size++;
        int i = min_heap->size - 1;
        while(i && node->freq < min_heap->array[(i - 1) / 2]->freq)
        {
            min_heap->array[i] = min_heap->array[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        min_heap->array[i] = node;
    }

    struct Node* build_huffman_tree(int freq[], int size)
    {
        struct Node *left, *right, *top;

        struct MinHeap* min_heap = create_min_heap(size);

        for(int i = 0; i < size; i++)
            insert_node(min_heap, new_node((char) i, freq[i]));

        while(!is_size_one(min_heap))
        {
            left = extract_min(min_heap);
            right = extract_min(min_heap);

            top = new_node('$', left->freq + right->freq);
            top->left = left;
            top->right = right;

            insert_node(min_heap, top);
        }

        return extract_min(min_heap);
    }

    // build huffman code for each character
    void build_huffman_code(struct Node* root, char* code, int depth, char** huffman_codes)
    {
        if(root->left)
        {
            code[depth] = '0';
            build_huffman_code(root->left, code, depth + 1, huffman_codes);
        }

        if(root->right)
        {
            code[depth] = '1';
            build_huffman_code(root->right, code, depth + 1, huffman_codes);
        }

        if(!root->left && !root->right)
        {
            huffman_codes[(int) root->data] = (char*) malloc((depth + 1) * sizeof(char));
            for(int i = 0; i < depth; i++)
                huffman_codes[(int) root->data][i] = code[i];
            huffman_codes[(int) root->data][depth] = '\0';
        }
    }

    // generate compressed output from huffman codes
    char* output = (char*) malloc(MAX_LEN * sizeof(char));
    int out_index = 0;

    char* huffman_codes[128] = {NULL};
    char code[MAX_LEN];
    build_huffman_code(build_huffman_tree(freq, 128), code, 0, huffman_codes);

    for(int i = 0; i < len; i++)
    {
        strcat(output, huffman_codes[(int) input[i]]);
        out_index += strlen(huffman_codes[(int) input[i]]);
    }

    return output;
}

int main() {
    char input[MAX_LEN];
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    char* rle_output = rle_compress(input);
    printf("Run-length encoding compressed output: %s\n", rle_output);
    free(rle_output);

    char* huffman_output = huffman_compress(input);
    printf("Huffman encoding compressed output: %s\n", huffman_output);
    free(huffman_output);

    return 0;
}