//FormAI DATASET v1.0 Category: Client Server Application ; Style: statistical
// Statistical Style C Client Server Application Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <math.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

   // Server socket creation
   int server_fd, new_socket, valread;
   struct sockaddr_in address;
   int opt = 1;
   int addrlen = sizeof(address);
   char buffer[MAX_BUFFER_SIZE] = {0};
   char *response = "Hello from server";
   
   // Creating socket file descriptor
   if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
   }
   
   // Forcefully attaching socket to the port 8080
   if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
      perror("setsockopt");
      exit(EXIT_FAILURE);
   }
   address.sin_family = AF_INET;
   address.sin_addr.s_addr = INADDR_ANY;
   address.sin_port = htons(PORT);
   
   // Attaching socket to the port
   if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
   }
   
   // Server is listening for incoming connection
   if (listen(server_fd, 3) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
   }
   
   // Accepting incoming connection
   if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
      perror("accept");
      exit(EXIT_FAILURE);
   }
   
   // Reading message from client and sending response
   valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
   printf("%s\n", buffer);
   send(new_socket, response, strlen(response), 0);
   printf("Hello message sent\n");

   // Closing the server socket
   close(server_fd);

   // Statistical calculation
   int i, n;
   float mean, sum = 0, std_deviation=0;
   float variance;
   printf("Enter the numbers of elements: ");
   scanf("%d",&n);
   float data[n];
   printf("Enter %d elements: ", n);
   
   // Reading input data from client side
   for(i=0; i < n; i++){
      scanf("%f",&data[i]);
      sum+=data[i];
   }
   mean = sum/n;
   
   // Calculating variance
   for(i=0; i < n; i++)
      variance+=(data[i]-mean)*(data[i]-mean)/n;
   std_deviation = sqrt(variance);

   // Printing out the results
   printf("Mean of the given data set is %.2f\n",mean);
   printf("Variance of the given data set is %.2f\n",variance);
   printf("Standard Deviation of the given data set is %.2f\n",std_deviation);

   return 0;
}