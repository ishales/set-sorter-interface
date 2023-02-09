//
//  newSet.cpp
//  cs32 hw1
//
//  Created by Isabelle Hales on 1/24/23.
//  Copyright © 2023 CS32. All rights reserved.
//

#include "newSet.h"
#include <iostream>
#include <string>

Set::Set(int max)
{
    Setsize = 0;
    Setmax = max;
    mainSet = new ItemType[Setmax];
}

Set::Set(const Set& other)
{
    Setsize = other.Setsize;
    Setmax = other.Setmax;
    mainSet = new ItemType[other.Setmax];
    
    for(int a = 0; a < Setsize; a++){
        mainSet[a] = other.mainSet[a];
    }
    
}

Set& Set::operator=(const Set& rhs)
{
    if(this != &rhs){
        Set input(rhs);
        this->swap(input);
    }
    return *this;
}

Set::~Set()
{
    delete [] mainSet;
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
    } if(Setsize == Setmax) {
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
    //record values of incoming set
    int tempother_s = other.size();
    int tempother_max = other.Setmax;
    
    //swap parameters of two sets
    other.Setsize = this->Setsize;
    this->Setsize = tempother_s;
    
    other.Setmax = this->Setmax;
    this->Setmax = tempother_max;
    
    //create pointer to incoming set
    ItemType* temp_pointer = other.mainSet;
    other.mainSet = this->mainSet;
    this->mainSet = temp_pointer;
    
}
