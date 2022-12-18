#include <iostream>
#include <string>
#include <algorithm>
#include "Declarations.h"
//#include "FuncImplementation.cpp"

using namespace std;


int main()
{
    cout << "Hello,Welcome to the shop!" << endl;
    char action;
    char* productName = new char[BUFSIZ];
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
            break;
        case 'f':
            //cin.getline(productName, BUFSIZ);
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Product name: ";fgets(productName, BUFSIZ, stdin);
            //cout << "Product name: ";cin >> productName;
            FindProduct(fgets(productName, BUFSIZ, stdin), products, arraySize);
            break;
        case 'a':
            products = AddProd(products, arraySize);
            break;
        case 's':
            sort(products, products + arraySize, compare);
            cout << "List of products is sorted" << endl;
            break;
        default:
            return 0;
            break;
        }

        cout << "Enter action: "; cin >> action;
    }

}



