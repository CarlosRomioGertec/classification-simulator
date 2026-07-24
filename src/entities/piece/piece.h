#pragma once

namespace simulator::entities::piece {
    struct Piece
    {
        int id = 0;

        double weight = 0.0;

        PieceClass piece_class = PieceClass::SmallRange;

        int closed_range_index = -1;
    };
}