//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT 8080 /* port number to listen on*/

int main()
{
    int sockfd, newsockfd, portno=PORT, clilen, n, i, j, k, m = 0;//declaration of various variables initialized
    struct sockaddr_in serv_addr, cli_addr;//structures for sock address
    char buffer[32768];//for data transfer and buffer

    sockfd = socket(AF_INET, SOCK_STREAM, 0);//creating a TCP socket
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    //bzero is used to clear out all the data in memory allocated
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
    {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd,5);//starts listening

    while(1)
    {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);//a new socket is created to handle the new connection

        if (newsockfd < 0) 
        {
            perror("ERROR on accept");
            exit(1);
        }
        bzero(buffer,32768);
        n = read(newsockfd,buffer,32768);//data is read from the browser, to first filter any images or ad.

        if (n < 0) 
        {
            perror("ERROR reading from socket");
            exit(1);
        }

        char url[500], path[500], protocol[30];//data from the browser is stored in the respective variables

        for (i = 0; i < 500; i++) 
        {
            if (buffer[i] == ' ' || buffer[i] == '\n') //extract URL from header
                break;
            url[i] = buffer[i];
        }
        url[i] = '\0';

        if (strstr(url, "http://"))//extract URL and path from URL
        {
            char *ptr = strstr(url, "http://");
            for (j = 7, k = 0; ptr[j] != '/'; j++, k++) 
            {
                path[k] = ptr[j];
            }
            path[k] = '/';
            path[k + 1] = '\0';
            ptr += j;
            strcpy(protocol, "HTTP/1.1");
        } 
        else if (strstr(url, "https://")) //if it is an SSL site, set protocol as SSL.
        {
            strcpy(protocol, "SSL\0");
            printf("SSL sites are not supported! \n");
            continue;
        } 
        else 
        {
            for (j = 0, k = 0; url[j] != '/'; j++, k++) 
            {
                path[k] = url[j];
            }
            path[k] = '/';
            path[k + 1] = '\0';
            strcat(path, url + j);
            strcpy(protocol, "HTTP/1.1");
        }

        printf("Connecting through proxy.. %s ", url);//inform the user about the URL that is being accessed.

        /*printing the URL*/
        printf("URL: %s\n",url);
        printf("PATH: %s\n", path);
        printf("PROTOCOL: %s\n", protocol);

        /*Sending request to server*/
        int sock = 0;
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)//creating a TCP socket to connect to the URL. 
        {
            printf("\n Socket creation error \n");
            return -1;
        }

        //nsocket address of the server
        struct sockaddr_in servaddr;
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(80);

        // Convert IPv4 and IPv6 addresses from text to binary form
        if(inet_pton(AF_INET, path, &servaddr.sin_addr)<=0)
        {
            printf("\nInvalid address/ Address not supported \n");
            return -1;
        }

        if (connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)//connect to the server.
        { 
            printf("\nConnection Failed \n");
            return -1;
        }

        write(sock, buffer, strlen(buffer));//writing data to URL path

        bzero(buffer, 32768);
        n = read(sock, buffer, 32768);//read data from the URL

        if (n < 0) 
        {
            perror("ERROR reading from socket");
            exit(1);
        }

        char response[32768]; //parse the response to remove any ad or image

        for (j = 0; j < n; j++) 
        {
            if (buffer[j] == '\r' && buffer[j + 1] == '\n' && buffer[j + 2] != '\r') 
            {
                response[m++] = buffer[j++];//store the response in a separate buffer
                response[m++] = buffer[j];
                continue;
            }

            if (m != 0 && buffer[j] == '\r' && buffer[j + 1] == '\n' && buffer[j + 2] == '\r' && buffer[j + 3] == '\n') 
            {
                response[m++] = buffer[j++];
                response[m++] = buffer[j++];
                response[m++] = buffer[j++];
                response[m++] = buffer[j];
                break;
            }
        }

        bzero(buffer,32768);
        sprintf(buffer, "%s 200 ok\r\nContent-Type: text/html\r\n\r\n%s",protocol,response);//store the response in the buffer.
        n = write(newsockfd, buffer, strlen(buffer));//send the response to the user

        close(newsockfd);
        close(sock);
    }
}