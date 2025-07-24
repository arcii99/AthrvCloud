//FormAI DATASET v1.0 Category: System boot optimizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define BOOT_TIME_MAX_LIMIT 300
#define BOOT_TIME_CRITICAL_LIMIT 60

typedef struct {
    uint32_t boot_time;
    bool system_optimized;
} system_state;

void print_boot_time(uint32_t time) {
    printf("Boot time: %02d:%02d\n", (time / 60), (time % 60));
}

void optimize_system() {
    printf("Optimizing system...\n");
    // insert code to optimize system here
}

void save_system_state(system_state current_state) {
    FILE* fp;
    fp = fopen("system_state.dat", "wb");
    if (fp != NULL) {
        fwrite(&current_state, sizeof(current_state), 1, fp);
        fclose(fp);
    }
}

system_state load_system_state() {
    system_state state;
    FILE* fp;
    fp = fopen("system_state.dat", "rb");
    if (fp != NULL) {
        fread(&state, sizeof(state), 1, fp);
        fclose(fp);
    }
    return state;
}

int main() {
    system_state current_state = load_system_state();
    uint32_t boot_time = time(NULL);

    if (current_state.boot_time == 0) {
        current_state.boot_time = boot_time;
        save_system_state(current_state);
    } else {
        boot_time -= current_state.boot_time;
    }

    print_boot_time(boot_time);

    if (boot_time > BOOT_TIME_MAX_LIMIT) {
        optimize_system();
        current_state.system_optimized = true;
        save_system_state(current_state);
    } else if (boot_time <= BOOT_TIME_CRITICAL_LIMIT) {
        printf("Warning: System is running slow...\n");
    } else {
        printf("System is running efficiently...\n");
    }

    return 0;
}