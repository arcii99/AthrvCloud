//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>

/**
 * This program rates movies on a scale from 0 to 10, based on a variety of factors.
 */

int main(void) {
    int plot = 7, acting = 8, effects = 9;
    float total_score = plot + acting + effects;

    // Adjust score based on additional criteria

    // Add points for originality
    total_score += 1.5;

    // Subtract points for predictability
    total_score -= 0.5;

    // Multiply score by audience engagement factor
    total_score *= 1.2;

    // Apply penalty for excessively long runtime
    if (total_score > 15) {
        total_score -= 2;
    }

    // Round the score to one decimal place
    total_score = ((int)(total_score * 10 + 0.5)) / 10.0;

    printf("The movie's score is: %.1f\n", total_score);

    return 0;
}