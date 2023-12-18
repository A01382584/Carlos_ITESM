#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Grafo {
    int numNodos;
    vector<vector<int>> listaAdyacencia;

public:
    Grafo(int nodos) {
        numNodos = nodos;
        listaAdyacencia.resize(numNodos);
    }

    void agregarArista(int origen, int destino) {
        listaAdyacencia[origen].push_back(destino);
        listaAdyacencia[destino].push_back(origen);
    }

    void imprimirGrafo() {
        for (int i = 0; i < numNodos; i++) {
            cout << "Nodo " << i << ": ";
            for (int j : listaAdyacencia[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    //Depth first search
    void DFS(int v, vector<bool>& visitado) {
        visitado[v] = true;
        cout << v << " ";

        for (int i : listaAdyacencia[v]) {
            if (!visitado[i]) {
                DFS(i, visitado);
            }
        }
    }

    //Breadth first search
    void BFS(int v) {
        vector<bool> visitado(numNodos, false);
        queue<int> cola;
        visitado[v] = true;
        cola.push(v);

        while (!cola.empty()) {
            int actual = cola.front();
            cola.pop();
            cout << actual << " ";

            for (int i : listaAdyacencia[actual]) {
                if (!visitado[i]) {
                    visitado[i] = true;
                    cola.push(i);
                }
            }
        }
    }
};

int main() {
    int numNodos = 5;
    Grafo grafo(numNodos);

    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 4);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(1, 4);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(3, 4);

    grafo.imprimirGrafo();

    cout << "Introduce un nodo para hacer las busquedas: ";
    int nodoBuscar;
    cin >> nodoBuscar;

    cout << "Recorrido DFS: ";
    vector<bool> visitadoDFS(numNodos, false);
    grafo.DFS(nodoBuscar, visitadoDFS);
    cout << endl;

    cout << "Recorrido BFS: ";
    grafo.BFS(nodoBuscar);
    cout << endl;

    return 0;
}
