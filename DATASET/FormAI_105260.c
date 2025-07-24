//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <sys/sysinfo.h>

int main() {

while(1) { // keep monitoring until user terminates the program

struct sysinfo s_info;
int err = sysinfo(&s_info);

if (err != 0) {
printf("Error getting system info.\n");
}

else {
long long total_ram = (long long)s_info.totalram * s_info.mem_unit;
long long free_ram = (long long)s_info.freeram * s_info.mem_unit;
long long used_ram = total_ram - free_ram;

printf("Total RAM: %lld MB\n", total_ram / (1024 * 1024));
printf("Used RAM: %lld MB\n", used_ram / (1024 * 1024));
printf("Free RAM: %lld MB\n\n", free_ram / (1024 * 1024));

// sleep for 1 second before rechecking RAM usage
sleep(1);
}
}

return 0;
}