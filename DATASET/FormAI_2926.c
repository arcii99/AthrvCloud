//FormAI DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256

typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct PriorityQueue {
    int size;
    Node **nodes;
} PriorityQueue;

Node *create_node(char character, int frequency);
void destroy_node(Node *node);
PriorityQueue *create_priority_queue();
void destroy_priority_queue(PriorityQueue *queue);
void enqueue(PriorityQueue *queue, Node *node);
Node *dequeue(PriorityQueue *queue);
void read_file(char *filename, char **buffer, long *size);
void write_file(char *filename, char *buffer, long size);
void serialize_tree(Node *root, char **buffer, int *index);
Node *deserialize_tree(char *buffer, int *index);
void compress(char *input_filename, char *output_filename);
void decompress(char *input_filename, char *output_filename);

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <c/d> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[2];
    char *output_filename = argv[3];

    if (argv[1][0] == 'c') {
        compress(input_filename, output_filename);
    } else if (argv[1][0] == 'd') {
        decompress(input_filename, output_filename);
    } else {
        printf("Invalid option: %c\n", argv[1][0]);
        return 1;
    }

    return 0;
}

Node *create_node(char character, int frequency) {
    Node *node = malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void destroy_node(Node *node) {
    if (node == NULL) return;
    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
}

PriorityQueue *create_priority_queue() {
    PriorityQueue *queue = malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->nodes = malloc(MAX_CHARS * sizeof(Node *));
    for (int i = 0; i < MAX_CHARS; i++) {
        queue->nodes[i] = NULL;
    }
    return queue;
}

void destroy_priority_queue(PriorityQueue *queue) {
    for (int i = 0; i < MAX_CHARS; i++) {
        if (queue->nodes[i] != NULL) {
            destroy_node(queue->nodes[i]);
        }
    }
    free(queue->nodes);
    free(queue);
}

void enqueue(PriorityQueue *queue, Node *node) {
    int i = queue->size++;
    while (i > 0 && node->frequency < queue->nodes[(i - 1) / 2]->frequency) {
        queue->nodes[i] = queue->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->nodes[i] = node;
}

Node *dequeue(PriorityQueue *queue) {
    Node *node = queue->nodes[0];
    queue->nodes[0] = queue->nodes[--queue->size];
    int i = 0;
    while (2 * i + 1 < queue->size) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int min_child = left_child;
        if (right_child < queue->size && queue->nodes[right_child]->frequency < queue->nodes[left_child]->frequency) {
            min_child = right_child;
        }
        if (queue->nodes[i]->frequency <= queue->nodes[min_child]->frequency) {
            break;
        }
        Node *temp = queue->nodes[i];
        queue->nodes[i] = queue->nodes[min_child];
        queue->nodes[min_child] = temp;
        i = min_child;
    }
    return node;
}

void read_file(char *filename, char **buffer, long *size) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fseek(file, 0, SEEK_SET);
    *buffer = malloc(*size);
    fread(*buffer, *size, 1, file);
    fclose(file);
}

void write_file(char *filename, char *buffer, long size) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(1);
    }
    fwrite(buffer, size, 1, file);
    fclose(file);
}

void serialize_tree(Node *root, char **buffer, int *index) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL || root->right != NULL) {
        (*buffer)[(*index)++] = 'I';
        serialize_tree(root->left, buffer, index);
        serialize_tree(root->right, buffer, index);
    } else {
        (*buffer)[(*index)++] = 'L';
        (*buffer)[(*index)++] = root->character;
    }
}

Node *deserialize_tree(char *buffer, int *index) {
    if (buffer[*index] == 'L') {
        (*index)++;
        return create_node(buffer[*index - 1], 0);
    }
    (*index)++;
    Node *node = create_node('\0', 0);
    node->left = deserialize_tree(buffer, index);
    node->right = deserialize_tree(buffer, index);
    return node;
}

