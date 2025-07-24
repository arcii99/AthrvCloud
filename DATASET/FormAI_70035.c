//FormAI DATASET v1.0 Category: Client Server Application ; Style: intelligent
/* A unique client-server program that allows users to store and retrieve
 * their favorite quotes. The server stores all the quotes in a text file, and
 * the client can add a new quote, retrieve a random quote from the server, or
 * retrieve a specific quote by providing its index.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_QUOTES 100
#define MAX_QUOTE_LENGTH 256

char* quotes[MAX_QUOTES]; // Array to hold all the quotes
int num_quotes = 0; // Number of quotes currently stored

// Add a new quote to the array
void add_quote(char* quote) {
    if (num_quotes < MAX_QUOTES) {
        quotes[num_quotes] = malloc(MAX_QUOTE_LENGTH);
        strcpy(quotes[num_quotes], quote);
        num_quotes++;
        printf("Added \"%s\" to the list of quotes.\n", quote);
    }
    else {
        printf("Failed to add \"%s\": Maximum number of quotes reached.\n", quote);
    }
}

// Retrieve a random quote from the array
char* get_random_quote() {
    if (num_quotes == 0) {
        return "No quotes found.";
    }
    else {
        int index = rand() % num_quotes;
        return quotes[index];
    }
}

// Retrieve a specific quote by index
char* get_quote_by_index(int index) {
    if (index >= 0 && index < num_quotes) {
        return quotes[index];
    }
    else {
        return "Invalid index.";
    }
}

int main() {
    // Initialize the quotes array
    for (int i = 0; i < MAX_QUOTES; i++) {
        quotes[i] = NULL;
    }

    // Open the quotes file and load any existing quotes
    FILE* fp = fopen("quotes.txt", "r");
    if (fp != NULL) {
        char buffer[MAX_QUOTE_LENGTH];
        while (fgets(buffer, MAX_QUOTE_LENGTH, fp) != NULL) {
            add_quote(buffer);
        }
        fclose(fp);
    }

    // Create a socket for the server
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("Failed to create socket.");
        exit(1);
    }

    // Bind the socket to a port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(listen_fd, (struct sockaddr*) &addr, sizeof(struct sockaddr_in)) < 0) {
        perror("Failed to bind socket.");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_fd, 5) < 0) {
        perror("Failed to listen for connections.");
        exit(1);
    }

    printf("Server started on port %d.\n", PORT);

    // Accept incoming connections and handle requests
    while (1) {
        // Accept a new connection
        int conn_fd = accept(listen_fd, NULL, NULL);
        if (conn_fd < 0) {
            perror("Failed to accept connection.");
            continue;
        }

        // Read the request type from the client
        int request_type;
        if (read(conn_fd, &request_type, sizeof(int)) < 0) {
            perror("Failed to read request type.");
            close(conn_fd);
            continue;
        }

        // Handle the request
        char* response = NULL;
        switch (request_type) {
            case 1: { // Add a new quote
                char buffer[MAX_QUOTE_LENGTH];
                if (read(conn_fd, buffer, MAX_QUOTE_LENGTH) < 0) {
                    perror("Failed to read quote.");
                    response = "Failed to add quote.";
                }
                else {
                    add_quote(buffer);
                    fp = fopen("quotes.txt", "a"); // Append the new quote to the file
                    if (fp != NULL) {
                        fprintf(fp, "%s", buffer);
                        fclose(fp);
                    }
                    response = "Quote added successfully.";
                }
                break;
            }
            case 2: { // Get a random quote
                char* quote = get_random_quote();
                response = malloc(MAX_QUOTE_LENGTH);
                strcpy(response, quote);
                break;
            }
            case 3: { // Get a specific quote by index
                int index;
                if (read(conn_fd, &index, sizeof(int)) < 0) {
                    perror("Failed to read quote index.");
                    response = "Failed to retrieve quote.";
                }
                else {
                    char* quote = get_quote_by_index(index);
                    response = malloc(MAX_QUOTE_LENGTH);
                    strcpy(response, quote);
                }
                break;
            }
            default: {
                response = "Invalid request type.";
                break;
            }
        }

        // Send the response back to the client
        if (write(conn_fd, response, strlen(response) + 1) < 0) {
            perror("Failed to send response.");
        }

        free(response);
        close(conn_fd);
    }

    // Clean up resources
    for (int i = 0; i < num_quotes; i++) {
        free(quotes[i]);
    }

    return 0;
}