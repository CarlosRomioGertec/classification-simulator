#include <decision_engine/decision_engine.h>

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

static decision_engine::Program createTestProgram() {

    decision_engine::Program program;

    program.name = "Teste";
    program.program_id = 1;

    decision_engine::OperationProfile profile;

    profile.name = "Perfil A";
    profile.operation_profile_id = 1;

    profile.target_weight = 1000.0;

    profile.base_margin = 10.0;
    profile.max_margin = 30.0;

    profile.timeout_seconds = 10.0;

    profile.weight_range.minimum_weight = 100.0;
    profile.weight_range.maximum_weight = 500.0;

    profile.outputs_id = { 1, 2, 3 };

    profile.decision_strategy = decision_engine::DecisionStrategy::Greedy;

    program.operation_profiles.push_back(profile);

    return program;
}

static void testPiece(decision_engine::DecisionEngine& engine, double weight) {

    decision_engine::Piece piece;

    piece.weight = weight;

    auto output = engine.process(piece);

    if (output) {
        std::cout
            << weight
            << " g -> Output "
            << *output
            << '\n';
    } else {
        std::cout
            << weight
            << " g -> Rejeitada\n";
    }
}

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

    //auto weights = loadWeightsFromCSV("weights.csv");

    auto program = createTestProgram();

    decision_engine::DecisionEngine engine(program);

    testPiece(engine, 250);
    testPiece(engine, 300);
    testPiece(engine, 700);
    testPiece(engine, 250);
    testPiece(engine, 250);
    testPiece(engine, 250);
    testPiece(engine, 250);

    return 0;
}
