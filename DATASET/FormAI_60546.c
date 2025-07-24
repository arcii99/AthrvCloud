//FormAI DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error_handling(const char* file_name)
{
    FILE* file = fopen(file_name, "r");
    
    if(!file)
    {
        if(errno == ENOENT) //Check if file doesn't exist
            fprintf(stderr, "Error: %s doesn't exist!\n", file_name);
        else if(errno == EACCES) //Check if permission denied
            fprintf(stderr, "Error: %s cannot be accessed!\n", file_name);
        else //For any other error
            perror("Error while opening the file");
            
        exit(EXIT_FAILURE); //Abort program with failure status
    }
    
    printf("File opened successfully!\n");
    fclose(file);
}

int main()
{
    const char* file_name = "non_existent_file.txt";
    
    error_handling(file_name);
    
    return 0;
}