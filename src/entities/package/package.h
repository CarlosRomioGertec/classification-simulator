#pragma once
#include <vector>

namespace entities::package {
    struct Package
    {
        int id;

        int accepted_range = -1;

        double target_weight = 0.0;

        double current_weight = 0.0;

        double time_open = 0.0;

        double dynamic_margin = 0.0;

        bool is_closed = false;

        std::vector<int> piece_ids;

        void reset(double base_margin)
        {
            current_weight = 0;
            time_open = 0;
            dynamic_margin = base_margin;
            is_closed = false;
            piece_ids.clear();
        }
    };
}