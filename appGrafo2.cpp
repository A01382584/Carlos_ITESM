#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class GrafoDirigido {
    int n; // numero de vertices
    list<int> *adj; // lista de adyacencia

    bool tieneCiclosUtil(int v, vector<bool> &visitado, vector<bool> &enRecorrido);
    void topologicalSortUtil(int v, vector<bool> &visitado, stack<int> &pila);

public:
    GrafoDirigido(int n);
    void agregarArco(int u, int v);
    bool tieneCiclos();
    void topologicalSort();
};

GrafoDirigido::GrafoDirigido(int n) {
    this->n = n;
    adj = new list<int>[n];
}

void GrafoDirigido::agregarArco(int u, int v) {
    adj[u].push_back(v);
}

bool GrafoDirigido::tieneCiclosUtil(int v, vector<bool> &visitado, vector<bool> &enRecorrido) {
    visitado[v] = true;
    enRecorrido[v] = true;

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visitado[*it] && tieneCiclosUtil(*it, visitado, enRecorrido))
            return true;
        else if (enRecorrido[*it])
            return true;
    }

    enRecorrido[v] = false;
    return false;
}

bool GrafoDirigido::tieneCiclos() {
    vector<bool> visitado(n, false);
    vector<bool> enRecorrido(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visitado[i]) {
            if (tieneCiclosUtil(i, visitado, enRecorrido))
                return true;
        }
    }

    return false;
}

void GrafoDirigido::topologicalSortUtil(int v, vector<bool> &visitado, stack<int> &pila) {
    visitado[v] = true;

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visitado[*it])
            topologicalSortUtil(*it, visitado, pila);
    }

    pila.push(v);
}

void GrafoDirigido::topologicalSort() {
    stack<int> pila;
    vector<bool> visitado(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visitado[i])
            topologicalSortUtil(i, visitado, pila);
    }

    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
}

int main() {
    int n, m;
    cout << "Introduzca el numero de vertices: ";
    cin >> n;
    cout << "Introduzca el numero de arcos: ";
    cin >> m;

    GrafoDirigido grafo(n);

    cout << "Introduzca los arcos (por favor pongalos separados por espacios ej. 0 1):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        grafo.agregarArco(u, v);
    }

    cout << "El grafo ";
    if (grafo.tieneCiclos())
        cout << "tiene ciclos.\n";
    else {
        cout << "no tiene ciclos.\nEl orden topologico es: ";
        grafo.topologicalSort();
        cout << endl;
    }

    return 0;
}
