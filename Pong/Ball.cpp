#include "Ball.hpp"
#include "Constants.hpp"
#include <iostream>

Ball::Ball(sf::RenderWindow& renderWindow, const int radius) :
	m_renderWindow{ renderWindow },
	m_ball{ radius },
	m_position{ WIDTHSCREEN / 2, HEIGHTSCREEN / 2 },
	m_angle{ 0 },
	m_speed{ 5, 5 }
{ 

	m_collisionCornerSnd.loadFromFile("assets/ping_pong_8bit_plop.ogg");
	m_outSceneSnd.loadFromFile("assets/ping_pong_8bit_peeeeeep.ogg");

	m_corner.setBuffer(m_collisionCornerSnd);
	m_out.setBuffer(m_outSceneSnd);


 	m_ball.move(m_position);
	
}

sf::Vector2f Ball::getPosition() const
{
	return m_position;
}

float Ball::getAngle() const
{
	return m_angle;
}

void Ball::setAngle(const float angle)
{
	m_angle = angle;
}

const sf::CircleShape& Ball::getShape()
{
	return m_ball;
}

void Ball::update(const sf::Time& dt)
{
	count += dt.asMilliseconds();

	if (count > DELAY)
	{
		count = 0;

		if (m_speed.x < SPEED_MAX && m_speed.y < SPEED_MAX)
		{
			m_speed.x += ACCELERATION * dt.asSeconds();
			m_speed.y += ACCELERATION * dt.asSeconds();
		}
	}

	if (m_position.x < 0 || m_position.x > WIDTHSCREEN)
	{
		m_out.play();
		m_position = { WIDTHSCREEN / 2.0f, HEIGHTSCREEN / 2.0f };
	}

	if (m_position.y < 0 || m_position.y > HEIGHTSCREEN)
	{
		m_corner.play();
		m_angle = -m_angle;
	}
	m_position.x += m_speed.x * std::cosf(m_angle * PI<float> / 180.0f) * dt.asSeconds();
	m_position.y += m_speed.y * std::sinf(m_angle * PI<float> / 180.0f) * dt.asSeconds();

 
	m_ball.setPosition(m_position);
}

void Ball::draw()
{
	m_renderWindow.draw(m_ball);
}