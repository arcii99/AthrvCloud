//FormAI DATASET v1.0 Category: System administration ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){

   int fd,n;
   char buffer[1024];

   /* Clearing the buffer */
   memset(buffer,'\0',sizeof(buffer));

   /* Opening the file to read */
   fd = open("test.txt",O_RDONLY);

   if(fd == -1){
      perror("Error in opening the file.");
      exit(EXIT_FAILURE);
   }

   /* Reading the content of the file */
   n = read(fd,buffer,sizeof(buffer));

   if(n == -1){
      perror("Error in reading the file.");
      exit(EXIT_FAILURE);
   }

   /* Printing the content of the file */
   printf("The content of the file is : \n\n %s \n",buffer);

   /* Closing the file */
   if(close(fd) == -1){
      perror("Error in closing the file.");
      exit(EXIT_FAILURE);
   }

   return 0;
}