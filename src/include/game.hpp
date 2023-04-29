#include <string>
using std::string;

class Game
{
    private:
        string title;
        int release_year;
        float price;

    public:
        Game(string title, int release_year, float price);
        
        //getters
        string get_title();
        int get_release_year();
        float get_original_price();

        //setter
        void set_original_price(float price);

        //other methods
        string to_string();
        float calc_cur_price(float price);
        friend bool operator==(Game g1, Game g2);
};