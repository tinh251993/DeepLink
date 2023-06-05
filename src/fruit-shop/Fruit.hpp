
#include <iostream>

class Fruit
{
public:
    std::string name;
    int price;

protected:
    Fruit(std::string name, int price)
    {
        this->name = name;
        this->price = price;
    }

    friend std::ostream& operator <<(std::ostream& os, const Fruit& fruit)
    {
        return os << "Name: " << fruit.name << " - Price: " << fruit.price << "\n";   
    }
};



