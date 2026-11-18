/*
 * PRN      : 202501100120
 * Seed S   : 120
 * Scenario : Mango varieties (PRN mod 3 = 2)
 * Dataset  : v[i] = (120 + 13*i) mod 100, i = 0..19
 * Hash fn  : Division method, h(key) = key mod M   (PRN is even)
 * Collision: Linear probing                        (PRN mod 2 = 0)
 * Table M  : 23 (smallest prime >= 20 keys)
 */
#include <iostream>
using namespace std;

const int N = 20;
const int M = 23;

int keys[N] = {20,33,46,59,72,85,98,11,24,37,50,63,76,89,2,15,28,41,54,67};

int hashFn(int key) {
    return key % M;
}

int main() {
    for (int i = 0; i < N; i++)
        cout << keys[i] << " -> slot " << hashFn(keys[i]) << endl;
    return 0;
}