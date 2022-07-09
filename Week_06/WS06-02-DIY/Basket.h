/*
*****************************************************************************
                              Basket.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 8 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef DIY_BASKET_H
#define DIY_BASKET_H
#include <iostream>

namespace sdds {
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket {
    private:
        Fruit* m_fruits;
        int m_cnt;
        double m_price;
    public:
        Basket();
        Basket(Fruit* fruitsArr, int sizeOfArray, double priceOfBasket);
        Basket(const Basket& basket);
        ~Basket();

        // Initializes the object to a safe empty state
        void setEmpty();

        // Copy assignment operator
        Basket& operator=(const Basket& basket);

        // Updates the m_price attribute to the value received as parameter
        void setPrice(double price);

        // Conversion to bool operator: returns true if the basket contains any fruits, false otherwise.
        operator bool() const;

        // An overload of the += operator that receives as a parameter an object of type Fruit (by value) and adds it to the attribute m_fruits
        Basket& operator+=(Fruit fruit);

        // Function to display the basket content
        std::ostream& display(std::ostream& os) const;
    };
    // Overloading the insertion operator to insert into stream
    std::ostream& operator<<(std::ostream& os, const Basket& basket);
}

#endif //DIY_BASKET_H
