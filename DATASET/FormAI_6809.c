//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Romeo and Juliet
/* 
  Romeo, young and fiery,
  Wanted to build an FTP client, most direly.
  His beloved Juliet, with a heart that's light,
  Kept him company, while he worked all night.

  With sockets and protocols, Romeo played,
  He coded with passion, sweat and shade.
  His love's sweet voice, like a soothing balm,
  Made him forget every compile-time qualm.

  Building the FTP client, was no easy feat,
  But with Juliet's encouragement, Romeo didn't retreat.
  He coded away, not a care in his mind,
  And soon a working client, he was able to find.

  Juliet was impressed, and proud of her beau,
  She smiled at him, and said "Bravo!"
  But Romeo was not one to rest on his laurels,
  He wanted to make his client, the best in the portals.

  So he added features, that others lacked,
  FTP over SSL, and a progress bar that tracked.
  His code was clean, and beautifully styled;
  Juliet knew that her Romeo, was indeed quite skilled.

  Finally, the FTP client was ready to go,
  And Romeo was eager to show,
  His creation to the world and all,
  With Juliet's picture, hanging on the wall.

  And so they clicked, on a button, with great pride,
  And the FTP client, took them on a thrilling ride.
  It downloaded files, with lightning speed,
  And with Juliet by his side, Romeo felt freed.

  In the world of tech, Romeo had made his mark,
  And with Juliet, he was ready to embark,
  On a journey that would take them far,
  They were all set, to conquer every bar.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 4096

int main(int argc, char *argv[]) {

  // Create socket
  int socket_desc;
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);

  if (socket_desc == -1) {
    printf("Error: could not create socket");
    return 1;
  }

  // Set up connection
  struct sockaddr_in server_addr;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(21);

  // Connect to server
  if (connect(socket_desc, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    printf("Error: could not establish connection");
    return 1;
  }

  // Get response from server
  char response[MAX_RESPONSE_LENGTH];
  if (recv(socket_desc, response, MAX_RESPONSE_LENGTH, 0) < 0) {
    printf("Error: receive failed");
    return 1;
  }

  printf("%s", response);

  // Login credentials
  char* username = "username";
  char* password = "password";

  // Send username
  char command[MAX_COMMAND_LENGTH];
  sprintf(command, "USER %s\r\n", username);
  if (send(socket_desc, command, strlen(command), 0) < 0) {
    printf("Error: send failed");
    return 1;
  }

  // Get response from server
  if (recv(socket_desc, response, MAX_RESPONSE_LENGTH, 0) < 0) {
    printf("Error: receive failed");
    return 1;
  }

  printf("%s", response);

  // Send password
  sprintf(command, "PASS %s\r\n", password);
  if (send(socket_desc, command, strlen(command), 0) < 0) {
    printf("Error: send failed");
    return 1;
  }

  // Get response from server
  if (recv(socket_desc, response, MAX_RESPONSE_LENGTH, 0) < 0) {
    printf("Error: receive failed");
    return 1;
  }

  printf("%s", response);

  // Change to binary mode
  sprintf(command, "TYPE I\r\n");
  if (send(socket_desc, command, strlen(command), 0) < 0) {
    printf("Error: send failed");
    return 1;
  }

  // Get response from server
  if (recv(socket_desc, response, MAX_RESPONSE_LENGTH, 0) < 0) {
    printf("Error: receive failed");
    return 1;
  }

  printf("%s", response);

  // Close connection
  if (close(socket_desc) < 0) {
    printf("Error: could not close socket");
    return 1;
  }

  return 0;
}