#pragma once

namespace configuration::simulation_config {
    struct SimulationConfig {
        double target_weight = 0.0;     // T (ex: 1000)
        double base_margin = 0.0;       // M (ex: 10)
        double max_margin = 0.0;        // M_max (ex: 30)
        double timeout_seconds = 0.0;   // τ (ex: 10)

        int max_packages = 0;         // ex: 16

        double min_probability_threshold = 0.0; // ex: 0.05 (5%)
    };
}