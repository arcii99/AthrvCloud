//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024

// Structure to hold the parsed resume data
typedef struct Resume {
    char name[MAX_BUFFER_SIZE];
    char email[MAX_BUFFER_SIZE];
    char phone[MAX_BUFFER_SIZE];
    char experience[MAX_BUFFER_SIZE];
    char education[MAX_BUFFER_SIZE];
} Resume;

Resume *parse_resume(char *filename);
void parse_line(char *line, Resume *resume);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s resume.txt\n", argv[0]);
        return -1;
    }

    char *filename = argv[1];
    Resume *resume = parse_resume(filename);

    if (resume != NULL) {
        printf("Resume Details:\n");
        printf("Name: %s\n", resume->name);
        printf("Email: %s\n", resume->email);
        printf("Phone: %s\n", resume->phone);
        printf("Experience: %s\n", resume->experience);
        printf("Education: %s\n", resume->education);
    } else {
        printf("Failed to parse resume file %s\n", filename);
    }

    return 0;
}

// Asynchronously parse the resume file
Resume *parse_resume(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return NULL;
    }

    Resume *resume = calloc(1, sizeof(Resume));
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read = 0;

    while ((bytes_read = read(fd, buffer, MAX_BUFFER_SIZE)) > 0) {
        char *line_start = buffer;
        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                parse_line(line_start, resume);
                line_start = buffer + i + 1;
            }
        }

        if (line_start != buffer + bytes_read) {
            int remaining_size = buffer + bytes_read - line_start;
            memmove(buffer, line_start, remaining_size);
            bytes_read = remaining_size;
        }
    }

    close(fd);
    return resume;
}

// Parse a single line of the resume file
void parse_line(char *line, Resume *resume) {
    char *colon_pos = strchr(line, ':');
    if (colon_pos != NULL) {
        *colon_pos = '\0';

        char *value = colon_pos + 1;
        switch (line[0]) {
            case 'n':
                strncpy(resume->name, value, MAX_BUFFER_SIZE);
                break;
            case 'e':
                strncpy(resume->email, value, MAX_BUFFER_SIZE);
                break;
            case 'p':
                strncpy(resume->phone, value, MAX_BUFFER_SIZE);
                break;
            case 'x':
                strncpy(resume->experience, value, MAX_BUFFER_SIZE);
                break;
            case 'd':
                strncpy(resume->education, value, MAX_BUFFER_SIZE);
                break;
            default:
                break;
        }
    }
}