//FormAI DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
   // Creating a file if it doesn't exist yet
   int fd = open("example_file", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

   // Checking if the file was created successfully
   if (fd == -1) {
      perror("Failed to create file");
      exit(EXIT_FAILURE);
   }

   // Writing to the file
   char* message = "This is an example message";
   int message_size = strlen(message);
   ssize_t bytes_written = write(fd, message, message_size);

   // Checking if the write was successful
   if (bytes_written != message_size) {
      perror("Failed to write to file");
      exit(EXIT_FAILURE);
   }

   // Closing the file
   close(fd);

   return EXIT_SUCCESS;
}