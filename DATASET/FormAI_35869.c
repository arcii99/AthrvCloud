//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_FILENAME_LEN 1024

void get_filename(char *filename) {
    FILE *fp = NULL;
    char line[256];

    #ifdef WIN32
    fp = popen("wmic cpu get loadpercentage", "r");
    #else
    fp = popen("top -b -n 1 | awk '/^%Cpu/ { print $2 }'", "r");
    #endif

    while (fgets(line, sizeof(line), fp)) {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        if (isdigit(line[0])) {
            int usage = atoi(line);
            printf("CPU usage: %d%%\n", usage);
        }
    }
    pclose(fp);
}

int main() {
    char filename[MAX_FILENAME_LEN] = {'\0'};

    while(1) {
        get_filename(filename);
        #ifdef WIN32
        Sleep(2000);
        #else
        sleep(2);
        #endif
    }

    return 0;
}