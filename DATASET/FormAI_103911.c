//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <signal.h>

#define MAX_BYTES 1024
#define MAX_WORDS 100
#define MAX_LEN 30
#define INTERVAL 1.0

char *input_file;
char *output_file;
int total_lines;
int total_words;
int total_chars;

struct word_count {
    char word[MAX_LEN];
    int count;
};

int cmpfunc(const void *a, const void *b) {
    return (*(struct word_count *)b).count - (*(struct word_count *)a).count;
}

void sig_handler(int signum) {
    printf("Total lines: %d\n", total_lines);
    printf("Total words: %d\n", total_words);
    printf("Total characters: %d\n", total_chars);
    exit(signum);
}

void count_words(char *data, int len, struct word_count count[]) {
    char word[MAX_LEN];
    int i, j, k;
    int index;
    for (i = 0, j = 0; i <= len; i++) {
        if (isalpha(data[i]) || isdigit(data[i])) {
            word[j++] = tolower(data[i]);
        } else {
            if (j > 0) {
                word[j] = '\0';
                index = -1;
                for (k = 0; k < total_words; k++) {
                    if (strcmp(count[k].word, word) == 0) {
                        index = k;
                        break;
                    }
                }
                if (index == -1) {
                    strcpy(count[total_words].word, word);
                    count[total_words].count = 1;
                    total_words++;
                } else {
                    count[index].count++;
                }
                j = 0;
            }
        }
    }
    qsort(count, total_words, sizeof(struct word_count), cmpfunc);
}

void write_result(struct word_count count[]) {
    int i;
    FILE *fp;
    fp = fopen(output_file, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s: %s\n", output_file, strerror(errno));
        exit(1);
    }
    for (i = 0; i < total_words; i++) {
        fprintf(fp, "%s: %d\n", count[i].word, count[i].count);
    }
    fclose(fp);
}

void read_file(int fd, struct word_count count[]) {
    char data[MAX_BYTES];
    int len, i;
    while ((len = read(fd, data, MAX_BYTES)) > 0) {
        for (i = 0; i < len; i++) {
            if (data[i] == '\n') {
                total_lines++;
            }
        }
        total_chars += len;
        count_words(data, len, count);
    }
    if (len < 0) {
        fprintf(stderr, "Error reading file: %s: %s\n", input_file, strerror(errno));
        exit(1);
    }
}

void monitor_file() {
    int fd;
    struct word_count count[MAX_WORDS];
    memset(count, 0, sizeof(count));
    fd = open(input_file, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error opening file: %s: %s\n", input_file, strerror(errno));
        exit(1);
    }
    read_file(fd, count);
    close(fd);
    write_result(count);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }
    input_file = argv[1];
    output_file = argv[2];
    signal(SIGINT, sig_handler);
    while (true) {
        monitor_file();
        sleep(INTERVAL);
    }
    return 0;
}