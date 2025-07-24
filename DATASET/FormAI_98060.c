//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

/* Set the client buffer size to 4096 bytes */
#define CLIENT_BUF_SIZE 4096

/* Set the server buffer size to 32768 bytes */
#define SERVER_BUF_SIZE 32768

/* Define the listening port */
#define SERVER_PORT 8080

/* Define the maximum number of concurrent connections we can handle */
#define MAX_CONNS 100

/* Define the HTTP line separator */
#define HTTP_LINE_SEP "\r\n"

/* Define the HTTP header separator */
#define HTTP_HEADER_SEP ":"

/* Define the HTTP GET method */
#define HTTP_GET "GET"

/* Define the HTTP POST method */
#define HTTP_POST "POST"

/* Define the HTTP response code for "OK" */
#define HTTP_RESP_CODE_OK "200 OK"

/* Define the HTTP response code for "Not Found" */
#define HTTP_RESP_CODE_NOT_FOUND "404 Not Found"

/* Define the HTTP response code for "Internal Server Error" */
#define HTTP_RESP_CODE_INTERNAL_ERROR "500 Internal Server Error"

/* Define the HTTP content type text/plain */
#define HTTP_CONTENT_TYPE_TEXT_PLAIN "text/plain"

/* Define the HTTP content type text/html */
#define HTTP_CONTENT_TYPE_TEXT_HTML "text/html"

/* Define the HTTP content type image/jpeg */
#define HTTP_CONTENT_TYPE_IMAGE_JPEG "image/jpeg"

/* Define the HTTP content type image/png */
#define HTTP_CONTENT_TYPE_IMAGE_PNG "image/png"

/* Define the HTTP content type application/json */
#define HTTP_CONTENT_TYPE_APPLICATION_JSON "application/json"

/* Struct to hold client connection data */
typedef struct {
    int conn_fd;                                       /* Client socket file descriptor */
    struct sockaddr_in cli_addr;                       /* Client sockaddr_in struct */
    char buf[CLIENT_BUF_SIZE];                         /* Client buffer */
    int buf_len;                                       /* Valid length of client buffer */
} conn_t;

/* Global variables */
static conn_t conn_list[MAX_CONNS];                    /* Connection list */
static int conn_cnt = 0;                               /* Connection count */
static int listen_fd;                                  /* Server socket file descriptor */

/* Function prototypes */
static void process_client_request(int index);
static void remove_conn(int index);

/* Function to print error messages and exit */
static void error(const char *msg) {
    perror(msg);
    exit(1);
}

/* Function to parse HTTP request line */
static void parse_http_request_line(char *buf, char *method, char *uri) {
    int i = 0;

    /* Extract method from request line */
    while(buf[i] != ' ') {
        method[i] = buf[i];
        i++;
    }
    method[i] = '\0';

    i++;

    /* Extract URI from request line */
    int j = 0;
    while(buf[i] != ' ') {
        uri[j] = buf[i];
        i++;
        j++;
    }
    uri[j] = '\0';
}

/* Function to parse HTTP request header */
static void parse_http_request_header(char *buf, char *header, char *value) {
    int i = 0;

    /* Extract header type from header */
    while(buf[i] != HTTP_HEADER_SEP[0] && i < strlen(buf)) {
        header[i] = buf[i];
        i++;
    }
    header[i] = '\0';

    i += strlen(HTTP_HEADER_SEP);

    /* Extract header value from header */
    int j = 0;
    while(buf[i] != '\r' && i < strlen(buf)) {
        value[j] = buf[i];
        i++;
        j++;
    }
    value[j] = '\0';
}

