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

const int shopSize = 2;

void EnterProducts(Product  products[shopSize]);
void FindProduct(string productName, Product  products[shopSize]);
void OutputProduct(Product product);
void OutputAllProducts(Product product[shopSize]);
bool compare(Product a, Product b);
void drawLine(int = 40, char = '=');

int main()
{
    Product products[shopSize];
    EnterProducts(products);
    drawLine();
    cout << "Before sorting: " << endl;
    OutputAllProducts(products);
    drawLine();
    cout << "After sorting: " << endl;
    sort(products, products + shopSize, compare);
    OutputAllProducts(products);
    drawLine();
    cout << "Find a product: " << endl;
    string prodName;
    cin >> prodName;
    FindProduct(prodName, products);

    return 0;
}

void EnterProducts(Product  products[shopSize])
{
    for (int i = 0; i < shopSize; i++)
    {
        cout << "Enter #" << (i + 1) << " product:" << endl;
        cout << "ProductName: "; cin >> products[i].ProductName;
        cout << "ShopName: "; cin >> products[i].ShopName;
        cout << "Price: "; cin >> products[i].Price;
        //cout << "Enter name of the product" << "\t"; getline(cin, products[i].ProductName); cout << endl;
    }
}

void OutputAllProducts(Product products[shopSize])
{
    cout << "Here is a list of all products" << endl;
    for (int i = 0; i < shopSize; i++)
    {
        cout << "Product # " << (i + 1) << endl;
        cout << " ProductName: "; cout << products[i].ProductName;
        cout << " ShopName: "; cout << products[i].ShopName;
        cout << " Price: "; cout << products[i].Price;
        cout << endl;
    }
}

void FindProduct(string productName, Product  products[shopSize])
{
    for (int i = 0; i < shopSize; i++)
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
