//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>

/*
    Modules:
    - main: The main driver code for the intrusion detection system.
    - read_log: Reads the log file and checks for suspicious activity.
    - send_alert: Sends an alert if suspicious activity is detected.
    - log_alert: Logs the alert message to a file.
*/

void read_log()
{
    // Read log file
    FILE *file;
    file = fopen("logfile.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }

    // Check for suspicious activity
    char line[100];
    while (fgets(line, sizeof(line), file)) 
    {
        if (strstr(line, "suspicious_keyword") != NULL) 
        {
            send_alert();
            break;
        }
    }

    fclose(file);
}

void send_alert()
{
    char message[] = "Suspicious activity detected!";
    log_alert(message);
    printf("Alert sent: %s\n", message);
}

void log_alert(char *message)
{
    FILE *file;
    file = fopen("alertlog.txt", "a");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s\n", message);
    fclose(file);
}

int main()
{
    read_log();

    return 0;
}