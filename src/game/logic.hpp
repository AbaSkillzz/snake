#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "utils/queue.hpp"
#include <cstdint>

namespace Snake {

typedef struct {
    uint16_t height;
    uint16_t width;

} GameTable;

typedef struct {
    uint16_t x;
    uint16_t y;
} Coordinates;

bool coordinates_are_equal(Coordinates a, Coordinates b);

typedef enum : int8_t {
    DIRECTION_UP = 1,
    DIRECTION_DOWN = 2,
    DIRECTION_LEFT = ~1,
    DIRECTION_RIGHT = ~2,
    DIRECTION_NONE = 0
} Direction;

typedef enum {
    GAME_UNFINISHED,
    GAME_WON,
    GAME_LOST
} GameResult;

class Game {
  private:
    GameResult result;
    GameTable game_table;
    Direction current_direction;
    Coordinates snake_head_position;
    Coordinates apple_position;
    Queue<Coordinates> snake_body;

    void new_apple_position();

  public:
    Game(uint16_t table_height, uint16_t table_width);

    GameResult update_game(Direction player_input);

    GameTable get_game_table() const {
        return game_table;
    }

    Coordinates get_snake_head_position() const {
        return snake_head_position;
    }

    Coordinates get_apple_position() const {
        return apple_position;
    }

    Queue<Coordinates> get_snake_body() const {
        return snake_body;
    }
};

} // namespace Snake

#endif