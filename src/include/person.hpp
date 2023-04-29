#include <iostream>
#include <list>
#include "game.hpp"
using std::string, std::list;


class Person
{
    private:
        string name;
        float budget;
        list<Game> collection;

    public:
        Person(string name, float budget);

        //setters
        void set_budget(float budget);
        void set_name(string name);
        void set_collection(list<Game> collection);

        //getters
        double get_budget();
        string get_name();
        list<Game> get_collection();

        //other methods
        void add_game(Game game);
        void remove_game(Game game);
        void buy(Game game);
        void sell(Game game, Person* person); 
        void to_string();
        bool check_game_in_collection(Game game);
};