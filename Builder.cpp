#include <iostream>

using namespace std;

class car
{
    public:
    string wheels, engine, torque, brand;
    void display()
    {
        cout << wheels << "," << engine << "," << torque << "," << brand << endl;
    }
};

class carbuilder
{
    public:
    virtual void getwheels() = 0;
    virtual void getengine() = 0;
    virtual void gettorque() = 0;
    virtual void getbrand() = 0;
    virtual car* getchar() {}
};

class createcar : public carbuilder
{
    public:
    car* CAR;
    createcar() {CAR = new car();}
    void getwheels() override {CAR -> wheels = "4 wheels";}
    void getengine() override {CAR -> engine = "mercedes engine";}
    void gettorque() override {CAR -> torque = "4000nM";}
    void getbrand() override {CAR -> brand = "mercedes AMG";}
    car* getchar() override {
        return CAR;
    }
};

class worker
{
    public:
    void merge(carbuilder* c)
    {
        c-> getwheels();
        c -> getengine();
        c -> gettorque();
        c -> getbrand();
    }
};

int main()
{
    createcar c;
    worker work;
    work.merge(&c);
    car* cat = c.getchar();
    cat->display();
}