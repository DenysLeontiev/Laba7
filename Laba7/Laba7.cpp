#include <iostream>
#include <string>
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

int main()
{
    Product products[shopSize];
    EnterProducts(products);
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

