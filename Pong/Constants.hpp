#pragma once

#include <SFML/Graphics.hpp>

 
const int WIDTHSCREEN{ static_cast<int>(sf::VideoMode::getDesktopMode().width) };

const int HEIGHTSCREEN{ static_cast<int>(sf::VideoMode::getDesktopMode().height) };

template<typename T>
constexpr T WIDTH_PADDLE{ 30 };

template<typename T>
constexpr T HEIGHT_PADDLE{ 100 };

template<typename T>
constexpr T SEPERATE{ HEIGHT_PADDLE<T> / 8 };

template<typename T>
constexpr T PI{ 3.14159 };