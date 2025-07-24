//FormAI DATASET v1.0 Category: Memory management ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

struct Block {
    int id; 
    int size; 
    int free; 
    struct Block *next; 
};

struct Block *head, *tail;

void initialize() {
    head = (struct Block*)malloc(sizeof(struct Block)); 
    tail = (struct Block*)malloc(sizeof(struct Block)); 

    head->id = 1; 
    head->size = SIZE - (2 * sizeof(struct Block)); 
    head->free = 1; 
    head->next = tail; 

    tail->id = 2; 
    tail->size = 0; 
    tail->free = 0; 
    tail->next = NULL; 
}

void my_free(void *ptr) {
    struct Block* current = (struct Block*)ptr - 1; 
    current->free = 1; 

    if(current->next->free == 1) { 
        current->size += current->next->size + sizeof(struct Block); 
        current->next = current->next->next; 
    }
    if(current->next->id == 2) { 
        struct Block *temp = current; 
        current->size += sizeof(struct Block); 
        current = current->next; 
        current->size = 0; 
        current->free = 0; 
        current->next = NULL; 
        free(temp); 
    }
    if(current->free == 1 && current->next->id == 2) { 
        struct Block *temp = head; 
        while(temp != tail) { 
            if(temp->next == current) { 
                temp->next = current->next; 
                break; 
            }
            temp = temp->next; 
        }
        head->size += current->size + sizeof(struct Block); 
        free(current); 
    }
}

void* my_malloc(size_t size) {
    struct Block *current = head; 
    while((current->size < size || current->free == 0) && current->next != NULL) {
        current = current->next; 
    }
    if(current->size == size) {
        current->free = 0; 
        return (void*)(++current); 
    }
    else if( current->size > (size + sizeof(struct Block))) { 
        struct Block* newBlock = (void*)((void*)(++current) + size); 
        newBlock->id = current->id + 1; 
        newBlock->free = 1; 
        newBlock->size = current->size - size - sizeof(struct Block); 
        newBlock->next = current->next; 
        current->size = size; 
        current->free = 0; 
        current->next = newBlock; 
        return (void*)(++current); 
    }
    else { 
        return NULL; 
    }
}

int main() {
    initialize(); 

    int* ptr1 = (int*)my_malloc(sizeof(int)); 
    printf("Block 1 address: %p\n", ptr1); 

    int* ptr2 = (int*)my_malloc(sizeof(int)*2); 
    printf("Block 2 address: %p\n", ptr2); 

    my_free(ptr1); 

    int* ptr3 = (int*)my_malloc(sizeof(int)*3); 
    printf("Block 3 address: %p\n", ptr3); 

    my_free(ptr2); 

    int* ptr4 = (int*)my_malloc(sizeof(int)*4); 
    printf("Block 4 address: %p\n", ptr4); 

    my_free(ptr3); 
    my_free(ptr4); 

    return 0; 
}