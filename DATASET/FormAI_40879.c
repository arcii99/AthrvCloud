//FormAI DATASET v1.0 Category: Log analysis ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct log_entry {
    char datetime[20];
    char client_ip[20];
    char request_type[10];
    char request_path[50];
    int response_code;
    char user_agent[50];
    int response_time;
};

// Returns the number of log entries in the given file
int count_log_entries(FILE *fp) {
    int count = 0;
    char line[200];

    // Count the number of lines in the file
    while (fgets(line, sizeof(line), fp)) {
        count++;
    }

    // Reset the file pointer to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    return count;
}

// Parses a single line of log file and fills the given log entry struct
void parse_log_entry(char *line, struct log_entry *entry) {
    char datetime[20];
    char client_ip[20];
    char request_type[10];
    char request_path[50];
    char response_code[4];
    char user_agent[50];
    char response_time[5];

    sscanf(line, "%[^ ] %[^ ] %[^ ] %[^ ] %s %[^\\n]s", datetime, client_ip, request_type, request_path, response_code, user_agent);
    sscanf(response_code, "%d", &entry->response_code);
    sscanf(response_time, "%d", &entry->response_time);

    strcpy(entry->datetime, datetime);
    strcpy(entry->client_ip, client_ip);
    strcpy(entry->request_type, request_type);
    strcpy(entry->request_path, request_path);
    strcpy(entry->user_agent, user_agent);
}

// Reads all log entries from the given file, and stores them in the given array of log entries
void read_log_entries(FILE *fp, struct log_entry *entries, int num_entries) {
    char line[200];
    int i = 0;

    while (fgets(line, sizeof(line), fp)) {
        parse_log_entry(line, &entries[i]);
        i++;
    }
}

// Finds the top n frequent client IPs from the given log entries
void top_client_ips(struct log_entry *entries, int num_entries, int n) {
    char **client_ips = (char **)malloc(num_entries * sizeof(char *));
    int *ip_counts = (int *)malloc(num_entries * sizeof(int));

    // Initialize the counts array
    int i;
    for (i = 0; i < num_entries; i++) {
        ip_counts[i] = 0;
    }

    // Count the number of times each IP appears
    int j, k;
    for (j = 0; j < num_entries; j++) {
        int found = 0;
        for (k = 0; k < j; k++) {
            if (strcmp(entries[j].client_ip, client_ips[k]) == 0) {
                ip_counts[k]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            client_ips[j] = strdup(entries[j].client_ip);
            ip_counts[j]++;
        }
    }

    // Find the top n frequent IPs
    for (i = 0; i < n; i++) {
        int max_count = 0;
        int max_index = 0;
        for (j = 0; j < num_entries; j++) {
            if (ip_counts[j] > max_count) {
                max_count = ip_counts[j];
                max_index = j;
            }
        }

        printf("%s: %d\n", client_ips[max_index], max_count);
        ip_counts[max_index] = 0;
    }

    // Free memory
    for (i = 0; i < num_entries; i++) {
        free(client_ips[i]);
    }
    free(client_ips);
    free(ip_counts);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Invalid filename\n");
        exit(1);
    }

    int num_entries = count_log_entries(fp);
    struct log_entry *entries = (struct log_entry *)malloc(num_entries * sizeof(struct log_entry));

    read_log_entries(fp, entries, num_entries);
    top_client_ips(entries, num_entries, 10);

    free(entries);
    fclose(fp);

    return 0;
}