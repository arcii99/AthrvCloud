//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
   printf("Welcome to the Typing Speed Test! \nYou will be given a random word to type. \nPress enter after typing the word. \nYour typing speed will be calculated in words per minute. \n\n");
   
   char dictionary[][10] = {"apple", "banana", "cherry", "dragon", "elephant", "forest", "giraffe", "harmony", "indigo", "jubilee", "kangaroo", "leopard", "mango", "nectar", "ocean", "penguin", "quadrant", "rainbow", "sunflower", "tiger", "unicorn", "violet", "waterfall", "xylophone", "yellow", "zebra"}; //list of words
   int dictionary_size =sizeof(dictionary)/sizeof(dictionary[0]); //calculating the size of the dictionary
   
   int score = 0; //initializing score to 0
   srand(time(NULL)); //seeding the random number generator
   while(1){
      int index = rand()%dictionary_size; //picking a random word
      char word[10];
      strcpy(word, dictionary[index]); //copying the random word into a string
      
      printf("\nType this word: %s\n", word); //prompting the user to type
      clock_t start_time = clock(); //starting timer
      
      char input_word[10];
      scanf("%s", input_word); //taking user input
      clock_t end_time = clock(); //stopping timer
      
      double elapsed_time = (double) (end_time - start_time)/CLOCKS_PER_SEC; //calculating time taken in seconds
      int word_length = strlen(word); //calculating length of the word
      int input_length = strlen(input_word); //calculating length of user input
      
      if(word_length==input_length && strcmp(word, input_word)==0){ //checking if the word was typed correctly
         printf("Correct!\n");
         double speed = (double) word_length/elapsed_time * 60; //calculating typing speed
         printf("Your typing speed is %.2f words per minute.\n", speed);
         score++; //incrementing score
      }
      else{
         printf("Incorrect. Try again!\n");
      }
      
      printf("Your current score is %d.\n", score); //displaying current score
      printf("Do you want to continue? (y/n) \n"); //asking user if they want to continue
      char choice;
      scanf(" %c", &choice); //reading user choice
      
      if(choice=='n'){
         break; //breaking the loop if user wants to quit
      }
   }
   printf("\nThank you for playing the Typing Speed Test!\n"); //displaying message at the end
   return 0;
}