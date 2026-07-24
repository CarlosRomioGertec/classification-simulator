#pragma once
#include <vector>

namespace services::simulator {
    class Simulator {
    public:
        Simulator() = default;
        ~Simulator() = default;

    private:
        std::vector<double> weights;
    };
}