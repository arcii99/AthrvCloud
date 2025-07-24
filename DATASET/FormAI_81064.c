//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
/* 
   Fair server code, good Capulet,
   That will make localhost our new market:
   To serve, to listen, a web server true,
   With pages of Montagues and Capulets too.

   By this we start, where hot-bloods run high,
   Yet do not fret, for this code is nigh:
   A simple server, that takes a client's call,
   And sends them pages, no brawls, no gall.

   Listen and accept, to take a client hand,
   Send back HTTP messages, the server's command:
   404 for missing pages, 200 for found
   Or error 500, for when something's unsound.

   Let us no longer, our foes internet roam,
   And with this code, make our own e-home:
   Of Capulets and Montagues, co-existing free,
   A server for unity, for all eyes to see.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in serv_addr, clnt_addr;
  char buffer[1024];
  int serv_sock, clnt_sock;
  socklen_t clnt_addr_size;
  int length, i;
  char response_200[] = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n";
  char response_404[] = "HTTP/1.1 404 Page Not Found\r\nContent-type: text/html\r\n\r\n";
  char html_template[] = "<html><head><title>%s</title></head><body>%s</body></html>";
  char home_html[1024], montague_html[1024], capulet_html[1024];
  char home_title[] = "Home", montague_title[] = "Montagues", capulet_title[] = "Capulets";
  char home_content[] = "<h1>Welcome to Our Web Server!</h1><h2>This is the home page.</h2>";
  char montague_content[] = "<h1>The Montagues</h1><p>The Montagues are a noble family in Verona, Italy, and aspired to become royalty. They were the enemies of the Capulets.</p>";
  char capulet_content[] = "<h1>The Capulets</h1><p>The Capulets were a wealthy family in Verona, Italy, and were considered the pride of the city. They were the enemies of the Montagues.</p>";
  
  // Set content for home page
  sprintf(home_html, html_template, home_title, home_content);
  // Set content for Montagues page
  sprintf(montague_html, html_template, montague_title, montague_content);
  // Set content for Capulets page
  sprintf(capulet_html, html_template, capulet_title, capulet_content);

  // Create server socket
  serv_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (serv_sock == -1) {
    printf("Error: Could not create socket.\n");
    return 1;
  }
  
  // Set server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(8080);
  
  // Bind socket with server address
  if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
    printf("Error: Could not bind socket.\n");
    return 1;
  }
  
  // Start listening
  if (listen(serv_sock, 5) == -1) {
    printf("Error: Could not listen on socket.\n");
    return 1;
  }
  
  // Accept incoming connection
  while (1) {
    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1) {
      printf("Error: Could not accept connection.\n");
      break;
    }
    
    // Get client request
    length = read(clnt_sock, buffer, 1024);
    buffer[length] = '\0';
    
    // Print client request
    printf("Client request: %s", buffer);
    
    // Check if client request is for home page
    if (strstr(buffer, "GET / HTTP/") != NULL) {
      write(clnt_sock, response_200, strlen(response_200));
      write(clnt_sock, home_html, strlen(home_html));
    }
    
    // Check if client request is for Montagues page
    else if (strstr(buffer, "GET /montagues HTTP/") != NULL) {
      write(clnt_sock, response_200, strlen(response_200));
      write(clnt_sock, montague_html, strlen(montague_html));
    }
    
    // Check if client request is for Capulet page
    else if (strstr(buffer, "GET /capulets HTTP/") != NULL) {
      write(clnt_sock, response_200, strlen(response_200));
      write(clnt_sock, capulet_html, strlen(capulet_html));
    }
    
    // Send 404 error if page not found
    else {
      write(clnt_sock, response_404, strlen(response_404));
    }
    
    // Close client socket
    close(clnt_sock);
  }
  
  // Close server socket
  close(serv_sock);
  
  return 0;
}