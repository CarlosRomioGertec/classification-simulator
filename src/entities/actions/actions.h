#pragma once

namespace simulator::entities::actions {
    enum class ActionType {
        Assign,
        Reject
    };

    struct Action {
        ActionType type;
        int package_id = -1;
    };
}