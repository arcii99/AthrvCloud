//FormAI DATASET v1.0 Category: Image compression ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Struct for storing Huffman Tree Node
typedef struct node {
    unsigned char val;
    int freq;
    struct node *left, *right;
} node_t;

//Struct for storing Heap Node
typedef struct heap_node {
    node_t *node;
    struct heap_node *next;
} heap_node_t;

//Struct for storing Huffman Code Table entry
typedef struct code {
    unsigned char len;
    unsigned int bits;
} code_t;

//Struct for storing image details
typedef struct image {
    unsigned char *data;
    int width;
    int height;
} image_t;

//Function to insert node in sorted order in linked list
void insert_node(heap_node_t **head, heap_node_t *new_node) {
    if (*head == NULL || new_node->node->freq <= (*head)->node->freq) {
        new_node->next = *head;
        *head = new_node;
    } else {
        heap_node_t *curr = *head;
        while (curr->next != NULL && curr->next->node->freq < new_node->node->freq) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

//Function to extract min node in heap linked list
node_t *extract_min(heap_node_t **head) {
    heap_node_t *temp = *head;
    *head = (*head)->next;
    node_t *node = temp->node;
    free(temp);
    return node;
}

//Function to construct Huffman Tree and return root node
node_t *build_huffman_tree(int *freqs) {
    heap_node_t *head = NULL;
    for (int i = 0; i < 256; i++) {
        if (freqs[i] > 0) { //if frequency of byte is non zero
            node_t *node = (node_t*) malloc(sizeof(node_t));
            node->val = i;
            node->freq = freqs[i];
            node->left = NULL;
            node->right = NULL;
            heap_node_t *new_node = (heap_node_t*) malloc(sizeof(heap_node_t));
            new_node->node = node;
            insert_node(&head, new_node);
        }
    }
    while (head->next != NULL) {
        node_t *left = extract_min(&head);
        node_t *right = extract_min(&head);
        node_t *parent = (node_t*) malloc(sizeof(node_t));
        parent->val = 0;
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;
        heap_node_t *new_node = (heap_node_t*) malloc(sizeof(heap_node_t));
        new_node->node = parent;
        insert_node(&head, new_node);
    }
    return extract_min(&head);
}

//Function to traverse Huffman Tree and populate code table
void traverse_tree(node_t *node, code_t *code_table, unsigned int bits, unsigned char len) {
    if (node->left == NULL && node->right == NULL) { //if leaf node
        code_table[node->val].bits = bits;
        code_table[node->val].len = len;
    } else {
        traverse_tree(node->left, code_table, (bits << 1), (len + 1)); //left child 0
        traverse_tree(node->right, code_table, (bits << 1) | 1, (len + 1)); //right child 1
    }
}

//Function to compress image using Huffman Coding and return compressed image
unsigned char *compress_image(image_t *image, int *compressed_size) {
    int freqs[256] = {0}; //frequency of each byte in image data
    for (int i = 0; i < image->width * image->height; i++) {
        freqs[image->data[i]]++;
    }
    node_t *root = build_huffman_tree(freqs);
    code_t code_table[256] = {0};
    traverse_tree(root, code_table, 0, 0);
    unsigned char *compressed_data = (unsigned char*) malloc(image->width * image->height); //max size of compressed data
    int curr_index = 0;
    unsigned int curr_byte = 0;
    unsigned char curr_len = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char byte = image->data[i];
        unsigned char len = code_table[byte].len;
        unsigned int bits = code_table[byte].bits;
        if (curr_len + len <= 8) { //if all bits fit in current byte
            curr_byte |= (bits << (8 - curr_len - len)); //append bits to curr_byte
            curr_len += len;
        } else { //if bits don't fit in current byte
            int remaining_len = 8 - curr_len;
            curr_byte |= (bits >> (len - remaining_len)); //append initial bits to curr_byte
            compressed_data[curr_index++] = curr_byte; //add curr_byte to compressed data
            curr_byte = (bits << (8 - len + remaining_len)); //set remaining bits as new curr_byte
            curr_len = (len - remaining_len);
        }
    }
    if (curr_len > 0) { //if there are bits in curr_byte that are not added to compressed data
        compressed_data[curr_index++] = curr_byte;
    }
    *compressed_size = curr_index;
    return compressed_data;
}

//Function to decompress image using Huffman Coding and return decompressed image
image_t *decompress_image(unsigned char *compressed_data, int compressed_size, int width, int height) {
    int freqs[256] = {0};
    for (int i = 0; i < compressed_size; i++) {
        freqs[compressed_data[i]]++;
    }
    node_t *root = build_huffman_tree(freqs);
    unsigned char *decompressed_data = (unsigned char*) malloc(width * height);
    node_t *node = root;
    int curr_index = 0;
    for (int i = 0; i < compressed_size; i++) {
        unsigned char byte = compressed_data[i];
        for (int j = 0; j < 8; j++) {
            if (byte & (1 << (7 - j))) { //if bit is 1
                node = node->right;
            } else { //if bit is 0
                node = node->left;
            }
            if (node->left == NULL && node->right == NULL) { //if leaf node
                decompressed_data[curr_index++] = node->val;
                node = root; //reset to root
                if (curr_index == width * height) { //if all pixels are decoded
                    goto end_of_decode;
                }
            }
        }
    }
    end_of_decode:
    image_t *image = (image_t*) malloc(sizeof(image_t));
    image->data = decompressed_data;
    image->width = width;
    image->height = height;
    return image;
}

int main() {
    //testing compression and decompression
    unsigned char data[] = {
        0, 1, 1, 2,
        2, 2, 3, 3,
        3, 3, 3, 4,
        4, 4, 4, 4
    };
    int width = 4;
    int height = 4;
    image_t *image = (image_t*) malloc(sizeof(image_t));
    image->data = data;
    image->width = width;
    image->height = height;
    int compressed_size;
    unsigned char *compressed_data = compress_image(image, &compressed_size);
    printf("Original size: %d bytes\n", width * height);
    printf("Compressed size: %d bytes\n", compressed_size);
    for (int i = 0; i < compressed_size; i++) {
        printf("%d ", compressed_data[i]);
    }
    printf("\n");
    image_t *decompressed_image = decompress_image(compressed_data, compressed_size, width, height);
    for (int i = 0; i < width * height; i++) {
        printf("%d ", decompressed_image->data[i]);
    }
    printf("\n");
    return 0;
}