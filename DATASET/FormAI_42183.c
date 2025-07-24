//FormAI DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 10

struct LogData {
    char date[MAX_FIELD_LENGTH];
    char time[MAX_FIELD_LENGTH];
    char source[MAX_FIELD_LENGTH];
    char message[MAX_FIELD_LENGTH];
};

struct LogEntry {
    char line[MAX_LINE_LENGTH];
    struct LogData data;
};

struct LogFile {
    struct LogEntry *entries;
    int count;
};

void print_usage() {
    printf("Usage: log_analysis [logfile]\n");
    printf("Example: log_analysis /var/log/myapp.log\n");
}

int parse_line(char *line, struct LogData *data) {
    // split line into fields using whitespace as delimiter
    char *field;
    char *fields[MAX_FIELDS];
    int field_count = 0;
    field = strtok(line, " ");
    while (field != NULL && field_count < MAX_FIELDS) {
        fields[field_count++] = field;
        field = strtok(NULL, " ");
    }
    // extract fields into struct
    if (field_count >= 4) {
        strncpy(data->date, fields[0], MAX_FIELD_LENGTH);
        strncpy(data->time, fields[1], MAX_FIELD_LENGTH);
        strncpy(data->source, fields[2], MAX_FIELD_LENGTH);
        int message_len = strlen(fields[3]);
        if (message_len > 0) {
            // trim trailing newline character
            if (fields[3][message_len-1] == '\n') {
                fields[3][message_len-1] = '\0';
                message_len--;
            }
            strncpy(data->message, fields[3], MAX_FIELD_LENGTH);
        } else {
            data->message[0] = '\0';
        }
        return 1;
    } else {
        return 0;
    }
}

struct LogFile load_log_file(char *filename) {
    struct LogFile log_file;
    log_file.count = 0;

    // open file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // read lines
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // parse line and add to array
        int parsed = parse_line(line, &log_file.entries[log_file.count].data);
        if (parsed) {
            strcpy(log_file.entries[log_file.count].line, line);
            log_file.count++;
        }
    }

    // close file and return array
    fclose(file);
    return log_file;
}

int count_messages_by_source(struct LogFile log_file, char *source) {
    int count = 0;
    for (int i = 0; i < log_file.count; i++) {
        if (strcmp(log_file.entries[i].data.source, source) == 0) {
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    // load log file and count messages by source
    struct LogFile log_file = load_log_file(argv[1]);
    int count = count_messages_by_source(log_file, "myapp");

    // print result
    printf("Messages from myapp: %d\n", count);

    return 0;
}