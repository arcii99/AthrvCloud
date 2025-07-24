//FormAI DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_CMDLINE 2048

// define the process information structure
typedef struct {
    int pid;
    char name[MAX_PATH];
    char state;
    int ppid;
    int pgrp;
    int session;
    int tty;
    int tpgid;
    unsigned int minflt;
    unsigned int cminflt;
} ProcessInfo;

// function declarations
static void printProcessInfo(ProcessInfo *info);
static void readProcFile(char *dir, int pid, char *filename, char *buffer, size_t size);
static int getProcessName(int pid, char *name);
static int getProcessState(int pid);
static int getParentPid(int pid);
static int getProcessGroup(int pid);
static int getSessionId(int pid);
static int getTerminal(int pid);
static int getTerminalProcessGroup(int pid);
static unsigned int getMinorFaults(int pid);
static unsigned int getCumulativeMinorFaults(int pid);

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *entry;
    ProcessInfo info;
    char statFile[MAX_PATH], cmdlineFile[MAX_PATH], buffer[MAX_CMDLINE];
    int pid;

    // check if running as root
    if (geteuid() != 0) {
        printf("Error: Permission denied!\n");
        exit(1);
    }

    // open the /proc directory
    if (!(dir = opendir("/proc"))) {
        printf("Error: Could not open /proc directory!\n");
        exit(1);
    }

    // print header for process information
    printf("%-8s %-20s %-5s %-8s %-8s %-8s %-8s %-16s\n", "PID", "COMMAND", "STATE", "PPID", "PGRP", "SESSION", "TTY", "MINOR FAULTS");

    // read each entry in the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // check if entry is a process directory
        if (isdigit(entry->d_name[0])) {
            // get the process id
            sscanf(entry->d_name, "%d", &pid);

            // get the process name
            if (getProcessName(pid, info.name) == -1) {
                continue; // skip to next entry
            }

            // get the process state
            info.state = getProcessState(pid);

            // get the parent pid
            info.ppid = getParentPid(pid);

            // get the process group
            info.pgrp = getProcessGroup(pid);

            // get the session id
            info.session = getSessionId(pid);

            // get the terminal
            info.tty = getTerminal(pid);

            // get the terminal process group
            info.tpgid = getTerminalProcessGroup(pid);

            // get the minor faults
            info.minflt = getMinorFaults(pid);

            // print the process information
            printProcessInfo(&info);

            // print the command line
            sprintf(cmdlineFile, "/proc/%d/cmdline", pid);
            readProcFile("/proc", pid, "cmdline", buffer, sizeof(buffer));
            printf("%-8s %-20s %s\n", "", "", buffer);
        }
    }

    // close the /proc directory
    closedir(dir);

    return 0;
}

/**
 * Prints the process information.
 */
static void printProcessInfo(ProcessInfo *info) {
    printf("%-8d %-20s %-5c %-8d %-8d %-8d %-8d %-10u\n",
        info->pid, info->name, info->state, info->ppid, info->pgrp,
        info->session, info->tty, info->minflt);
}

/**
 * Reads the contents of a file in the /proc directory.
 */
static void readProcFile(char *dir, int pid, char *filename, char *buffer, size_t size) {
    char path[MAX_PATH];
    int len;

    sprintf(path, "%s/%d/%s", dir, pid, filename);
    FILE *fp = fopen(path, "r");
    if (!fp) {
        snprintf(buffer, size, "Error: Could not read %s!", filename);
        return;
    }
    len = fread(buffer, 1, size, fp);
    fclose(fp);
    buffer[len] = '\0';
}

/**
 * Gets the process name.
 */
static int getProcessName(int pid, char *name) {
    char exeFile[MAX_PATH];

    sprintf(exeFile, "/proc/%d/exe", pid);
    if (readlink(exeFile, name, MAX_PATH) == -1) {
        return -1;
    }
    return 0;
}

/**
 * Gets the process state.
 */
