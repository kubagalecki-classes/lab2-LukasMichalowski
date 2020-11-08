#pragma once

#include "Resource.hpp"

usingnamespace std;


class ResourceManager
{
public:
ResourceManager()
{
    w = new Resource;
}

~ResourceManager()
{
    cout<<"The cleaning service!!"<<endl;
    delete w;
}

double get() { return w.get(); } // metoda double get()

ResourceManager(const ResourceManager & a) : w(a.w)
{
   a.w = nullptr; // check

} // konstruktor kopiujacy

ResourceManager& operator=(const ResourceManager & t) // operator przypisania
{
    if(this!= &t)
        w=t.w;
    t.w = nullptr; // check
    return *this;
}

ResourceManager(ResourceManager && other) // Move constructor
{
    w = other.w;
    other.w = nullptr;
}


ResourceManager& operator=(ResourceManager&& other) // move operator
    {

        w = other.w;
        other.w = nullptr;
        return *this;
    }



private:
Resource* w;
};
