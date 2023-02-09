//
//  testCardSet.cpp
//  cs32 hw1
//
//  Created by Isabelle Hales on 1/24/23.
//  Copyright © 2023 CS32. All rights reserved.
//

#include "CardSet.h"
#include <iostream>
using namespace std;

int main() {
    //declare CardSet
    
    CardSet ace;
    ace.print();
 
    cout << endl;

    CardSet jump;
    jump.add(6);
    jump.print();
    
    
    CardSet a;
    a.add(7);
    a.add(8);
    a.print();
    
    CardSet b;
    b.add(12);
    b.print();
    cout << "Passed all CardSet tests" << endl;
}
