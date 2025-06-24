#include <stdint.h>
#include <stdio.h>

#define SWAP(a, b) if ((a) > (b)) { uint16_t tmp = (a); (a) = (b); (b) = tmp; }

uint16_t median9(const uint16_t* p) {
    uint16_t v[9];
    for (int i = 0; i < 9; ++i) v[i] = p[i];

    SWAP(v[1], v[2]); SWAP(v[4], v[5]); SWAP(v[7], v[8]);
    SWAP(v[0], v[1]); SWAP(v[3], v[4]); SWAP(v[6], v[7]);
    SWAP(v[1], v[2]); SWAP(v[4], v[5]); SWAP(v[7], v[8]);
    SWAP(v[0], v[3]); SWAP(v[5], v[8]); SWAP(v[4], v[7]);
    SWAP(v[3], v[6]); SWAP(v[1], v[4]); SWAP(v[2], v[5]);
    SWAP(v[4], v[7]); SWAP(v[4], v[2]); SWAP(v[6], v[4]);
    SWAP(v[4], v[2]);

    return v[4];
}

int main() {
    uint16_t arr[] = {9, 2, 6, 1, 7, 3, 4, 8, 5};

    printf("Median: %d", median9(arr));
}

