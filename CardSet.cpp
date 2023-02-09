//
//  CardSet.cpp
//  cs32 hw1
//
//  Created by Isabelle Hales on 1/24/23.
//  Copyright © 2023 CS32. All rights reserved.
//

#include "CardSet.h"
#include <iostream>
using namespace std;

CardSet::CardSet()
{

}

bool CardSet::add(unsigned long cardNumber)
{
    return m_set.insert(cardNumber);
}

int CardSet::size() const
{
    return m_set.size();
}

void CardSet::print() const
{
    int a = m_set.size();
    for(int i = 0; i < a; i++){
        ItemType value;
        m_set.get(i, value);
        cout << value << endl;
    }
}


