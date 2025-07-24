//FormAI DATASET v1.0 Category: Client Server Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

// Struct to hold appointment information
typedef struct {
    char client_name[50];
    char service_provider[50];
    char date[50];
    char time_start[50];
    char time_end[50];
} appointment_t;

// Struct to hold client and service provider information
typedef struct {
    char name[50];
    int is_service_provider;
    appointment_t schedule[10];
    int num_appointments;
} user_t;

// Create user database
user_t users[2] = {
    {.name = "John Smith", .is_service_provider = 0},
    {.name = "Jane Doe", .is_service_provider = 1}
};

// Function to handle client requests
void *handle_client(void *arg) {
    int client_fd = *(int*)arg;
    char buffer[1024] = {0};
    int valread;

    // Receive message from client
    valread = read(client_fd, buffer, 1024);
    if (valread <= 0) {
        perror("read failed");
        close(client_fd);
        return NULL;
    }

    // Split message into command and arguments
    char *cmd = strtok(buffer, " ");
    char *arg1 = strtok(NULL, " ");
    char *arg2 = strtok(NULL, " ");
    char *arg3 = strtok(NULL, " ");
    char *arg4 = strtok(NULL, " ");

    // Handle request based on command
    if (strcmp(cmd, "schedule") == 0) {
        // Check if user is a client or service provider
        int is_service_provider = 0;
        int user_index;
        for (int i = 0; i < 2; i++) {
            if (strcmp(users[i].name, arg1) == 0) {
                is_service_provider = users[i].is_service_provider;
                user_index = i;
                break;
            }
        }

        // Get appointment information
        appointment_t appt = {
            .client_name = arg2,
            .service_provider = arg1,
            .date = arg3,
            .time_start = arg4,
            .time_end = strtok(NULL, " ")
        };

        // Check if requested time slot is already booked
        for (int i = 0; i < users[user_index].num_appointments; i++) {
            appointment_t *existing_appt = &users[user_index].schedule[i];
            if (strcmp(existing_appt->date, appt.date) == 0) {
                if ((strcmp(existing_appt->time_start, appt.time_start) >= 0 && strcmp(existing_appt->time_start, appt.time_end) < 0) ||
                    (strcmp(existing_appt->time_end, appt.time_start) > 0 && strcmp(existing_appt->time_end, appt.time_end) <= 0)) {
                    // Time slot already booked
                    char msg[] = "Time slot already booked.";
                    send(client_fd, msg, strlen(msg), 0);
                    close(client_fd);
                    return NULL;
                }
            }
        }

        // Add appointment to service provider's schedule
        users[user_index].schedule[users[user_index].num_appointments++] = appt;

        // Send confirmation message to client
        char msg[100] = {0};
        sprintf(msg, "Appointment scheduled with %s on %s from %s to %s.", appt.service_provider, appt.date, appt.time_start, appt.time_end);
        send(client_fd, msg, strlen(msg), 0);
    } else if (strcmp(cmd, "view_schedule") == 0) {
        // Find user by name
        int user_index = -1;
        for (int i = 0; i < 2; i++) {
            if (strcmp(users[i].name, arg1) == 0) {
                user_index = i;
                break;
            }
        }
        if (user_index == -1) {
            // User not found
            char msg[] = "User not found.";
            send(client_fd, msg, strlen(msg), 0);
            close(client_fd);
            return NULL;
        }

        // Send schedule to client
        char msg[1024] = {0};
        sprintf(msg, "Schedule for %s:\n", users[user_index].name);
        for (int i = 0; i < users[user_index].num_appointments; i++) {
            appointment_t *appt = &users[user_index].schedule[i];
            sprintf(msg + strlen(msg), "%s on %s from %s to %s\n", appt->client_name, appt->date, appt->time_start, appt->time_end);
        }
        send(client_fd, msg, strlen(msg), 0);
    } else {
        // Invalid command
        char msg[] = "Invalid command.";
        send(client_fd, msg, strlen(msg), 0);
    }

    // Close client socket
    close(client_fd);

    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t threads[MAX_CLIENTS];

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return 1;
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        return 1;
    }
    
    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        return 1;
    }
    
    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        return 1;
    }
    
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }

        printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Create new thread to handle client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket) != 0) {
            perror("pthread_create failed");
            return 1;
        }

        // Add thread to thread pool
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (threads[i] == 0) {
                threads[i] = thread_id;
                break;
            }
        }
        if (i == MAX_CLIENTS) {
            fprintf(stderr, "Thread pool full\n");
            exit(1);
        }
    }

    return 0;
}