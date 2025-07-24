//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: invasive
#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<unistd.h>

int main() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Error creating socket!\n");
    return 1;
  }

  struct sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8080);
  serverAddr.sin_addr.s_addr = INADDR_ANY;

  int bindStatus = bind(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
  if (bindStatus == -1) {
    printf("Error binding socket!\n");
    return 1;
  }

  int listenStatus = listen(sock, 5);
  if (listenStatus == -1) {
    printf("Error listening on socket!\n");
    return 1;
  }

  printf("Server running on port 8080...\n");
  while (1) {
    int clientSock = accept(sock, NULL, NULL);
    if (clientSock == -1) {
      printf("Error accepting client connection!\n");
      continue;
    }

    printf("Client connected!\n");

    char buffer[1024];
    ssize_t readStatus = read(clientSock, buffer, 1023);
    if (readStatus == -1) {
      printf("Error reading from client!\n");
      continue;
    }

    buffer[readStatus] = '\0';
    printf("Message from client: %s\n", buffer);

    const char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello World!";

    ssize_t writeStatus = write(clientSock, response, strlen(response));
    if (writeStatus == -1) {
      printf("Error writing to client!\n");
      continue;
    }

    printf("Response sent to client!\n");

    close(clientSock);
    printf("Client disconnected!\n");
  }

  close(sock);
  return 0;
}