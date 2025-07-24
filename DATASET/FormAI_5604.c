//FormAI DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int opt;
    char *user = NULL;
    int flag_a = 0, flag_u = 0;

    while ((opt = getopt(argc, argv, "au:")) != -1) {
        switch (opt) {
            case 'a':
                flag_a = 1;
                break;
            case 'u':
                user = optarg;
                flag_u = 1;
                break;
            default: /* '?' */
                fprintf(stderr, "Usage: %s [-a] [-u user]\n",
                        argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (flag_a == 1 && flag_u == 1) {
        fprintf(stderr, "Error: Options -a and -u cannot be used together\n");
        exit(EXIT_FAILURE);
    }

    if (flag_a == 0 && flag_u == 0) {
        fprintf(stderr, "Error: Either option -a or -u must be used\n");
        exit(EXIT_FAILURE);
    }

    if (flag_a == 1) {
        printf("Current system uptime:\n");
        system("uptime");
    }

    if (flag_u == 1) {
        char command[1024];
        snprintf(command, sizeof(command), "ps aux | grep ^%s | wc -l", user);
        FILE *fp;
        char buf[1024];
        if ((fp = popen(command, "r")) == NULL) {
            perror("popen error");
            exit(EXIT_FAILURE);
        }

        while (fgets(buf, 1024, fp) != NULL) {
            printf("%s processes running for user %s\n", buf, user);
        }
        pclose(fp);
    }

    return 0;
}