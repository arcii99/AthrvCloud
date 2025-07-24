//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <time.h>

double calculate_typing_speed(int total_chars, double time_taken) {
    double chars_per_min = (total_chars / time_taken) * 60;
    return chars_per_min;
}

int main() {
    printf("-----------------------------------------------\n");
    printf(" Welcome to the C Typing Speed Test \n");
    printf("-----------------------------------------------\n\n");
    printf("Instructions:\n");
    printf("Type the following as quickly and accurately as possible within 1 minute\n");
    printf("Press ENTER to start the test\n");
    
    fflush(stdin);
    getchar();
    
    char paragraph[] = "C is a high-level and general-purpose programming language that is ideal for developing firmware or portable applications";
    char user_input[150];
    int chars_typed = 0;
    time_t start_time, end_time;
    double time_taken;
    
    printf("\n%s\n\n", paragraph);
    start_time = time(NULL);
    
    while (1) {
        printf("Type here: ");
        fflush(stdout);
        fgets(user_input, 150, stdin);
        
        if (strcmp(user_input, "\n") == 0) break;
        
        for (int i = 0; i < strlen(user_input) - 1; i++) {
            if (user_input[i] == paragraph[i]) chars_typed++;
        }
    }
    
    end_time = time(NULL);
    time_taken = difftime(end_time, start_time);
    
    printf("\n\nTyping Speed: %.2f chars per minute", calculate_typing_speed(chars_typed, time_taken));
    return 0;
}