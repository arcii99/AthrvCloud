//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Linus Torvalds
/*
 * greedy.c - A program that uses a greedy algorithm to determine the minimum number
 * of coins needed to make change for an amount of money.
 *
 * Copyright (C) 2021 [Your Name]
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int coins[] = {25, 10, 5, 1}; // Available coin denominations
    int num_coins = sizeof(coins) / sizeof(int); // Number of coin denominations
    int total = atoi(argv[1]); // Total amount of money to make change for
    int min_coins[num_coins]; // Minimum number of coins needed for each denomination
    int i, j, num_coins_needed = 0;

    for (i = 0; i < num_coins; i++) {
        min_coins[i] = total / coins[i];
        total -= min_coins[i] * coins[i];
        num_coins_needed += min_coins[i];
    }

    printf("Number of Coins Needed: %d\n", num_coins_needed);
    printf("Coin Breakdown:\n");

    for (i = 0; i < num_coins; i++) {
        if (min_coins[i] > 0) {
            printf("%d x %d cents\n", min_coins[i], coins[i]);
        }
    }

    return 0;
}