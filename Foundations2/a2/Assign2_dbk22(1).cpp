// File Name: assign2_dbk22.cpp
//
// Author: Dillon Kern// Date: 10/3/2017
// Assignment Number: 2
// CS 2308.256 Fall2017
// Instructor: Yijuan Lu
//
// Display's a store's inventory. Displays a menu
// that gives the user the option to display inventory,
// search by SKU, and search by name. Also uses sorting and searching.
//
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


struct product
{
    string name;
    int sku;
    int qty;
    double price;


};
// function definitions
void displayInventory(product[],int);
void sortSku (product [], int);
int searchSku(product [], int, int);
int searchName(product[], int, string);


int main()
{
    const int SIZE= 100;
    product item[SIZE];
    int count = 0;



    ifstream fin;
    fin.open ("inventory.dat");
//Validate if file open
    if(!fin)
    {
        cout << "Error File did not open"<<endl;
    }

    while (fin >> item[count].name)
    {
        fin >> item[count].sku;
        fin >> item[count].qty ;
        fin >> item[count].price;

        count = count + 1;
    }

// Constants for menu choices
    const int DISPLAY_INVENTORY = 1,
              LOOKUP_SKU = 2,
              LOOKUP_NAME = 3,
              QUIT_CHOICE = 4;

    int choice;       // Menu choice

// Set up numeric output formatting.
    cout << fixed << showpoint << setprecision(2);

    do
    {
// Display the menu.
        cout << "\n\t\tInventory Menu\n\n"
             << "1. Display Inventory\n"
             << "2. Look up Product by SKU\n"
             << "3. Look up Product by Name\n"
             << "4. Quit the Program\n\n"
             << "Enter your choice: ";
        cin >> choice;

// Validate the menu selection.
        while (choice < DISPLAY_INVENTORY || choice > QUIT_CHOICE)
        {
            cout << "Please enter a valid menu choice: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
        {


            sortSku (item, count);
            displayInventory(item, count);

        }
        break;

        case 2:
        {
            int value;
            sortSku (item, count);
            cout << "enter the product SKU number: "<<endl;
            cin >> value;
            value= searchSku(item, count, value);
            if (value ==-1)
            {
                cout << "No product found with this SKU number";
            }
            else
            {
                cout << "Product name:" << item[value].name<<endl;
                cout << "SKU:" << item[value].sku<<endl;
                cout << "Quantity:" << item[value].qty<<endl;
                cout << "Price:" << item[value].price<<endl;
            }
        }
        break;




        case 3:
        {


            int result=0;
            string product;
            cout << "Enter product name of product to find: "<<endl;
            cin.ignore();
            getline(cin,product);
            result= searchName( item, count, product);
            if (result ==-1)
            {
                cout << "No product found with this product name";
            }
            else
            {
                cout << "Product name:" << item[result].name<<endl;
                cout << "SKU:" << item[result].sku<<endl;
                cout << "Quantity:" << item[result].qty<<endl;
                cout << "Price:" << item[result].price<<endl;
            }
        }
        break;
        case 4:
            cout << "Exiting the Program"<<endl;
            break;


        }
    }



    while (choice!= QUIT_CHOICE);
    return 0;
}
//***********************************************************
// displayInventory: uses a simple for loop to access the
//structure containing the store inventory.
// param1 accesses the product struct
// param2 initializes a count for how many times the loop will run.
//***********************************************************
void displayInventory(product item[], int count)
{

    for (int i=0; i < count; i++)
    {
        //cout<<fixed <<setprecision(2)<< setw(4)<<left;
        cout <<setw(8)<<item[i].sku;
        cout <<setw(8)<<item[i].qty;
        cout <<setw(8)<<item[i].price<<" ";
        cout <<setw(8)<<item[i].name<<endl;
    }
}

//***********************************************************
// sortSku: uses a simple bubble sort to sort the sku numbers.
//
// param1 accesses the product struct
// param2 initializes a count for how many times the loop will run.
//***********************************************************
void sortSku (product item[], int count)
{
    for (int i=1; i < count; i++)
    {
        while (i != 0 && item[i].sku < item[i-1].sku)
        {
            swap(item[i], item[i-1]);
            i--;
        }
    }
}
//***********************************************************
// searchSku: uses binary search to search for the sku number
//
// param1 accesses the product struct
// param2 initializes a count for how many times the loop will run.
// param3 gives a variable for the value
// returns the position
//***********************************************************

int searchSku(product item[], int count, int value)
{
    //Binary search algorithm.
    int first = 0,
        last = count - 1,
        middle,
        pos=-1;
    bool found = false;
    while (!found &&first <= last)
    {
        middle = (first + last) / 2;
        if(item[middle].sku == value)
        {
            found=true;
            pos = middle;
        }
        else if (item[middle].sku > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return pos;
}
//***********************************************************
// displayInventory: searches the product name.
//
// param1 accesses the product struct
// param2 initializes a count for how many times the loop will run.
// param3 assigns a variable for the product string.
// returns position
//***********************************************************

int searchName(product item[], int count, string value)
{

    int pos=-1;
    for(int i=0; i<count; i++)
    {
        if(item[i].name==value)
        {
            pos=i;
            break;
        }
    }
    return pos;
}






