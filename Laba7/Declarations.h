#pragma once
#include <cstdio>

struct Product
{
    char* ProductName = new char[BUFSIZ];
    char* ShopName = new char[BUFSIZ];
    double Price;
};

int setValue(const char v[]);
void EnterProducts(Product* products, int& arrSize);
void FindProduct(char* productName, Product* products, int& arrSize);
void OutputProduct(Product products);
void OutputAllProducts(Product* product, int& arrSize);
bool compare(Product a, Product b);
void drawLine(int = 40, char = '=');
Product* AddProd(Product* products, int& size);