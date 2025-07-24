//FormAI DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Entry struct for a diary entry
struct Entry {
    char date[11];
    char time[6];
    char content[255];
};

int main(int argc, char *argv[]) {
    int sock, client_sock, read_size;
    struct sockaddr_in server, client;
    struct Entry entries[365];
    int cur_index = 0;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket.");
        return 1;
    }
    
    // Set server properties
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    
    // Bind socket to server
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Bind failed.");
        return 1;
    }
    
    // Listen for incoming connections
    listen(sock, 3);
    
    // Wait for incoming connections and handle them
    while (1) {
        // Accept connection and assign a new socket to client
        int c = sizeof(struct sockaddr_in);
        client_sock = accept(sock, (struct sockaddr *)&client, (socklen_t*)&c);
        if (client_sock < 0) {
            puts("Accept failed.");
            return 1;
        }
        
        // Receive incoming data
        char client_message[255];
        while ((read_size = recv(client_sock, client_message, 255, 0)) > 0) {
            // Parse incoming message and add entry to diary
            struct Entry new_entry;
            strncpy(new_entry.date, client_message, 10);
            new_entry.date[10] = '\0';
            strncpy(new_entry.time, client_message + 11, 5);
            new_entry.time[5] = '\0';
            strncpy(new_entry.content, client_message + 17, 254);
            new_entry.content[254] = '\0';
            entries[cur_index] = new_entry;
            cur_index++;
            
            // Send confirmation message to client
            char *message = "Entry added to diary.";
            write(client_sock, message, strlen(message));
        }
        
        if (read_size == 0) {
            puts("Client disconnected.");
            fflush(stdout);
        }
        else if (read_size == -1) {
            puts("Receive failed.");
        }
        
        // Close client socket
        close(client_sock);
    }
    
    return 0;
}