//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 256 

struct huffman_node 
{ 
    int frequency; 
    char character; 
    struct huffman_node * left_node; 
    struct huffman_node * right_node; 
}; 

struct frequency_table 
{ 
    int frequency; 
    char character; 
}; 

struct huffman_tree 
{ 
    struct huffman_node * node; 
}; 

struct code_table 
{ 
    int code[SIZE]; 
    int length; 
}; 

int compare( const void *left, const void *right ) 
{ 
    return ( (struct frequency_table *)left ) -> frequency - ( (struct frequency_table *)right ) -> frequency; 
} 

struct huffman_tree * create_huffman_tree (struct frequency_table f[], int count) 
{ 
    struct huffman_tree * trees = calloc(count, sizeof(struct huffman_tree)); 

    for (int i = 0; i < count; i ++) 
    { 
        trees[i].node = malloc(sizeof(struct huffman_node)); 
        trees[i].node -> frequency = f[i].frequency; 
        trees[i].node -> character = f[i].character; 
        trees[i].node -> left_node = trees[i].node -> right_node = NULL; 
    } 

    for (int i = 0; i < count - 1; i ++) 
    { 
        qsort(trees, count - i, sizeof(struct huffman_tree), compare); 

        trees[count - i - 2].node = malloc(sizeof(struct huffman_node)); 
        trees[count - i - 2].node -> frequency = trees[count - i - 1].node -> frequency + trees[count - i - 2].node -> frequency; 
        trees[count - i - 2].node -> left_node = trees[count - i - 1].node; 
        trees[count - i - 2].node -> right_node = trees[count - i - 2].node; 
    } 

    return &trees[0]; 
} 

void create_code_table (struct huffman_node * node, struct code_table table[], int path[], int depth) 
{ 
    if (node -> left_node == NULL && node -> right_node == NULL) 
    { 
        table[node -> character].length = depth; 

        for (int i = 0; i < depth; i ++) 
        table[node -> character].code[i] = path[i]; 
    }
    else 
    { 
        path[depth] = 0; 
        create_code_table(node -> left_node, table, path, depth + 1); 

        path[depth] = 1; 
        create_code_table(node -> right_node, table, path, depth + 1); 
    } 
} 

void encode_data (char * input, struct code_table table[], char * output) 
{ 
    int length = strlen(input); 
    int index = 0; 

    for (int i = 0; i < length; i ++) 
    { 
        int c = input[i]; 

        for (int j = 0; j < table[c].length; j ++) 
        { 
            output[index / 8] <<= 1; 

            if (table[c].code[j] == 1) 
            { 
                output[index / 8] |= 1; 
            } 

            index ++; 
        } 
     } 
 } 

 void main () 
 { 
    char input[] = "A sample sentence for Huffman coding algorithm"; 
    int length = strlen(input); 
    int path[SIZE]; 
    struct frequency_table table[SIZE] = { 0 }; 

    for (int i = 0; i < length; i ++) 
    { 
        table[input[i]].frequency ++; 
    } 

    int count = 0; 

    for (int i = 0; i < SIZE; i ++) 
    { 
        if (table[i].frequency > 0) 
        { 
            table[i].character = i; 
            count ++; 
        } 
    } 

    qsort(table, SIZE, sizeof(struct frequency_table), compare); 
    struct huffman_tree * tree = create_huffman_tree(table, count); 
    static struct code_table codes[SIZE]; 
    create_code_table(tree -> node, codes, path, 0); 

    char output[256]; 
    encode_data(input, codes, output); 

    printf("\nOriginal data: %s", input); 
    printf("\nEncoded data: "); 

    for (int i = 0; i < (strlen(input) * 8); i ++) 
    { 
        printf("%d", (output[i / 8] >> (7 - i % 8)) % 2); 
    } 

    printf("\n"); 
 }