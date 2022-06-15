#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace BubbleBash
{
    static struct Timer
    {
        int runTime;
        bool bPaused;
        sf::Clock mC;

        Timer()
        {
            bPaused = false;
            runTime = 0;
        }

        void Start()
        {
            if (bPaused)
            {
                mC.restart();
            }
            bPaused = false;
        }

        void Pause()
        {
            if (!bPaused)
            {
                runTime += mC.getElapsedTime().asSeconds();
            }
            bPaused = true;
        }

        int GetElapsedSeconds()
        {
            if (!bPaused)
            {
                return runTime + mC.getElapsedTime().asSeconds();
            }
            return runTime;
        }
    } obj;

    class GameState : public State
    {
    public:
        GameState(GameDataRef data, int i);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

        int sc = 0;

    private:
        GameDataRef _data;

        sf::Sprite _background;

        sf::Sprite _gridSprite;

        sf::Sprite _pausebutton;

        sf::Sprite _helpbutton;

        sf::Sprite _bubbles;

        sf::Font font;

        sf::Text text_time, time_text;
        sf::Text text_score;

        int time, level;

        std::string string_time;

        struct piece
        {
            int x, y, col, row, kind, match, alpha;
            piece()
            {
                match = 0;
                alpha = 255;
            }
        } grid[10][10];

        int ts = 48;

        sf::Vector2i offset = sf::Vector2i(510, 207);
        sf::Vector2i pos;

        int x0, y0, x, y;
        int click = 0;
        bool isSwap = false, isMoving = false, special = false;
        ;
        int max = 10;

        void processEvents();
        void update();
        void render();
        void swap(piece p1, piece p2);
        int NoMoreMoves(piece grid[10][10]);
    };
}