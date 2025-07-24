//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

#define PORT 8080

int main()
{
    int sock, client_sock;
    struct sockaddr_in server, client;
    char send_buff[1024];
    char recv_buff[1024];
    int recv_len, client_len;
    time_t start, end;
    double time_taken;
    int client_count = 0;

    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1)
    {
        printf("\n Socket creation failed");
        exit(1);
    }

    printf("\nSocket created");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    //bind socket to IP address and port
    if(bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("\n Binding failed");
        exit(1);
    }

    printf("\nBind successful");

    listen(sock, 10);   //listen for incoming connections

    printf("\nListening for incoming connections...\n");

    while(1)
    {
        client_len = sizeof(client);

        client_sock = accept(sock, (struct sockaddr *)&client, (socklen_t*)&client_len);

        printf("\nConnection accepted from %s:%d", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        client_count += 1;

        if(client_count<2)
        {
            send(client_sock, "Waiting for another player...", strlen("Waiting for another player..."), 0);
        }

        else if(client_count>=2)
        {
            send(client_sock, "Welcome! Please type 'start' to begin the multiplayer internet speed test...", strlen("Welcome! Please type 'start' to begin the multiplayer internet speed test..."), 0);

            recv_len = read(client_sock, recv_buff, 1024);

            if(strcmp(recv_buff, "start\n")==0)
            {
                printf("\nStarting test with %d players...", client_count);

                //send signal to start
                sprintf(send_buff, "start");
                send(client_sock, send_buff, strlen(send_buff), 0);

                //start timer
                start = time(NULL);

                //receive signal from all players
                for(int i=1; i<client_count; i++)
                {
                    recv_len = read(client_sock, recv_buff, 1024);
                }

                //end timer
                end = time(NULL);

                time_taken = difftime(end, start);

                printf("\nTest complete. Time taken to receive signal from all %d players: %lf seconds", client_count, time_taken);

                //send results to all players
                for(int i=1; i<=client_count; i++)
                {
                    sprintf(send_buff, "Your internet speed test is complete. Time taken to receive signal from all players: %lf seconds", time_taken);
                    send(client_sock, send_buff, strlen(send_buff), 0);
                }

                //reset client count
                client_count = 0;

                close(client_sock);
            }
        }

    }

    return 0;
}