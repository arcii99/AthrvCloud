//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char file_path[100], recovered_file[100], buffer[BUFFER_SIZE];
    FILE *file_ptr, *recovered_file_ptr;
    
    printf("Enter the file path of the file to be recovered: ");
    scanf("%s", file_path);
    
    // Open the damaged file for reading
    file_ptr = fopen(file_path, "rb");
    if(file_ptr == NULL) {
        printf("Unable to open the damaged file.");
        exit(EXIT_FAILURE);
    }
    
    // Open new file for writing the recovered data
    strcpy(recovered_file, "Recovered_");
    strcat(recovered_file, file_path);
    recovered_file_ptr = fopen(recovered_file, "wb");
    if(recovered_file_ptr == NULL) {
        printf("Unable to create the recovered file.");
        fclose(file_ptr);
        exit(EXIT_FAILURE);
    }
    
    // Read the contents of the damaged file and write into the new file
    while(fread(buffer, BUFFER_SIZE, 1, file_ptr)) {
        fwrite(buffer, BUFFER_SIZE, 1, recovered_file_ptr);
    }
    
    fclose(file_ptr);
    fclose(recovered_file_ptr);
    
    printf("File recovery completed successfully!\n");
    return 0;
}