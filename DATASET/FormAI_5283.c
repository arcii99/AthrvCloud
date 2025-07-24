//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024
#define MAXIP 16

int check_ip(char *ip) {
    int nums[4];
    char buf[MAXLINE];
    strcpy(buf, ip);
    char *p = strtok(buf, ".");
    int i = 0;
    while (p) {
        if (i > 3) {
            return 0;
        }
        int num = atoi(p);
        if (num < 0 || num > 255) {
            return 0;
        }
        nums[i] = num;
        i++;
        p = strtok(NULL, ".");
    }
    if (i != 4) {
        return 0;
    }
    return 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    char *logfile = argv[1];
    FILE *fp = fopen(logfile, "r");
    if (!fp) {
        printf("Could not open file %s\n", logfile);
        return 1;
    }

    char line[MAXLINE];
    while (fgets(line, MAXLINE, fp) != NULL) {
        char ip[MAXIP];
        char *p = strstr(line, "src=");
        if (p) {
            sscanf(p+4, "%15s", ip);
            if (check_ip(ip)) {
                printf("Possible intrusion detected from IP address: %s\n", ip);
            }
        }
    }
    fclose(fp);
    return 0;
}