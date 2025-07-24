//FormAI DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
   // Creating a file
   int fd = open("example.txt", O_CREAT | O_RDWR, 0644);
   if (fd == -1) {
      printf("Error creating file");
      return 1;
   }
   printf("File created successfully!\n");

   // Write to the file
   char *msg = "Hello World!\n";
   int len = strlen(msg);
   int bytes_written = write(fd, msg, len);
   if (bytes_written == -1) {
      printf("Error writing to file");
      return 1;
   }
   printf("%d bytes written to file.\n", bytes_written);

   // Read from file
   char *buf = (char *) malloc(len);
   int bytes_read = read(fd, buf, len);
   if (bytes_read == -1) {
      printf("Error reading from file");
      return 1;
   }
   printf("%d bytes read from file: %s", bytes_read, buf);

   // Closing file
   close(fd);
   printf("File closed successfully!\n");
   
   return 0;
}