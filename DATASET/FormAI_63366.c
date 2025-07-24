//FormAI DATASET v1.0 Category: File system simulation ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 100

struct block {
    char data[BLOCK_SIZE];
    int next_block;
};

struct file_node {
    char name[100];
    int size;
    int block_ptr;
    int is_dir;
    struct file_node *next;
};

//global variables
struct block blocks[MAX_BLOCKS];
struct file_node *root = NULL;
int free_block_ptr = 0;

//prototype for helper functions
void initialize_blocks();
void initialize_root();
int get_free_block();
void create_file(char *name, int size, int is_dir);
struct file_node* search_file(char *name);
void delete_file(char *name);
void display_files();

void initialize_blocks() {
    int i;
    for(i=0; i<MAX_BLOCKS-1; i++)
        blocks[i].next_block = i+1;
    blocks[MAX_BLOCKS-1].next_block = -1;
}

void initialize_root() {
    root = (struct file_node*)malloc(sizeof(struct file_node));
    strcpy(root->name, "root");
    root->size = 0;
    root->block_ptr = -1;
    root->is_dir = 1;
    root->next = NULL;
}

int get_free_block() {
    int block = free_block_ptr;
    free_block_ptr = blocks[block].next_block;
    blocks[block].next_block = -1;
    return block;
}

void create_file(char *name, int size, int is_dir) {
    struct file_node *new_node = (struct file_node*)malloc(sizeof(struct file_node));
    strcpy(new_node->name, name);
    new_node->size = size;
    new_node->block_ptr = get_free_block();
    new_node->is_dir = is_dir;
    new_node->next = NULL;

    if(root == NULL)
        initialize_root();
    else {
        //check if file with same name already exists
        struct file_node *check = root->next;
        while(check != NULL) {
            if(strcmp(check->name, name) == 0) {
                printf("File with name %s already exists!\n", name);
                return;
            }
            check = check->next;
        }
    }

    //add new node to end of list
    if(root->next != NULL) {
        struct file_node *temp = root->next;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
    else
        root->next = new_node;

    //initialize block data to 0s
    memset(blocks[new_node->block_ptr].data, 0, BLOCK_SIZE);

    printf("File %s created successfully!\n", name);
}

struct file_node* search_file(char *name) {
    if(root == NULL) {
        printf("No files exist!\n");
        return NULL;
    }

    struct file_node *tmp = root->next;
    while(tmp != NULL) {
        if(strcmp(tmp->name, name) == 0)
            return tmp;
        tmp = tmp->next;
    }

    printf("File %s not found!\n", name);
    return NULL;
}

void delete_file(char *name) {
    struct file_node *prev = root;
    struct file_node *curr = prev->next;

    while(curr != NULL) {
        if(strcmp(curr->name, name) == 0) {
            //release blocks occupied by file
            int block_ptr = curr->block_ptr;
            while(block_ptr != -1) {
                int tmp = blocks[block_ptr].next_block;
                blocks[block_ptr].next_block = free_block_ptr;
                free_block_ptr = block_ptr;
                block_ptr = tmp;
            }

            //remove file from linked list
            prev->next = curr->next;
            free(curr);
            printf("File %s deleted successfully!\n", name);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("File %s not found!\n", name);
}

void display_files() {
    if(root == NULL || root->next == NULL) {
        printf("No files exist!\n");
        return;
    }

    struct file_node *tmp = root->next;

    while(tmp != NULL) {
        if(tmp->is_dir)
            printf("[DIR] %s\n", tmp->name);
        else
            printf("[FILE] %s\n", tmp->name);
        tmp = tmp->next;
    }
}

int main() {
    int choice;
    initialize_blocks();

    do {
        printf("\n1. Create file\n2. Search file\n3. Delete file\n4. Display files\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[100];
                int size, is_dir;
                printf("Enter file/directory name: ");
                scanf("%s", name);
                printf("Enter size (in bytes) for file or 0 for directory: ");
                scanf("%d", &size);
                printf("Enter 1 for directory, 0 for file: ");
                scanf("%d", &is_dir);
                create_file(name, size, is_dir);
                break;
            }

            case 2: {
                char name[100];
                printf("Enter file/directory name: ");
                scanf("%s", name);
                struct file_node *node = search_file(name);
                if(node != NULL) {
                    printf("Name: %s\n", node->name);
                    printf("Size: %d\n", node->size);
                    printf("Block Pointer: %d\n", node->block_ptr);
                    printf("Type: %s\n", node->is_dir ? "Directory": "File");
                }
                break;
            }

            case 3: {
                char name[100];
                printf("Enter file/directory name: ");
                scanf("%s", name);
                delete_file(name);
                break;
            }

            case 4: {
                display_files();
                break;
            }

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

    }while(choice != 5);

    return 0;
}