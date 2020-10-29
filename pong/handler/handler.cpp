#include "handler.hpp"
#include "../game.hpp"
#include <iostream>

namespace herbglitch {
    Handler::Handler(game::Data *data): data(data) {
        load();
        AddState(new state::Menu(data), false);
    }

    Handler::~Handler(){
        for(State *state : states){ delete state; }
        states.clear();
    }

    void Handler::load(){
        config::load("pong/.res/settings.config", data->texture);
    }

    void Handler::update(){
        for(State *state : states){ state->update(); }
    }

    void Handler::render(){
        for(State *state : states){ state->render(); }
    }

    void Handler::AddState(State *state, bool isReplacing){
        if(isReplacing){ RemoveState(); }
        states.push_back(state);
    }

    void Handler::RemoveState(){
        delete states.at(states.size() - 1);
        states.erase(states.begin() + (states.size() - 1));
    }
}