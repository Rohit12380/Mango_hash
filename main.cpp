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
#include <string>
using namespace std;

const int N = 20;
const int M = 23;

struct Mango { int key; string name; };

int keys[N] = {20,33,46,59,72,85,98,11,24,37,50,63,76,89,2,15,28,41,54,67};
string names[N] = {"Alphonso","Kesar","Dasheri","Langra","Chausa","Totapuri","Banganapalli",
    "Neelam","Mallika","Amrapali","Himsagar","Raspuri","Safeda","Fazli","Badami",
    "Malgova","Rajapuri","Sindhura","Mankurad","Pairi"};

Mango table[M];                    // key == -1 means empty

int hashFn(int key) { return key % M; }

bool insertKey(int key, string name) {
    int idx = hashFn(key);
    for (int step = 0; step < M; step++) {
        int pos = (idx + step) % M;
        if (table[pos].key == -1) { table[pos] = {key, name}; return true; }
    }
    return false;
}

void display() {
    cout << "\nFINAL HASH TABLE (M = " << M << ")\n";
    for (int i = 0; i < M; i++) {
        cout << i << " : ";
        if (table[i].key == -1) cout << "Empty";
        else cout << table[i].key << " (" << table[i].name << ")";
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < M; i++) table[i] = {-1, ""};
    for (int i = 0; i < N; i++) insertKey(keys[i], names[i]);
    display();
    return 0;
}