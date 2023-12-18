#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string getIPWithoutPort(const string& ipWithPort) {
    size_t colonPos = ipWithPort.find(':');
    if (colonPos != string::npos) {
        return ipWithPort.substr(0, colonPos);
    }
    return ipWithPort;
}

class Graph {
private:
    unordered_map<string, int> ipToNode;  // Mapeo de IP a nodo
    vector<unordered_set<int>> adjacencyList;

public:
    void addEdge(int u, int v) {
        adjacencyList[u].insert(v);
        adjacencyList[v].insert(u);
    }

    int getNode(const string& ip) {
        if (ipToNode.find(ip) == ipToNode.end()) {
            int newNode = ipToNode.size();
            ipToNode[ip] = newNode;
            adjacencyList.push_back({});
        }
        return ipToNode[ip];
    }

    void printGraph() {
        for (const auto& entry : ipToNode) {
            const string& ip = entry.first;
            int node = entry.second;

            cout << "\nNode: " << ip << endl;
            cout << "Connections: ";
            for (const auto& neighbor : adjacencyList[node]) {
                const string& neighborIp = getNodeIP(neighbor);
                cout << neighborIp << " ";
            }
            cout << endl;
        }
    }

    void detectarBots() {
        vector<pair<string, int>> nodeConnections;

        for (const auto& entry : ipToNode) {
            const string& ip = entry.first;
            int node = entry.second;
            int connections = adjacencyList[node].size();

            nodeConnections.emplace_back(ip, connections);
        }

        sort(nodeConnections.begin(), nodeConnections.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });

        cout << "\nTop 10 nodos con mayor numero de conexiones:" << endl;
        int count = min(10, static_cast<int>(nodeConnections.size()));
        for (int i = 0; i < count; ++i) {
            const auto& nodeConn = nodeConnections[i];
            cout << "Node: " << nodeConn.first << ", Connections: " << nodeConn.second << endl;
        }
    }

private:
    string getNodeIP(int node) {
        for (const auto& entry : ipToNode) {
            if (entry.second == node) {
                return entry.first;
            }
        }
        return "";
    }
};

int main() {
    string filename = "datos.txt";  // Nombre del archivo de datos
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    Graph graph;

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string month, day, time, srcIp, dstIp, ignore;
        iss >> month >> day >> time >> srcIp >> dstIp;
        getline(iss, ignore);  // Ignorar el resto de la línea

        // Obtener los nodos correspondientes a las IPs
        int srcNode = graph.getNode(getIPWithoutPort(srcIp));
        int dstNode = graph.getNode(getIPWithoutPort(dstIp));

        // Agregar las aristas al grafo
        graph.addEdge(srcNode, dstNode);
    }

    file.close();

    // Imprimir el grafo
    graph.printGraph();

    // Detectar los 5 nodos con más conexiones
    graph.detectarBots();

    return 0;
}
