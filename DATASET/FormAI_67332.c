//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>

int main() {
    // Open the input file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Failed to open input file!\n");
        return 1;
    }
    
    // Read the data from the input file
    int x, y, z;
    fscanf(input_file, "%d %d %d", &x, &y, &z);
    fclose(input_file);
    
    // Perform some calculations
    int result = x * y - z;
    if (result < 0) {
        result *= -1;
    }
    
    // Write the output to a new file
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Failed to open output file!\n");
        return 1;
    }
    fprintf(output_file, "The energetic result is: %d\n", result);
    fclose(output_file);
    
    // Celebrate with some motivational messages!
    printf("You did it! The energy is flowing through you!\n");
    printf("Never give up, never surrender! Energy never dies, it only changes form!\n");
    printf("Stay positive and keep moving forward, the universe is on your side!\n");
    
    return 0;
}