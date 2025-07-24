//FormAI DATASET v1.0 Category: System process viewer ; Style: lively
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// Define the maximum possible length for a process id string
#define MAX_PID_LENGTH 10

// Define the directory where the process information is stored
#define PROC_DIRECTORY "/proc"

// Define the maximum possible length for a process name
#define MAX_NAME_LENGTH 50

// Define the command to retrieve the process information
#define PROCESS_INFO_COMMAND "ps -ef"

// Define the maximum possible length for a command line
#define MAX_COMMAND_LENGTH 1000

// Define the maximum possible length for a username
#define MAX_USERNAME_LENGTH 50

// Define the maximum possible length for a status string
#define MAX_STATUS_LENGTH 20

// Define the maximum possible length for a cpu time string
#define MAX_CPU_TIME_LENGTH 20

// Define the maximum possible length for a memory usage string
#define MAX_MEMORY_USAGE_LENGTH 20

// Define the maximum possible number of processes to display
#define MAX_PROCESSES_TO_DISPLAY 100

// Define a struct to hold information about a process
struct ProcessInfo
{
    char pid[MAX_PID_LENGTH];
    char name[MAX_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char status[MAX_STATUS_LENGTH];
    char cpu_time[MAX_CPU_TIME_LENGTH];
    char memory_usage[MAX_MEMORY_USAGE_LENGTH];
};

int main()
{
    // Get a list of all the processes running on the system
    DIR *proc_directory = opendir(PROC_DIRECTORY);
    struct dirent *entry;
    int process_count = 0;
    struct ProcessInfo processes[MAX_PROCESSES_TO_DISPLAY];
    while ((entry = readdir(proc_directory)) != NULL && process_count < MAX_PROCESSES_TO_DISPLAY)
    {
        // Check if the current directory entry is a directory and its name is a number
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0]))
        {
            // Open the process status file for the current process
            char process_status_filename[MAX_COMMAND_LENGTH];
            snprintf(process_status_filename, MAX_COMMAND_LENGTH, "%s/%s/status", PROC_DIRECTORY, entry->d_name);
            FILE *process_status_file = fopen(process_status_filename, "r");
            if (process_status_file != NULL)
            {
                // Read the process name and status from the status file
                char line[MAX_COMMAND_LENGTH];
                char name[MAX_NAME_LENGTH];
                char status[MAX_STATUS_LENGTH];
                while (fgets(line, MAX_COMMAND_LENGTH, process_status_file) != NULL)
                {
                    if (sscanf(line, "Name: %[^\n]", name) == 1)
                    {
                        // Copy the process name into the struct
                        strncpy(processes[process_count].name, name, MAX_NAME_LENGTH-1);
                        processes[process_count].name[MAX_NAME_LENGTH-1] = '\0';
                    }
                    else if (sscanf(line, "State: %[^\n]", status) == 1)
                    {
                        // Copy the process status into the struct
                        strncpy(processes[process_count].status, status, MAX_STATUS_LENGTH-1);
                        processes[process_count].status[MAX_STATUS_LENGTH-1] = '\0';
                    }
                }
                fclose(process_status_file);

                // Open the cmdline file for the current process
                char cmdline_filename[MAX_COMMAND_LENGTH];
                snprintf(cmdline_filename, MAX_COMMAND_LENGTH, "%s/%s/cmdline", PROC_DIRECTORY, entry->d_name);
                FILE *cmdline_file = fopen(cmdline_filename, "r");
                if (cmdline_file != NULL)
                {
                    // Read the command line for the process from the cmdline file
                    char command_line[MAX_COMMAND_LENGTH];
                    if (fgets(command_line, MAX_COMMAND_LENGTH, cmdline_file) != NULL)
                    {
                        // Copy the command line into the struct
                        strncpy(processes[process_count].command, command_line, MAX_COMMAND_LENGTH-1);
                        processes[process_count].command[MAX_COMMAND_LENGTH-1] = '\0';
                    }
                    fclose(cmdline_file);
                }

                // Open the stat file for the current process
                char stat_filename[MAX_COMMAND_LENGTH];
                snprintf(stat_filename, MAX_COMMAND_LENGTH, "%s/%s/stat", PROC_DIRECTORY, entry->d_name);
                FILE *stat_file = fopen(stat_filename, "r");
                if (stat_file != NULL)
                {
                    // Read the process id, username, cpu time, and memory usage from the stat file
                    char line[MAX_COMMAND_LENGTH];
                    char username[MAX_USERNAME_LENGTH];
                    char cpu_time[MAX_CPU_TIME_LENGTH];
                    char memory_usage[MAX_MEMORY_USAGE_LENGTH];
                    if (fgets(line, MAX_COMMAND_LENGTH, stat_file) != NULL)
                    {
                        sscanf(line, "%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %s %s", processes[process_count].pid, username, cpu_time, memory_usage);
                        // Copy the username, cpu time, and memory usage into the struct
                        strncpy(processes[process_count].username, username, MAX_USERNAME_LENGTH-1);
                        processes[process_count].username[MAX_USERNAME_LENGTH-1] = '\0';
                        strncpy(processes[process_count].cpu_time, cpu_time, MAX_CPU_TIME_LENGTH-1);
                        processes[process_count].cpu_time[MAX_CPU_TIME_LENGTH-1] = '\0';
                        strncpy(processes[process_count].memory_usage, memory_usage, MAX_MEMORY_USAGE_LENGTH-1);
                        processes[process_count].memory_usage[MAX_MEMORY_USAGE_LENGTH-1] = '\0';
                    }
                    fclose(stat_file);
                }

                // Increment the process count
                process_count++;
            }
        }
    }
    closedir(proc_directory);

    // Sort the processes by process id
    for (int i = 0; i < process_count-1; i++)
    {
        for (int j = i+1; j < process_count; j++)
        {
            if (atoi(processes[i].pid) > atoi(processes[j].pid))
            {
                struct ProcessInfo temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print the process information
    printf("%-10s %-20s %-20s %-12s %-12s %-20s %s\n", "PID", "NAME", "COMMAND", "USERNAME", "STATUS", "CPU TIME", "MEMORY USAGE");
    printf("%-10s %-20s %-20s %-12s %-12s %-20s %s\n", "---", "----", "-------", "--------", "------", "--------", "------------");
    for (int i = 0; i < process_count; i++)
    {
        printf("%-10s %-20s %-20s %-12s %-12s %-20s %s\n", processes[i].pid, processes[i].name, processes[i].command, processes[i].username, processes[i].status, processes[i].cpu_time, processes[i].memory_usage);
    }

    // Run the ps command to get the same information
    printf("\nRunning 'ps -ef' to get the same information:\n");
    printf("%s\n", PROCESS_INFO_COMMAND);
    system(PROCESS_INFO_COMMAND);

    return 0;
}