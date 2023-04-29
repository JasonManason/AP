#include "include/person.hpp"
#include <windows.h>
using std::cout, std:: endl, std::to_string, std::list;


Person::Person(string name, float budget)
{
    this -> name = name;
    this -> budget = budget;
}


void Person::set_budget(float n_budget)
{
    budget = n_budget;
}


void Person::set_name(string name)
{
    name = name;
}


void Person::set_collection(list<Game> collection)
{
    collection = collection;
}


string Person::get_name() 
{
    return name;
}


double Person::get_budget()
{
    return budget;
}


list<Game> Person::get_collection()
{
    return collection;
}


void Person::add_game(Game game)
{
    collection.push_back(game);
}


void Person::remove_game(Game game)
{
    for (Game i : collection) {
        if (i == game) {
            collection.remove(i);
            break;
        }
    }
}


bool Person::check_game_in_collection(Game game)
{
    for (Game i : collection) {
        if (i == game) {
            return true;
        } 
        return false;
    }
}


void Person::buy(Game game)
{
    if (budget >= game.calc_cur_price(game.get_original_price())) {
        cout << name + " tries to buy " + game.get_title() + ", with succes." << endl;
        set_budget(budget - game.calc_cur_price(game.get_original_price()));
        add_game(game);

    } 
    else {
        cout << name + " tries to buy " + game.get_title() + ", but failed." << endl;
    }
}


void Person::sell(Game game, Person* buyer)
{
    cout << endl;
    if (buyer -> get_budget() >= game.calc_cur_price(game.get_original_price()) && check_game_in_collection(game) == true) {
        cout << buyer -> get_name() + " tries to buy " + game.get_title() + " from " + name + ", with succes." << endl;
        buyer -> set_budget(buyer -> get_budget() - game.calc_cur_price(game.get_original_price()));
        buyer -> add_game(game);
        remove_game(game);
        set_budget(budget + game.calc_cur_price(game.get_original_price()));

    } else {
        cout << buyer -> get_name() + " tries to buy " + game.get_title() + " from " + name + ", but failed." << endl;
    }
}


void Person::to_string()
{
    SetConsoleOutputCP(1252);
    cout << "\n" + name + " has a budget of " + (char)(128) + std::to_string(get_budget()) + " and owns: " << endl;
    for (Game i : collection)
    {
        cout << i.get_title() + ", released in " + 
        std::to_string(i.get_release_year()) +
        "; original price: " + (char)(128) + std::to_string(i.get_original_price()) + 
        " now for: " + (char)(128) + std::to_string(i.calc_cur_price(i.get_original_price())) << endl;
    };
    cout << endl;
}