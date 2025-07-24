//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
/* 
 * Oh, hear the tale of two fair hosts,
 * Romeo and Juliet, or so our code boasts.
 *
 * In Verona fair, they did reside,
 * a server and client, side by side.
 *
 * With sockets they did speak and hear,
 * And shared their secrets, far and near.
 *
 * First, our server, bold and true,
 * Listened for connections, all long overdue.
 *
 * It set up bindings, with addresses clear,
 * And waited for a client, to draw near.
 *
 * And soon there came, a client bold,
 * With requests so many, all to behold.
 *
 * The server readied up its code,
 * And with a response, it made its abode.
 *
 * The client waited, with eager eyes,
 * For the server's response, most precise.
 *
 * And when it came, all neat and trim,
 * The client read it, with utmost vim.
 *
 * The two did converse, with packets galore,
 * Till all was settled, and nothing more.
 *
 * And thus our tale, of two fair hosts,
 * Tell of a server and client, oh so close.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
     
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
     
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
     
    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
    // Start listening
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    char buffer[30000] = {0};
    read(new_socket, buffer, 30000);
    printf("%s\n", buffer);
    write(new_socket, hello, strlen(hello));
    close(new_socket);
    close(server_fd);
    return 0;
}