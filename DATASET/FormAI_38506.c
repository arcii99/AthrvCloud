//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>

// function to find minimum of three numbers
int minimum(int a, int b, int c) {
   int min = a;
   if(min > b) min = b;
   if(min > c) min = c;
   return min;
}

// function to calculate Levenshtein distance
int levenshtein_distance(char *str1, char *str2) {
   int len1 = strlen(str1);
   int len2 = strlen(str2);
   int i, j, cost;
   int arr[len1 + 1][len2 + 1];

   // initializing value of 1st row and column of the matrix
   for(i = 0; i <= len1; i++) arr[i][0] = i;
   for(j = 0; j <= len2; j++) arr[0][j] = j;

   // filling up the entire matrix using dynamic programming approach
   for(i = 1; i <= len1; i++) {
      for(j = 1; j <= len2; j++) {
         if(str1[i - 1] == str2[j - 1]) cost = 0;
         else cost = 1;
         arr[i][j] = minimum(arr[i - 1][j] + 1, arr[i][j - 1] + 1, arr[i - 1][j - 1] + cost);
      }
   }

   // returning the last element of the matrix, which is the minimum edit distance
   return arr[len1][len2];
}

int main() {
   char str1[] = "Romeo";
   char str2[] = "Juliet";
   int distance = levenshtein_distance(str1, str2);

   printf("Romeo: Oh Juliet, my love for thee knows no bounds! \n");
   printf("Juliet: My dear Romeo, what troubles you so much? \n");
   printf("Romeo: The Levenshtein distance between our names is %d. \n", distance);
   printf("Juliet: Levenshtein distance? What is that? \n");
   printf("Romeo: It is the number of changes required to convert one string to another. \n");
   printf("Juliet: I see. And what is the Levenshtein distance between our names? \n");
   printf("Romeo: Our names are '%s' and '%s', and the distance is %d. \n", str1, str2, distance);
   printf("Juliet: %d? That seems quite large. Is there any way to reduce it? \n", distance);
   printf("Romeo: We could change our names, my love. But I would rather die than be without you. \n");
   printf("Juliet: Oh Romeo, you are a true romantic. Let us keep our names as they are and be together forever. \n");

   return 0;
}