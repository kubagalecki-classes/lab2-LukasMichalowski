#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
ResourceManager(Resource obiekt){
    w = new obiekt;
}

~ResourceManager()
{
    cout<<"The cleaning service!!"<<endl;
    delete w;
}

double get() { return k.get(); } // metoda double get()

ResourceManager(const ResourceManager& a): w{a.w} { } // konstruktor kopiujacy

ResourceManager& operator=(const ResourceManager& t) // operator przypisania
{
        delete w;
        w = t.w;
        return *this;
}

ResourceManager(ResourceManager && other): w(other.w) // Move constructor

        other.w = 0;
}

ResourceManager& operator=(ResourceManager&& other) // move operator
    {
        if (this != &other)
        {
            cout<<"You try to assign the object to itself"<<endl;
        }
        delete w;
        w= other.w;
        other.w = 0;
        return *this;
    }



private:
Resource* w;
};
