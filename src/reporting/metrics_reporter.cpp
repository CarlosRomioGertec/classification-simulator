#include "metrics_reporter.h"

#include <iostream>

namespace simulator::reporting {

    void MetricsReporter::printSummary() {

        std::cout << "\n===== SIMULATION SUMMARY =====\n";
        std::cout << "================================\n";
    }

}