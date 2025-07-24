//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
#include <stdio.h>
#include <string.h>
  
int min(int x, int y, int z) {
   if(x<y && x<z) {
      return x;
   } else if(y<x && y<z) {
      return y;
   } else {
      return z;
   }
}
  
int levenshteinDistance(char *str1, int len1, char *str2, int len2) {
    if (len1 == 0)
        return len2;
  
    if (len2 == 0)
        return len1;
  
    if (str1[len1-1] == str2[len2-1])
        return levenshteinDistance(str1, len1-1, str2, len2-1);
  
    return 1 + min( levenshteinDistance(str1, len1, str2, len2-1),
                     levenshteinDistance(str1, len1-1, str2, len2),
                     levenshteinDistance(str1, len1-1, str2, len2-1)
                   );
}
  
int main() {
    char str1[30], str2[30];
    int len1, len2;
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    printf("Levenshtein distance between %s and %s is %d.\n", str1, str2, levenshteinDistance(str1, len1, str2, len2));
    return 0;
}