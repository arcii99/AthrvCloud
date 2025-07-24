//FormAI DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of questions
#define MAX_QUESTIONS 20 

// Define the question structure
typedef struct {
  char question[256];
  char options[4][128];
  int correct_option;
} question_t;

// Define the student structure
typedef struct {
  char name[128];
  int score;
} student_t;

// Define the exam structure
typedef struct {
  char exam_name[128];
  int num_questions;
  question_t questions[MAX_QUESTIONS];
  int num_students;
  student_t students[MAX_STUDENTS];
} exam_t;

// Function to display the exam menu
void display_menu(exam_t *exam) {
  printf("\n");
  printf("Welcome to the %s Exam System\n", exam->exam_name);
  printf("-----------------------------\n");
  printf("1. Add Question\n");
  printf("2. View Questions\n");
  printf("3. Modify Question\n");
  printf("4. Remove Question\n");
  printf("5. Start Exam\n");
  printf("6. Exit\n");
  printf("-----------------------------\n");
  printf("Enter choice: ");
}

// Function to add a question to the exam
void add_question(exam_t *exam) {
  if (exam->num_questions >= MAX_QUESTIONS) {
    printf("Sorry, maximum number of questions reached.\n");
    return;
  }

  question_t question;
  printf("Enter question: ");
  fgets(question.question, 256, stdin);

  for (int i = 0; i < 4; i++) {
    printf("Enter option #%d: ", i + 1);
    fgets(question.options[i], 128, stdin);
  }

  printf("Enter correct option (1-4): ");
  scanf("%d", &question.correct_option);
  getchar();

  exam->questions[exam->num_questions] = question;
  exam->num_questions++;

  printf("Question added successfully.\n");
}

// Function to view all questions in the exam
void view_questions(exam_t *exam) {
  printf("\n");
  printf("Questions in the %s Exam\n", exam->exam_name);
  printf("-----------------------------\n");

  for (int i = 0; i < exam->num_questions; i++) {
    printf("%d. %s\n", i + 1, exam->questions[i].question);
    printf("   1. %s\n", exam->questions[i].options[0]);
    printf("   2. %s\n", exam->questions[i].options[1]);
    printf("   3. %s\n", exam->questions[i].options[2]);
    printf("   4. %s\n", exam->questions[i].options[3]);
    printf("   Correct Option: %d\n", exam->questions[i].correct_option);
  }
}

// Function to modify a question in the exam
void modify_question(exam_t *exam) {
  int question_num;

  printf("Enter question number to modify: ");
  scanf("%d", &question_num);
  getchar();

  if (question_num < 1 || question_num > exam->num_questions) {
    printf("Invalid question number.\n");
    return;
  }

  printf("Enter new question: ");
  fgets(exam->questions[question_num - 1].question, 256, stdin);

  for (int i = 0; i < 4; i++) {
    printf("Enter new option #%d: ", i + 1);
    fgets(exam->questions[question_num - 1].options[i], 128, stdin);
  }

  printf("Enter new correct option (1-4): ");
  scanf("%d", &exam->questions[question_num - 1].correct_option);
  getchar();

  printf("Question modified successfully.\n");
}

// Function to remove a question from the exam
void remove_question(exam_t *exam) {
  int question_num;

  printf("Enter question number to remove: ");
  scanf("%d", &question_num);
  getchar();

  if (question_num < 1 || question_num > exam->num_questions) {
    printf("Invalid question number.\n");
    return;
  }

  for (int i = question_num - 1; i < exam->num_questions - 1; i++) {
    exam->questions[i] = exam->questions[i + 1];
  }

  exam->num_questions--;

  printf("Question removed successfully.\n");
}

// Function to start the exam
void start_exam(exam_t *exam) {
  int num_students;

  printf("Enter number of students taking the exam: ");
  scanf("%d", &num_students);
  getchar();

  if (num_students < 1 || num_students > MAX_STUDENTS) {
    printf("Invalid number of students.\n");
    return;
  }

  exam->num_students = num_students;

  for (int i = 0; i < exam->num_students; i++) {
    student_t student;
    printf("Enter name of student #%d: ", i + 1);
    fgets(student.name, 128, stdin);
    exam->students[i] = student;
  }

  // Start the exam for each student
  for (int i = 0; i < exam->num_students; i++) {
    printf("Starting exam for %s...\n", exam->students[i].name);
    exam->students[i].score = 0;

    for (int j = 0; j < exam->num_questions; j++) {
      printf("%d. %s\n", j + 1, exam->questions[j].question);
      printf("   1. %s\n", exam->questions[j].options[0]);
      printf("   2. %s\n", exam->questions[j].options[1]);
      printf("   3. %s\n", exam->questions[j].options[2]);
      printf("   4. %s\n", exam->questions[j].options[3]);

      int chosen_option;
      printf("Enter chosen option (1-4): ");
      scanf("%d", &chosen_option);
      getchar();

      if (chosen_option == exam->questions[j].correct_option) {
        exam->students[i].score++;
        printf("Correct answer!\n");
      } else {
        printf("Incorrect answer!\n");
      }
    }

    printf("Exam for %s complete. Score: %d/%d\n", exam->students[i].name, exam->students[i].score, exam->num_questions);
  }
}

int main() {
  exam_t exam;
  strcpy(exam.exam_name, "C programming");

  int choice;
  do {
    display_menu(&exam);
    scanf("%d", &choice);
    getchar();

    switch (choice) {
      case 1:
        add_question(&exam);
        break;
      case 2:
        view_questions(&exam);
        break;
      case 3:
        modify_question(&exam);
        break;
      case 4:
        remove_question(&exam);
        break;
      case 5:
        start_exam(&exam);
        break;
      case 6:
        printf("Exiting exam system...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }

  } while (choice != 6);
  
  return 0;
}