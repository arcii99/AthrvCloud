//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

/**
 * Represents the URL of a website
 */
typedef struct {
    char* host;
    int port;
    char* path;
} Url;

/**
 * Parses a URL string into separate host, port, and path components.
 */
Url parse_url(char* url_string) {
    Url url = { NULL, 80, "/" };
    char* url_copy = strdup(url_string);
    char* scheme = strtok(url_copy, ":");
    char* rest_of_url = strtok(NULL, "");
    char* host = strtok(rest_of_url, "/");
    char* path = strtok(NULL, "");
    char* port_str = strtok(host, ":");
    char* port = strtok(NULL, "");

    if (port != NULL) {
        url.port = atoi(port);
    }

    if (path != NULL) {
        url.path = path;
    }

    url.host = host;
    free(url_copy);
    return url;
}

/**
 * Returns the IP address for a given host.
 */
char* resolve_host(char* hostname) {
    struct addrinfo hints, *results, *p;
    int status;
    char ip_address[INET_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(hostname, "http", &hints, &results)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return NULL;
    }

    for (p = results; p != NULL; p = p->ai_next) {
        void* addr;
        char* ip;

        if (p->ai_family == AF_INET) {
            struct sockaddr_in* ipv4 = (struct sockaddr_in*) p->ai_addr;
            addr = &(ipv4->sin_addr);
        } else {
            continue;
        }

        inet_ntop(p->ai_family, addr, ip_address, sizeof ip_address);
        ip = strdup(ip_address);
        freeaddrinfo(results);
        return ip;
    }

    freeaddrinfo(results);
    return NULL;
}

/**
 * Retrieves the HTML content of a webpage given its URL.
 */
char* fetch_page(Url url) {
    int sockfd, bytes_received;
    bool connected;
    struct sockaddr_in server_addr;
    char* ip_address = resolve_host(url.host);
    char buffer[BUFFER_SIZE];

    if (ip_address == NULL) {
        return NULL;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        return NULL;
    }

    memset(&server_addr, 0, sizeof server_addr);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(url.port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    connected = connect(sockfd, (struct sockaddr*) &server_addr, sizeof server_addr) >= 0;
    free(ip_address);

    if (!connected) {
        fprintf(stderr, "ERROR connecting to server\n");
        return NULL;
    }

    snprintf(buffer, BUFFER_SIZE,
             "GET %s HTTP/1.0\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:84.0) Gecko/20100101 Firefox/84.0\r\nConnection: close\r\n\r\n",
             url.path, url.host);

    int len = strlen(buffer);
    int total_sent = 0;

    while (total_sent < len) {
        int sent = send(sockfd, buffer + total_sent, len - total_sent, 0);

        if (sent == -1) {
            fprintf(stderr, "ERROR sending data\n");
            return NULL;
        }

        total_sent += sent;
    }

    char* page_contents = calloc(BUFFER_SIZE, sizeof(char));
    char* current_position = page_contents;
    int total_received = 0;
    int bytes_to_read;

    while (true) {
        bytes_to_read = BUFFER_SIZE - total_received;
        bytes_received = recv(sockfd, current_position, bytes_to_read, 0);

        if (bytes_received <= 0) {
            break;
        }

        total_received += bytes_received;
        current_position += bytes_received;

        if (total_received >= BUFFER_SIZE) {
            int new_size = BUFFER_SIZE * 2;
            page_contents = realloc(page_contents, new_size * sizeof(char));
            memset(page_contents + BUFFER_SIZE, 0, BUFFER_SIZE * sizeof(char));
            current_position = page_contents + total_received;
        }
    }

    return page_contents;
}

int main(int argc, char** argv) {
    char* url_string = "https://www.google.com/";
    Url url = parse_url(url_string);
    char* webpage = fetch_page(url);

    if (webpage != NULL) {
        printf("%s\n", webpage);
        free(webpage);
    } else {
        printf("Failed to connect to website at URL: %s\n", url_string);
    }

    return 0;
}