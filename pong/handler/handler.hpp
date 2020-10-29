#pragma once
#include "../states/states.hpp"
#include "../states/menu/menu.hpp"
#include "../manager/config.hpp"
#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace game { struct Data; }

    class Handler {
    public:
        Handler(game::Data *data);
        ~Handler();

        void load();

        void update();
        void render();

        void AddState(State *state, bool isReplacing = true);
        void RemoveState();

    private:
        std::vector<State *> states;
        game::Data *data;
    };
}