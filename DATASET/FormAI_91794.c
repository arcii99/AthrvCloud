//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128

void print_top_section() {
    printf("%-8s%-10s%-8s%-10s%-12s%-8s%s\n", "USER", "PID", "%CPU", "%MEM", "TIME+", "COMMAND", "");
    fflush(stdout);
}

void print_process_section(char* user, int pid, float cpu, float mem, char* time, char* command) {
    printf("%-8s%-10d%-8.2f%-10.2f%-12s%-8s%s\n", user, pid, cpu, mem, time, command, "");
    fflush(stdout);
}

int main() {
    int interval = 1;
    char* current_user = getenv("USER");
    char* command = "top -b -n 1 | grep %s";
    char buffer[BUFFER_SIZE];
    int pid = -1;
    float cpu = -1.0f;
    float mem = -1.0f;
    char time[10];

    memset(buffer, 0, BUFFER_SIZE);

    while (1) {
        system("clear");
        print_top_section();

        FILE* fp = NULL;

        sprintf(buffer, command, current_user);
        fp = popen(buffer, "r");

        if (fp != NULL) {
            while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
                pid = -1;
                cpu = -1.0f;
                mem = -1.0f;
                memset(time, 0, 10);

                sscanf(buffer, "%*s%d%*s%*s%*s%f%*s%f%s", &pid, &cpu, &mem, time);

                if (pid != -1) {
                    print_process_section(current_user, pid, cpu, mem, time, command);
                }
            }

            pclose(fp);
            fp = NULL;
        }

        sleep(interval);
    }

    return 0;
}