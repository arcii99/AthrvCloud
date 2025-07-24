//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to check typing speed
float typingSpeedTest(char text[], int timeTaken)
{
    int wordsTyped = 0;
    int incorrectWords = 0;
    int textLength = strlen(text);
    char userText[textLength+1]; // To store user's typed text
    int i,j,k;
    i = j = k = 0;

    // Start the timer
    time_t start, end;
    time(&start);

    // Loop until user types the entire text
    while(i<textLength)
    {
        char c = getchar(); // Get character from user
        if(c == '\n') // Break if user presses "Enter"
            break;
        if(c == text[i]) // If typed character is correct
        {
            userText[k++] = c; // Store typed text
            i++; // Move to next character in original text
        }
        else // If typed character is incorrect
        {
            incorrectWords++;
        }
        if(c == ' ') // If user types a space, check if a word has been completed
        {
            if(i != 0 && text[i-1] == ' ') // Ignore if there are multiple spaces
                continue;
            wordsTyped++;
        }
    }

    // Stop the timer
    time(&end);
    float timeTakenInSeconds = difftime(end,start);

    // Calculate typing speed
    float typingSpeed = ((float)wordsTyped/(float)timeTakenInSeconds)*60;

    // Print typing results and return the typing speed
    printf("\nYou typed: %s\n", userText);
    printf("Words typed: %d\n", wordsTyped+1);
    printf("Incorrect words: %d\n", incorrectWords);
    printf("Time taken: %d seconds\n", (int)timeTakenInSeconds);
    printf("Your typing speed: %.2f words per minute\n", typingSpeed);
    return typingSpeed;
}

int main()
{
    char medievalText[] = "Ye olde farme with welle and hedge and cowes and horses all arounde. Thrice the rooster did crowe as the morninge sunne rose over the hilles and dales. Mayhap the harvest woulde beginne this day.";
    printf("Welcome to the Medieval Typing Speed Test!\n");
    printf("Type the following text as fast as thou canst:\n\n");
    printf("%s\n", medievalText);

    float speed = typingSpeedTest(medievalText, 60);
    printf("Your typing speed was: %.2f words per minute.\n", speed);
    return 0;
}