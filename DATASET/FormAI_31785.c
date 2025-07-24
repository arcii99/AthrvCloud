//FormAI DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(void) {
    DIR *directory;
    struct dirent *file;
    char folder_name[20];
    char pid[10];
    char file_name[50];
    FILE *fp;
    char line[100];
    int line_count = 0;
    char *exe_path = NULL;
    char *status = NULL;

    printf("Enter the name of the folder containing process folder\n");
    scanf("%s", folder_name);

    directory = opendir(folder_name);

    if(directory) {
        printf("PID\t\tCommand\t\t\tExe Path\n");
        while((file = readdir(directory)) != NULL) {
            if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0 || strcmp(file->d_name, ".DS_Store") == 0) {
                continue;
            }

            strncpy(pid, file->d_name, sizeof(pid) - 1);

            snprintf(file_name, sizeof(file_name) - 1, "%s/%s/%s", folder_name, pid, "status");

            fp = fopen(file_name, "r");
            if(fp) {
                while(fgets(line, sizeof(line), fp)) {
                    line_count++;
                    if(line_count == 1) {
                        printf("%s\t\t", pid);
                        printf("%s\t\t", line + 6);
                    }

                    if(line_count == 6) {
                        status = line + 7;
                        if(strcmp(status, "running\n") == 0) {
                            exe_path = malloc(100);
                            snprintf(file_name, sizeof(file_name) - 1, "%s/%s/%s", folder_name, pid, "exe");
                            readlink(file_name, exe_path, 100);
                            printf("%s\n", exe_path);
                            free(exe_path);
                        } else {
                            printf("N/A\n");
                        }
                        break;
                    }
                }
                fclose(fp);
            }

            line_count = 0;
        }
        closedir(directory);
    }

    return 0;
}