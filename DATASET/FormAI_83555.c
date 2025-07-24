//FormAI DATASET v1.0 Category: System process viewer ; Style: surprised
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    printf("Oh my goodness, I can't believe I can actually view running processes on this system!\n");
    
    // Open the /proc directory
    DIR *dir = opendir("/proc");
    
    // Read the entries in the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        
        // Check if the entry is a directory
        if (entry->d_type == DT_DIR) {
            
            // Check if the name is a number (pid)
            char *endptr;
            long pid = strtol(entry->d_name, &endptr, 10);
            
            if (*endptr == '\0') {
                
                // Read the stat file for the process
                char stat_path[100];
                snprintf(stat_path, sizeof(stat_path), "/proc/%ld/stat", pid);
                FILE* stat_file = fopen(stat_path, "r");
                
                if (stat_file) {
                    
                    // Get the process name from the 2nd field of the stat file
                    char name[100];
                    fscanf(stat_file, "%*d %s", name);
                    
                    // Print the process ID and the process name
                    printf("Process ID: %ld, Process Name: %s\n", pid, name);
                    fclose(stat_file);
                }
            }
        }
    }
    
    // Close the directory
    closedir(dir);
    return 0;
}