//FormAI DATASET v1.0 Category: Online Examination System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate random numbers for questions
int generate_random_number(int min, int max) {
   static int flag;
   
   if (flag == 0) {
      srand(time(NULL));
      flag = 1;
   }
   
   return (rand() % (max - min + 1)) + min;
}

//structure for questions
struct question {
   int q_no;
   char question[200];
   char option1[30];
   char option2[30];
   char option3[30];
   char option4[30];
   int correct;
};

//function to display the questions
void display_question(struct question q) {
   printf("%d. %s\n", q.q_no, q.question);
   printf("  A. %s\n", q.option1);
   printf("  B. %s\n", q.option2);
   printf("  C. %s\n", q.option3);
   printf("  D. %s\n", q.option4);
}

//function to display the result
void display_result(int score) {
   printf("\nYour Score: %d\n", score);
   if (score >= 8)
       printf("Congratulations! You have passed the examination.\n");
   else
       printf("Sorry! You have failed the examination.\n");
}

int main() {
   int i, choice, score=0;
   
   //array of questions
   struct question q[10] = {
                           {1, "What is the capital of India?", "Delhi", "Kolkata", "Mumbai", "Chennai", 1},
                           {2, "Who is the founder of Microsoft?", "Bill Gates", "Steve Jobs", "Larry Page", "Mark Zuckerberg", 1},
                           {3, "What is the currency of Japan?", "Rupee", "Dollar", "Pound", "Yen", 4},
                           {4, "In which year did India become independent?", "1947", "1950", "1930", "1945", 1},
                           {5, "Who is the current CEO of Google?", "Sundar Pichai", "Mark Zuckerberg", "Tim Cook", "Elon Musk", 1},
                           {6, "What is the largest continent?", "Africa", "Australia", "Europe", "Asia", 4},
                           {7, "What is the highest mountain peak in the world?", "Mount Everest", "K2", "Annapurna", "Makalu", 1},
                           {8, "What is the chemical formula of water?", "H2O", "CO2", "SO2", "HCl", 1},
                           {9, "Who painted the famous painting 'Mona Lisa'?", "Pablo Picasso", "Leonardo da Vinci", "Vincent van Gogh", "Rembrandt", 2},
                           {10, "What is the largest planet in our solar system?", "Neptune", "Jupiter", "Saturn", "Uranus", 2}
                           };
   
   printf("Welcome to the Online Examination System!\n");
   printf("You will have to answer 10 multiple choice questions.\n");
   printf("Each correct answer will give you 1 point.\n");
   printf("There is no negative marking.\n");
   printf("Let's start the examination.\n\n");
   
   for (i=0; i<10; i++) {
      choice = generate_random_number(1, 4); //generate random number for options
      
      printf("Question %d:\n", i+1);
      display_question(q[i]); //display the question
      
      do {
         printf("\nEnter your choice (A/B/C/D): ");
         char ch = getchar();
          
         switch(ch) {
            case 'A':
            case 'a': if (choice == 1) {
                         printf("Correct Answer!\n\n");
                         score++;
                      }
                      else {
                         printf("Wrong Answer!\n\n");
                      }
                      break;
                      
            case 'B':
            case 'b': if (choice == 2) {
                         printf("Correct Answer!\n\n");
                         score++;
                      }
                      else {
                         printf("Wrong Answer!\n\n");
                      }
                      break;
                      
            case 'C':
            case 'c': if (choice == 3) {
                         printf("Correct Answer!\n\n");
                         score++;
                      }
                      else {
                         printf("Wrong Answer!\n\n");
                      }
                      break;
                      
            case 'D':
            case 'd': if (choice == 4) {
                         printf("Correct Answer!\n\n");
                         score++;
                      }
                      else {
                         printf("Wrong Answer!\n\n");
                      }
                      break;
                      
            default: printf("Invalid choice! Please enter again.\n\n"); break;
         }
         
         getchar(); //consume the newline character
         
      } while (choice < 1 || choice > 4);
   }
   
   display_result(score); //display the result
   
   return 0;
}