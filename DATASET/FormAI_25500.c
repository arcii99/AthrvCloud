//FormAI DATASET v1.0 Category: Networking ; Style: statistical
/* In this example, we will create a client-server networking program that calculates the mean and standard deviation of a given set of numbers using sockets */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8000
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

double calculate_mean(int *numbers, int size);
double calculate_standard_deviation(int *numbers, int size, double mean);

int main() {

  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};
  char *hello = "Hello from server";
  int numbers[100];
  int i = 0;
  int n;

  // Creating socket file descriptor
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Attaching socket to the port
  bind(server_fd, (struct sockaddr *)&address, sizeof(address));
  listen(server_fd, MAX_CONNECTIONS);
  while (1) {
    printf("Waiting for new connection...\n");

    // Accepting incoming connection
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    printf("Connection established with client: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Receiving number of elements and the elements themselves
    read(new_socket, &n, sizeof(int));
    read(new_socket, numbers, sizeof(int)*n);
    printf("Numbers received from client: ");

    for (i=0; i<n; i++) {
      printf("%d ", numbers[i]);
    }
    printf("\n");

    // Calculating mean and standard deviation
    double mean = calculate_mean(numbers, n);
    double std_deviation = calculate_standard_deviation(numbers, n, mean);
    printf("Mean: %.2f, Standard deviation: %.2f\n", mean, std_deviation);

    // Sending result back to client
    char result[50];
    snprintf(result, 50, "Mean: %.2f, Standard deviation: %.2f\n", mean, std_deviation);
    send(new_socket, result, strlen(result), 0);
    printf("Results sent back to client\n");
    
    // Closing connection
    close(new_socket);
    printf("Connection closed with client: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
  }
  return 0;
}

/* Functions for mean and standard deviation calculation */
double calculate_mean(int *numbers, int size) {
  int sum = 0, i;
  double mean;
  for (i=0; i<size; i++) {
    sum += numbers[i];
  }
  mean = (double) sum/size;
  return mean;
}

double calculate_standard_deviation(int *numbers, int size, double mean) {
  double deviation = 0;
  int i;
  for (i=0; i<size; i++) {
    deviation += pow(numbers[i] - mean, 2);
  }
  deviation = sqrt(deviation/size);
  return deviation;
}