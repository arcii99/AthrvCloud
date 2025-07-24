//FormAI DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


int main(void) {
    DIR *d;
    struct dirent *dir;
    char path[100], buffer[100];
    int pid;
    
    printf("Enter the PID of the process: ");
    scanf("%d", &pid);

    sprintf(path, "/proc/%d/status", pid);
    FILE *f = fopen(path, "r");

    if(f == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, 100, f)) {
        if(strncmp(buffer, "Name:", 5) == 0 || strncmp(buffer, "Pid:", 4) == 0 || 
        strncmp(buffer, "State:", 6) == 0 || strncmp(buffer, "PPid:", 5) == 0 ||
        strncmp(buffer, "VmSize:", 7) == 0) {
            printf("%s", buffer);
        }
    }

    fclose(f);
    return 0;
}