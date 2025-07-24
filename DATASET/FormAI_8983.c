//FormAI DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Question{
   char question[100];
   char option1[50], option2[50], option3[50], option4[50];
   int correctOption;
};

int main(){
   struct Question questions[10];
   int marks = 0;

   // Question 1
   strcpy(questions[0].question, "What is the meaning of ‘sizeof’ operator?");
   strcpy(questions[0].option1, "It returns the size of an array.");
   strcpy(questions[0].option2, "It returns the size of an object.");
   strcpy(questions[0].option3, "It returns the size of a pointer.");
   strcpy(questions[0].option4, "It returns the number of elements in an array.");
   questions[0].correctOption = 2;

   // Question 2
   strcpy(questions[1].question, "What is a function prototype?");
   strcpy(questions[1].option1, "It is a declaration of a function with a return type and arguments.");
   strcpy(questions[1].option2, "It is a definition of a function with a return type and arguments.");
   strcpy(questions[1].option3, "It is a definition of a function with only a return type.");
   strcpy(questions[1].option4, "It is a declaration of a function with only a return type.");
   questions[1].correctOption = 1;

   // Question 3
   strcpy(questions[2].question, "What is the base address in linked list?");
   strcpy(questions[2].option1, "It is the address of the first node in linked list.");
   strcpy(questions[2].option2, "It is the address of the last node in linked list.");
   strcpy(questions[2].option3, "It is the address of the middle node in linked list.");
   strcpy(questions[2].option4, "It is the address of the node just before the first node in linked list.");
   questions[2].correctOption = 1;

   // Question 4
   strcpy(questions[3].question, "What is the output of the following program?\n\nvoid main(){\n   int i = 0;\n   if(i == 1)\n      printf('Zero');\n   else if(i == 0)\n      printf('One');\n}");
   strcpy(questions[3].option1, "Zero");
   strcpy(questions[3].option2, "One");
   strcpy(questions[3].option3, "Nothing");
   strcpy(questions[3].option4, "Compilation Error");
   questions[3].correctOption = 2;

   // Question 5
   strcpy(questions[4].question, "What is the difference between malloc() and calloc()?");
   strcpy(questions[4].option1, "malloc() allocates single block of memory, calloc() allocates multiple blocks of memory.");
   strcpy(questions[4].option2, "malloc() initializes memory to 0, calloc() initializes memory to NULL.");
   strcpy(questions[4].option3, "calloc() allocates single block of memory, malloc() allocates multiple blocks of memory.");
   strcpy(questions[4].option4, "calloc() initializes memory to 0, malloc() does not initialize memory.");
   questions[4].correctOption = 4;

   // Question 6
   strcpy(questions[5].question, "What is the output of the following program?\n\nvoid main(){\n   int i;\n   for(i=0; i<5; ++i)\n      printf('%d ', i);\n}");
   strcpy(questions[5].option1, "0 1 2 3 4");
   strcpy(questions[5].option2, "1 2 3 4 5");
   strcpy(questions[5].option3, "0 1 2 3 4 5");
   strcpy(questions[5].option4, "Compilation Error");
   questions[5].correctOption = 1;

   // Question 7
   strcpy(questions[6].question, "What is recursion?");
   strcpy(questions[6].option1, "A structure in which two elements of type struct are linked.");
   strcpy(questions[6].option2, "A function calling itself.");
   strcpy(questions[6].option3, "A pointer pointing to itself.");
   strcpy(questions[6].option4, "A code block within another code block.");
   questions[6].correctOption = 2;

   // Question 8
   strcpy(questions[7].question, "What is a stack?");
   strcpy(questions[7].option1, "A container that stores elements in FIFO order.");
   strcpy(questions[7].option2, "A container that stores elements in LIFO order.");
   strcpy(questions[7].option3, "A container that stores elements in ascending order.");
   strcpy(questions[7].option4, "A container that stores elements in descending order.");
   questions[7].correctOption = 2;

   // Question 9
   strcpy(questions[8].question, "What is a union?");
   strcpy(questions[8].option1, "A structure in which two elements of type struct are linked.");
   strcpy(questions[8].option2, "A function calling itself.");
   strcpy(questions[8].option3, "A collection of elements that are related and of same data type.");
   strcpy(questions[8].option4, "A variable that can be known by more than one name.");
   questions[8].correctOption = 1;

   // Question 10
   strcpy(questions[9].question, "What is the output of the following program?\n\nvoid main(){\n   char s1[] = 'Computer';\n   char *s2 = s1;\n   printf('%c %c %c', *s1, *(s1+2), *(s2+2));\n}");
   strcpy(questions[9].option1, "C n p");
   strcpy(questions[9].option2, "C m t");
   strcpy(questions[9].option3, "C n t");
   strcpy(questions[9].option4, "Compilation Error");
   questions[9].correctOption = 3;

   // Taking user input and checking answers
   printf("Welcome to the Online Examination System\n");
   for(int i=0; i<10; ++i){
      printf("\nQuestion %d: %s\n", i+1, questions[i].question);
      printf("1. %s\n2. %s\n3. %s\n4. %s\nAnswer: ", questions[i].option1,questions[i].option2,questions[i].option3,questions[i].option4);
      int answer;
      scanf("%d", &answer);
      if(answer == questions[i].correctOption)
         marks++;
   }
   printf("\nThanks for taking the exam!\nYour score is %d/10\n", marks);
   return 0;
}