//FormAI DATASET v1.0 Category: Networking ; Style: interoperable
// C program to demonstrate interprocess communication 
// between two processes using Named Pipe 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd; 
  
    // FIFO file path 
    char * myfifo = "/tmp/myfifo"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    mkfifo(myfifo, 0666); 
  
    char arr1[80], arr2[80]; 
    while (1) 
    { 
        // First open in read only and read 
        fd = open(myfifo, O_RDONLY); 
        read(fd, arr1, sizeof(arr1)); 
  
        // Print the read message 
        printf("User1: %s\n", arr1); 
        close(fd); 
  
        // Now open in write mode and write 
        // string taken from user. 
        fd = open(myfifo, O_WRONLY); 
        fgets(arr2, 80, stdin); 
        write(fd, arr2, strlen(arr2)+1); 
        close(fd); 
    } 
    return 0; 
}