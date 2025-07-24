//FormAI DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

char msg[] = "Congratulations! You have solved the puzzle.";

int main()
{
    // Creating socket file descriptor
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the defined port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the defined port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = {0};
    valread = read(new_socket, buffer, 1024);
    printf("Received: %s\n", buffer);
    if (strcmp(buffer, "I am ready to solve the puzzle") == 0)
    {
        char clue1[] = "I am a three-letter word. My first two letters indicate an opposite of a 'yes'. Ans = $&";
        send(new_socket, clue1, strlen(clue1), 0);
    }

    memset(buffer, 0, 1024);
    valread = read(new_socket, buffer, 1024);
    printf("Received: %s\n", buffer);
    if (strcmp(buffer, "I think the answer is '$&'") == 0)
    {
        char clue2[] = "Correct. I am a five-letter word. If you remove my first and last letters, I become a country's name. Ans = &*#%";
        send(new_socket, clue2, strlen(clue2), 0);
    }

    memset(buffer, 0, 1024);
    valread = read(new_socket, buffer, 1024);
    printf("Received: %s\n", buffer);
    if (strcmp(buffer, "I think the answer is '&*#%'") == 0)
    {
        char clue3[] = "Well done. I am a nine-letter word. My first four letters represent a term used in cricket, while my last five letters are superstars of Hollywood. Ans = ^%*$#&@^";
        send(new_socket, clue3, strlen(clue3), 0);
    }

    memset(buffer, 0, 1024);
    valread = read(new_socket, buffer, 1024);
    printf("Received: %s\n", buffer);
    if (strcmp(buffer, "I think the answer is '^%*$#&@^'") == 0)
    {
        send(new_socket, msg, strlen(msg), 0);
    }

    printf("Puzzle solved. Connection closed.\n");
    close(new_socket);
    close(server_fd);
    return 0;
}