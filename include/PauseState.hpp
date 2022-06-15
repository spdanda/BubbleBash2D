#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "HelpState.hpp"

namespace BubbleBash
{
    class PauseState : public State
    {
    public:
        PauseState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _background;

        sf::Sprite _resumebutton;

        sf::Sprite _restartbutton;

        sf::Sprite _exitbutton;
    };
}