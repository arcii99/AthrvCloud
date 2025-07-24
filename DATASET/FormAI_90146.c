//FormAI DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sync_files(char *file_path1, char *file_path2) {
    FILE *file1, *file2;
    char buffer1[1024], buffer2[1024];
    int line_number = 1, has_diff = 0;
    
    file1 = fopen(file_path1, "r");
    file2 = fopen(file_path2, "r");
    
    if(!file1 || !file2) {
        printf("Error: Unable to open the files\n");
        exit(1);
    }
    
    while(fgets(buffer1, sizeof(buffer1), file1) && fgets(buffer2, sizeof(buffer2), file2)) {
        if(strcmp(buffer1, buffer2) != 0) {
            printf("Difference in line %d\n", line_number);
            has_diff = 1;
            break;
        }
        line_number++;
    }
    
    if(!has_diff) {
        printf("Files are in sync\n");
    }
    
    fclose(file1);
    fclose(file2);

}

int main() {
    char file_path1[100], file_path2[100];
    
    printf("Enter the file path 1: ");
    scanf("%s", file_path1);
    
    printf("Enter the file path 2: ");
    scanf("%s", file_path2);
    
    sync_files(file_path1, file_path2);
    
    return 0;
}