#include <iostream>
using namespace std;


class chair
{
public:
    virtual void sit(){}
};

class sofa
{
    public:
    virtual void lay(){}
};

class victorianchair : public chair
{
    public:
    void sit() override
    {
        cout << "This is a victorian chair : sateth" << endl;
    }
};

class victoriansofa : public sofa
{
    public:
    void lay() override
    {
        cout << "This is a victorian sofa : layeth" << endl;
    }
};

class ModernChair : public chair
{
    public:
    void sit() override
    {
        cout << "This is a modern chair : sit" << endl;
    }
};

class Modernsofa : public sofa
{
    public:
    void lay() override
    {
        cout << "This is a modern sofa : lay" << endl;
    }
};

class furniturefactory
{
    public:
    virtual chair* createchair() = 0;
    virtual sofa* createsofa() = 0;
};

class Modernfactory : public furniturefactory
{
    chair* createchair() override
    {
        return new ModernChair();
    }

    sofa* createsofa() override
    {
        return new Modernsofa();
    }
};

class vicotiranfactory : public furniturefactory
{
    chair* createchair() override
    {
        return new victorianchair;
    }

    sofa* createsofa() override
    {
        return new victoriansofa;
    }
};


int main()
{
    furniturefactory* f = new vicotiranfactory();

    chair* c = f -> createchair();
    sofa* s = f -> createsofa();
    c -> sit();
    s -> lay();    
    return 0;
}