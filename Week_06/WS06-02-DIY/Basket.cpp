/*
*****************************************************************************
                              Basket.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 8 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Basket.h"
#include <iomanip>

namespace sdds {
    Basket::Basket() {
        setEmpty();
    }

    Basket::Basket(Fruit* fruitsArr, int sizeOfArray, double priceOfBasket) {
        if (fruitsArr != nullptr && sizeOfArray > 0 && priceOfBasket > 0) {
            m_fruits = new Fruit[sizeOfArray];
             for (int i = 0; i < sizeOfArray; i++) {
                 m_fruits[i] = fruitsArr[i];
             }
             m_cnt = sizeOfArray;
             m_price = priceOfBasket;
        }
    }

    Basket::Basket(const Basket& basket) {
        setEmpty();
        *this = basket;
    }

    Basket::~Basket() {
        delete[] m_fruits;
    }

    // Initializes the object to a safe empty state
    void Basket::setEmpty() {
        m_fruits = nullptr;
        m_cnt = 0;
        m_price = 0;
    }

    // Copy assignment operator
    Basket& Basket::operator=(const Basket& basket) {
        delete[] m_fruits;
        m_fruits = new Fruit[basket.m_cnt];

        // Shallow copying
        m_cnt = basket.m_cnt;
        m_price = basket.m_price;

        // Deep copying
        for (int i = 0; i < basket.m_cnt; i++) {
            m_fruits[i] = basket.m_fruits[i];
        }

        return *this;
    }

    // Conversion to bool operator: returns true if the basket contains any fruits, false otherwise.
    Basket::operator bool() const {
        return (m_cnt != 0);
    }

    // Updates the m_price attribute to the value received as parameter
    void Basket::setPrice(double price) {
        m_price = price;
    }

    // An overload of the += operator that receives as a parameter an object of type Fruit (by value) and adds it to the attribute m_fruits
    Basket& Basket::operator+=(Fruit fruit) {
        Fruit* temp = new Fruit[m_cnt + 1];
        int i;
        for (i = 0; i < m_cnt; i++) {
            temp[i] = m_fruits[i];
        }
        m_cnt++;
        temp[m_cnt - 1] = fruit;
        delete[] m_fruits;
        m_fruits = temp;

        return *this;
    }

    // Function to display a Numbers object
    std::ostream& Basket::display(std::ostream& os) const {
        if (m_cnt == 0) {
            os << "The basket is empty!" << std::endl;
        }
        else {
            os << "Basket Content:" << std::endl;
            for (int i = 0; i < m_cnt; i++) {
                os << std::setw(10) << std::right << m_fruits[i].m_name;
                os << ": ";
                os << std::setprecision(2) << std::fixed << std::showpoint << m_fruits[i].m_qty;
                os << "kg" << std::endl;
            }
            os << "Price: " << m_price << std::endl;
        }

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Basket& basket) {
        return basket.display(os);
    }
}