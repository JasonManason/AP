#include "include/game.hpp"
#include <math.h>
#include <cstring>

class Game;

Game::Game(string title, int release_year, float price)
{
    this -> title = title;
    this -> release_year = release_year;
    this -> price = price;
}


string Game::get_title()
{
    return title;
}


int Game::get_release_year()
{
    return release_year;
}


float Game::get_original_price()
{
    return price;
}


void Game::set_original_price(float price)
{
    price = price;
}


float Game::calc_cur_price(float price)
{
    return (price * pow(0.7, (2022 - get_release_year())));
}


std::string Game::to_string()
{
    return "Title: " + title + "\nRelease year: " + std::to_string(release_year) + "\nPrice: " + std::to_string(price);
}


bool operator==(Game g1, Game g2) 
{
    return (g1.get_title() == g2.get_title() && g1.get_release_year() == g2.get_release_year());
}