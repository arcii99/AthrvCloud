//FormAI DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

int main() {
    char block_size[100], block_num[100], file_name[100];
    FILE *source_file, *target_file;
    int size, num, i, data;
    
    printf("Enter block size: ");
    fgets(block_size, 100, stdin);
    size = atoi(block_size); 
    
    printf("Enter block numbers: ");
    fgets(block_num, 100, stdin);
    num = atoi(block_num); 
    
    printf("Enter file name: ");
    fgets(file_name, 100, stdin);
    
    source_file = fopen(file_name, "r");
    if(source_file == NULL) {
        printf("Error: Could not open the file.\n");
        exit(1);
    }
    
    target_file = fopen("recovered_file", "w");
    if(target_file == NULL) {
        printf("Error: Could not create recovered file.\n");
        exit(1);
    }
    
    for(i = 1; i <= num; i++) {
        fseek(source_file, size*(i-1), SEEK_SET);
        data = fgetc(source_file);
        fputc(data, target_file);
        printf("Block %d recovered.\n", i);
    }
    
    fclose(source_file);
    fclose(target_file);
    printf("File recovered.\n");
    return 0;
}