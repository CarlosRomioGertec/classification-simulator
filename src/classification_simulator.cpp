#include "services/simulator/simulator.h"
#include "reporting/metrics_reporter.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

static std::vector<double> loadWeightsFromCSV(const std::string& path) {
    std::vector<double> weights;

    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir CSV");
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        try {
            double value = std::stod(line);
            weights.push_back(value);
        }
        catch (...) {
            // ignora linhas inválidas
        }
    }

    return weights;
}

int main()
{

    //teste
	// ==========================
    //ClassificationConfig config;

    //config.small_max = 199;

    //config.closed_ranges = {
    //    {200, 220},
    //    {221, 240},
    //    {241, 260},
    //    {261, 280},
    //    {281, 300}
    //};

    //config.large_min = 301;

    auto weights = loadWeightsFromCSV("weights.csv");

    int small = 0;
    int closed = 0;
    int open = 0;

    std::cout << "\n--- Distribuição ---\n";
    std::cout << "Small: " << small << "\n";
    std::cout << "Closed: " << closed << "\n";
    std::cout << "Open: " << open << "\n";

    return 0;
}
