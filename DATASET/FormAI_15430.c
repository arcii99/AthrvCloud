//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // initialize mutex for synchronization
int sync_flag = 0; // flag to indicate synchronization status

void* sync_files(void* arg);

int main()
{
    // create two directories to synchronize
    system("mkdir -p directory1");
    system("mkdir -p directory2");
    
    pthread_t sync_thread; // thread for synchronization
    int result_code; // result code for thread creation
    
    // create a loop for user input and file synchronization
    while(1)
    {
        char input[256]; // buffer for user input
        printf("Enter 'sync' to synchronize files between directories or 'quit' to exit: ");
        fgets(input, sizeof(input), stdin); // get user input
        input[strcspn(input, "\n")] = 0; // remove trailing newline from input
        
        if(strcmp(input, "sync") == 0) // if user wants to synchronize files
        {
            // create thread for synchronization
            result_code = pthread_create(&sync_thread, NULL, sync_files, NULL);
            if(result_code)
            {
                fprintf(stderr, "Error creating synchronization thread. Status code: %d\n", result_code);
                exit(1);
            }
            
            printf("Synchronization started.\n");
            
            // wait for thread to finish and join it
            pthread_join(sync_thread, NULL);
            
            printf("Synchronization completed.\n");
        }
        else if(strcmp(input, "quit") == 0) // if user wants to quit the program
        {
            break;
        }
        else // if user enters an invalid option
        {
            printf("Invalid option. Please enter 'sync' or 'quit'.\n");
        }
    }
    
    // remove the directories and their contents
    system("rm -r directory1");
    system("rm -r directory2");
    
    pthread_mutex_destroy(&mutex); // destroy mutex
    
    return 0;
}

void* sync_files(void* arg)
{
    pthread_mutex_lock(&mutex); // lock mutex for synchronization
    
    // open directory1
    DIR* dir1 = opendir("directory1");
    if(dir1 == NULL)
    {
        fprintf(stderr, "Error opening directory1.\n");
        pthread_exit(NULL);
    }
    
    // open directory2
    DIR* dir2 = opendir("directory2");
    if(dir2 == NULL)
    {
        fprintf(stderr, "Error opening directory2.\n");
        closedir(dir1);
        pthread_exit(NULL);
    }
    
    // loop through files in directory1
    struct dirent* entry1;
    while((entry1 = readdir(dir1)) != NULL)
    {
        if(entry1->d_type == DT_REG) // if entry is a regular file
        {
            char file_path1[256]; // buffer for file path in directory1
            char file_path2[256]; // buffer for file path in directory2
            
            sprintf(file_path1, "%s/%s", "directory1", entry1->d_name); // construct file path in directory1
            sprintf(file_path2, "%s/%s", "directory2", entry1->d_name); // construct file path in directory2
            
            // check if file exists in directory2
            if(access(file_path2, F_OK) == -1)
            {
                // if file doesn't exist in directory2, copy file to directory2
                char copy_command[512]; // buffer for copy command
                sprintf(copy_command, "cp %s %s", file_path1, "directory2"); // construct copy command
                system(copy_command); // execute copy command
                
                printf("%s copied to directory2.\n", entry1->d_name);
            }
            else
            {
                // if file exists in directory2, check if they are different
                FILE* file1 = fopen(file_path1, "rb"); // open file in directory1 for comparison
                FILE* file2 = fopen(file_path2, "rb"); // open file in directory2 for comparison
                
                fseek(file1, 0, SEEK_END); // seek to end of file1
                long file1_size = ftell(file1); // get size of file1
                fseek(file1, 0, SEEK_SET); // seek back to beginning of file1
                
                fseek(file2, 0, SEEK_END); // seek to end of file2
                long file2_size = ftell(file2); // get size of file2
                fseek(file2, 0, SEEK_SET); // seek back to beginning of file2
                
                if(file1_size != file2_size) // if files have different sizes, copy file to directory2
                {
                    char copy_command[512]; // buffer for copy command
                    sprintf(copy_command, "cp %s %s", file_path1, "directory2"); // construct copy command
                    system(copy_command); // execute copy command
                    
                    printf("%s copied to directory2.\n", entry1->d_name);
                }
                
                char* buffer1 = malloc(file1_size); // allocate buffer for file1 contents
                char* buffer2 = malloc(file2_size); // allocate buffer for file2 contents
                
                fread(buffer1, 1, file1_size, file1); // read file1 into buffer1
                fread(buffer2, 1, file2_size, file2); // read file2 into buffer2
                
                if(memcmp(buffer1, buffer2, file1_size) != 0) // if file contents are different, copy file to directory2
                {
                    char copy_command[512]; // buffer for copy command
                    sprintf(copy_command, "cp %s %s", file_path1, "directory2"); // construct copy command
                    system(copy_command); // execute copy command
                    
                    printf("%s copied to directory2.\n", entry1->d_name);
                }
                
                free(buffer1); // free buffer1 memory
                free(buffer2); // free buffer2 memory
                fclose(file1); // close file1
                fclose(file2); // close file2
            }
        }
    }
    
    closedir(dir1); // close directory1
    closedir(dir2); // close directory 2
    
    pthread_mutex_unlock(&mutex); // unlock mutex
    
    pthread_exit(NULL); // exit thread
}