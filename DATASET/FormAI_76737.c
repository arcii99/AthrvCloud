//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<errno.h>
#include<string.h>
#include<time.h>
#include<signal.h>
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define BUFSIZE 100000

int sockfd;
struct sockaddr_in server_addr;
socklen_t addrlen = sizeof(server_addr);

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void sig_handler(int signo)
{
    if(signo == SIGINT)
    {
        printf("\nClosing connection. Goodbye!\n");
        close(sockfd);
        exit(0);
    }   
}

void start_time(struct timespec *start)
{
    clock_gettime(CLOCK_REALTIME, start);
}

void end_time(struct timespec *start, struct timespec *end, double *result)
{
    clock_gettime(CLOCK_REALTIME, end);
    *result = (end->tv_sec - start->tv_sec) + (end->tv_nsec - start->tv_nsec) / 1000000000.0;
}

void get_ip(char *hostname, char *ip)
{
    struct hostent *he;
    struct in_addr **addr_list;
    int i;

    if((he = gethostbyname(hostname)) == NULL)
    {
        herror("gethostbyname");
        exit(1);
    }

    addr_list = (struct in_addr **)he->h_addr_list;

    for(i = 0; addr_list[i] != NULL; i++)
    {
        strcpy(ip, inet_ntoa(*addr_list[i]));
        return;
    }
}

void send_request(char *hostname, char *request, char *port)
{
    char ip[100];
    int bytes_sent, total_sent = 0;
    int conn;

    get_ip(hostname, ip);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
        error("Error opening socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(ip);

    if(connect(sockfd, (struct sockaddr *)&server_addr, addrlen) < 0)
        error("Error connecting");

    if((bytes_sent = send(sockfd, request, strlen(request), 0)) < 0)
        error("Error sending request");

    total_sent += bytes_sent;

    printf("Request sent: %d bytes\n", total_sent);
}

void receive_response(char *response)
{
    int bytes_received, total_received = 0;
    char buffer[BUFSIZE];
    char *start, *end, *temp;
    double time_taken;
    struct timespec start_time_p, end_time_p;

    start_time(&start_time_p);

    while((bytes_received = recv(sockfd, buffer, BUFSIZE, 0)) > 0)
    {
        total_received += bytes_received;
        buffer[bytes_received] = '\0';
        strcat(response, buffer);
    }

    end_time(&start_time_p, &end_time_p, &time_taken);

    printf("Response received: %d bytes\n", total_received);
    printf("Time taken: %lf seconds\n", time_taken);

    if(bytes_received < 0)
        error("Error receiving response");

    close(sockfd);

    start = strstr(response, "Speedtest.net");

    if(start != NULL)
    {
        temp = strstr(start, "result-box");

        if(temp != NULL)
        {
            start = strstr(temp, "Download:");

            if(start != NULL)
            {
                start += strlen("Download:</strong>");

                end = strstr(start, "Mbps");

                if(end != NULL)
                {
                    *end = '\0';
                    printf("Download speed: %sMbps\n", start);
                }
            }

            start = strstr(temp, "Upload:");

            if(start != NULL)
            {
                start += strlen("Upload:</strong>");

                end = strstr(start, "Mbps");

                if(end != NULL)
                {
                    *end = '\0';
                    printf("Upload speed: %sMbps\n", start);
                }
            }
        }
    }   
    else
    {
        printf("Unable to determine speedtest result\n");
    }
}

int main(int argc, char *argv[])
{
    signal(SIGINT, sig_handler);

    if(argc != 4)
    {
        fprintf(stderr, "Usage: %s <hostname> <port> <path>\n", argv[0]);
        exit(1);
    }

    char request[1000] = {0};
    char response[BUFSIZE] = {0};
    char *hostname = argv[1];
    char *port = argv[2];
    char *path = argv[3];

    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:41.0) Gecko/20100101 Firefox/41.0\r\nConnection: keep-alive\r\n\r\n", path, hostname);

    send_request(hostname, request, port);

    receive_response(response);

    return 0;
}