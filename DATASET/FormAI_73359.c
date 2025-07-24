//FormAI DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_IP_LEN 16
#define MAX_DATE_TIME_LEN 64

struct log_entry {
    char ip[MAX_IP_LEN];
    char date_time[MAX_DATE_TIME_LEN];
    char request_type[MAX_LINE_LEN];
    int status_code;
    long int response_size;
};

void display_usage() {
    printf("Usage: log <filename>\n");
}

int parse_log_entry(char *line, struct log_entry *entry) {
    char *token;
    char *rest = line;
    int token_num = 0;

    while ((token = strtok_r(rest, " ", &rest))) {
        switch (token_num) {
            case 0:
                strncpy(entry->ip, token, MAX_IP_LEN - 1);
                break;
            case 3:
                strncpy(entry->date_time, token + 1, MAX_DATE_TIME_LEN - 1);
                break;
            case 5:
                strncpy(entry->request_type, token + 1, MAX_LINE_LEN - 1);
                break;
            case 8:
                entry->status_code = atoi(token);
                break;
            case 9:
                entry->response_size = atol(token);
                break;
        }

        token_num++;
    }

    return 0;
}

int read_log_file(char *filename, struct log_entry **entries, int *num_entries) {
    FILE *fp;
    char buf[MAX_LINE_LEN];
    int i;

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Failed to open file %s\n", filename);
        return -1;
    }

    while (fgets(buf, MAX_LINE_LEN, fp)) {
        (*num_entries)++;
    }

    if (*num_entries == 0) {
        printf("Error: File %s is empty\n", filename);
        fclose(fp);
        return -1;
    }

    rewind(fp);

    *entries = malloc(*num_entries * sizeof(struct log_entry));
    if (!*entries) {
        printf("Error: Failed to allocate memory for log entries\n");
        fclose(fp);
        return -1;
    }

    for (i = 0; i < *num_entries; i++) {
        if (!fgets(buf, MAX_LINE_LEN, fp)) {
            printf("Error: Failed to read log entry %d\n", i);
            fclose(fp);
            free(*entries);
            return -1;
        }

        parse_log_entry(buf, &(*entries)[i]);
    }

    fclose(fp);

    return 0;
}

void display_top_ips(struct log_entry *entries, int num_entries, int limit) {
    int i, j;
    char *ips[num_entries];
    int counts[num_entries];

    for (i = 0; i < num_entries; i++) {
        ips[i] = entries[i].ip;
        counts[i] = 1;
    }

    for (i = 0; i < num_entries; i++) {
        for (j = i + 1; j < num_entries; j++) {
            if (strcmp(ips[i], ips[j]) == 0) {
                counts[i]++;
            }
        }
    }

    printf("\nTop %d IPs\n-------------\n", limit);

    for (i = 0; i < limit; i++) {
        int max_index = i;
        for (j = i + 1; j < num_entries; j++) {
            if (counts[j] > counts[max_index]) {
                max_index = j;
            }
        }
        printf("%s - %d\n", ips[max_index], counts[max_index]);
        counts[max_index] = counts[i];
        ips[max_index] = ips[i];
    }
}

void display_top_request_types(struct log_entry *entries, int num_entries, int limit) {
    int i, j;
    char *types[num_entries];
    int counts[num_entries];

    for (i = 0; i < num_entries; i++) {
        types[i] = entries[i].request_type;
        counts[i] = 1;
    }

    for (i = 0; i < num_entries; i++) {
        for (j = i + 1; j < num_entries; j++) {
            if (strcmp(types[i], types[j]) == 0) {
                counts[i]++;
            }
        }
    }

    printf("\nTop %d Request Types\n-------------\n", limit);

    for (i = 0; i < limit; i++) {
        int max_index = i;
        for (j = i + 1; j < num_entries; j++) {
            if (counts[j] > counts[max_index]) {
                max_index = j;
            }
        }
        printf("%s - %d\n", types[max_index], counts[max_index]);
        counts[max_index] = counts[i];
        types[max_index] = types[i];
    }
}

int main(int argc, char **argv) {
    struct log_entry *entries;
    int num_entries = 0;
    int limit = 10;

    if (argc < 2) {
        display_usage();
        return 1;
    }

    if (read_log_file(argv[1], &entries, &num_entries) != 0) {
        return 1;
    }

    display_top_ips(entries, num_entries, limit);
    display_top_request_types(entries, num_entries, limit);

    free(entries);

    return 0;
}