#include <iostream>
using namespace std;

class IValid //интерфейс            
{
    public:
    virtual bool IsValid(int _price) = 0;
};

class Product
{
    private:
    int price;

    public:
    Product (int _price = 0)
    {
        price = _price;
    }
    int Get_Price()
    {
        return price;
    }
};

class ValidStandart: public IValid 
{
    public:
    bool IsValid(int _price) override
    {
        if (_price > 0)
        {
            return true;
        }
        return false;
    }
};

class ValidCustom: public IValid 
{
    public:
    bool IsValid(int _price) override
    {
        if (_price > 100000)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Product product1 (200200);
    
    ValidStandart valid1;   // > 0
    ValidCustom valid2;     // > 100000
    
    cout << valid1.IsValid(product1.Get_Price()) << endl;
    cout << valid2.IsValid(product1.Get_Price()) << endl;

    return 0;
}


