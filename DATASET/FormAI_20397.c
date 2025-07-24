//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>

void convert(float temp_celsius) {
    float temp_fahrenheit = (temp_celsius * 9 / 5) + 32;
    printf("%.2f°C is equivalent to %.2f°F\n", temp_celsius, temp_fahrenheit);
}

int main() {
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    for (int i = 1; i <= num_players; i++) {
        float temp_celsius;
        printf("Player %d, enter temperature in Celsius: ", i);
        scanf("%f", &temp_celsius);

        convert(temp_celsius);
    }

    return 0;
}