/* Function to handle HTTP GET requests */
static void handle_http_get_request(char *uri, int conn_fd) {
    char file_path[256];
    char *file_ext;
    char buf[SERVER_BUF_SIZE];
    FILE *fp;

    /* Determine the file extension of the requested resource */
    file_ext = strrchr(uri, '.');
    if(!file_ext)
        error("Unknown file type");

    /* Open the requested file */
    sprintf(file_path, "htdocs%s", uri);
    fp = fopen(file_path, "r");
    if(!fp) {
        /* File not found */
        sprintf(buf, "HTTP/1.1 %s" HTTP_LINE_SEP "Content-Type: " HTTP_CONTENT_TYPE_TEXT_PLAIN HTTP_LINE_SEP HTTP_LINE_SEP "Requested resource not found", HTTP_RESP_CODE_NOT_FOUND);
        send(conn_fd, buf, strlen(buf), 0);
        return;
    }

    /* Read the file into a buffer */
    int nread;
    char file_buf[SERVER_BUF_SIZE];
    memset(file_buf, 0, sizeof(file_buf));
    while ((nread = fread(file_buf, 1, sizeof(file_buf), fp)) > 0)
        strcat(buf, file_buf);
    fclose(fp);

    /* Set the content type based on the file extension */
    char content_type[32];
    if(strcmp(file_ext, ".html") == 0)
        strcpy(content_type, HTTP_CONTENT_TYPE_TEXT_HTML);
    else if(strcmp(file_ext, ".jpeg") == 0 || strcmp(file_ext, ".jpg") == 0)
        strcpy(content_type, HTTP_CONTENT_TYPE_IMAGE_JPEG);
    else if(strcmp(file_ext, ".png") == 0)
        strcpy(content_type, HTTP_CONTENT_TYPE_IMAGE_PNG);
    else if(strcmp(file_ext, ".json") == 0)
        strcpy(content_type, HTTP_CONTENT_TYPE_APPLICATION_JSON);
    else
        strcpy(content_type, HTTP_CONTENT_TYPE_TEXT_PLAIN);

    /* Build the HTTP response */
    sprintf(buf, "HTTP/1.1 %s" HTTP_LINE_SEP "Content-Type: %s" HTTP_LINE_SEP "Content-Length: %lu" HTTP_LINE_SEP HTTP_LINE_SEP "%s", HTTP_RESP_CODE_OK, content_type, strlen(buf), buf);

    /* Send the response */
    send(conn_fd, buf, strlen(buf), 0);
}

/* Function to handle HTTP POST requests */
static void handle_http_post_request(char *uri, char *content_type, char *body, int conn_fd) {
    char buf[SERVER_BUF_SIZE];
    sprintf(buf, "HTTP/1.1 %s" HTTP_LINE_SEP "Content-Type: " HTTP_CONTENT_TYPE_TEXT_PLAIN HTTP_LINE_SEP HTTP_LINE_SEP "Received POST request with content type %s and body %s", HTTP_RESP_CODE_OK, content_type, body);
    send(conn_fd, buf, strlen(buf), 0);
}

