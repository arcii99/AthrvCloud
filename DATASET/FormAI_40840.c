//FormAI DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

void remove_newline(char *str) {
    char *newline_char = strchr(str, '\n');
    if (newline_char != NULL) *newline_char = '\0';
}

char *read_file_content(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char *content = (char *) malloc(100 * sizeof(char));
    size_t content_size = 100, total_read_size = 0;
    char buffer[10];
    while (fgets(buffer, 10, file) != NULL) {
        total_read_size += strlen(buffer);
        if (total_read_size >= content_size - 1) {
            content_size *= 2;
            content = realloc(content, content_size * sizeof(char));
        }
        strcat(content, buffer);
    }

    fclose(file);
    remove_newline(content);
    return content;
}

char *parse_avg_cpu_load() {
    char *content = read_file_content("/proc/loadavg");
    char *partials[3];

    int count = 0;
    char *tok = strtok(content, " ");
    while (tok != NULL) {
        if (count < 3) {
            partials[count] = tok;
            count++;
        } else break;

        tok = strtok(NULL, " ");
    }

    char *result = (char *) malloc(20 * sizeof(char));
    sprintf(result, "%.2f", atof(partials[0]));

    free(content);
    return result;
}

char *process_name_from_pid(const char* pid) {
    char filename[50];
    sprintf(filename, "/proc/%s/status", pid);
    char *content = read_file_content(filename);

    char *name = NULL;
    char *tok = strtok(content, "\n");
    while (tok != NULL && name == NULL) {
        if (strncmp(tok, "Name:", 5) == 0) {
            name = (char *) malloc(strlen(tok) - 5 + 1);
            strcpy(name, tok + 5);
            remove_newline(name);
        }

        tok = strtok(NULL, "\n");
    }

    free(content);
    return name;
}

void print_header() {
    printf("+--------+----------------------+---------------+-----------------------+\n");
    printf("|  PID   |      Process Name     |  Virtual Mem  |  Average CPU Load (1m) |\n");
    printf("+--------+----------------------+---------------+-----------------------+\n");
}

void print_row(const char *pid, const char *process_name, const char *virtual_mem, const char *cpu_load) {
    char row[100];
    sprintf(row, "|%7s|%22s|%15s|%23s|\n", pid, process_name, virtual_mem, cpu_load);
    printf("%s", row);
}

void process_viewer() {
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        fprintf(stderr, "Failed to open /proc directory\n");
        exit(EXIT_FAILURE);
    }

    print_header();

    struct dirent *entry;
    while ((entry = readdir(proc_dir))) {
        if (isdigit(*entry->d_name)) {
            char *pid = entry->d_name;
            char *process_name = process_name_from_pid(pid);
            if (process_name != NULL) {
                char filename[50];
                sprintf(filename, "/proc/%s/status", pid);
                char *content = read_file_content(filename);

                char *virtual_mem = NULL;
                char *tok = strtok(content, "\n");
                while (tok != NULL && virtual_mem == NULL) {
                    if (strncmp(tok, "VmSize:", 7) == 0) {
                        virtual_mem = (char *) malloc(strlen(tok) - 7 + 1);
                        strcpy(virtual_mem, tok + 7);
                        remove_newline(virtual_mem);
                    }

                    tok = strtok(NULL, "\n");
                }

                char *cpu_load = parse_avg_cpu_load();

                print_row(pid, process_name, virtual_mem, cpu_load);

                free(process_name);
                free(virtual_mem);
                free(cpu_load);
                free(content);
            }
        }
    }

    closedir(proc_dir);
    printf("+--------+----------------------+---------------+-----------------------+\n");
}

int main() {
    process_viewer();
    return 0;
}