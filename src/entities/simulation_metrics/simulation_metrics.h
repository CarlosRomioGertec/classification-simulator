#pragma once

namespace simulator::entities::simulation_metrics {
    struct SimulationMetrics {
        int total_pieces = 0;
        int rejected_pieces = 0;

        int packages_closed = 0;

        double total_weight_processed = 0.0;
        double total_weight_rejected = 0.0;

        double total_closing_time = 0.0;
    };
}