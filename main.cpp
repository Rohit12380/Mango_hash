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
int table[M];

int hashFn(int key) { return key % M; }

// FIRST ATTEMPT: no collision handling
void insertKey(int key) {
    table[hashFn(key)] = key;      // simply overwrite whatever is there
}

int main() {
    for (int i = 0; i < M; i++) table[i] = -1;
    for (int i = 0; i < N; i++) insertKey(keys[i]);

    int stored = 0;
    for (int i = 0; i < M; i++) if (table[i] != -1) stored++;
    cout << "Inserted: " << N << "  Stored: " << stored << endl;
    return 0;
}