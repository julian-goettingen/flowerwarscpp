#ifndef INDEXING_H
#define INDEXING_H
#include <stdint.h>
#include <assert.h>


class FlowerCoord {

    uint16_t dir : 1;
    uint16_t col : 7;
    uint16_t row : 7;

    // FlowerCoord() = default;
    // explicit FlowerCoord(short linear_pos, int board_size);

    // short as_linear(int board_size);

};
static_assert(sizeof(FlowerCoord) == 2);




#endif // INDEXING_H