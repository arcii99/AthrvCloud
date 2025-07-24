//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: paranoid
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STR_LEN 1000

int check_attack(char *line, int line_num);
void print_alert(int line_num, char *line);

int main() {
    char line[MAX_STR_LEN];
    int line_num = 0;

    while(fgets(line, MAX_STR_LEN, stdin)) {
        line_num++;

        if(check_attack(line, line_num)) {
            print_alert(line_num, line);
        }
    }

    return 0;
}

int check_attack(char *line, int line_num) {
    int len = strlen(line);

    // Checking for buffer overflow attack
    if(strstr(line, "strcpy")) {
        if(strstr(line, "gets")) {
            printf("Buffer overflow attack detected on line %d\n", line_num);
            return 1;
        }
    }

    // Checking for SQL injection attack
    if(strstr(line, "SELECT")) {
        if(strstr(line, "FROM")) {
            printf("SQL injection attack detected on line %d\n", line_num);
            return 1;
        }
    }

    // Checking for cross-site scripting attack
    if(strstr(line, "<script>") || strstr(line, "alert(")) {
        printf("Cross-site scripting attack detected on line %d\n", line_num);
        return 1;
    }

    return 0;
}

void print_alert(int line_num, char *line) {
    printf("ALERT! Attack detected on line %d: %s\n", line_num, line);
    printf("Stopping further execution of program...\n");
    exit(0);
}