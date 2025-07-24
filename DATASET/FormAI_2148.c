//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_spaces(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
}

void print_usage_recursively(int depth) {
    char buffer[1024];
    FILE* pipe = popen("cat /proc/meminfo | grep 'MemAvailable' | awk '{print $2}'", "r");
    if (pipe == NULL) {
        printf("Error: Unable to execute command.\n");
        return;
    }
    fgets(buffer, sizeof(buffer), pipe);
    pclose(pipe);

    int mem_available = atoi(buffer);
    print_spaces(depth);
    printf("- Memory available: %d kB\n", mem_available);

    if (depth == 0) {
        printf("\n");
    }
    sleep(1);

    print_usage_recursively(depth + 1);
}

int main() {
    printf("Starting RAM monitor...\n\n");
    print_usage_recursively(0);
    return 0;
}