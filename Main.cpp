
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;

// PROBLEMA 1: ESCALERAS
void escaleras() {
    int N;

    cout << "\n--- PROBLEMA 1: ESCALERAS ---" << endl;
    cout << "Ingrese el numero de escalones: ";
    cin >> N;

    if (N < 0 || N > 91) {
        cout << "Ingrese un valor entre 0 y 91." << endl;
        return;
    }

    long long dp[92];

    dp[0] = 1;

    if (N >= 1) {
        dp[1] = 1;
    }

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "\nFormas posibles: " << dp[N] << endl;

    cout << "Tabla DP:" << endl;
    cout << "[";

    for (int i = 0; i <= N; i++) {
        cout << dp[i];

        if (i < N) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

// PROBLEMA 2: CAMBIO MINIMO DE MONEDAS
void cambioMonedas() {
    int M, cantidad;

    cout << "\n--- PROBLEMA 2: CAMBIO MINIMO DE MONEDAS ---" << endl;

    cout << "Ingrese la cantidad de denominaciones: ";
    cin >> M;

    if (M <= 0 || M > 100) {
        cout << "Cantidad de denominaciones invalida." << endl;
        return;
    }

    vector<int> monedas(M);

    for (int i = 0; i < M; i++) {
        cout << "Ingrese la moneda " << i + 1 << ": ";
        cin >> monedas[i];

        if (monedas[i] <= 0) {
            cout << "Las denominaciones deben ser positivas." << endl;
            return;
        }
    }

    cout << "Ingrese la cantidad objetivo: ";
    cin >> cantidad;

    if (cantidad < 0 || cantidad > 100000) {
        cout << "Cantidad objetivo invalida." << endl;
        return;
    }

    vector<int> dp(cantidad + 1, INF);
    vector<int> monedaUsada(cantidad + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= cantidad; i++) {

        for (int j = 0; j < M; j++) {
            int moneda = monedas[j];

            if (moneda <= i && dp[i - moneda] != INF) {
                int candidato = dp[i - moneda] + 1;

                if (candidato < dp[i]) {
                    dp[i] = candidato;
                    monedaUsada[i] = moneda;
                }
            }
        }
    }

    cout << "\nTabla DP:" << endl;
    cout << "[";

    for (int i = 0; i <= cantidad; i++) {
        if (dp[i] == INF) {
            cout << "INF";
        } else {
            cout << dp[i];
        }

        if (i < cantidad) {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    if (dp[cantidad] == INF) {
        cout << "No es posible formar la cantidad exacta." << endl;
        return;
    }

    cout << "Cantidad minima de monedas: "
         << dp[cantidad] << endl;

    cout << "Combinacion: ";

    int actual = cantidad;
    bool primero = true;

    while (actual > 0) {
        int moneda = monedaUsada[actual];

        if (!primero) {
            cout << " + ";
        }

        cout << moneda;

        primero = false;
        actual -= moneda;
    }

    cout << endl;
}

int main() {
    int opcion;

    do {
        cout << "\n=================================" << endl;
        cout << "     PROGRAMACION DINAMICA" << endl;
        cout << "=================================" << endl;
        cout << "1. Problema de escaleras" << endl;
        cout << "2. Cambio minimo de monedas" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                escaleras();
                break;

            case 2:
                cambioMonedas();
                break;

            case 3:
                cout << "Programa finalizado." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }

    } while (opcion != 3);

    return 0;
}
