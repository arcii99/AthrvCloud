//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
// Romeo: Good morrow, fair Juliet. Pray tell, have you heard the latest news in the stock market?
// Juliet: Why, yes, good sir Romeo. I have been keeping track of the stocks for the past fortnight.
// Romeo: Excellent news, fair maiden. Wouldst thou care to share thy knowledge with me?
// Juliet: Of course, my dear Romeo. Let me bring up my stock market tracker program that I have coded myself.

#include <stdio.h>
#include <stdlib.h>

int main() {
  double apple = 148.99;
  double google = 2352.88;
  double tesla = 715.46;
  double microsoft = 305.84;

  printf("Fair Juliet's Stock Market Tracker\n\n");
  printf("Current Value of Apple: $%.2f\n", apple);
  printf("Current Value of Google: $%.2f\n", google);
  printf("Current Value of Tesla: $%.2f\n", tesla);
  printf("Current Value of Microsoft: $%.2f\n", microsoft);

  // Let us now calculate the total investment made by Romeo in the aforementioned companies

  printf("\nEnter thy investment amount for Apple: ");
  double apple_investment;
  scanf("%lf", &apple_investment);

  printf("\nEnter thy investment amount for Google: ");
  double google_investment;
  scanf("%lf", &google_investment);

  printf("\nEnter thy investment amount for Tesla: ");
  double tesla_investment;
  scanf("%lf", &tesla_investment);

  printf("\nEnter thy investment amount for Microsoft: ");
  double microsoft_investment;
  scanf("%lf", &microsoft_investment);

  double total_investment = apple_investment + google_investment + tesla_investment + microsoft_investment;
  printf("\nTotal Investment Made: $%.2f\n", total_investment);
  
  // Romeo is quite pleased with the results and thanks Juliet for her knowledgeable insights.
  printf("\nRomeo: Thou art truly a genius, fair Juliet. Thy programming skills are unparalleled. Fare thee well!\n");
  printf("Juliet: 'Tis nothing, my dear Romeo. I am but a humble programmer. Until we meet again!\n");

  return 0;
}