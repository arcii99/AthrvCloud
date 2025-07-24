//FormAI DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_ENTRIES 10000

typedef struct Entry {
    char date[20];
    char time[20];
    char request[1000];
    int status;
} Entry;

void parse_entry(char* line, Entry* entry) {
    const char delimiter[3] = " ";
    char* token;
    int count = 0;
    token = strtok(line, delimiter);
    while(token != NULL) {
        switch(count) {
            case 3:
                strcpy(entry->date, token);
                break;
            case 4:
                strcpy(entry->time, token);
                break;
            case 5:
                strcat(entry->request, token);
                token = strtok(NULL, delimiter);
                while(token != NULL && strcmp(token, "\"") != 0) {
                    strcat(entry->request, " ");
                    strcat(entry->request, token);
                    token = strtok(NULL, delimiter);
                }
                break;
            case 6:
                entry->status = atoi(token);
                break;
        }
        count++;
        token = strtok(NULL, delimiter);
    }
}

void print_entry(Entry entry) {
    printf("%s %s %s %d\n", entry.date, entry.time, entry.request, entry.status);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: ./log_analyzer <log_file_path>\n");
        return -1;
    }
    FILE* log_file = fopen(argv[1], "r");
    if(log_file == NULL) {
        printf("Failed to open log file\n");
        return -1;
    }
    char line[MAX_LINE_LEN];
    int entry_count = 0;
    Entry entries[MAX_ENTRIES];
    while(fgets(line, MAX_LINE_LEN, log_file) != NULL) {
        Entry entry;
        parse_entry(line, &entry);
        entries[entry_count++] = entry;
    }
    int success_count = 0, redirect_count = 0, client_error_count = 0, server_error_count = 0;
    for(int i = 0; i < entry_count; i++) {
        Entry entry = entries[i];
        if(entry.status >= 200 && entry.status < 300) {
            success_count++;
        } else if(entry.status >= 300 && entry.status < 400) {
            redirect_count++;
        } else if(entry.status >= 400 && entry.status < 500) {
            client_error_count++;
        } else if(entry.status >= 500 && entry.status < 600) {
            server_error_count++;
        }
        print_entry(entry);
    }
    printf("Total entries: %d\nSuccess: %d\nRedirect: %d\nClient error: %d\nServer error: %d\n", entry_count, success_count, redirect_count, client_error_count, server_error_count);
    fclose(log_file);
    return 0;
}