//FormAI DATASET v1.0 Category: System boot optimizer ; Style: recursive
#include <stdio.h>

void optimize_boot(int boot_speed) {
	/* Base Case */
	if (boot_speed == 0) {
		return;
	}

	/* Recursive Case */
	else {
		printf("Boot optimization at speed %d...\n", boot_speed);
		optimize_boot(boot_speed - 10);
		printf("Boot optimization complete at speed %d.\n", boot_speed);
		return;
	}
}

int main() {
	int boot_speed = 100;
	printf("Initial boot speed: %d\n", boot_speed);

	/* Call optimize_boot recursively */
	optimize_boot(boot_speed);

	printf("Final boot speed: %d\n", boot_speed);
	return 0;
}