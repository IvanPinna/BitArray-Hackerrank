#include <iostream>

using namespace std;

int main() {
    int n, s, p, q;
    cin >> n >> s >> p >> q;

    const int MOD = 2147483648;  // 2^31

    // Initial values for tortoise and hare
    int tortoise = s % MOD;
    int hare = s % MOD;

    // Step 1: Tortoise moves one step and hare moves two steps
    for (int i = 1; i < n; ++i) {
        tortoise = (tortoise * 1LL * p + q) % MOD;
        hare = (hare * 1LL * p + q) % MOD;
        hare = (hare * 1LL * p + q) % MOD;

        if (tortoise == hare) {
            // If they meet, we have found a cycle
            break;
        }
    }

    // Step 2: Count the distinct elements
    int count = 1;  // The initial element is always counted
    int current = s % MOD;
    for (int i = 1; i < n; ++i) {
        current = (current * 1LL * p + q) % MOD;
        if (current == tortoise) {
            break;
        }
        count++;
    }

    cout << count << endl;

    return 0;
}