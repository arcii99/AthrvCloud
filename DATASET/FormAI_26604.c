//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // ASCII code ranges for the random characters (including space)
    int min_char = 32, max_char = 126;
    
    // Variables to store score and number of tests
    int score = 0, num_tests = 0;
    
    // Set the random seed
    srand(time(NULL));
    
    // Welcome message
    printf("\nWelcome to the Typing Speed Test!\n");
    printf("Type the random sentence below and press ENTER to continue:\n\n");
    
    // Generate the random sentence for the user to type
    char sentence[100];
    for(int i = 0; i < 100; i++) {
        sentence[i] = rand() % (max_char - min_char + 1) + min_char;
        printf("%c", sentence[i]);
    }
    
    // Wait for the user to press ENTER to start the test
    getchar();
    
    // Clear the console
    system("clear");
    
    // Start the timer
    time_t start_time = time(NULL);
    
    // Loop for 5 tests
    for(int i = 1; i <= 5; i++) {
        
        // Print the current test number
        printf("Test %d:\n", i);
        
        // Copy the random sentence to a new string for the user to type
        char user_input[100];
        for(int j = 0; j < 100; j++) {
            user_input[j] = sentence[j];
        }
        
        // Randomly replace 20 characters with spaces
        for(int j = 0; j < 20; j++) {
            int rand_index = rand() % 100;
            user_input[rand_index] = ' ';
        }
        
        // Print the modified sentence for the user to type
        printf("%s\n\n", user_input);
        
        // Wait for the user to type their input
        char input[100];
        fgets(input, 100, stdin);
        
        // Check their input against the original sentence
        int correct_chars = 0;
        for(int j = 0; j < 100; j++) {
            if(input[j] == sentence[j]) {
                correct_chars++;
            }
        }
        
        // Print their score for the current test
        int test_score = (correct_chars * 100) / 80;
        printf("Your score for Test %d is %d%%.\n\n", i, test_score);
        
        // Add their score to the total score and increment the number of tests
        score += test_score;
        num_tests++;
        
        // Wait for the user to press ENTER to continue
        getchar();
        
        // Clear the console
        system("clear");
    }
    
    // Calculate the average score and print it
    int avg_score = score / num_tests;
    printf("Your average score is %d%%.\n\n", avg_score);
    
    // Calculate the total time taken and print it
    time_t end_time = time(NULL);
    int total_time = (int) difftime(end_time, start_time);
    printf("Total time taken: %d seconds.\n\n", total_time);
    
    // Print a farewell message
    printf("Thank you for playing the Typing Speed Test!\n\n");
    
    return 0;
}