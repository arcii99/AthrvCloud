//FormAI DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <grp.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_NUM 64

typedef void BuiltInFunc(char *args[]);

typedef struct {
    char *name;
    BuiltInFunc *func;
} BuiltInCmd;

void handle_shell_cmd(char *cmd);
void execute_command(char *args[]);
void execute_external_cmd(char *args[]);
void execute_cd(char *args[]);
void execute_chmod(char *args[]);
void execute_chown(char *args[]);
void execute_chgrp(char *args[]);
void execute_exit(char *args[]);
void print_error(char *msg);

int main() {
    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("> ");
        fflush(stdout);

        if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
            if (errno == EINTR) {
                continue;
            } else {
                break;
            }
        }

        cmd[strcspn(cmd, "\n")] = '\0';

        handle_shell_cmd(cmd);
    }

    return 0;
}

void handle_shell_cmd(char *cmd) {
    char *args[MAX_ARG_NUM];
    int i, len = strlen(cmd), argc = 0;

    if (len == 0) {
        return;
    }

    for (i = 0; i < len; ) {
        while (isspace(cmd[i])) {
            i++;
        }

        if (cmd[i] == '\0') {
            break;
        }

        args[argc++] = cmd + i;

        while (cmd[i] != '\0' && !isspace(cmd[i])) {
            i++;
        }

        if (cmd[i] == '\0') {
            break;
        } else {
            cmd[i++] = '\0';
        }
    }

    args[argc] = NULL;

    if (argc == 0) {
        return;
    }

    execute_command(args);
}

void execute_command(char *args[]) {
    static BuiltInCmd built_in_cmds[] = {
        { "cd", execute_cd },
        { "chmod", execute_chmod },
        { "chown", execute_chown },
        { "chgrp", execute_chgrp },
        { "exit", execute_exit },
        { NULL, NULL }
    };

    int i;

    for (i = 0; built_in_cmds[i].name != NULL; i++) {
        if (strcmp(args[0], built_in_cmds[i].name) == 0) {
            built_in_cmds[i].func(args);
            return;
        }
    }

    execute_external_cmd(args);
}

void execute_cd(char *args[]) {
    if (args[1] == NULL) {
        return;
    }

    if (chdir(args[1]) == -1) {
        print_error("cd");
    }
}

void execute_chmod(char *args[]) {
    if (args[1] == NULL || args[2] == NULL) {
        return;
    }

    int mode = strtol(args[1], NULL, 8);

    if (chmod(args[2], mode) == -1) {
        print_error("chmod");
    }
}

void execute_chown(char *args[]) {
    if (args[1] == NULL || args[2] == NULL) {
        return;
    }

    struct passwd *owner = getpwnam(args[1]);

    if (owner == NULL) {
        print_error("chown");
        return;
    }

    if (chown(args[2], owner->pw_uid, -1) == -1) {
        print_error("chown");
    }
}

void execute_chgrp(char *args[]) {
    if (args[1] == NULL || args[2] == NULL) {
        return;
    }

    struct group *grp = getgrnam(args[1]);

    if (grp == NULL) {
        print_error("chgrp");
        return;
    }

    if (chown(args[2], -1, grp->gr_gid) == -1) {
        print_error("chgrp");
    }
}

void execute_exit(char *args[]) {
    exit(0);
}

void execute_external_cmd(char *args[]) {
    pid_t pid;
    int status;

    switch (pid = fork()) {
    case -1:
        print_error("fork");
        break;

    case 0:
        execvp(args[0], args);
        print_error("execvp");
        exit(1);

    default:
        if (waitpid(pid, &status, 0) == -1) {
            print_error("waitpid");
        }

        break;
    }
}

void print_error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}