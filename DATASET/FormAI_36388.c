//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Function Prototype
int create_tcp_socket();
char *get_ip(char *host);
char *build_get_query(char *host, char *page);

#define HOST "www.example.com"
#define PAGE "/"
#define PORT 80
#define USERAGENT "HTTPClient/1.0"

int main(int argc, char const *argv[])
{
    struct sockaddr_in *remote;
    int sock;
    int tmpres;
    char *ip;
    char *get;
    char buf[BUFSIZ + 1];

    // Create TCP Socket
    sock = create_tcp_socket();

    // Retrieve IP Address of the Server
    ip = get_ip(HOST);
    fprintf(stderr, "IP is %s\n", ip);

    // Set Remote Address
    remote = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in *));
    remote->sin_family = AF_INET;
    tmpres = inet_pton(AF_INET, ip, (void *)&(remote->sin_addr.s_addr));
    if (tmpres < 0)
    {
        perror("Can't set remote->sin_addr.s_addr");
        exit(1);
    }
    else if (tmpres == 0)
    {
        fprintf(stderr, "%s is not a valid IP address\n", ip);
        exit(1);
    }
    remote->sin_port = htons(PORT);

    // Connect to Remote Server
    if (connect(sock, (struct sockaddr *)remote, sizeof(struct sockaddr)) < 0)
    {
        perror("Could not connect");
        exit(1);
    }

    // Send GET Request
    get = build_get_query(HOST, PAGE);
    fprintf(stderr, "Query is:\n<<START>>\n%s<<END>>\n", get);

    int sent = 0;
    while (sent < strlen(get))
    {
        tmpres = send(sock, get + sent, strlen(get) - sent, 0);
        if (tmpres == -1)
        {
            perror("Can't send query");
            exit(1);
        }
        sent += tmpres;
    }

    // Read Response from Server
    memset(buf, 0, sizeof(buf));
    int htmlstart = 0;
    char *htmlcontent = NULL;
    while ((tmpres = recv(sock, buf, BUFSIZ, 0)) > 0)
    {
        if (htmlstart == 0)
        {
            htmlcontent = strstr(buf, "\r\n\r\n");
            if (htmlcontent != NULL)
            {
                htmlstart = 1;
                htmlcontent += 4;
            }
        }
        else
        {
            htmlcontent = buf;
        }
        if (htmlstart)
        {
            fprintf(stdout, "%s", htmlcontent);
        }

        memset(buf, 0, tmpres);
    }
    if (tmpres < 0)
    {
        perror("Error receiving data");
    }

    // Free Resources
    free(get);
    free(remote);
    close(sock);
    return 0;
}

// Create TCP Socket
int create_tcp_socket()
{
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("Can't create TCP socket");
        exit(1);
    }
    return sock;
}

// Get IP Address from Hostname
char *get_ip(char *host)
{
    struct hostent *hent;
    int iplen = 15;  // XXX.XXX.XXX.XXX
    char *ip = (char *)malloc(iplen + 1);
    memset(ip, 0, iplen + 1);
    if ((hent = gethostbyname(host)) == NULL)
    {
        herror("Can't get IP host by name");
        exit(1);
    }
    if (inet_ntop(AF_INET, (void *)hent->h_addr_list[0], ip, iplen) == NULL)
    {
        perror("Can't resolve host");
        exit(1);
    }
    return ip;
}

// Build GET Request
char *build_get_query(char *host, char *page)
{
    char *query;
    char *getpage = page;
    char *tpl = "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
    if (getpage[0] == '/')
    {
        getpage += 1;
        printf("Removing leading \"/\", converting %s to %s\n", page, getpage);
    }
    query = (char *)malloc(strlen(host) + strlen(getpage) + strlen(USERAGENT) + strlen(tpl) + 1);
    sprintf(query, tpl, getpage, host, USERAGENT);
    return query;
}