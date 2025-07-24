//FormAI DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char event[100];
    char location[50];
    time_t now;
    struct tm *local;
    now = time(NULL);
    local = localtime(&now);

    printf("Oh system log, what news doth thou record today?\n");
    fgets(event, sizeof(event), stdin);
    printf("Where hath this occurred, dear log?\n");
    fgets(location, sizeof(location), stdin);

    printf("Alas! %s has happened at %s. Verily, let it be recorded in the System Event Logger!\n", event, location);

    FILE *file;
    file = fopen("event_log.txt", "a");
    fprintf(file, "%s - %s - %s\n", asctime(local), event, location);
    fclose(file);

    printf("Farewell, sweet log, until our paths cross again.\n");

    return 0;
}