//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h> 
#include <string.h> 

//Function to extract emotions from user input 
char* extract_emotion(char input[]) 
{ 
    //Positive words list 
    char *positive_words[] = {"happy", "joyful", "excited", "amazing", "great", "fantastic", "love", "like"}; 
    
    //Negative words list 
    char *negative_words[] = {"sad", "angry", "disappointed", "hate", "horrible", "terrible", "bad", "unhappy"}; 
    
    //Tokenize user input 
    char *token = strtok(input, " "); 
    
    //Loop through input to find emotions 
    while (token != NULL) 
    { 
        //Check for positive words 
        for (int i = 0; i < 8; i++) 
        { 
            if (strcmp(token, positive_words[i]) == 0) 
            { 
                return "Positive"; 
            } 
        } 
        
        //Check for negative words 
        for (int i = 0; i < 8; i++) 
        { 
            if (strcmp(token, negative_words[i]) == 0) 
            { 
                return "Negative"; 
            } 
        } 
        
        //Move to next token 
        token = strtok(NULL, " "); 
    } 
    
    //If no emotion detected, return "Neutral" 
    return "Neutral"; 
} 

//Main function 
int main() 
{ 
    char input[1000]; 
    
    printf("Enter your message: "); 
    fgets(input, 1000, stdin); 
    
    //Extract emotion from user input 
    char *emotion = extract_emotion(input); 
    
    //Print detected emotion 
    printf("Detected emotion: %s\n", emotion); 
    
    return 0; 
}