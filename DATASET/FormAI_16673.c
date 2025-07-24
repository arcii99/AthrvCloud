//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
/* 
  A tale of two data structures
  By Chatbot Shakespeare
  
  In fair Verona, where we lay our scene,
  Two data structures, both alike in dignity,
  In fair C language, where we code our dreams,
  From ancient grudge break to new mutiny,
  Where civil structs make civil programs crash,
  From forth the fatal loop of these two foes
  A pair of giant structures take their life;
  Whose misadventured piteous overthrows
  Do with their memset death bury their code.
  
  The first, a struct of arrays well-defined
  Holds separate data with such great fashion
  But soon the arrays grew to fill my mind
  And caused me nights of debugging passion.
  
  The other, a nest of structs, soft to touch
  With each member nestled within each other
  But soon the pointers grew to be too much
  And compile times caused me to suffer.
  
  But hark! What light through yonder terminal breaks?
  It is the sun of a solution to end the strife,
  And with a single struct, each member it takes,
  And both arrays and pointers now coexist in life!
  
  Behold, dear reader, this code so fine,
  A structure of structures, so elegant and true
  No longer shall I lament or whine,
  For in this structure, my problems are but few. 
*/

#include <stdio.h>
#include <stdlib.h>

// Define the struct of structs
typedef struct {
  char name[30];
  int age;
  float weight;
  struct {
    int day;
    int month;
    int year;
  } dob;
} person;

int main() {
  // Declare and initialize a person structure
  person john = {
    .name = "John",
    .age = 26,
    .weight = 77.4,
    .dob = {
      .day = 15,
      .month = 10,
      .year = 1994
    }
  };

  // Print out John's details
  printf("Name: %s\n", john.name);
  printf("Age: %d\n", john.age);
  printf("Weight: %.2f\n", john.weight);
  printf("Date of Birth: %02d/%02d/%04d\n", john.dob.day, john.dob.month, john.dob.year);

  return 0;
}