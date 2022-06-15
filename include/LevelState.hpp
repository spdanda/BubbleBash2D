#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "HelpState.hpp"

namespace BubbleBash
{
	class LevelState : public State
	{
	public:
		LevelState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Font font;

		sf::Text title;

		sf::Sprite _background;

		sf::Sprite _easybutton;

		sf::Sprite _mediumbutton;

		sf::Sprite _hardbutton;

		
	};
}