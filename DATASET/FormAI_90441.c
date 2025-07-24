//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUF_SIZE 128
#define WLAN_PATH "/sys/class/net/"

int main(int argc, char *argv[]) {
    char path[MAX_BUF_SIZE];
    char buf[MAX_BUF_SIZE];
    char *ptr;
    int fd;
    int scan_index;

    printf("Scanning for available wireless networks...\n");

    for (scan_index = 0; scan_index < argc; scan_index++) {
        strcpy(path, WLAN_PATH);
        strcat(path, argv[scan_index]);
        strcat(path, "/wireless/scan_results");

        fd = open(path, O_RDONLY);
        if (fd == -1) {
            perror("Failed to open file");
            continue;
        }

        printf("Displaying available networks for %s:\n", argv[scan_index]);

        while (read(fd, buf, MAX_BUF_SIZE) > 0) {
            ptr = strtok(buf, " ");
            while (ptr != NULL) {
                if (isascii(*ptr))
                    printf("%s ", ptr);
                ptr = strtok(NULL, " ");
            }
            printf("\n");
        }

        close(fd);
    }

    return 0;
}