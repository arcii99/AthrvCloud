//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000]; // initialize an input array of size 1000
    int count[256] = {0}; // initialize an array to store the frequency of each character
    
    printf("Enter your text to compress: ");
    fgets(input, 1000, stdin); // read the input from user
    
    int input_length = strlen(input); // get the length of the input string
    input[input_length-1] = '\0'; // replace the '\n' character at the end with '\0'
    
    // loop through the input and count the frequency of each character
    for (int i = 0; i < input_length-1; i++) {
        count[(int)input[i]]++;
    }
    
    // initialize a linked list to store the character and its frequency
    struct node {
        char character;
        int frequency;
        struct node* next;
    };
    
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    
    // loop through the frequency array and add each character and its frequency to the linked list
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            struct node* temp = head->next;
            
            // insert the character/frequency node in the correct order
            while (temp != NULL && temp->frequency < count[i]) {
                temp = temp->next;
            }
            
            struct node* new_node = (struct node*)malloc(sizeof(struct node));
            new_node->character = (char)i;
            new_node->frequency = count[i];
            new_node->next = temp;
            
            head->next = new_node;
        }
    }
    
    // print the linked list to see the frequency of each character
    printf("Character\tFrequency\n");
    printf("========================\n");
    
    struct node* temp = head->next;
    
    while (temp != NULL) {
        printf("%c\t\t%d\n", temp->character, temp->frequency);
        temp = temp->next;
    }
    
    printf("\n");
    
    // initialize an array to store the binary code for each character
    char code[256][100] = {0};
    
    // recursively generate the binary code for each character using the linked list
    void generate_code(struct node* current, char* binary_code) {
        if (current == NULL) {
            return;
        }
        
        char temp_code[100];
        strcpy(temp_code, binary_code);
        
        strcat(binary_code, "0");
        generate_code(current->next, binary_code);
        
        if (current->character != '\0') {
            strcpy(code[(int)current->character], binary_code);
        }
        
        strcpy(binary_code, temp_code);
        strcat(binary_code, "1");
        generate_code(current->next, binary_code);
    }
    
    char binary_code[100] = {0};
    generate_code(head->next, binary_code);
    
    // print the binary code for each character
    printf("Character\tBinary Code\n");
    printf("=========================\n");
    
    for (int i = 0; i < 256; i++) {
        if (code[i][0] != '\0') {
            printf("%c\t\t%s\n", i, code[i]);
        }
    }
    
    printf("\n");
    
    // compress the input string using the binary code for each character
    char compressed[10000] = {0};
    
    for (int i = 0; i < input_length-1; i++) {
        strcat(compressed, code[(int)input[i]]);
    }
    
    // recover the original string from the compressed string using the binary code
    struct binary_node {
        char character;
        struct binary_node* left;
        struct binary_node* right;
    };
    
    struct binary_node* root = (struct binary_node*)malloc(sizeof(struct binary_node));
    root->left = NULL;
    root->right = NULL;
    
    // recursively build the Huffman tree using the linked list
    struct binary_node* generate_binary_tree(struct node* current) {
        if (current == NULL) {
            return NULL;
        }
        
        struct binary_node* new_node = (struct binary_node*)malloc(sizeof(struct binary_node));
        new_node->character = current->character;
        new_node->left = generate_binary_tree(current->next);
        new_node->right = generate_binary_tree(current->next);
        
        return new_node;
    }
    
    root = generate_binary_tree(head->next);
    
    // recover the original string from the compressed string using the binary tree
    char decompressed[1000] = {0};
    struct binary_node* current = root;
    
    for (int i = 0; i < strlen(compressed); i++) {
        if (compressed[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        
        if (current->left == NULL && current->right == NULL) {
            strncat(decompressed, &current->character, 1);
            current = root;
        }
    }
    
    // print the compressed and decompressed strings
    printf("Compressed String: %s\n", compressed);
    printf("Decompressed String: %s\n", decompressed);
    
    return 0;
}