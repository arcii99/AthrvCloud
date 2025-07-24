//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//Function to generate random string
void generate_string(char* string, int length) {
    int i;
    for(i=0; i<length; i++){
        string[i] = rand() % 26 + 'a'; //Generates lowercase random alphabets
    }
    string[length] = '\0'; //End the string with null character
}

int main() {
    int string_length = 30;
    char random_string[string_length+1];
    int timer;
    char input_string[string_length+1];

    printf("Welcome to the Typing Speed Test\n");
    printf("You will be given a random string to type, and will be timed on how quickly you can type it\n\n");
    
    printf("Press enter to start the test");
    getchar(); //Waits for user to press enter
    
    generate_string(random_string, string_length); //Generate the random string
    
    printf("\n%s\n", random_string); //Outputs the random string
    time_t start = time(NULL); //Record the start time
    
    fgets(input_string, string_length+1, stdin); //Record the user's input
    time_t end = time(NULL); //Record the end time
    
    //Calculate the time taken and the typing speed
    timer = end - start;
    double speed = (double)string_length / (double)timer * 60;

    printf("\nYou took %d seconds to type the string\n", timer);
    printf("Your typing speed is %.2f characters per minute\n", speed);
    
    return 0;
}