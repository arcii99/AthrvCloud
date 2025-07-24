//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define LENGTH 50 // Length of the string user needs to type

void welcome(){
  printf("Welcome to the Typing Speed test!\n\n");
}

int generate_phrases(char phrases[][LENGTH+1]){
  int rand_index;
  int num_phrases=10;//Number of phrases
  
  // List of random phrases
  char phrases_list[][LENGTH+1] = {"The quick brown fox jumps over the lazy dog.",
                                   "Pack my box with five dozen liquor jugs.",
                                   "Waltz, bad nymph, for quick jigs vex.",
                                   "Blowzy night-frumps vex'd Jack Q.",
                                   "How vexingly quick daft zebras jump!",
                                   "Bright vixens jump; dozy fowl quack.",
                                   "The five boxing wizards jump quickly.",
                                   "Amazingly few discotheques provide jukeboxes.",
                                   "My girl wove six dozen plaid jackets before she quit.",
                                   "Six Big Devs fought her for the juiciest plum."};
  srand(time(NULL));//Set Seed value  
  for(int i=0;i<num_phrases;i++){
    rand_index = rand()%num_phrases;
    strcpy(phrases[i], phrases_list[rand_index]);
  }
  return num_phrases;
}

double get_time_taken(struct timespec t1, struct timespec t2){
  return (t2.tv_sec-t1.tv_sec)+(t2.tv_nsec-t1.tv_nsec)/1e9;//Returns difference of times in seconds
}

void score_calculator(int time_taken){
  double time_in_mins = time_taken/60.0;//Convert seconds to minutes
  double wpm = (50 / 5) / time_in_mins;//WPM Calculation based on word count
  printf("\nYour typing speed is %.2f words per minute!", wpm);
}

void type_phrases(char phrases[][LENGTH+1], int num_phrases){
  char user_input[LENGTH+1];//User Input
  int i;
  struct timespec t1, t2;//Stores start and end time of typing
  
  //Loop to display phrases and get user input
  for(i=0;i<num_phrases;i++){
    printf("\nPhrase %d:\n %s\n",i+1,phrases[i]);    
    printf("Type here (Press Enter key when done):");
    clock_gettime(CLOCK_REALTIME, &t1);
    fflush(stdout);
    fgets(user_input, LENGTH+1, stdin);
    clock_gettime(CLOCK_REALTIME, &t2);
    user_input[strlen(user_input)-1] ='\0';//To remove newline character at the end
    if(strcmp(phrases[i], user_input)==0){
      printf("Phrase %d is correct!\n",(i+1));
    }else{
      printf("Sorry, Phrase %d is incorrect\n", (i+1));
    }
  }
  //Get Time taken to type the phrases
  double time_taken = get_time_taken(t1, t2);
  score_calculator((int)time_taken);
}

int main(){
  char phrases[10][LENGTH+1];//Array to store list of phrases
  
  welcome();
  
  int num_phrases=generate_phrases(phrases);
  
  printf("You will be asked to type %d phrases each containing %d characters\n",num_phrases, LENGTH);
  
  type_phrases(phrases, num_phrases);
  
  return 0;
}