/* Main function */
int main() {
    int i, j;
    int conn_fd, cli_len;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[SERVER_BUF_SIZE];
    fd_set rdset;

    /* Create a TCP socket */
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("Cannot create socket");

    /* Set the socket to reuse the address */
    int optval = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int)) < 0)
        error("Cannot set socket option");

    /* Bind the socket to the server address */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SERVER_PORT);
    if (bind(listen_fd, (struct sockaddr *)(&serv_addr), sizeof(serv_addr)) < 0)
        error("Cannot bind socket");

    /* Listen for client connections */
    if (listen(listen_fd, MAX_CONNS) < 0)
        error("Cannot listen on socket");

    /* Initialize connection list */
    for(i = 0; i < MAX_CONNS; i++)
        conn_list[i].conn_fd = -1;

    while(1) {
        /* Set up the read set for select() */
        FD_ZERO(&rdset);
        FD_SET(listen_fd, &rdset);
        for(i = 0; i < MAX_CONNS; i++)
            if(conn_list[i].conn_fd != -1)
                FD_SET(conn_list[i].conn_fd, &rdset);

        /* Wait for activity */
        if (select(FD_SETSIZE, &rdset, NULL, NULL, NULL) < 0)
            error("Error in select");

        /* Check for new client connections */
        if (FD_ISSET(listen_fd, &rdset)) {
            if (conn_cnt == MAX_CONNS) {
                printf("Too many connections -- dropping new client\n");
                continue;
            }

            /* Accept incoming connection */
            cli_len = sizeof(cli_addr);
            if ((conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &cli_len)) < 0)
                error("Cannot accept new connection");

            /* Add new connection to connection list */
            for(i = 0; i < MAX_CONNS; i++) {
                if(conn_list[i].conn_fd == -1) {
                    conn_list[i].conn_fd = conn_fd;
                    conn_list[i].cli_addr = cli_addr;
                    conn_cnt++;
                    break;
                }
            }
        }

        /* Check for data on existing client connections */
        for(i = 0; i < MAX_CONNS; i++) {
            if(conn_list[i].conn_fd == -1)
                continue;

            if(FD_ISSET(conn_list[i].conn_fd, &rdset)) {
                /* Receive data from client */
                memset(buf, 0, sizeof(buf));
                int nread = recv(conn_list[i].conn_fd, buf, SERVER_BUF_SIZE-1, 0);
                if (nread < 0)
                    error("Error reading from socket");
                else if (nread == 0)
                    remove_conn(i);
                else {
                    /* Process client request */
                    conn_list[i].buf_len = nread;
                    process_client_request(i);
                }
            }
        }
    }
}

/* Function to process client request */
static void process_client_request(int index) {
    char *ptr;
    char method[16], uri[256];
    char header[128], value[256];
    char content_type[32], body[SERVER_BUF_SIZE];
    int content_length = 0;
    int i;

    /* Parse HTTP request line */
    ptr = conn_list[index].buf;
    parse_http_request_line(ptr, method, uri);

    /* Check for supported HTTP method */
    if(strcmp(method, HTTP_GET) != 0 && strcmp(method, HTTP_POST) != 0) {
        /* Unsupported method */
        char buf[SERVER_BUF_SIZE];
        sprintf(buf, "HTTP/1.1 %s" HTTP_LINE_SEP "Content-Type: " HTTP_CONTENT_TYPE_TEXT_PLAIN HTTP_LINE_SEP HTTP_LINE_SEP "Unsupported HTTP method: %s", HTTP_RESP_CODE_INTERNAL_ERROR, method);
        send(conn_list[index].conn_fd, buf, strlen(buf), 0);
        remove_conn(index);
        return;
    }

    /* Parse HTTP request headers */
    ptr = strstr(ptr, HTTP_LINE_SEP) + strlen(HTTP_LINE_SEP);
    while(strstr(ptr, HTTP_LINE_SEP) != ptr) {
        parse_http_request_header(ptr, header, value);
        if(strcmp(header, "Content-Type") == 0)
            strcpy(content_type, value);
        else if(strcmp(header, "Content-Length") == 0)
            content_length = atoi(value);
        ptr = strstr(ptr, HTTP_LINE_SEP) + strlen(HTTP_LINE_SEP);
    }
    ptr += strlen(HTTP_LINE_SEP);

    /* Parse HTTP request body */
    if(content_length > 0) {
        memcpy(body, ptr, content_length);
        body[content_length] = '\0';
    }

    /* Handle HTTP GET request */
    if(strcmp(method, HTTP_GET) == 0)
        handle_http_get_request(uri, conn_list[index].conn_fd);

    /* Handle HTTP POST request */
    if(strcmp(method, HTTP_POST) == 0)
        handle_http_post_request(uri, content_type, body, conn_list[index].conn_fd);

    /* Remove connection */
    remove_conn(index);
}

/* Function to remove a connection */
static void remove_conn(int index) {
    close(conn_list[index].conn_fd);
    conn_list[index].conn_fd = -1;
    conn_cnt--;
}