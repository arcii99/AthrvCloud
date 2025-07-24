//FormAI DATASET v1.0 Category: Data recovery tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_FILE_SIZE 10485760 // 10 MB
#define NODE_COUNT 4

typedef struct file {
    char name[MAX_FILENAME_SIZE];
    int size;
    char data[MAX_FILE_SIZE];
} File;

typedef struct node {
    int id;
    int file_count;
    File files[MAX_FILE_SIZE];
} Node;

Node nodes[NODE_COUNT];

int get_node_id_for_file(char* filename) {
    int id = 0;
    int i;
    for(i=0; i<strlen(filename); i++) {
        id += (int)filename[i];
    }
    return id % NODE_COUNT;
}

void save_file(char* filename, int data_size, char* data) {
    File f;
    strcpy(f.name, filename);
    f.size = data_size;
    memcpy(f.data, data, data_size);

    int node_id = get_node_id_for_file(filename);
    Node node = nodes[node_id];

    node.files[node.file_count] = f;
    node.file_count += 1;
    nodes[node_id] = node;
}

File get_file(char* filename) {
    int node_id = get_node_id_for_file(filename);
    Node node = nodes[node_id];

    int i;
    for(i=0; i<node.file_count; i++) {
        if(strcmp(node.files[i].name, filename) == 0) {
            return node.files[i];
        }
    }

    File empty_file;
    memset(&empty_file, 0, sizeof(File));
    return empty_file;
}

void delete_file(char* filename) {
    int node_id = get_node_id_for_file(filename);
    Node node = nodes[node_id];

    int i, j;
    for(i=0; i<node.file_count; i++) {
        if(strcmp(node.files[i].name, filename) == 0) {
            for(j=i+1; j<node.file_count; j++) {
                node.files[j-1] = node.files[j];
            }
            node.file_count -= 1;
            nodes[node_id] = node;
            break;
        }
    }
}

int main() {
    int menu_choice;
    char filename[MAX_FILENAME_SIZE];
    int data_size;
    char data[MAX_FILE_SIZE];

    // Initialize nodes
    int i;
    for(i=0; i<NODE_COUNT; i++) {
        nodes[i].id = i;
        nodes[i].file_count = 0;
    }

    printf("Welcome to the distributed file system!\n");

    while(1) {
        printf("\nPlease select an action:\n");
        printf("1. Save file\n");
        printf("2. Get file\n");
        printf("3. Delete file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        if(menu_choice == 1) {
            printf("Enter the filename: ");
            scanf("%s", filename);
            printf("Enter the file size (in bytes): ");
            scanf("%d", &data_size);
            printf("Enter the file data (up to %d bytes):\n", MAX_FILE_SIZE);
            scanf("%s", data);
            save_file(filename, data_size, data);
            printf("\nFile '%s' saved successfully.\n", filename);
        }
        else if(menu_choice == 2) {
            printf("Enter the filename: ");
            scanf("%s", filename);
            File file = get_file(filename);
            if(file.size == 0) {
                printf("File '%s' not found.\n", filename);
            }
            else {
                printf("\nFile '%s' found:\n", filename);
                printf("Size: %d bytes\n", file.size);
                printf("Data: %s\n", file.data);
            }
        }
        else if(menu_choice == 3) {
            printf("Enter the filename: ");
            scanf("%s", filename);
            delete_file(filename);
            printf("\nFile '%s' deleted successfully.\n", filename);
        }
        else if(menu_choice == 4) {
            printf("\nExiting program...\n");
            break;
        }
        else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}