//FormAI DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 65535 // Maximum number of threads that can be created (65535 is the max number of ports)
#define PORT_RANGE_START 1 // Starting port number of the scan
#define PORT_RANGE_END 65535 // Ending port number of the scan
#define THREAD_SLEEP_TIME 10 // Sleep time in milliseconds between thread creations
#define MAXIMUM_OPEN_PORTS 100 // Maximum number of open ports to print

static int open_ports[MAXIMUM_OPEN_PORTS]; // Array to hold open ports
static int number_of_open_ports = 0; // Number of open ports found

struct sockaddr_in server;
char *target_hostname = "127.0.0.1"; // Hostname to scan
int scanned_ports_count = 0; // Number of ports scanned

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex to prevent race condition while writing to the open_ports array

void *port_scanner(void *thread_id) // The function that will be executed by each thread
{
    int port;
    int socket_fd;
    int connection_status;
    int thread_id_num = *(int*) thread_id; // Get the thread ID as an integer

    while (1) // Loop to keep executing until all ports are scanned
    {
        pthread_mutex_lock(&mutex); // Lock the mutex to prevent race condition
        port = scanned_ports_count + PORT_RANGE_START; // Choose a port to scan
        scanned_ports_count++; // Increment the count for the next loop.
        pthread_mutex_unlock(&mutex); // Unlock the mutex
        
        if (port > PORT_RANGE_END) // If all ports are scanned, exit the loop
        {
            break;
        }

        socket_fd = socket(AF_INET, SOCK_STREAM, 0); // Create a TCP socket

        if (socket_fd == -1) // Check if socket creation failed
        {
            perror("socket creation failed");
            exit(EXIT_FAILURE);
        }

        server.sin_addr.s_addr = inet_addr(target_hostname);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        connection_status = connect(socket_fd, (struct sockaddr *)&server, sizeof(server));

        if (connection_status == 0) // If connection is established, the port is open
        {
            pthread_mutex_lock(&mutex); // Lock the mutex to prevent race condition
            open_ports[number_of_open_ports] = port; // Add open port to the array
            number_of_open_ports++; // Increment the count
            pthread_mutex_unlock(&mutex); // Unlock the mutex

            printf("Port %d is open.\n", port);

            close(socket_fd); // Close the socket
        }

        usleep(THREAD_SLEEP_TIME * 1000); // Wait for some time before creating the next thread
    }

    pthread_exit(NULL); // Exit the thread
}

int main()
{
    int i;
    pthread_t threads[MAX_THREADS]; // Array to hold thread objects
    int thread_ids[MAX_THREADS]; // Array to hold thread IDs

    printf("Starting port scan on %s...\n", target_hostname);

    for (i = 0; i < MAX_THREADS; i++)
    {
        thread_ids[i] = i + 1; // Assign IDs to the threads
        if (pthread_create(&threads[i], NULL, port_scanner, (void *) &thread_ids[i]) != 0) // Create a thread and pass the ID as a parameter
        {
            perror("thread creation failed");
            exit(EXIT_FAILURE);
        }

        usleep(THREAD_SLEEP_TIME * 1000); // Wait for some time before creating the next thread
    }

    for (i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL); // Wait for all threads to finish executing
    }

    printf("Number of open ports: %d\n", number_of_open_ports);

    if (number_of_open_ports > 0) // Print the open ports
    {
        printf("Open ports:\n");
        for (i = 0; i < number_of_open_ports; i++)
        {
            printf("%d\n", open_ports[i]);
        }
    }

    return 0;
}