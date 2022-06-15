#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"


namespace BubbleBash
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _background;

        sf::Sprite _playAgainbutton;

        sf::Font font;
        
        sf::Text text_score;
        sf::Text score_text;

        sf::Sprite _exitbutton;
    };
}