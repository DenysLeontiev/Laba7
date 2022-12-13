#include <iostream>
#include <string>
#include <algorithm>
#include "Laba7.h"
using namespace std;

struct Product
{
    string ProductName;
    string ShopName;
    double Price;
};

int setValue(const char v[]);
void EnterProducts(Product *products, int &arrSize);
void FindProduct(string productName, Product *products, int &arrSize);
void OutputProduct(Product products);
void OutputAllProducts(Product *product, int &arrSize);
bool compare(Product a, Product b);
void drawLine(int = 40, char = '=');
Product* AddProd(Product* products, int& size);

int main()
{
    cout << "Hello,Welcome to the shop!" << endl;
    char action;
    string productName;
    cout << "Add initial values to the shop:" << endl;
    int arraySize = setValue("size");
    Product* products = new Product[arraySize];
    EnterProducts(products, arraySize);
    
    cout << "a - to add product" << endl << "f - to find product" << endl << "o - to output the list of products" << endl << "q - to quit the programm" << endl <<"s - to sort the list" <<  endl;
    cout << "Enter action:";cin >> action;

    while (action != 'q')
    {
        switch (action)
        {
        case 'o':
            OutputAllProducts(products, arraySize);
            cout << "Enter action: "; cin >> action;
            break;
        case 'f':
            cout << "Enter productName:";cin >> productName;
            FindProduct(productName, products, arraySize);
            cout << "Enter action: "; cin >> action;
            break;
        case 'a':
            products = AddProd(products, arraySize);
            cout << "Enter action: "; cin >> action;
            break;
        case 's':
            sort(products, products + arraySize, compare);
            cout << "List of products is sorted" << endl;
            cout << "Enter action: "; cin >> action;
            break;
        default:
            return 0;
            break;
        }
    }

}


Product* AddProd(Product* products, int& size) {
    size++;
    Product* newProducts = new Product[size];
    for (int i = 0; i < size - 1; i++)
    {
        newProducts[i].ProductName = products[i].ProductName;
        newProducts[i].ShopName = products[i].ShopName;
        newProducts[i].Price = products[i].Price;
    }

    Product newProduct;

    cout << "Adding new product: " << endl;
    cout << "ProductName: "; cin >> newProduct.ProductName;
    cout << "ShopName: "; cin >> newProduct.ShopName;
    cout << "Price: "; cin >> newProduct.Price;

    newProducts[size - 1] = newProduct;

    return newProducts;
}

void EnterProducts(Product *products, int &arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Enter #" << (i + 1) << " product:" << endl;
        cout << "ProductName: "; cin >> products[i].ProductName;
        cout << "ShopName: "; cin >> products[i].ShopName;
        cout << "Price: "; cin >> products[i].Price;
        //cout << "Enter name of the product" << "\t"; getline(cin, products[i].ProductName); cout << endl;
    }
}

void OutputAllProducts(Product *products, int &arrSize)
{
    cout << "Here is a list of all products" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Product # " << (i + 1) << endl;
        cout << " ProductName: "; cout << products[i].ProductName;
        cout << " ShopName: "; cout << products[i].ShopName;
        cout << " Price: "; cout << products[i].Price;
        cout << endl;
    }
    return;
}

void FindProduct(string productName, Product  *products, int &arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (products[i].ProductName == productName)
        {
            OutputProduct(products[i]);
        }
    }
}

void OutputProduct(Product product)
{
    cout << "Product name is " << product.ProductName << endl;
    cout << "Shop name is " << product.ShopName << endl;
    cout << "Product price is " << product.Price << endl;
    cout << endl;
}

bool compare(Product a, Product b) {
    if (a.ProductName.size() < b.ProductName.size())
    {
        return 1;
    }
    else if(a.ProductName.size() > b.ProductName.size())
    {
        return 0;
    }
    else
    {
        if (a.ShopName.size() < b.ShopName.size())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void drawLine(int n, char c)
{
    cout.fill(c);
    cout.width(n + 1);
    cout << "\n";
    cout.fill(' ');
    //cout << setfill(c) << setw(n + 1) << '\n' << setfill(' ');
}

int setValue(const char v[])
{
    int error;
    int value;
    do
    {
        error = 0;
        cout << "Please enter " << v << " = ";
        cin >> value;
        if (cin.fail())
        {
            cout.clear();
            cout << "Please enter a valid number" << endl;
            error = 1;
            cin.clear();
            cin.ignore(80, '\n');
        }
    } while (error == 1);

    return value;
}
