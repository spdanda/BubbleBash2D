#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "HelpState.hpp"
#include "LevelState.hpp"

namespace BubbleBash
{
	class MainmenuState : public State
	{
	public:
		MainmenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _playbutton;

		sf::Sprite _helpbutton;

		sf::Sprite _exitbutton;

		
	};
}