//FormAI DATASET v1.0 Category: System administration ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    
    // Create a child process
    pid_t child = fork();
    
    // Check if fork was successful
    if(child < 0){
        perror("Fork failed");
        exit(1);
    }
    // The child process executes this block
    else if(child == 0){
        printf("Child process starting...\n");
        
        // Mount a file system
        printf("Mounting file system...\n");
        execl("/bin/mount", "", "/dev/sdb1", "/mnt/usb", NULL);
        printf("Mount failed!\n");
        exit(1);
    }
    // The parent process executes this block
    else{
        printf("Parent process starting...\n");
        
        // Wait for child to finish
        int status;
        waitpid(child, &status, 0);
        
        // Check if child exited successfully
        if(WIFEXITED(status)){
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
        
        // Unmount the file system
        printf("Unmounting file system...\n");
        system("umount /mnt/usb");
    }
    
    return 0;
}