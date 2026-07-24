#pragma once

#include "entities/simulation_metrics/simulation_metrics.h"

namespace simulator::reporting {

    class MetricsReporter {
    public:
        static void printSummary();
    };
}