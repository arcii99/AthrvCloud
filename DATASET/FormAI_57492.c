//FormAI DATASET v1.0 Category: System boot optimizer ; Style: puzzling
#include <stdio.h>

int main() {
    printf("Welcome to the C System boot optimizer!\n\n");

    char boot_options[5][20] = {"Fast boot", "Low power boot", "Diagnostic boot", "Safe mode", "Regular boot"};
    int boot_option_times[5] = {3, 5, 12, 7, 10};

    printf("Please select a boot option:\n\n");

    for(int i = 0; i < 5; i++) {
        printf("%d. %s\n", i+1, boot_options[i]);
    }

    int selected_option;
    scanf("%d", &selected_option);

    printf("\nYou have selected: %s\n", boot_options[selected_option-1]);

    printf("\nOptimizing boot sequence...\n");

    int total_time = 0;
    for(int i = 0; i < boot_option_times[selected_option-1]; i++) {
        printf("Loading %s [%d%%]\n", boot_options[selected_option-1], (i+1)*10);
        total_time += 1;
        for(int j = 0; j < 100000000; j++) {} // delay loop
    }

    printf("\nBoot sequence optimized. Total time: %d seconds.\n", total_time);

    return 0;
}