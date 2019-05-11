#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.hpp"

class Paddle
{
public:
	Paddle() = delete;
	Paddle(sf::RenderWindow& renderWindow, const int x, const int y, const int w, const int h);
	~Paddle() = default;

	void setControllable(const bool state);

	void update(const sf::Time& dt, Ball& ball);
	void draw();

private:
	sf::RenderWindow& m_renderWindow;
	sf::RectangleShape m_paddle;
	sf::Vector2f m_position;

	sf::SoundBuffer m_buffer;
	sf::Sound m_sound;


	bool m_controllable;
	

	static constexpr unsigned int SPEED{ 500 };
 
};