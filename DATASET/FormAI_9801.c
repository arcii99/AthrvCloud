//FormAI DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID 32768  // Maximum limit of available PIDs in a Linux system
#define MAX_BUF_SIZE 256 

// Shape-shifting variable
int shapeShift = 0;

// Function to check if a given string is a number
int isNumber(char *str) {
    int i = 0;
    while (str[i]) {
        if (!isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

// Function to convert size in KB to MB or GB depending on its size
void convertSize(char *size) {
    double val = atof(size);
    if (val >= 1024 && val < 1048576) {
        sprintf(size, "%.1fMB", val/1024);
    }
    else if (val >= 1048576) {
        sprintf(size, "%.1fGB", val/1048576);
    }
    else {
        sprintf(size, "%.1fKB", val);
    }
}

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *dirEntry;
    char path[MAX_BUF_SIZE], cmd[MAX_BUF_SIZE], state[MAX_BUF_SIZE], utime[MAX_BUF_SIZE], stime[MAX_BUF_SIZE], virt[MAX_BUF_SIZE], res[MAX_BUF_SIZE], size[MAX_BUF_SIZE];
    int pid;
    double cpu;
    
    // Infinite loop to continuously display process information
    while(1) {
        
        // Determine the shape shift of the program 
        switch(shapeShift) {
            case 0: 
                printf("------------------NORMAL MODE--------------------\n");
                break;
            case 1: 
                printf("-------------------HYDRA MODE--------------------\n");
                break;
            case 2:
                printf("-------------------DRAGON MODE-------------------\n");
                break;
            default:
                printf("------------------NORMAL MODE--------------------\n");
                shapeShift = 0;
                break;
        }
        
        printf("PID\tCOMMAND\t\t\tSTATE\tCPU\tMEMORY\n");
        printf("---\t-------\t\t\t-----\t---\t------\n");
        
        // Iterate over all valid process IDs and print their information
        for (pid = 1; pid <= MAX_PID; pid++) {
            sprintf(path, "/proc/%d/stat", pid);
            
            // Check if process directory path exists
            if (access(path, F_OK) != -1) {
                
                // Open the process stat file and read process information
                FILE *fp = fopen(path, "r");
                fscanf(fp, "%d %s %s %d %d %d %d %d %lu %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %llu",
                    &pid, cmd, state, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &cpu, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
                fclose(fp); 
                
                // Get process memory usage information
                sprintf(path, "/proc/%d/statm", pid);
                fp = fopen(path, "r");
                fscanf(fp, "%lu %lu %lu %lu %lu %lu %lu", NULL, NULL, NULL, NULL, NULL, NULL, NULL); 
                fscanf(fp, "%lu", &res);
                fclose(fp);
                
                // Convert size of memory usage to appropriate unit
                convertSize(size);
                
                // Display process information
                printf("%d\t", pid);
                if (strlen(cmd) > 20) {
                    printf("%s\t", cmd);
                }
                else {
                    printf("%s\t\t", cmd);
                }
                
                printf("%s\t%.1f\t%s\n", state, cpu, size);
            }
        }
        
        // Process mode changing user input
        printf("\n\nEnter 'H' for HYDRA mode and 'D' for DRAGON mode, 'Q' to quit and return to normal mode: ");
        char input[MAX_BUF_SIZE];
        fgets(input, MAX_BUF_SIZE, stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "H") == 0) {
            shapeShift = 1;
        }
        else if (strcmp(input, "D") == 0) {
            shapeShift = 2;
        }
        else if (strcmp(input, "Q") == 0) {
            shapeShift = 0;
            break;
        }
        else {
            printf("Invalid input. Please try again.\n");
            shapeShift = 0;
        }
    }
    return 0;
}