//FormAI DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *log_file;
    char log_entry[256];
    int radiation_count = 0;
    int mutants_detected = 0;
    int zombies_detected = 0;
    int supplies_collected = 0;
    
    log_file = fopen("log_file.txt", "r");
    
    if (log_file == NULL) {
        printf("Error opening log file.");
        exit(1);
    }
    
    while (fgets(log_entry, 256, log_file)) {
        if (strstr(log_entry, "RAD:") != NULL) {
            sscanf(log_entry, "RAD:%d", &radiation_count);
            printf("Radiation count: %d\n", radiation_count);
        } else if (strstr(log_entry, "MUTANT:") != NULL) {
            mutants_detected++;
        } else if (strstr(log_entry, "ZOMBIE:") != NULL) {
            zombies_detected++;
        } else if (strstr(log_entry, "SUPPLY:") != NULL) {
            supplies_collected++;
        }
    }
    
    fclose(log_file);
    
    printf("Mutants detected: %d\n", mutants_detected);
    printf("Zombies detected: %d\n", zombies_detected);
    printf("Supplies collected: %d\n", supplies_collected);
    
    return 0;
}