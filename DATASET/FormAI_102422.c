//FormAI DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#define MAX_SIZE 100

struct inventory {
    char name[MAX_SIZE];
    int quantity;
    float price;
} inv[10];

void initialize_inventory() {
    strcpy(inv[0].name, "pen");
    inv[0].quantity = 100;
    inv[0].price = 5.0;

    strcpy(inv[1].name, "pencil");
    inv[1].quantity = 150;
    inv[1].price = 2.5;

    strcpy(inv[2].name, "eraser");
    inv[2].quantity = 75;
    inv[2].price = 1.0;

    strcpy(inv[3].name, "ruler");
    inv[3].quantity = 50;
    inv[3].price = 3.0;

    strcpy(inv[4].name, "sharpener");
    inv[4].quantity = 25;
    inv[4].price = 2.0;

    strcpy(inv[5].name, "notebook");
    inv[5].quantity = 80;
    inv[5].price = 10.0;

    strcpy(inv[6].name, "marker");
    inv[6].quantity = 40;
    inv[6].price = 4.0;

    strcpy(inv[7].name, "stapler");
    inv[7].quantity = 20;
    inv[7].price = 15.0;

    strcpy(inv[8].name, "tape");
    inv[8].quantity = 30;
    inv[8].price = 7.5;

    strcpy(inv[9].name, "highlighter");
    inv[9].quantity = 50;
    inv[9].price = 3.5;
}

void display_inventory() {
    printf("\n%-20s%-12s%-12s\n", "Item Name", "Quantity", "Price");
    for(int i=0; i<10; i++) {
        printf("%-20s%-12d%-12.2f\n", inv[i].name, inv[i].quantity, inv[i].price);
    }
}

int main() {
    int serversocket, clientsocket;
    socklen_t len;
    struct sockaddr_in serveraddress, clientaddress;
    char buffer[MAX_SIZE];
    int opt = 1;

    initialize_inventory();

    // create server socket
    serversocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serversocket < 0) {
        perror("socket error");
        exit(1);
    }

    if (setsockopt(serversocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt error");
        exit(1);
    }

    // bind socket to port
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = INADDR_ANY;
    serveraddress.sin_port = htons(5000);

    if (bind(serversocket, (struct sockaddr *)&serveraddress, sizeof(serveraddress)) < 0) {
        perror("bind error");
        exit(1);
    }

    // listen for incoming connection
    if (listen(serversocket, 10) < 0) {
        perror("listen error");
        exit(1);
    }

    printf("Server waiting for connection...\n");

    while(1) {
        int n;
        len = sizeof(clientaddress);

        // accept new connection
        clientsocket = accept(serversocket, (struct sockaddr *)&clientaddress, &len);
        if (clientsocket < 0) {
            perror("accept error");
            exit(1);
        }

        // read command from client
        n = read(clientsocket, buffer, MAX_SIZE);
        if (n < 0) {
            perror("read error");
            exit(1);
        }

        printf("\nReceived command from client: %s", buffer);
        strcat(buffer, "\n");

        // execute command 
        if (strcmp(buffer, "display inventory\n") == 0) {
            display_inventory();
            strcpy(buffer, "Inventory Displayed.\n");
        } else {
            strcpy(buffer, "Invalid Command.\n");
        }

        // send response to client
        n = write(clientsocket, buffer, strlen(buffer));
        if (n < 0) {
            perror("write error");
            exit(1);
        }

        close(clientsocket); 
    }

    return 0;
}