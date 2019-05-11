#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

class Ball
{
public:
	Ball(sf::RenderWindow& renderWindow, const int radius);
	~Ball() = default;

	sf::Vector2f getPosition() const;
	float getAngle() const;
	void setAngle(const float angle);
	const sf::CircleShape& getShape();

	void update(const sf::Time& dt);
	void draw();

private:
	sf::RenderWindow& m_renderWindow;
	sf::CircleShape m_ball;
	sf::Vector2f m_position;
	sf::Vector2f m_speed;

	sf::SoundBuffer m_collisionCornerSnd;
	sf::SoundBuffer m_outSceneSnd;

	sf::Sound m_corner;
	sf::Sound m_out;

	float m_angle;
	unsigned int count;

	static constexpr unsigned int SPEED_MAX{ 1800 };
	static constexpr unsigned int DELAY{ 1000 };
	static constexpr float ACCELERATION{ 9.81 * 100 };
};