#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
ResourceManager(Resource obiekt){
    w = new obiekt;
}

~ResourceManager(){
    cout<<"The cleaning service!!"<<endl;
    delete w;
}

double get() { return k.get(); } // metoda double get()

ResourceManager(const ResourceManager& a): w{a.w}, { } // konstruktor kopiujacy

ResourceManager& operator=(const ResourceManager& t) // operator przypisania
{
        delete w;
        w = t.w;
        return *this;
}

ResourceManager(ResourceManager && a) // Move constructor
{
        w = a.w;
        a.w = nullptr;
        a.dlugosc = 0;
        a.pojemnosc = 0;
}

ResourceManager& operator=(ResourceManager&& other) // move operator
    {
        if (this != &other)
        {
            cout<<"You try to assign the object to itself"<<endl;
        }
        delete w;
        w= other.w;
        other.w = nullptr;
        return *this;
    }



private:
Resource* w;
};
