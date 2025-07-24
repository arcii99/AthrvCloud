//FormAI DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
   char question[1000];
   char options[4][500];
   int correct_ans;
};

struct student {
   char name[100];
   int marks;
};

int main() {
   struct question quiz[5]; // 5 questions quiz
   quiz[0].correct_ans = 3;
   quiz[1].correct_ans = 1;
   quiz[2].correct_ans = 2;
   quiz[3].correct_ans = 4;
   quiz[4].correct_ans = 2;
   
   // questions
   strcpy(quiz[0].question, "What is the capital of France?\n");
   strcpy(quiz[1].question, "What is 10 * 2 + 3?\n");
   strcpy(quiz[2].question, "What is the largest organ in the human body?\n");
   strcpy(quiz[3].question, "Who painted the Mona Lisa?\n");
   strcpy(quiz[4].question, "What is the smallest country in the world?\n");
   
   // options
   strcpy(quiz[0].options[0], "1. London\n");
   strcpy(quiz[0].options[1], "2. Madrid\n");
   strcpy(quiz[0].options[2], "3. Paris\n");
   strcpy(quiz[0].options[3], "4. Rome\n");
   
   strcpy(quiz[1].options[0], "1. 23\n");
   strcpy(quiz[1].options[1], "2. 23\n");
   strcpy(quiz[1].options[2], "3. 12\n");
   strcpy(quiz[1].options[3], "4. 5\n");
   
   strcpy(quiz[2].options[0], "1. Heart\n");
   strcpy(quiz[2].options[1], "2. Skin\n");
   strcpy(quiz[2].options[2], "3. Liver\n");
   strcpy(quiz[2].options[3], "4. Stomach\n");
   
   strcpy(quiz[3].options[0], "1. Leonardo da Vinci\n");
   strcpy(quiz[3].options[1], "2. Michaelangelo\n");
   strcpy(quiz[3].options[2], "3. Vincent van Gogh\n");
   strcpy(quiz[3].options[3], "4. Pablo Picasso\n");
   
   strcpy(quiz[4].options[0], "1. Monaco\n");
   strcpy(quiz[4].options[1], "2. Vatican City\n");
   strcpy(quiz[4].options[2], "3. Liechtenstein\n");
   strcpy(quiz[4].options[3], "4. San Marino\n");
   
   struct student students[3]; // for 3 students
   for(int i=0; i<3; i++){
       printf("Enter student name: ");
       scanf("%s", students[i].name);
       students[i].marks = 0;
       printf("\n%s, answer the following questions:\n\n", students[i].name);
       
       for(int j=0; j<5; j++){
           printf("%d. %s", j+1, quiz[j].question);
           printf("%s%s%s%s", quiz[j].options[0], quiz[j].options[1], 
                           quiz[j].options[2], quiz[j].options[3]);
           printf("Answer: ");
           int ans;
           scanf("%d", &ans);
           
           if(ans == quiz[j].correct_ans){
               students[i].marks += 2;
           }
           else{
               students[i].marks -= 1;
           }
       }
       
       printf("\n%s's marks: %d\n", students[i].name, students[i].marks);
   }
   
   printf("\nFinal scores:\n");
   for(int i=0; i<3; i++){
       printf("%s: %d\n", students[i].name, students[i].marks);
   }
   
   return 0;
}