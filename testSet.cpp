//
//  main.cpp
//  cs32 hw1
//
//  Created by Isabelle Hales on 1/20/23.
//  Copyright © 2023 CS32. All rights reserved.
//

#include "Set.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void test()
{
    Set ss;
    assert(ss.insert("roti"));
    assert(ss.insert("pita"));
    assert(ss.size() == 2);
    assert(ss.contains("pita"));
    ItemType x = "laobing";
    assert(ss.get(0, x)  &&  x == "pita");
    assert(ss.get(1, x)  &&  x == "roti");
}

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
    
    test();
    
    cout << "Passed all tests" << endl;
}


