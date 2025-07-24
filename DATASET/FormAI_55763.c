//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a random sentence to type.\n");
    printf("Type the sentence as fast and accurately as possible.\n");
    printf("Press Enter when you are ready to begin the test.\n");
    getchar(); // Waits for the user to type Enter key

    char* sentences[] = {"The quick brown fox jumps over the lazy dog.",
                         "I am the very model of a modern Major-General.",
                         "Simplicity is the ultimate sophistication.",
                         "A dream you dream alone is only a dream. A dream you dream together is reality.",
                         "Fear is the path to the dark side. Fear leads to anger. Anger leads to hate. Hate leads to suffering.",
                         "Some people can never believe in themselves until someone believes in them.",
                         "I solemnly swear that I am up to no good.",
                         "It is our choices, Harry, that show what we truly are, far more than our abilities.",
                         "Time flies over us, but leaves its shadow behind.",
                         "Be the change that you wish to see in the world.",
                         "All we have to decide is what to do with the time that is given us.",
                         "You have brains in your head. You have feet in your shoes. You can steer yourself any direction you choose.",
                         "If you want to live a happy life, tie it to a goal, not to people or things.",
                         "Believe you can and you're halfway there.",
                         "The best way to predict the future is to invent it.",
                         "Success is not final, failure is not fatal: It is the courage to continue that counts.",
                         "A person who never made a mistake never tried anything new.",
                         "Stay hungry, stay foolish.",
                         "I have not failed. I've just found 10,000 ways that won't work.",
                         "The way to get started is to quit talking and begin doing.",
                         "Imagination is more important than knowledge. Knowledge is limited. Imagination encircles the world.",
                         "It does not matter how slowly you go as long as you do not stop.",
                         "The only true wisdom is in knowing you know nothing.",
                         "As we express our gratitude, we must never forget that the highest appreciation is not to utter words, but to live by them.",
                         "Your work is going to fill a large part of your life, and the only way to be truly satisfied is to do what you believe is great work. And the only way to do great work is to love what you do. If you haven't found it yet, keep looking. Don't settle. As with all matters of the heart, you'll know when you find it.",
                         "Life is 10% what happens to you and 90% how you react to it."};
    int total_sentences = sizeof(sentences)/sizeof(char*);
    int random_index = rand() % total_sentences;
    char* sentence = sentences[random_index];
    printf("%s", sentence);
    
    time_t begin = time(NULL); // Start the timer
    char input[200];
    fgets(input, 200, stdin); // Accept the user's input
    time_t end = time(NULL); // End the timer

    double time_spent = difftime(end, begin);
    int words_typed = 0;
    int characters_typed = 0;

    char* word = strtok(sentence, " \t\n"); // Tokenize the original sentence
    while(word != NULL){
        words_typed++; // Increase the count of words in the original sentence
        
        char* input_word = strtok(input, " \t\n"); // Tokenize the user's input sentence
        while(input_word != NULL){
            if(strcmp(word, input_word) == 0){ // If the word typed by the user matches the original word
                characters_typed += strlen(word); // Then increase the count of characters typed accordingly
                break;
            }
            input_word = strtok(NULL, " \t\n"); // Move on to the next word in the input sentence
        }

        word = strtok(NULL, " \t\n"); // Move on to the next word in the original sentence
    }

    int accuracy = (characters_typed*100)/(strlen(sentence)-words_typed+1); // Calculate the accuracy
    printf("You typed %d out of %d correct characters in %.2lf seconds with %d%% accuracy.\n", characters_typed, strlen(sentence), time_spent, accuracy);
    return 0;
}