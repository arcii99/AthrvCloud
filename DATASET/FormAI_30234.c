//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_PATTERN_SIZE 64
#define MAX_PATTERNS 10

int is_attack(char *input) {
    char patterns[MAX_PATTERNS][MAX_PATTERN_SIZE] = {"rm -rf ", "ls -l ", "echo ", "cat ", "python ", "perl ", "curl ", "wget ", "sudo ", "ssh "};
    
    int num_patterns = sizeof(patterns) / sizeof(patterns[0]);
    
    for (int i = 0; i < num_patterns; i++) {
        if (strstr(input, patterns[i])) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    char input[MAX_INPUT_SIZE];
    
    while (fgets(input, MAX_INPUT_SIZE, stdin)) {
        if (is_attack(input)) {
            printf("Intrusion detected!\n");
            break;
        }
    }
    
    printf("Program exiting.\n");
    
    return 0;
}