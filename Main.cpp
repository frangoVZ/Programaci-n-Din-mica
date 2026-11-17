
#include <iostream>
using namespace std;

int main() {
    int N;
    // problema 1 
    cout << "Ingrese el numero de escalones: ";
    cin >> N;

    if (N < 0 || N > 91) {
        cout << "Ingrese un valor entre 0 y 91." << endl;
        return 0;
    }

    long long dp[92];

    dp[0] = 1;

    if (N >= 1) {
        dp[1] = 1;
    }

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Formas posibles: " << dp[N] << endl;

    cout << "Tabla DP:" << endl;
    cout << "[";

    for (int i = 0; i <= N; i++) {
        cout << dp[i];

        if (i < N) {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}
