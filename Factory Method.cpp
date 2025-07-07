#include <iostream>

using namespace std;

class shape 
{
    public:
    virtual void draw() = 0;
};

class circle : public shape
{
    public:
    void draw() override
    {
        cout << "shape is circle " << endl;
    }
};

class square : public shape
{
    public:
    void draw() override
    {
        cout << "shape is square " << endl;
    }
};

class shapefactory
{
    public:
    virtual shape* createshape() = 0;
};

class circlefactory : public shapefactory
{
    shape* createshape() override
    {
        return new circle();
    }
};

class squarefactory : public shapefactory
{
    public:
    shape* createshape() override{
        return new square();
    }
};

int main()
{
    shapefactory* f = nullptr;
    string shapeType;
    cin >> shapeType;

    if(shapeType == "circle")
    {
        f = new circlefactory();
    }
    else if (shapeType == "square")
    {
        f = new squarefactory();
    }
    else
    {
        cout << "error";
        return 1;
    }

    shape* shp = f -> createshape();
    shp -> draw();
    return 0;

}