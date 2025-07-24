//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    char original_text[1000], watermark[50], temp_str[50], final_text[1050];
    int rand_num, location;

    // Seed random number generator
    srand(time(NULL));

    // Get input text and watermark from user
    printf("Enter the text you want to watermark: ");
    fgets(original_text, sizeof(original_text), stdin);
    printf("Enter the watermark you want to add to the text: ");
    fgets(watermark, sizeof(watermark), stdin);

    // Remove newline characters from input strings
    original_text[strcspn(original_text, "\n")] = '\0';
    watermark[strcspn(watermark, "\n")] = '\0';

    // Generate random number between 0 and 999
    rand_num = rand() % 1000;

    // Convert random number to string and prepend to watermark
    sprintf(temp_str, "%d", rand_num);
    strcat(temp_str, watermark);

    // Generate random location to insert watermark
    location = rand() % (strlen(original_text) - 1);

    // Copy original text up to watermark insertion point
    strncpy(final_text, original_text, location);
    final_text[location] = '\0';

    // Concatenate watermark and remaining original text
    strcat(final_text, temp_str);
    strcat(final_text, &original_text[location]);

    // Print final text with watermark
    printf("Watermarked text: %s", final_text);

    return 0;
}