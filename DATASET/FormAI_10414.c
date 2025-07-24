//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: funny
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\nCould not create socket ٩(๑❛ᴗ❛๑)۶");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid Address or Address not supported (•ิ_•ิ)?");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed (っ- ‸ – ς) ");
        return -1;
    }

    printf("Connected to the server! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧\n");
    printf("Say something to the server: ");
    fgets(message, 1024, stdin);

    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("\nCould not send message (╯°□°）╯︵ ┻━┻");
        return -1;
    }

    printf("\nMessage sent to the server successfully!");
    printf("\nServer's response: ");

    valread = read(sock, message, 1024);
    printf("%s\n", message);
    close(sock);

    printf("\nSocket closed! (￣ε(#￣)☆╰╮o(￣皿￣///) \n");
    return 0;
}