static int getProcessState(int pid) {
    char statFile[MAX_PATH];
    char buffer[128];
    FILE *fp;
    int state;

    sprintf(statFile, "/proc/%d/stat", pid);
    fp = fopen(statFile, "r");
    if (!fp) {
        return '?';
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    strtok(buffer, " "); // skip pid
    strtok(NULL, " "); // skip name
    strtok(NULL, " "); // skip state
    state = fgetc(fp); // get state
    return state;
}

/**
 * Gets the parent pid.
 */
static int getParentPid(int pid) {
    char statFile[MAX_PATH];
    char buffer[128];
    FILE *fp;
    int ppid;

    sprintf(statFile, "/proc/%d/stat", pid);
    fp = fopen(statFile, "r");
    if (!fp) {
        return -1;
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    strtok(buffer, " "); // skip pid
    strtok(NULL, " "); // skip name
    strtok(NULL, " "); // skip state
    strtok(NULL, " "); // skip ppid
    ppid = atoi(strtok(NULL, " ")); // get ppid
    return ppid;
}

/**
 * Gets the process group.
 */
static int getProcessGroup(int pid) {
    char statFile[MAX_PATH];
    char buffer[128];
    FILE *fp;
    int pgrp;

    sprintf(statFile, "/proc/%d/stat", pid);
    fp = fopen(statFile, "r");
    if (!fp) {
        return -1;
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    strtok(buffer, " "); // skip pid
    strtok(NULL, " "); // skip name
    strtok(NULL, " "); // skip state
    strtok(NULL, " "); // skip ppid
    strtok(NULL, " "); // skip pgrp
    pgrp = atoi(strtok(NULL, " ")); // get pgrp
    return pgrp;
}

/**
 * Gets the session id.
 */
static int getSessionId(int pid) {
    char statFile[MAX_PATH];
    char buffer[128];
    FILE *fp;
    int session;

    sprintf(statFile, "/proc/%d/stat", pid);
    fp = fopen(statFile, "r");
    if (!fp) {
        return -1;
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    strtok(buffer, " "); // skip pid
    strtok(NULL, " "); // skip name
    strtok(NULL, " "); // skip state
    strtok(NULL, " "); // skip ppid
    strtok(NULL, " "); // skip pgrp
    strtok(NULL, " "); // skip sid
    session = atoi(strtok(NULL, " ")); // get sid
    return session;
}

/**
 * Gets the terminal.
 */
static int getTerminal(int pid) {
    char statFile[MAX_PATH];
    char buffer[128];
    FILE *fp;
    int tty;

    sprintf(statFile, "/proc/%d/stat", pid);
    fp = fopen(statFile, "r");
    if (!fp) {
        return -1;
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    strtok(buffer, " "); // skip pid
    strtok(NULL, " "); // skip name
    strtok(NULL, " "); // skip state
    strtok(NULL, " "); // skip ppid
    strtok(NULL, " "); // skip pgrp
    strtok(NULL, " "); // skip sid
    strtok(NULL, " "); // skip tty_nr
    tty = atoi(strtok(NULL, " ")); // get tty_nr
    return tty;
}

/**
 * Gets the terminal process group.
 */
static int getTerminalProcessGroup(int pid) {
    char statFile[MAX_PATH];
    char buffer[128];
    FILE *fp;
    int tpgid;

    sprintf(statFile, "/proc/%d/stat", pid);
    fp = fopen(statFile, "r");
    if (!fp) {
        return -1;
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    strtok(buffer, " "); // skip pid
    strtok(NULL, " "); // skip name
    strtok(NULL, " "); // skip state
    strtok(NULL, " "); // skip ppid
    strtok(NULL, " "); // skip pgrp
    strtok(NULL, " "); // skip sid
    strtok(NULL, " "); // skip tty_nr
    strtok(NULL, " "); // skip tpgid
    tpgid = atoi(strtok(NULL, " ")); // get tpgid
    return tpgid;
}

/**
 * Gets the number of minor faults.
 */
static unsigned int getMinorFaults(int pid) {
    char statFile[MAX_PATH];
    char buffer[128];
    FILE *fp;
    unsigned int minflt;

    sprintf(statFile, "/proc/%d/stat", pid);
    fp = fopen(statFile, "r");
    if (!fp) {
        return -1;
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    strtok(buffer, " "); // skip pid
    strtok(NULL, " "); // skip name
    strtok(NULL, " "); // skip state
    strtok(NULL, " "); // skip ppid
    strtok(NULL, " "); // skip pgrp
    strtok(NULL, " "); // skip sid
    strtok(NULL, " "); // skip tty_nr
    strtok(NULL, " "); // skip tpgid
    strtok(NULL, " "); // skip flags
    strtok(NULL, " "); // skip minflt
    minflt = atoi(strtok(NULL, " ")); // get minflt
    return minflt;
}

/**
 * Gets the cumulative number of minor faults.
 */
static unsigned int getCumulativeMinorFaults(int pid) {
    char statFile[MAX_PATH];
    char buffer[128];
    FILE *fp;
    unsigned int cminflt;

    sprintf(statFile, "/proc/%d/stat", pid);
    fp = fopen(statFile, "r");
    if (!fp) {
        return -1;
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    strtok(buffer, " "); // skip pid
    strtok(NULL, " "); // skip name
    strtok(NULL, " "); // skip state
    strtok(NULL, " "); // skip ppid
    strtok(NULL, " "); // skip pgrp
    strtok(NULL, " "); // skip sid
    strtok(NULL, " "); // skip tty_nr
    strtok(NULL, " "); // skip tpgid
    strtok(NULL, " "); // skip flags
    strtok(NULL, " "); // skip minflt
    strtok(NULL, " "); // skip cminflt
    cminflt = atoi(strtok(NULL, " ")); // get cminflt
    return cminflt;
}