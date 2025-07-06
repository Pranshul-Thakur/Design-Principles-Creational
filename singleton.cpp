#include <iostream>

using namespace std;

class Logger
{
    private:
    Logger(){}
    static Logger* instance;
    
    public:
    static Logger* getinstance()
    {
        if(instance = nullptr)
        {
            instance = new Logger;
        }
        return instance;
    }

    void log(const string& a) 
    {
        cout << "log : "<< a << endl;
    }
};

Logger* Logger:: instance = nullptr;

int main()
{
    Logger* l1 = Logger::getinstance();
    l1 -> log("started the app");

    Logger* l2 = Logger::getinstance();
    l2 -> log("still the same logger");

    cout << (l1 == l2) << endl;
    return 0;
}