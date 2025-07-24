//FormAI DATASET v1.0 Category: Online Examination System ; Style: mathematical
#include<stdio.h>

int main() {
   int n, i, j, mark = 0, total, ans[50][10];

   printf("Enter the number of students: ");
   scanf("%d", &n);

   printf("Enter the number of questions: ");
   scanf("%d", &total);

   for(i = 0; i < n; i++) {
      printf("Enter answers of student %d: ", i + 1);
      for(j = 0; j < total; j++) {
         scanf("%d", &ans[i][j]);
      }
   }

   printf("\n");

   for(i = 0; i < n; i++) {
      mark = 0;
      printf("Marks of student %d: ", i + 1);
      for(j = 0; j < total; j++) {
         if(ans[i][j] == 1) {
            mark++;
         }
      }
      printf("%d\n", mark);
   }

   return 0;
}