#include <iostream>
using namespace std;

class shape
{
    public:
    virtual shape* clone() = 0; 
    virtual void print() = 0;
};

class circle : public shape
{
    private:
    int radius;

    public:
    circle(int r) : radius(r) {}

    circle* clone() override
    {
        return new circle(*this);
    }

    void print() override
    {
        cout << "circle with radius : " << radius << endl;
    }
};

int main()
{
    shape* c1 = new circle(5);
    shape* c2 = c1 -> clone();

    c1 -> print();
    c2 -> print();
    return 0;
}