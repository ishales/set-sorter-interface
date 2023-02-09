//
//  testnewSet.cpp
//  cs32 hw1
//
//  Created by Isabelle Hales on 1/24/23.
//  Copyright © 2023 CS32. All rights reserved.
//

#include "newSet.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main()
{
    Set s;
    assert(s.empty());
    ItemType x = "arepa";
    assert( !s.get(42, x)  &&  x == "arepa"); // x unchanged by get failure
    s.insert("chapati");
    assert(s.size() == 1);
    assert(s.get(0, x)  &&  x == "chapati");
    
    cout << endl;
    
    Set a;
    a.insert("jump");
    a.insert("cat");
    a.insert("rainbow");
    a.insert("at");
    a.insert("jim");
    ItemType r;
    a.get(0, r);
    cout << r << endl;
    Set b;
    b.insert("hat");
    b.insert("pass");
    b.get(0, r);
    cout << r << endl;
    b.swap(a);
    b.get(0, r);
    cout << r << endl;
    
    a.swap(b);
    b.get(0, r);
    cout << r << endl;
    
    Set c(1000);
    Set d(5);
    ItemType v[6] = {"hi", "bye", "call", "me", "later", "please"};
    for (int k = 0; k < 5; k++)
        assert(d.insert(v[k]));
    assert(!d.insert(v[5]));
    c.swap(d);
    assert(!c.insert(v[5])  &&  d.insert(v[5]));
    
    cout << "Passed all tests" << endl;
}

