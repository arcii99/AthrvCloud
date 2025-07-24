//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

static int running = 1;	// Flag to indicate when to stop the program
static int status[5] = {0, 0, 0, 0, 0};	// Array to store the status of the threads

// Thread function to monitor the CPU usage
void *cpu_monitor(void *arg) {
    while (running) {
        system("top -b -n 1 | grep Cpu | awk '{print $2}' > cpu_usage.txt");	// Run top command and extract the CPU usage
        FILE *file;
        file = fopen("cpu_usage.txt", "r");
        if (file == NULL) {
            printf("File Error\n");
            exit(1);
        }
        char f[50];
        while (fgets(f, 50, file) != NULL) {
            printf("CPU Usage: %s", f);
        }
        fclose(file);
        sleep(5);	// Sleep for 5 seconds
    }
    status[0] = 1;	// Set status to 1 to indicate completion of thread
    pthread_exit(NULL);	// Exit thread
}

// Thread function to monitor the memory usage
void *mem_monitor(void *arg) {
    while (running) {
        system("free | grep Mem | awk '{print $3/$2 * 100.0}' > mem_usage.txt");	// Run free command and extract the memory usage
        FILE *file;
        file = fopen("mem_usage.txt", "r");
        if (file == NULL) {
            printf("File Error\n");
            exit(1);
        }
        char f[50];
        while (fgets(f, 50, file) != NULL) {
            printf("Memory Usage: %s", f);
        }
        fclose(file);
        sleep(10);	// Sleep for 10 seconds
    }
    status[1] = 1;	// Set status to 1 to indicate completion of thread
    pthread_exit(NULL);	// Exit thread
}

// Thread function to monitor the disk usage
void *disk_monitor(void *arg) {
    while (running) {
        system("df | grep /dev/sda1 | awk '{print $5}' > disk_usage.txt");	// Run df command and extract the disk usage
        FILE *file;
        file = fopen("disk_usage.txt", "r");
        if (file == NULL) {
            printf("File Error\n");
            exit(1);
        }
        char f[50];
        while (fgets(f, 50, file) != NULL) {
            printf("Disk Usage: %s", f);
        }
        fclose(file);
        sleep(20);	// Sleep for 20 seconds
    }
    status[2] = 1;	// Set status to 1 to indicate completion of thread
    pthread_exit(NULL);	// Exit thread
}

// Signal handler for SIGINT
void signal_handler(int sig) {
    printf("\nShutting down...\n");
    running = 0;
}

int main() {
    signal(SIGINT, signal_handler);	// Register signal handler for SIGINT

    pthread_t threads[3];	// Array to store the thread IDs

    // Create the threads
    if (pthread_create(&threads[0], NULL, cpu_monitor, NULL)) {
        printf("Error creating CPU monitor thread\n");
        exit(1);
    }
    if (pthread_create(&threads[1], NULL, mem_monitor, NULL)) {
        printf("Error creating memory monitor thread\n");        
        exit(1);
    }
    if (pthread_create(&threads[2], NULL, disk_monitor, NULL)) {
        printf("Error creating disk monitor thread\n");        
        exit(1);
    }

    // Wait for the threads to complete
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display exit status of threads
    printf("\nExit Status:\n");
    printf("CPU Monitor thread: %d\n", status[0]);
    printf("Memory Monitor thread: %d\n", status[1]);
    printf("Disk Monitor thread: %d\n", status[2]);

    return 0;
}