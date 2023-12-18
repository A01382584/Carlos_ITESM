#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>



struct LogEntry {
    std::string month;
    int day;
    std::string time;
    std::string ip;
    std::string message;
};

std::string extractIP(std::string ipWithPort) {
    std::string delimiter = ":";
    size_t pos = ipWithPort.find(delimiter);
    if (pos != std::string::npos) {
        return ipWithPort.substr(0, pos);
    }
    return ipWithPort;
}

void printLogEntry(const LogEntry& entry) {
    std::cout << "Fecha: " << entry.month << " " << entry.day << std::endl;
    std::cout << "Hora: " << entry.time << std::endl;
    std::cout << "IP: " << entry.ip << std::endl;
    std::cout << "Mensaje: " << entry.message << std::endl;
    std::cout << std::endl;
}

void searchByIP(const std::unordered_map<std::string, std::vector<LogEntry>>& logTable, const std::string& ip) {
    std::string searchIP = extractIP(ip);

    auto it = logTable.find(searchIP);
    if (it != logTable.end()) {
        const std::vector<LogEntry>& entries = it->second;
        for (const LogEntry& entry : entries) {
            printLogEntry(entry);
        }
    } else {
        std::cout << "No se encontraron registros para la direccion IP especificada." << std::endl;
    }
}

int main() {
    std::ifstream file("bitacora_3-1.txt");

    std::unordered_map<std::string, std::vector<LogEntry>> logTable;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        LogEntry entry;
        iss >> entry.month >> entry.day >> entry.time >> entry.ip;
        entry.ip = extractIP(entry.ip);

        std::string message;
        std::getline(iss, message);
        entry.message = message.substr(1);

        logTable[entry.ip].push_back(entry);
    }

    file.close();

    std::string searchIP;
    int choice = 1;
    while (choice != 0) {
        std::cout << "Ingrese la direccion IP que desea buscar (o 0 para salir): ";
        std::cin >> searchIP;
        std::cout << "\n";

        if (searchIP == "0") {
            choice = 0;
        } else {
            searchByIP(logTable, searchIP);
        }
    }

    return 0;
}
