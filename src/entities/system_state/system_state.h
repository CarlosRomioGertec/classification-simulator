#pragma once
#include <vector>
#include "simulator/entities/package/package.h"

namespace simulator::entities::system_state {
    struct SystemState {
        std::vector<package::Package> packages;

        int current_index = 0; // posição no CSV
        double current_time = 0.0;

    };
}