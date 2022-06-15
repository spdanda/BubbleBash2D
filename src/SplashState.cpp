#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainmenuState.hpp"
#include <iostream>
#include <sstream>

namespace BubbleBash
{
    SplashState::SplashState(GameDataRef data) : _data(data) {}
    void SplashState::Init()
    {
        this->_data->assets.LoadTexture("SplashStateBackGround", SPLASH_STATE_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("SplashStateBackGround"));

        this->_data->assets.LoadTexture("IITH MILAN", IITH_MILAN_FILEPATH);
        _logo.setTexture(this->_data->assets.GetTexture("IITH MILAN"));

        _logo.setPosition((SCREEN_WIDTH / 2) - (this->_logo.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_logo.getGlobalBounds().height / 2));

        this->_data->assets._music.openFromFile(SPLASH_STATE_MUSIC_FILEPATH);
        this->_data->assets._music.setVolume(70);
        this->_data->assets._music.play();
    }

    void SplashState::HandleInput()
    {
        sf::Event e;
        while (this->_data->window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                this->_data->window.close();
            }
            if (e.type == sf::Event::EventType::KeyPressed)
            {
                // Up and down to control volume
                if (e.key.code == sf::Keyboard::Down)
                    this->_data->assets._music.setVolume(_data->assets._music.getVolume() - 10);

                if (e.key.code == sf::Keyboard::Key::Up)
                    this->_data->assets._music.setVolume(_data->assets._music.getVolume() + 10);
            }
        }
    }

    void SplashState::Update([[maybe_unused]] float dt)
    {
        if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            // Switch To Main Menu
            this->_data->assets._music.stop();
            this->_data->machine.AddState(StateRef(new MainmenuState(_data)), true);
        }
    }

    void SplashState::Draw([[maybe_unused]] float dt)
    {
        this->_data->window.clear(sf::Color::Black);

        this->_data->window.draw(_logo);

        if (this->_clock.getElapsedTime().asSeconds() >= 2)
        {
            this->_data->window.draw(_background);
        }

        this->_data->window.display();
    }
}
