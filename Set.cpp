//
//  Set.cpp
//  cs32 hw1
//
//  Created by Isabelle Hales on 1/23/23.
//  Copyright © 2023 CS32. All rights reserved.
//

#include "Set.h"
#include <iostream>
#include <string>

Set::Set()
{
    Setsize = 0;
}

bool Set::empty() const
{
    if(Setsize == 0)
        return true;
    else
        return false;
}

int Set::size() const
{
    return Setsize;
}

bool Set::insert(const ItemType& value)
{
    
    for(int i = 0; i < Setsize; i++){
        if(mainSet[i] == value){
            return false;
        }
    } if(Setsize == DEFAULT_MAX_ITEMS) {
        return false;
    } else
        mainSet[Setsize] = value;
        Setsize++;
        return true;
}

bool Set::erase(const ItemType& value)
{
    for(int i = 0; i < Setsize; i++){
        if(mainSet[i] == value){
            mainSet[i] = mainSet[i+1];
            for(int j = i+1; j < Setsize-1; j++){
                mainSet[j] = mainSet[j+1];
            }
            Setsize--;
            return true;
        }
    }
    return false;
}

bool Set::contains(const ItemType& value) const
{
    for(int i = 0; i < Setsize; i++){
        if(mainSet[i] == value){
            return true;
        }
    }
    return false;
}

bool Set::get(int i, ItemType& value) const
{
    if(i < 0 || i >= Setsize){
        return false;
    }
    if(Setsize == 0){
        return false;
    }

    ItemType tempArray[Setsize];
    //copy array into temp array
    for(int a = 0; a < Setsize; a++){
        tempArray[a] = mainSet[a];
    }
    
    if(Setsize == 1){
        value = tempArray[0];
        return true;
    }
    
    //sort array
    for(int b = 1; b < Setsize; b++){
        for(int d = 0; d < Setsize; d++){
            if(tempArray[b] < tempArray[d]){
                ItemType fill = tempArray[b];
                tempArray[b] = tempArray[d];
                tempArray[d] = fill;
            }
        }
    }
    
    //find correct value
    value = tempArray[i];
    return true;
}

void Set::swap(Set& other)
{
    int tempother_s = other.size();
    int tmain_s = Setsize;
    ItemType temp_array[Setsize];
    //create copy of main Set
    for(int a = 0; a < Setsize; a++){
       temp_array[a] = mainSet[a];
    }
    //replace mainSet with other
    for(int b = 0; b < tempother_s; b++){
        mainSet[b] = other.mainSet[b];
    }
    Setsize = tempother_s;
    //replace other with mainSet
    for(int c = 0; c < tmain_s; c++){
        other.mainSet[c] = temp_array[c];
    }
    if(tmain_s < tempother_s){
        for(int d = tmain_s; d < tempother_s; d++){
            other.erase(mainSet[d]);
        }
    }
}

