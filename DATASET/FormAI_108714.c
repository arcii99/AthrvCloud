//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE* fp;
    char path[1035];

    // loop to constantly monitor the RAM usage
    while (1) {
        fp = popen("free -m", "r");

        if (fp == NULL) {
            printf("Failed to run command\n");
            exit(1);
        }

        while (fgets(path, sizeof(path), fp) != NULL) {
            printf("%s", path);
        }

        pclose(fp);

        // wait for 1 second before checking RAM usage again
        sleep(1);
    }

    return 0;
}