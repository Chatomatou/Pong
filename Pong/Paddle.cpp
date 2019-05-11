#include "Paddle.hpp"
#include "Constants.hpp"
#include <iostream>

Paddle::Paddle(sf::RenderWindow& renderWindow, const int x, const int y, const int w, const int h) : m_renderWindow{ renderWindow },  m_paddle{ sf::Vector2f(w, h) }, m_position{ x, y }
{
	m_paddle.move(m_position);

	m_buffer.loadFromFile("assets/ping_pong_8bit_beeep.ogg");
	m_sound.setBuffer(m_buffer);
}

void Paddle::setControllable(const bool state)
{
	m_controllable = state;
}

void Paddle::update(const sf::Time& dt, Ball& ball)
{
	
	if(sf::Mouse::getPosition().y < HEIGHTSCREEN - HEIGHT_PADDLE<int> && m_controllable)
		m_position.y = sf::Mouse::getPosition().y;

	if (m_position.y + HEIGHT_PADDLE<int> > HEIGHTSCREEN)
	{
		m_position.y = HEIGHTSCREEN - HEIGHT_PADDLE<int>;
	}
	 
 
	if (!m_controllable)
	{
		if(ball.getPosition().y - HEIGHT_PADDLE<int> / 2 > 0 && ball.getPosition().y - HEIGHT_PADDLE<int> / 2 < HEIGHTSCREEN - HEIGHT_PADDLE<int>)
			m_position.y = ball.getPosition().y - HEIGHT_PADDLE<int> / 2;
	}

	if (m_paddle.getGlobalBounds().intersects(ball.getShape().getGlobalBounds()))
	{
		m_sound.play();
		auto angle = 0.0f;
		if (m_controllable)
		{
			if (ball.getPosition().y >= m_position.y && ball.getPosition().y <= m_position.y + SEPERATE<float>)
				angle = -45;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> && ball.getPosition().y <= m_position.y + SEPERATE<float> * 2)
				angle = -30;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 3 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 4)
				angle = -15;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 4 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 6)
				angle = 0;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 6 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 7)
				angle = 15;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 7 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 8)
				angle = 30;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 8 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 9)
				angle = 45;
		}
		else
		{
			if (ball.getPosition().y >= m_position.y && ball.getPosition().y <= m_position.y + SEPERATE<float>)
				angle = -135;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> && ball.getPosition().y <= m_position.y + SEPERATE<float> * 2)
				angle = -150;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 3 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 4)
				angle = -165;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 4 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 6)
				angle = 180;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 6 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 7)
				angle = 165;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 7 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 8)
				angle = 150;

			if (ball.getPosition().y >= m_position.y + SEPERATE<float> * 8 && ball.getPosition().y <= m_position.y + SEPERATE<float> * 9)
				angle = 135;
		}

		ball.setAngle(angle);
	}

	m_paddle.setPosition(m_position);

}

void Paddle::draw()
{
	m_renderWindow.draw(m_paddle);
}