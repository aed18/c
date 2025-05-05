#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

class trio {
public:
    int a, b, c;
    trio(int aa = 0, int bb = 0, int cc = 0) {
        a = aa;
        b = bb;
        c = cc;
    }
};

int main() {
    int t;
    cin >> t;
    string dummy;
    getline(cin, dummy); // consumir \n después del número de casos
    getline(cin, dummy); // línea en blanco entre t y el primer caso

    vector<trio> answer;

    for (int caso = 0; caso < t; ++caso) {
        map<int, map<int, int>> intentos_incorrectos;
        map<int, map<int, bool>> resuelto;
        map<int, int> problemas_resueltos, penalidad;
        set<int> participantes;

        int id, problema, tiempo;
        char estado;

        while (true) {
            string linea;
            getline(cin, linea);
            if (linea.empty()) break;

            istringstream ss(linea);
            ss >> id >> problema >> tiempo >> estado;

            participantes.insert(id);

            if (estado == 'C') {
                if (!resuelto[id][problema]) {
                    resuelto[id][problema] = true;
                    problemas_resueltos[id]++;
                    penalidad[id] += tiempo + 20 * intentos_incorrectos[id][problema];
                }
            }
            else if (estado == 'I') {
                if (!resuelto[id][problema])
                    intentos_incorrectos[id][problema]++;
            }
            // R, U, E no afectan el resultado
        }

        vector<trio> resultados;
        for (int id : participantes)
            resultados.push_back(trio(id, problemas_resueltos[id], penalidad[id]));

        sort(resultados.begin(), resultados.end(), [](const trio& a, const trio& b) {
            if (a.b != b.b) return a.b > b.b;
            if (a.c != b.c) return a.c < b.c;
            return a.a < b.a;
            });

        for (auto r : resultados) answer.push_back(r);
        if (caso < t - 1) answer.push_back(trio(-1, -1, -1));
    }

    for (auto ans : answer) {
        if (ans.a == -1) cout << endl;
        else cout << ans.a << " " << ans.b << " " << ans.c << endl;
    }

    return 0;
}
