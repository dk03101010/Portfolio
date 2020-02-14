// File Name: StringList.cpp
//
// Author: Dillon Kern
// Date: 11/17/2017
// Assignment Number: 5
// CS 2308.256 Fall2017
// Instructor: Yijuan Lu
//
//
// Interface that manipulates strings.
//

#include<iostream>
#include<iomanip>
#include "StringList.h"

using namespace std;
//***********************************************************
// StringList
//
//
// Creates and empty list of strings
//**********************************************************
StringList::StringList()
{
    head=NULL;
}
//***********************************************************
// function name: ~StringList
//
//
// Deallocates all the nodes in the list
//**********************************************************
StringList::~StringList()
{
    StringNode *p;
    StringNode *n;


    p = head;

    while (p)
    {

        n=p->next;
        delete p;
        p = n;
    }
}
//***********************************************************
//count
//
//
// returns the total number of strings in the list.
//**********************************************************
int StringList::count()
{
    StringNode *p=head;
    int n=0;
    while (p)
    {
        n++;
        p=p->next;

    }
    return n;

}
//***********************************************************
// Add
//
// param1: var creates an object for the string.
// Adds a new node containing the string to the end of the list
//**********************************************************
void StringList::add(string var)
{
    StringNode *newNode;
    StringNode *p;

    newNode = new StringNode;
    newNode->data = var;
    newNode->next=NULL;


    if(!head)
        head=newNode;
    else
    {
        p= head;

        while(p->next)
            p= p->next;


        p->next=newNode;


    }
}
//***********************************************************
// Remove
//
// param1: var creates an object for the string.
// removes a node containing the given string from the list.
//**********************************************************
bool StringList::remove(string var)
{
    StringNode *p=head;
    StringNode *n;


    if(!head)
        return false;

    if(head->data ==var)
    {
        p=head->next;
        head->next = NULL;
        delete head;
        head = p;
    }
    else
    {
        p = head;

        while (p !=NULL && p->data !=var)
        {
            n=p;
            p=p->next;
        }
        if(p)
        {
            n->next= p->next;
            p->next = NULL;
            delete p;
            return true;
        }
        return false;
    }
}
//***********************************************************
// Display
//
//
// displays the strings in the list to the screen.
//**********************************************************
void StringList::display()
{
    StringNode *p =head;

    while(p)
    {
        cout  << p->data<< " ";


        p=p->next;
    }
    cout << endl;
}
string StringList::minimum()
{
    StringNode *p;
    p=head;


    string mini= p->data;


    while (p)
    {
        if(p->data<mini)
        {
            mini=p->data;
        }

        p = p -> next;
    }


    return mini;
}
//***********************************************************
// Sort:
//
//
// Finds the minimum calling the function. sorts the list,
// inserts the node into the proper position.
// Makes the old head pointer point to the new list.
//**********************************************************
 void StringList::sort()
 {

     StringNode *p = NULL;
     while (head!=NULL){
         string var= minimum();
        StringNode *newNode  = new StringNode;
        newNode->data = var;
        newNode->next = NULL;

        StringNode * lastNode = p;
        if(p != NULL)
        {
            while(lastNode->next)
                lastNode = lastNode->next;

            lastNode->next = newNode;
        }
        else
        {
            p = newNode;
        }

        remove(var);
     }

     head = p;

 }
