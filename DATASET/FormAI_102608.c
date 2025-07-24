//FormAI DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[256];
    printf("Enter process name: ");
    scanf("%s", path);
    strcat(path, "/task/");
    dir = opendir(path);
    if (dir != NULL) {
        printf("\nPID  NAME\n");
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                printf("%s  ", ent->d_name);
                char procPath[512];
                sprintf(procPath, "%s%s/status", path, ent->d_name);
                FILE *fp = fopen(procPath, "r");
                if (fp) {
                    char buf[256];
                    while (fgets(buf, sizeof(buf), fp)) {
                        if (strncmp(buf, "Name:", 5) == 0) {
                            printf("%s", buf+6);
                            break;
                        }
                    }
                    fclose(fp);
                }
            printf("\n");
            }
        }
        closedir(dir);
    } else {
        perror("Could not open /proc directory");
        return EXIT_FAILURE;
    }
    return 0;
}