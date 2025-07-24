//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>

int main() {
  int num_questions = 10, num_students = 20;
  int answers[num_questions], student_ans[num_students][num_questions], marks[num_students];
  char student_names[num_students][20];

  // Getting answers from teacher
  printf("Enter the correct answers:\n");
  for (int i = 0; i < num_questions; i++) {
    printf("Question %d: ", i+1);
    scanf("%d", &answers[i]);
  }

  // Getting student details and answers
  for (int i = 0; i < num_students; i++) {
    printf("\nEnter the name of student %d: ", i+1);
    scanf("%s", student_names[i]);
    printf("Enter the answers of student %s: \n", student_names[i]);
    for (int j = 0; j < num_questions; j++) {
      printf("Question %d: ", j+1);
      scanf("%d", &student_ans[i][j]);
    }
  }

  // Checking answers and calculating marks
  for (int i = 0; i < num_students; i++) {
    int marks_obtained = 0;
    for (int j = 0; j < num_questions; j++) {
      if (answers[j] == student_ans[i][j]) {
        marks_obtained++;
      }
    }
    marks[i] = marks_obtained;
  }

  // Printing student details and marks
  printf("\n\n========================================\n");
  printf("       ONLINE EXAMINATION RESULTS       \n");
  printf("========================================\n");
  for (int i = 0; i < num_students; i++) {
    printf("\nStudent %d: %s\n", i+1, student_names[i]);
    printf("Marks obtained: %d", marks[i]);
  }
  
  return 0;
}