void compress(char *input_filename, char *output_filename) {
    char *text, *compressed_text, *tree_buffer;
    long text_size, compressed_size = 0, tree_size;
    int frequencies[MAX_CHARS] = { 0 };
    Node *root, *node;
    PriorityQueue *queue;

    read_file(input_filename, &text, &text_size);

    // count frequencies of each character in the input text
    for (int i = 0; i < text_size; i++) {
        frequencies[(unsigned char) text[i]]++;
    }

    // create huffman tree and encoding table
    queue = create_priority_queue();
    for (int i = 0; i < MAX_CHARS; i++) {
        if (frequencies[i] > 0) {
            node = create_node(i, frequencies[i]);
            enqueue(queue, node);
        }
    }
    while (queue->size > 1) {
        Node *node1 = dequeue(queue);
        Node *node2 = dequeue(queue);
        Node *parent = create_node('\0', node1->frequency + node2->frequency);
        parent->left = node1;
        parent->right = node2;
        enqueue(queue, parent);
    }
    root = dequeue(queue);
    destroy_priority_queue(queue);

    // serialize huffman tree to a string
    tree_buffer = calloc(text_size, sizeof(char));
    int tree_index = 0;
    serialize_tree(root, &tree_buffer, &tree_index);
    tree_size = tree_index;

    // encode input text using huffman code
    int code_lengths[MAX_CHARS] = { 0 };
    char *codes[MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; i++) {
        codes[i] = NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        // special case for one-character input text
        codes[(unsigned char) text[0]] = strdup("");
        code_lengths[(unsigned char) text[0]] = 1;
    } else {
        char code[MAX_CHARS] = { 0 };
        int code_length = 0;
        void encode(Node *node) {
            if (node->left == NULL && node->right == NULL) {
                codes[(unsigned char) node->character] = strdup(code);
                code_lengths[(unsigned char) node->character] = code_length;
                return;
            }
            if (node->left != NULL) {
                code[code_length++] = '0';
                encode(node->left);
                code_length--;
            }
            if (node->right != NULL) {
                code[code_length++] = '1';
                encode(node->right);
                code_length--;
            }
        }
        encode(root);
    }
    compressed_text = malloc(text_size);
    int index = 0;
    for (int i = 0; i < text_size; i++) {
        char *code = codes[(unsigned char) text[i]];
        int code_length = code_lengths[(unsigned char) text[i]];
        memcpy(&compressed_text[index], code, code_length);
        index += code_length;
    }
    compressed_size = index / 8 + (index % 8 != 0);

    // write compressed output file
    char *compressed_buffer = malloc(tree_size + compressed_size + 4);
    memcpy(compressed_buffer, &tree_size, sizeof(int));
    memcpy(compressed_buffer + sizeof(int), &compressed_size, sizeof(int));
    memcpy(compressed_buffer + 2 * sizeof(int), tree_buffer, tree_size);
    memcpy(compressed_buffer + 2 * sizeof(int) + tree_size, compressed_text, compressed_size);
    write_file(output_filename, compressed_buffer, 2 * sizeof(int) + tree_size + compressed_size);

    free(text);
    free(tree_buffer);
    free(compressed_text);
    free(compressed_buffer);
    destroy_node(root);
}

void decompress(char *input_filename, char *output_filename) {
    char *compressed_buffer, *tree_buffer, *text;
    long compressed_size, text_size = 0;
    int tree_size, code_lengths[MAX_CHARS] = { 0 };
    Node *root;
    int index;

    read_file(input_filename, &compressed_buffer, &compressed_size);
    memcpy(&tree_size, compressed_buffer, sizeof(int));
    index = 2 * sizeof(int);
    tree_buffer = strndup(compressed_buffer + index, tree_size);
    index += tree_size;
    root = deserialize_tree(tree_buffer, &index);
    free(tree_buffer);

    // decode input text using huffman code
    char *codes[MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; i++) {
        codes[i] = NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        // special case for one-character input text
        codes[(unsigned char) root->character] = strdup("");
        code_lengths[(unsigned char) root->character] = 1;
    } else {
        char code[MAX_CHARS] = { 0 };
        int code_length = 0;
        void decode(Node *node) {
            if (node->left == NULL && node->right == NULL) {
                codes[(unsigned char) node->character] = strdup(code);
                code_lengths[(unsigned char) node->character] = code_length;
                return;
            }
            if (node->left != NULL) {
                code[code_length++] = '0';
                decode(node->left);
                code_length--;
            }
            if (node->right != NULL) {
                code[code_length++] = '1';
                decode(node->right);
                code_length--;
            }
        }
        decode(root);
    }
    free(compressed_buffer);
    text = malloc(compressed_size - index);
    int text_index = 0, remaining_bits = 0, remaining_code = 0;
    for (; index < compressed_size; index++) {
        unsigned char byte = compressed_buffer[index];
        int bits_to_read = remaining_bits == 0 ? 8 : remaining_bits;
        for (int i = 0; i < bits_to_read; i++) {
            int bit = byte >> (7 - i) & 1;
            remaining_code = (remaining_code << 1) | bit;
            remaining_bits--;
            if (codes[remaining_code] != NULL) {
                char *code = codes[remaining_code];
                int code_length = code_lengths[remaining_code];
                memcpy(&text[text_index], code, code_length);
                text_index += code_length;
                remaining_code = 0;
                remaining_bits = 8 - code_length;
            }
        }
    }
    text_size = text_index;

    write_file(output_filename, text, text_size);

    free(text);
    destroy_node(root);
}