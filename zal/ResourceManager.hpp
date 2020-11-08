#pragma once

#include "Resource.hpp"


class ResourceManager
{
public:
ResourceManager()
{
    w = new Resource;
}

~ResourceManager()
{
    delete w;
}

double get() { return w->get(); } // metoda double get()

ResourceManager(const ResourceManager & a)
{
    w = new Resource;
    *w=*a.w;
} //  deep copy constructor

ResourceManager& operator=(const ResourceManager & t) // operator przypisania
{
    if(this!= &t)
        *w=*t.w;
    return *this;
}

ResourceManager(ResourceManager && other) // Move constructor
{
    w = other.w;
    other.w = nullptr;
}



ResourceManager& operator=(ResourceManager&& other) // move operator
    {
    if (&other == this)
        return *this;
    delete w;
    w=other.w;
    other.w = nullptr;
    return *this
    }



private:
Resource *w;
};
