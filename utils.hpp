#ifndef UTILS_HPP
#define UTILS_HPP

//SFML (Simple Fast Media Library)
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//STL (Standard Toolkit Library)
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>

const float TO_DEGREES = (1 / (float ) M_PI) * 180;
const float TO_RADIANS = (1 / 180.0f) * (float ) M_PI;

// If you want to declare global variables you can do it here:
extern int number; // You must to declare this avariable again on utils.cpp

#endif // UTILS_HPP
