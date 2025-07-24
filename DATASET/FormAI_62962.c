//FormAI DATASET v1.0 Category: Chat server ; Style: post-apocalyptic
/*
Post-Apocalyptic Chat Server

The world as we knew it has been destroyed and communication is scarce. This chat server was created to allow survivors to connect with one another and exchange information about the state of the world. 

The server accepts connections on port 5000 and allows clients to send messages that are broadcasted to all other users connected to the server.

Author: ApocalypseCoder
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SZ 2048

static _Atomic unsigned int cli_count = 0;
static int uid = 10;

/* Client structure */
typedef struct {
    struct sockaddr_in address;
    int sockfd;
    int uid;
    char name[32];
} client_t;

client_t *clients[MAX_CLIENTS];

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Print error message */
void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

/* Add a client to the connected clients array */
void add_client(client_t *client) {
    pthread_mutex_lock(&clients_mutex);

    for(int i = 0; i < MAX_CLIENTS; ++i) {
        if (!clients[i]) {
            clients[i] = client;
            break;
        }
    }

    pthread_mutex_unlock(&clients_mutex);
}

/* Remove a client from the connected clients array */
void remove_client(int uid) {
    pthread_mutex_lock(&clients_mutex);

    for(int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] && clients[i]->uid == uid) {
            clients[i] = NULL;
            break;
        }
    }

    pthread_mutex_unlock(&clients_mutex);
}

/* Send message to all clients except this particular client */
void send_message(char *s, int uid) {
    pthread_mutex_lock(&clients_mutex);

    for(int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] && clients[i]->uid != uid) {
            write(clients[i]->sockfd, s, strlen(s));
        }
    }

    pthread_mutex_unlock(&clients_mutex);
}

/* Handle clients' inputs */
void *handle_client(void *arg) {
    char buffer[BUFFER_SZ] = {};
    char name[32] = {};
    int leave_flag = 0;
    client_t *client = (client_t *)arg;

    /* Get client name */
    if (recv(client->sockfd, name, 32, 0) <= 0 || strlen(name) < 2 || strlen(name) >= 32-1) {
        printf("Didn't enter the name.\n");
        leave_flag = 1;
    } else {
        strcpy(client->name, name);
        sprintf(buffer, "%s has joined\n", client->name);
        printf("%s", buffer);
        send_message(buffer, client->uid);
    }

    bzero(buffer, BUFFER_SZ);

    while (1) {
        if (leave_flag) break;

        int receive = recv(client->sockfd, buffer, BUFFER_SZ, 0);

        if (receive > 0) {
            if (strlen(buffer) > 0) {
                send_message(buffer, client->uid);
                printf("%s", buffer);
            }
        } else if (receive == 0 || strcmp(buffer, "/exit") == 0) {
            sprintf(buffer, "%s has left\n", client->name);
            printf("%s", buffer);
            send_message(buffer, client->uid);
            leave_flag = 1;
        } else {
            printf("Error -1\n");
            leave_flag = 1;
        }

        bzero(buffer, BUFFER_SZ);
    }

    /* Remove client on exit and client info */
    close(client->sockfd);
    remove_client(client->uid);
    free(client);
    cli_count--;
    pthread_detach(pthread_self());

    return NULL;
}

int main(int argc, char **argv) {
    int sockfd = 0, newsockfd = 0, portno = 5000;
    struct sockaddr_in serv_addr, cli_addr;
    pthread_t tid;

    /* Initialize clients */
    for(int i = 0; i < MAX_CLIENTS; ++i) {
        clients[i] = NULL;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket.");
    }

    /* Set socket information */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding.");
    }

    if (listen(sockfd, 10) < 0) {
        error("ERROR on listening.");
    }

    printf("Server Listening on port %d\n", portno);

    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        /* Check for max number of clients */
        if ((cli_count+1) == MAX_CLIENTS) {
            printf("Max clients reached. Connection rejected.");
            close(newsockfd);
            continue;
        }

        /* Client information */
        client_t *client = (client_t *)malloc(sizeof(client_t));
        client->address = cli_addr;
        client->sockfd = newsockfd;
        client->uid = uid++;

        /* Add client to array */
        add_client(client);
        pthread_create(&tid, NULL, &handle_client, (void*)client);

        /* Increment client count */
        cli_count++;
    }

    return EXIT_SUCCESS;
}