//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile int running = 1;

void sigint_handler(int sig) {
    running = 0;
}

int main() {
    // Register SIGINT handler
    signal(SIGINT, sigint_handler);

    printf("CPU Usage Monitor: Press Ctrl+C to exit\n");

    while (running) {
        FILE *fp;
        char buffer[128];
        double usage;

        // Read CPU usage using top command
        fp = popen("top -bn1 | grep -oP '^%Cpu.*? id,' | sed 's/%Cpu(s)://g' | awk '{print $8}'", "r");
        fgets(buffer, sizeof(buffer), fp);
        pclose(fp);

        usage = strtod(buffer, NULL);

        printf("\033[2J\033[H"); // Clear screen
        printf("CPU Usage: %.2f%%\n\n", 100 - usage);
        printf("|");
        for (int i=0; i<50; i++) {
            if ((i/50.0)*100 < (100 - usage))
                printf("█");
            else
                printf("-");
        }
        printf("|");

        fflush(stdout); // Flush output buffer
        sleep(1); // Wait for 1 second
    }

    return 0;
}