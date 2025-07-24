//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Cyberpunk
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Initializing CyberPunk CPU Usage Monitor...\n");
    
    while (1) {
        FILE* fp = popen("top -b -n1 | grep \"Cpu(s)\" | awk '{print $2 + $4}'", "r");
        float cpu_usage;
        fscanf(fp, "%f", &cpu_usage);
        pclose(fp);
        printf("Current CPU Usage: %.2f%%\n", cpu_usage);
        sleep(1); //wait for one second before checking again
    }
    return 0;
}