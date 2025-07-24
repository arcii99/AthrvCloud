//FormAI DATASET v1.0 Category: System boot optimizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 1024
#define BOOT_PATH "/boot/grub/grub.cfg"

int main(void) {
    char buf[BUF_SIZE];
    FILE *fp;
    int num_entries = 0;
    time_t start_time, end_time;

    // Record start time
    start_time = time(NULL);

    // Open grub.cfg for reading
    fp = fopen(BOOT_PATH, "r");
    if (fp == NULL) {
        printf("Error: Could not open %s\n", BOOT_PATH);
        return 1;
    }

    // Count number of menu entries
    while (fgets(buf, BUF_SIZE, fp)) {
        if (strstr(buf, "menuentry") != NULL) {
            num_entries++;
        }
    }

    // Close file
    fclose(fp);

    // Reopen file for writing
    fp = fopen(BOOT_PATH, "w");
    if (fp == NULL) {
        printf("Error: Could not open %s\n", BOOT_PATH);
        return 1;
    }

    // Write boot entry with shortest boot time first
    for (int i = 0; i < num_entries; i++) {
        int shortest_time = 9999;
        char shortest_entry[BUF_SIZE];
        char *entry_start;

        // Reset file pointer to beginning of file
        fseek(fp, 0, SEEK_SET);

        // Find shortest boot time entry
        while (fgets(buf, BUF_SIZE, fp)) {
            if ((entry_start = strstr(buf, "menuentry")) != NULL) {
                // Save menu entry name
                entry_start += 10;  // move pointer to beginning of entry name
                char *entry_end = strchr(entry_start, '\'');
                *entry_end = '\0';
                char *entry_name = malloc(sizeof(char) * (strlen(entry_start) + 1));
                strcpy(entry_name, entry_start);

                // Get boot time for entry
                int boot_time = 0;
                while (fgets(buf, BUF_SIZE, fp)) {
                    if (strstr(buf, "kernel") != NULL) {
                        char *time_str = strstr(buf, "boot_time=");
                        if (time_str != NULL) {
                            time_str += 10;
                            boot_time = atoi(time_str);
                            break;
                        }
                    }
                }

                // Save shortest entry
                if (boot_time < shortest_time) {
                    shortest_time = boot_time;
                    strcpy(shortest_entry, entry_name);
                }

                // Free memory for entry name
                free(entry_name);
            }
        }

        // Write shortest entry to grub.cfg
        fseek(fp, 0, SEEK_SET);
        while (fgets(buf, BUF_SIZE, fp)) {
            if (strstr(buf, shortest_entry) != NULL) {
                printf("Writing boot entry: %s\n", shortest_entry);
                fprintf(fp, "%s", buf);  // write menu entry line
                while (fgets(buf, BUF_SIZE, fp)) {
                    fprintf(fp, "%s", buf);  // write rest of entry
                    if (strstr(buf, "}") != NULL) {
                        break;
                    }
                }
                break;
            }
        }
    }

    // Close file
    fclose(fp);

    // Record end time and calculate elapsed time
    end_time = time(NULL);
    int elapsed_time = difftime(end_time, start_time);

    printf("Boot optimizer finished in %d seconds.\n", elapsed_time);

    return 0;
}