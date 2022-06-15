#include <sstream>
#include "HelpState.hpp"
#include "LevelState.hpp"


#include <iostream>

namespace BubbleBash
{
	HelpState::HelpState(GameDataRef data) : _data(data)
	{

	}

	void HelpState::Init()
	{
		this->_data->assets.LoadTexture("Background", HELP_STATE_FILEPATH);		
		this->_data->assets.LoadTexture("PLAY", PLAY_BUTTON_FILEPATH);		
		this->_data->assets.LoadTexture("EXIT", EXIT_BUTTON_FILEPATH);
			


		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_playbutton.setTexture(this->_data->assets.GetTexture("PLAY"));		
		this->_exitbutton.setTexture(this->_data->assets.GetTexture("EXIT"));



		this->_playbutton.setPosition(800,455);
		this->_exitbutton.setPosition(797,525);


        if(!font.loadFromFile(MARKER_FONT_FILEPATH))
        {
            throw("COULD NOT LOAD FONT");
        }


         text.setFont(font);
         text.setCharacterSize(30);
         text.setColor(sf::Color::White);   
		 //void sf::Text::setFillColor	
         //text.setPosition(0,100);


         title.setFont(font);
         title.setCharacterSize(50);
         title.setColor(sf::Color::Yellow);
         title.setPosition(400,0);


         title.setString("INSTRUCTIONS");
         text.setString("\n\nYou are given 8*8 board filled with bubbles. \nThe game is played by swaping bubbles in any direction to create sets of 3 or more \nmatching bubbles.\nEach time when you match 3 or more bubbles, you will get points. \nYour time is limited. So score as much as you can. \nTo swap: use left mouse click on each of two bubbles to get swapped.");

		 this->_data->assets._music.openFromFile(HELP_STATE_MUSIC_FILEPATH);
		 this->_data->assets._music.setVolume(70);
		 this->_data->assets._music.setLoop(true);
		 this->_data->assets._music.play();
		}

	void HelpState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->assets._music.stop();
				this->_data->window.close();
			}
	

			else if (this->_data->input.IsSpriteClicked(this->_playbutton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->assets._music.stop();
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

	void HelpState::Update([[maybe_unused]] float dt)
	{

	}

	void HelpState::Draw([[maybe_unused]] float dt)
	{
		this->_data->window.clear(sf::Color::Blue);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playbutton);		
		this->_data->window.draw(this->_exitbutton);
        this->_data->window.draw(text);
        this->_data->window.draw(title);

		this->_data->window.display();
	}
}
