//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Begin parsing the resume */
    char* resume = "I am a surreal resume with experience in levitating cups and juggling jellyfish";
    char* current_word = strtok(resume, " ");
    int cups_levitated = 0;
    int jellyfish_juggled = 0;
    int line_count = 0;
    
    while (current_word != NULL) {
        /* Analyze the resume for specific skills */
        if (strcmp(current_word, "levitating") == 0) {
            cups_levitated++;
            printf("Cups levitated: %d\n", cups_levitated);
        } else if (strcmp(current_word, "juggling") == 0) {
            /* Get additional information about the juggling experience */
            current_word = strtok(NULL, " ");
            if (strcmp(current_word, "jellyfish") == 0) {
                jellyfish_juggled++;
                printf("Jellyfish juggled: %d\n", jellyfish_juggled);
            }
        }
        
        /* Count the number of lines in the resume */
        if (strstr(current_word, "\n") != NULL) {
            line_count++;
        }
        
        /* Move onto the next word in the resume */
        current_word = strtok(NULL, " ");
    }
    
    /* Print out the final results */
    printf("Total cups levitated: %d\n", cups_levitated);
    printf("Total jellyfish juggled: %d\n", jellyfish_juggled);
    printf("Total number of lines in the resume: %d\n", line_count);
    
    return 0;
}