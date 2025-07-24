//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct metadata {
    char file_name[20];
    int file_size;
    char created_by[20];
} Metadata;

int main() {
    printf("Enter the file name:\n");
    char file_name[20];
    scanf("%s", file_name);
    
    Metadata *data = (Metadata*)malloc(sizeof(Metadata));
    strcpy(data->file_name, file_name);
    
    printf("Enter the file size:\n");
    scanf("%d", &(data->file_size));
    
    printf("Enter the creator's name:\n");
    char creator[20];
    scanf("%s", creator);
    strcpy(data->created_by, creator);
    
    printf("\nMetadata:\n");
    printf("File name: %s\n", data->file_name);
    printf("File size: %d bytes\n", data->file_size);
    printf("Created by: %s\n", data->created_by);
    
    free(data);
    return 0;
}