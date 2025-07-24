//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    unsigned long size, resident, share, text, lib, data, dt;
} statm_t;

static void parse_statm(unsigned long *sm, statm_t *result) {
    if (!sm) return;
    result->size = *sm++, result->resident = *sm++, result->share = *sm++,
    result->text = *sm++, result->lib = *sm++, result->data = *sm++,
    result->dt = *sm++;
}

int get_mem_usage(unsigned long *vm_usage, unsigned long *resident_set) {
    static int page_size = 0;
    FILE *fp;
    char buf[500], *c, *cs;
    unsigned long size = 0, resident = 0, share = 0, text = 0, lib = 0,
        data = 0, dt = 0;

    if (page_size == 0) page_size = getpagesize();

    fp = fopen("/proc/self/statm", "r");
    if (fp == NULL) return -1;

    if (fgets(buf, sizeof(buf), fp) == NULL) {
        fclose(fp);
        return -1;
    }

    fclose(fp);

    c = buf;
    cs = strchr(c, ' ');

    if (!cs || (cs - c >= strlen(buf))) return -1;

    *cs++ = '\0';
    size = atol(c) * page_size;
    c = cs;

    cs = strchr(c, ' ');

    if (!cs || (cs - c >= strlen(buf))) return -1;

    *cs++ = '\0';
    resident = atol(c) * page_size;
    c = cs;

    cs = strchr(c, ' ');

    if (!cs || (cs - c >= strlen(buf))) return -1;

    *cs++ = '\0';
    share = atol(c) * page_size;
    c = cs;

    cs = strchr(c, ' ');

    if (!cs || (cs - c >= strlen(buf))) return -1;

    *cs++ = '\0';
    text = atol(c) * page_size;
    c = cs;

    cs = strchr(c, ' ');

    if (!cs || (cs - c >= strlen(buf))) return -1;

    *cs++ = '\0';
    lib = atol(c) * page_size;
    c = cs;

    cs = strchr(c, ' ');

    if (!cs || (cs - c >= strlen(buf))) return -1;

    *cs++ = '\0';
    data = atol(c) * page_size;
    c = cs;

    cs = strchr(c, ' ');

    if (!cs || (cs - c >= strlen(buf))) return -1;

    *cs++ = '\0';
    dt = atol(c) * page_size;

    if (vm_usage) *vm_usage = size;
    if (resident_set) *resident_set = resident;

    return 0;
}

int main() {

    unsigned long vm_usage, resident_set;

    while (1) {
        get_mem_usage(&vm_usage, &resident_set);
        printf("Memory usage: resident set size = %ldKB, virtual memory size = %ldKB\n", resident_set / 1024, vm_usage / 1024);
    }

    return 0;
}