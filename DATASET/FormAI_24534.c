//FormAI DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_NUM_FILES 10
#define MAX_FILE_CONTENT_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
} File;

void initialize(File *files) {
    int i;
    for (i = 0; i < MAX_NUM_FILES; i++) {
        sprintf(files[i].filename, "file%d.txt", i+1);
        sprintf(files[i].content, "");
    }
}

int main() {
    File files[MAX_NUM_FILES];
    initialize(files);
    char input[MAX_FILE_CONTENT_LENGTH];
    int choice, file_index;
    
    // Main loop
    while (1) {
        // Display menu
        printf("\n");
        printf("1. List files\n");
        printf("2. Write to file\n");
        printf("3. Read file\n");
        printf("4. Delete file\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        // Handle user choice
        switch (choice) {
            case 1:
                // List files
                printf("Files:\n");
                int i;
                for (i = 0; i < MAX_NUM_FILES; i++) {
                    printf("%s\n", files[i].filename);
                }
                break;
            case 2:
                // Write to file
                printf("Enter file index: ");
                scanf("%d", &file_index);
                if (file_index < 1 || file_index > MAX_NUM_FILES) {
                    printf("Invalid file index\n");
                    break;
                }
                printf("Enter file content: ");
                scanf("%s", input);
                if (strlen(input) > MAX_FILE_CONTENT_LENGTH) {
                    printf("File content too long\n");
                    break;
                }
                strcpy(files[file_index-1].content, input);
                printf("File %d successfully updated\n", file_index);
                break;
            case 3:
                // Read file
                printf("Enter file index: ");
                scanf("%d", &file_index);
                if (file_index < 1 || file_index > MAX_NUM_FILES) {
                    printf("Invalid file index\n");
                    break;
                }
                printf("%s: %s\n", files[file_index-1].filename, files[file_index-1].content);
                break;
            case 4:
                // Delete file
                printf("Enter file index: ");
                scanf("%d", &file_index);
                if (file_index < 1 || file_index > MAX_NUM_FILES) {
                    printf("Invalid file index\n");
                    break;
                }
                memset(files[file_index-1].content, 0, sizeof(files[file_index-1].content));
                printf("File %d successfully deleted\n", file_index);
                break;
            case 5:
                // Exit program
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}