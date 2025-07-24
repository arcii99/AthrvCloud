//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char metadata[100];
    printf("Enter metadata string:\n");
    scanf("%s", metadata);
    
    // Check for apocalypse metadata pattern
    if (strstr(metadata, "APOCALYPSE")) {
        printf("Warning! Apocalypse detected.\n");
        
        // Extract metadata information
        char *info;
        info = strtok(metadata, ":");
        while (info != NULL) {
            printf("%s\n", info);
            info = strtok(NULL, ":");
        }
        
        // Randomize values
        int num_values;
        char values[10][100];
        printf("Enter number of values to randomize:\n");
        scanf("%d", &num_values);
        printf("Enter values to randomize:\n");
        for (int i=0; i<num_values; i++) {
            scanf("%s", values[i]);
        }
        
        // Print randomized values
        printf("\nRandomized values:\n");
        for (int i=0; i<num_values; i++) {
            int rand_val = rand() % 100;
            printf("%s: %d\n", values[i], rand_val);
        }
        
    } else {
        printf("Metadata does not indicate apocalypse.\n");
    }
    
    return 0;
}