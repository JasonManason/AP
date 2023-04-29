#include <iostream>
#include <ctime>
#include "include/person.hpp"
using std::cout, std::endl;


int main()
{
    std::time_t result = std::time(NULL);
    cout << std::asctime(std::localtime(&result));
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int release_date1 = tm_local->tm_year + 1899; // 1 year ago
    int release_date2 = tm_local->tm_year + 1898; // 2 years ago
    
    Game g1("Just Cause 3", release_date1, 49.98);
    Game g2("Need for Speed: Rivals", release_date2, 45.99);
    Game g3("The witcher 3: Wild Hunt", release_date2, 45.99); // gave g3 another title because it might be confusing?

    Person p1("Eric", 200);
    Person p2("Hans", 55);
    Person p3("Arno", 185);
    
    // Transactions
    p1.buy(g1);
    p1.buy(g2);
    p1.buy(g3);
    p2.buy(g2);
    p2.buy(g1);
    p3.buy(g3);
    
    // Current state of persons
    p1.to_string();
    p2.to_string();
    p3.to_string();
   
    // Transactions between persons
    p1.sell(g1, &p3);
    p2.sell(g2, &p3);
    p2.sell(g1, &p1);
    
    // Current state of persons
    p1.to_string();
    p2.to_string();
    p3.to_string();

    return 0;
}