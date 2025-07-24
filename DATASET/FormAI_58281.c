//FormAI DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>

int main() {

  // The game is afoot!

  int initial_amount = 100;
  float interest_rate = 0.03;
  int number_of_years = 5;
  int final_amount;

  // Let's begin by deducing the final amount after 5 years of investment

  final_amount = initial_amount * (1 + interest_rate) * number_of_years;

  // Ah, but there is more to this case than meets the eye

  printf("After %d years, your investment will grow to $%d\n", number_of_years, final_amount);

  // But what if we wanted to know the total amount of interest earned over time?

  float total_interest = (final_amount - initial_amount) / (float)initial_amount;

  printf("Your total interest over %d years will be %.2f percent\n", number_of_years, total_interest * 100);

  // However, the plot thickens as we investigate the impact of different interest rates

  printf("What would be the final amount after %d years if the interest is different?\n", number_of_years);

  // Holmes' gaze narrows as he concentrates on the problem at hand

  float new_interest_rates[] = {0.04, 0.05, 0.06};
  int i;

  for (i = 0; i < 3; i++) {
    final_amount = initial_amount * (1 + new_interest_rates[i]) * number_of_years;
    printf("With an interest rate of %.2f percent, your final amount after %d years will be $%d\n", new_interest_rates[i] * 100, number_of_years, final_amount);
  }

  // The game is now afoot!

  return 0;
}