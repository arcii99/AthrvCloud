//FormAI DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    printf("======================================\n");
    printf("|  Welcome to the C System Viewer!   |\n");
    printf("======================================\n");

    printf("\n\n");
    printf("--------------------------------------\n");
    printf("|  Currently running processes:      |\n");
    printf("--------------------------------------\n");

    FILE* fp;
    char path[300];
    char cmd[150];

    sprintf(cmd, "ps -eo pid,ppid,comm | awk '{ printf \"%-10s %-10s %-10s\\n\", $1, $2, $3 }'");

    fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Error: failed to open pipe.\n");
        return 1;
    }

    while (fgets(path, 300, fp) != NULL)
        printf("%s", path);

    pclose(fp);
    return 0;
}