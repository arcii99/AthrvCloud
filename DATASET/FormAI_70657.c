//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include <stdio.h>

int main()
{
  int num_flavors = 10;
  int num_scoops = 3;
  int scoops_per_person = 2;
  int total_people = 5;
  int flavor_ratings[10] = {5, 2, 8, 9, 1, 6, 4, 10, 3, 7};

  int flavors_chosen[num_scoops];
  int num_people_served = 0;

  printf("Welcome to the greedy ice cream shop!\n");

  int i, j, max_val, max_index;
  for (i = 0; i < num_scoops * total_people; i++)
  {
    max_val = -1;
    for (j = 0; j < num_flavors; j++)
    {
      if (flavor_ratings[j] > max_val)
      {
        max_val = flavor_ratings[j];
        max_index = j;
      }
    }

    flavors_chosen[i % num_scoops] = max_index;
    flavor_ratings[max_index] = -1;

    if ((i + 1) % num_scoops == 0)
    {
      printf("Scoops for customers %d-%d: ", num_people_served + 1, num_people_served + scoops_per_person);
      for (j = 0; j < num_scoops; j++)
      {
        printf("%d ", flavors_chosen[j]);
      }
      printf("\n");

      num_people_served += scoops_per_person;
      if (num_people_served >= total_people)
      {
        break;
      }
    }
  }

  return 0;
}