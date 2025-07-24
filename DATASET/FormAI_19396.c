//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char root[4] = "C:\\";
    int gb = 1024 * 1024 * 1024;
    double total_space, free_space, used_space, percent_used;
    char command[30] = "dir ";
    char result[200];
    
    strcat(command, root);
    printf("Analyzing C Disk Space...\n\n");
    printf("Executing command: %s\n", command);
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        printf("Error: command execution failed!\n");
    }
    while (fgets(result, sizeof(result), pipe) != NULL) {
        if (strstr(result, "Total Files Listed") != NULL) {
            char* token = strtok(result, " ");
            while (token != NULL) {
                if (isdigit(token[0])) {
                    total_space = atoi(token) * gb;
                    break;
                } 
                else {
                    token = strtok(NULL, "");
                }
            }
        } 
        else if (strstr(result, "Free") != NULL) {
            char* token = strtok(result, " ");
            while (token != NULL) {
                if (isdigit(token[0])) {
                    free_space = atoi(token) * gb;
                    break;
                } 
                else {
                    token = strtok(NULL, "");
                }
            }
        }
    }
    used_space = total_space - free_space;
    percent_used = (used_space / total_space) * 100;
    printf("\nC Drive Space Analyzed:\n");
    printf("Total Space: %.2lf GB\n", (double)total_space/gb);
    printf("Free Space: %.2lf GB\n", (double)free_space/gb);
    printf("Used Space: %.2lf GB\n", (double)used_space/gb);
    printf("Percent Used: %.2lf%%\n", percent_used);
    pclose(pipe);
    return 0;
}