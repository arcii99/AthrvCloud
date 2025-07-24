//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h> 

// Define the maximum file system size 
#define MAX_FS_SIZE 1000 

// Structure for the file system 
struct file_system 
{ 
    char name[20]; 
    char data[100]; 
    int size; 
    int start_block; 
}; 

// Function to initialize the file system 
void init_file_system(struct file_system fs[], int num_files) 
{ 
    for(int i=0; i<num_files; i++) 
    { 
        sprintf(fs[i].name, "file%d.txt", i+1); 
        sprintf(fs[i].data, "Sample data for %s", fs[i].name); 
        fs[i].size = sizeof(fs[i].data); 
        fs[i].start_block = i * (MAX_FS_SIZE/num_files); 
    } 
} 

// Function to display the file system contents 
void display_file_system(struct file_system fs[], int num_files) 
{ 
    printf("File System Contents:\n"); 
    for(int i=0; i<num_files; i++) 
    { 
        printf("File: %s\n", fs[i].name); 
        printf("Data: %s\n", fs[i].data); 
        printf("Size: %d bytes\n", fs[i].size); 
        printf("Starting Block: %d\n", fs[i].start_block); 
        printf("\n"); 
    } 
} 

int main() 
{ 
    // Define the number of files 
    int num_files = 5; 

    // Create an array to hold the file system 
    struct file_system fs[num_files]; 

    // Initialize the file system 
    init_file_system(fs, num_files); 

    // Display the file system contents 
    display_file_system(fs, num_files); 

    return 0; 
}