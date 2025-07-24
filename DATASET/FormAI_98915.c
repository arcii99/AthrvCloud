//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
// RAM usage monitor in shape shifting style

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char shapes[5] = {'C', 'R', 'A', 'M', '!'};
    int i = 0;
    while(1) {
        printf("\033[2J\033[1;1H");  // clear screen
        
        // Display RAM usage message in shape-shifting style
        printf("RAM Usage Monitor: ");
        for (int j=0; j < 5; j++) {
            if (j == i) {
                printf("\033[1m\033[31m%c\033[0m", shapes[j]);  // highlight current shape in red
            } else {
                printf("%c", shapes[j]);  // print other shapes normally
            }
        }
        printf("\n");

        FILE* fp = popen("free | grep Mem | awk '{print $3/$2 * 100.0}'", "r");  // execute free command and get RAM usage percentage
        float ram_usage;
        fscanf(fp, "%f", &ram_usage);
        pclose(fp);

        // Display RAM usage percentage with color coding
        if (ram_usage < 50) {
            printf("\033[0;32m%.2f%%\033[0m", ram_usage);
        } else if (ram_usage < 75) {
            printf("\033[1;33m%.2f%%\033[0m", ram_usage);
        } else {
            printf("\033[1;31m%.2f%%\033[0m", ram_usage);
        }

        // Shape-shifting animation
        if (++i >= 5) {
            i = 0;
        }
        usleep(500000);  // wait for 500ms
    }
    return 0;
}