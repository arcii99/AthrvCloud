//FormAI DATASET v1.0 Category: System administration ; Style: Cyberpunk
#include <stdlib.h>
#include <stdio.h>

#define MAX_CONNECTIONS 10

struct connection {
    int id;
    char* address;
    int port;
    int status;
};

struct connection conn_list[MAX_CONNECTIONS];

void print_menu() {
    printf("\nChoose an action: \n"); 
    printf("1. View active connections\n");
    printf("2. Add new connection\n");
    printf("3. Remove connection\n"); 
    printf("4. Exit\n\n");
}

int main() {
    printf("CyberSys Admin v1.0\n");

    int choice;
    int id = 0;

    while(1) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: // View active connections
                printf("\nActive connections:\n");
                for(int i=0; i<MAX_CONNECTIONS; i++) {
                    if(conn_list[i].status == 1) {
                        printf("ID: %d\t Address: %s\t Port: %d\n", 
                               conn_list[i].id, conn_list[i].address, conn_list[i].port);
                    }
                }
                break;

            case 2: // Add new connection
                if(id >= MAX_CONNECTIONS) {
                    printf("\nError: Maximum number of connections exceeded.\n");
                    break;
                }

                char* address = malloc(sizeof(char) * 20); // Max length of IP address is 15
                int port;

                printf("\nEnter IP address: ");
                scanf("%s", address);

                printf("Enter port number: ");
                scanf("%d", &port);

                conn_list[id].id = id;
                conn_list[id].address = address;
                conn_list[id].port = port;
                conn_list[id].status = 1;

                printf("\nConnection added successfully. ID: %d\n", id);
                id++;
                break;

            case 3: // Remove connection
                int remove_id;

                printf("\nEnter ID of connection to remove: ");
                scanf("%d", &remove_id);

                if(remove_id < 0 || remove_id >= id || conn_list[remove_id].status == 0) {
                    printf("\nError: Invalid ID.\n");
                    break;
                }

                free(conn_list[remove_id].address);
                conn_list[remove_id].address = NULL;
                conn_list[remove_id].status = 0;

                printf("\nConnection removed successfully.\n");
                break;

            case 4: // Exit
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nError: Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}