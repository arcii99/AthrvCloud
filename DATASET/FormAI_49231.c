//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    float LOAD_THRESHOLD = 70.0; // Maximum allowed CPU load (percent)
    float current_load;
    FILE *fp;
    char buffer[1024];

    while(1) { // Run indefinitely
        fp = popen("top -b -n1 | grep 'Cpu(s)' | awk '{print $2 + $4}'", "r"); // Execute system command
        fgets(buffer, sizeof(buffer), fp); // Read output of command
        pclose(fp); // Close command output stream

        current_load = atof(buffer); // Convert buffer to float

        if(current_load > LOAD_THRESHOLD) {
            printf("WARNING: CPU is overloaded! Current load: %f%%\n", current_load);
            // Here you can add any action to take when CPU usage exceeds the limit
        }

        sleep(1); // Wait for 1 second
    }

    return 0;
}