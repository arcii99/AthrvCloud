//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
#include<stdio.h> // including standard input/output header file
#include<stdlib.h> // including standard library header file
#include<unistd.h> // including standard unix API header file
#include<sys/socket.h> // including socket header file
#include<netinet/in.h> // including internet header file

int main() // main function
{
  int clientSocket; // declaring clientSocket as integer
  char buffer[1024]; // declaring buffer as character with 1024 array size
  struct sockaddr_in serverAddr; // declaring sockaddr_in structure for server
  socklen_t addr_size; // declaring address size

  clientSocket = socket(AF_INET, SOCK_STREAM, 0); // creating socket with socket() API

  serverAddr.sin_family = AF_INET; // setting address family in server
  serverAddr.sin_port = htons(25); // setting port number for server
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // setting IP address for server

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); // setting memory to zero for server address

  addr_size = sizeof serverAddr; // assigning address size

  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size); // connecting clientSocket to server

  recv(clientSocket, buffer, 1024, 0); // receiving message from server

  printf("Server message received: %s",buffer); // printing server message

  send(clientSocket, "HELO example.com\r\n", 17, 0); // sending HELO command to server

  recv(clientSocket, buffer, 1024, 0); // receiving message from server

  printf("Server message received: %s",buffer); // printing server message

  send(clientSocket, "MAIL FROM:<example@example.com>\r\n", 30, 0); // sending MAIL FROM command to server

  recv(clientSocket, buffer, 1024, 0); // receiving message from server

  printf("Server message received: %s",buffer); // printing server message

  send(clientSocket, "RCPT TO:<recipient@example.com>\r\n", 30, 0); // sending RCPT TO command to server

  recv(clientSocket, buffer, 1024, 0); // receiving message from server

  printf("Server message received: %s",buffer); // printing server message

  send(clientSocket, "DATA\r\n", 6, 0); // sending DATA command to server

  recv(clientSocket, buffer, 1024, 0); // receiving message from server

  printf("Server message received: %s",buffer); // printing server message

  send(clientSocket, "Subject: SMTP Example\r\n\r\nThis is a test email.\r\n.\r\n", 46, 0); // sending email message to server

  recv(clientSocket, buffer, 1024, 0); // receiving message from server

  printf("Server message received: %s",buffer); // printing server message

  send(clientSocket, "QUIT\r\n", 6, 0); // sending QUIT command to server

  recv(clientSocket, buffer, 1024, 0); // receiving message from server

  printf("Server message received: %s",buffer); // printing server message

  close(clientSocket); // closing clientSocket

  return 0; // returning value
}