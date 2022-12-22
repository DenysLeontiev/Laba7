#include "Declarations.h"
#include <cstdio>
#include <iostream>
using namespace std;

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
    //cout << "ProductName: "; fgets(newProduct.ProductName, BUFSIZ, stdin);

        /*cout << "ProductName: "; cin >> newProduct.ProductName;
    cout << "ShopName: "; cin >> newProduct.ShopName;
    cout << "Price: "; cin >> newProduct.Price;*/
    cout << "Adding new product: " << endl;
    //cin.clear();
    cin.ignore(80, '\n');
    cout << "ProductName: "; fgets(newProduct.ProductName, BUFSIZ, stdin);
    cout << "ShopName: "; fgets(newProduct.ShopName, BUFSIZ, stdin);
    cout << "Price: "; cin >> newProduct.Price;

    newProducts[size - 1] = newProduct;

    return newProducts;
}

void EnterProducts(Product* products, int& arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        fgets(products[i].ProductName, BUFSIZ, stdin);
        cout << "Enter #" << (i + 1) << " product:" << endl;
        cout << "ProductName: "; fgets(products[i].ProductName, BUFSIZ, stdin);
        cout << "ShopName: "; fgets(products[i].ShopName, BUFSIZ, stdin);
        cout << "Price: "; cin >> products[i].Price;
        //cout << "Enter name of the product" << "\t"; getline(cin, products[i].ProductName); cout << endl;
    }
}

void OutputAllProducts(Product* products, int& arrSize)
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

void FindProduct(char* productName, Product* products, int& arrSize)
{
    bool hasFound = false;
    for (int i = 0; i < arrSize; i++)
    {
        if(!strcmp(products[i].ProductName, productName)) // TODO: CHeck string
        {
            hasFound = true;
            OutputProduct(products[i]);
        }
    }

    if (!hasFound)
    {
        cout << "No product with " << productName << " was found!" << endl;;
    }
}

void OutputProduct(Product product)
{
    cout << endl;
    cout << "Product name is " << product.ProductName;
    cout << "Shop name is " << product.ShopName;
    cout << "Product price is " << product.Price;
    cout << endl;
}

bool compare(Product a, Product b) {
    if (strlen(a.ProductName) < strlen(b.ProductName))
    {
        return 1;
    }
    else if (strlen(a.ProductName) > strlen(b.ProductName))
    {
        return 0;
    }
    else
    {
        if (strlen(a.ShopName) < strlen(b.ShopName))
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