//FormAI DATASET v1.0 Category: Networking ; Style: mathematical
/* This program computes the sum of two matrices using networking in C programming language. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

// Define the size of the matrices
#define ROW 3
#define COL 3

// Function to print the matrix
void printMatrix(int matrix[][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    // Create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Connect socket to server
    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1) {
        printf("Error connecting to server!\n");
        return -1;
    }

    // Define the matrices
    int matrix1[ROW][COL] = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    int matrix2[ROW][COL] = {{10, 11, 12},
                             {13, 14, 15},
                             {16, 17, 18}};

    // Send the matrices to the server
    int bytes_sent = send(network_socket, matrix1, sizeof(matrix1), 0);
    bytes_sent = send(network_socket, matrix2, sizeof(matrix2), 0);

    // Receive the result from server
    int result[ROW][COL];
    int bytes_received = recv(network_socket, result, sizeof(result), 0);

    // Print the matrices and result
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2);
    printf("\nResult:\n");
    printMatrix(result);

    // Close the socket
    close(network_socket);

    return 0;
}