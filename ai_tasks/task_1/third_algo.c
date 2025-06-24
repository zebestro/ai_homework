#include <stdint.h>
#include <stdio.h>

uint16_t median9(const uint16_t* p) {
    static uint16_t counts[4096] = {0};

    for (int i = 0; i < 4096; ++i) counts[i] = 0;

    for (int i = 0; i < 9; ++i) {
        counts[p[i]]++;
    }

    int total = 0;
    for (int i = 0; i < 4096; ++i) {
        total += counts[i];
        if (total >= 5) return i;
    }

    return 0;
}

int main() {
    uint16_t arr[] = {9, 2, 6, 1, 7, 3, 4, 8, 5};

    printf("Median: %d", median9(arr));
}

