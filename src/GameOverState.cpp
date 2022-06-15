
#include "GameOverState.hpp"
#include "LevelState.hpp"
#include <iostream>
#include <sstream>

namespace BubbleBash
{
    GameOverState::GameOverState(GameDataRef data) : _data(data)
    {
    }

    void GameOverState::Init()
    {
        this->_data->assets.LoadTexture("Background", GAME_OVER_STATE_FILEPATH);
        this->_data->assets.LoadTexture("PLAY AGAIN", PLAY_AGAIN_BUTTON_FILEPATH);
        this->_data->assets.LoadTexture("EXIT", EXIT_BUTTON_FILEPATH);

        this->_background.setTexture(this->_data->assets.GetTexture("Background"));
        this->_playAgainbutton.setTexture(this->_data->assets.GetTexture("PLAY AGAIN"));
        this->_exitbutton.setTexture(this->_data->assets.GetTexture("EXIT"));

        this->_data->assets._music.openFromFile(MAIN_MENU_STATE_MUSIC_FILEPATH);
        this->_data->assets._music.setVolume(70);
        this->_data->assets._music.setLoop(true);
        this->_data->assets._music.play();

        this->_playAgainbutton.setPosition(423, 320);
        this->_exitbutton.setPosition(427, 420);

        if (!font.loadFromFile(MARKER_FONT_FILEPATH))
        {
            throw("COULD NOT LOAD FONT");
        }

        text_score.setFont(font);
        text_score.setCharacterSize(80);
        text_score.setColor(sf::Color::Yellow);
        text_score.setPosition(200, 155);
        text_score.setString("Your score is : ");

        score_text.setFont(font);
        score_text.setCharacterSize(80);
        score_text.setColor(sf::Color::Yellow);
        score_text.setPosition(650, 155);
        score_text.setString(std::to_string(this->_data->assets.score));
    }

    void GameOverState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->assets._music.stop();
                this->_data->window.close();
            }

            else if (this->_data->input.IsSpriteClicked(this->_playAgainbutton, sf::Mouse::Left, this->_data->window))
            {
                // Switch To Level State
                this->_data->machine.AddState(StateRef(new LevelState(_data)), true);
            }
            else if (this->_data->input.IsSpriteClicked(this->_exitbutton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->assets._music.stop();
                this->_data->window.close();
            }

            if (event.type == sf::Event::EventType::KeyPressed)
            {
                // Up and down to control volume
                if (event.key.code == sf::Keyboard::Down)
                    this->_data->assets._music.setVolume(_data->assets._music.getVolume() - 10);

                if (event.key.code == sf::Keyboard::Key::Up)
                    this->_data->assets._music.setVolume(_data->assets._music.getVolume() + 10);
            }
        }
    }

    void GameOverState::Update([[maybe_unused]] float dt)
    {
    }

    void GameOverState::Draw([[maybe_unused]] float dt)
    {
        this->_data->window.clear(sf::Color::Black);

        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_playAgainbutton);
        this->_data->window.draw(this->_exitbutton);

        this->_data->window.draw(text_score);
        this->_data->window.draw(score_text);

        this->_data->window.display();
    }
}