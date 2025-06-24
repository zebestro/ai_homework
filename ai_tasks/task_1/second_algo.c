#include <stdint.h>
#include <stdio.h>

void swap(uint16_t* a, uint16_t* b) {
    uint16_t t = *a;
    *a = *b;
    *b = t;
}

uint16_t median9(const uint16_t* p) {
    uint16_t v[9];
    for (int i = 0; i < 9; ++i) v[i] = p[i];

    for (int i = 0; i <= 4; ++i) {
        int min = i;
        for (int j = i + 1; j < 9; ++j) {
            if (v[j] < v[min]) min = j;
        }
        swap(&v[i], &v[min]);
    }
    return v[4];
}

int main() {
    uint16_t arr[] = {9, 2, 6, 1, 7, 3, 4, 8, 5};

    printf("Median: %d", median9(arr));
}

