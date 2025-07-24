//FormAI DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//This is a custom lossless compression algorithm called "UltraPreciseCompress"
//This algorithm is designed to compress a string based on the frequency of each character in the string.

//Node structure to store character and its frequency
struct Node{
    char character;
    int frequency;
    struct Node* next;
};

//Function to insert a node in the linked list
void insert_node(struct Node** head, char c){
    struct Node* temp = *head;
    while(temp){
        if(temp->character==c){
            temp->frequency++;
            return;
        }
        temp = temp->next;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->character = c;
    new_node->frequency = 1;
    new_node->next = *head;
    *head = new_node;
    return;
}

//Function to delete a node from the linked list
void delete_node(struct Node** head, char c){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while(temp){
        if(temp->character==c){
            if(prev)
                prev->next = temp->next;
            else
                *head = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    return;
}

//Function to find the node with the minimum frequency in the linked list
struct Node* min_frequency(struct Node** head){
    struct Node* temp = *head;
    struct Node* min_node = temp;
    while(temp){
        if(temp->frequency<min_node->frequency)
            min_node = temp;
        temp = temp->next;
    }
    return min_node;
}

//Main function that performs compression
void UltraPreciseCompress(char* input_string){
    int length = strlen(input_string);
    int compressed_length = 0;
    struct Node* head = NULL;
    //Step 1: Create linked list with characters and their frequencies
    for(int i=0;i<length;i++)
        insert_node(&head,input_string[i]);
    //Step 2: Compress the input string based on the linked list
    while(head){
        //Find the character with the minimum frequency
        struct Node* min_node = min_frequency(&head);
        char c = min_node->character;
        int frequency = min_node->frequency;
        //Delete the node from the linked list
        delete_node(&head,c);
        //Add the character and its frequency to the compressed string
        compressed_length += sprintf(&input_string[compressed_length],"%c%d",c,frequency);
    }
    input_string[compressed_length]='\0';
    return;
}

int main(){
    //Example usage:
    char input_string[100] = "abracadabra";
    UltraPreciseCompress(input_string);
    printf("Compressed string: %s\n",input_string);
    return 0;
}