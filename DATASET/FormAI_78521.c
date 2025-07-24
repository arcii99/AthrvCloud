//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Romeo and Juliet
// Scene 1: Introduction
#include <stdio.h>

int main() {
   printf("Enter the number of Wi-Fi signal strengths to analyze: ");
   int numSignals;
   scanf("%d", &numSignals);
   int signalStrengths[numSignals];
   printf("Enter the signal strengths:\n");
   for (int i = 0; i < numSignals; i++) {
      scanf("%d", &signalStrengths[i]);
   }
   printf("\n");
   
   // Scene 2: Analysis
   printf("The analyzed signal strengths are as follows:\n");
   for (int i = 0; i < numSignals; i++) {
      printf("%d ", signalStrengths[i]);
   }
   printf("\n");
   int avgStrength = 0;
   for (int i = 0; i < numSignals; i++) {
      avgStrength += signalStrengths[i];
   }
   avgStrength /= numSignals;
   printf("The average signal strength is: %d\n", avgStrength);
   
   // Scene 3: Confrontation
   if (avgStrength < 30) {
      printf("Romeo: Alas! This signal strength is weaker than my love for Juliet!\n");
      printf("Juliet: Oh Romeo, fear not! Our love is stronger than any signal!\n");
   } else if (avgStrength >= 30 && avgStrength < 60) {
      printf("Romeo: This signal strength is moderate, much like our love.\n");
      printf("Juliet: Nay, Romeo! Our love is stronger than any signal!\n");
   } else {
      printf("Romeo: Rejoice! This signal strength is stronger than our love!\n");
      printf("Juliet: How dare you, Romeo! Our love is the strongest of all!\n");
   }
   
   // Scene 4: Conclusion
   printf("Farewell, dear children of Verona!\n");
   return 0;
}