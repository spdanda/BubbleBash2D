#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"


namespace BubbleBash
{
	class HelpState : public State
	{
	public:
		HelpState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _playbutton;

		sf::Sprite _exitbutton;

        sf::Font font;

        sf::Text text;

        sf::Text title;

		
	};
}