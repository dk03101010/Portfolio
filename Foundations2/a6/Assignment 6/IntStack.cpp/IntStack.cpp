// File Name: assign6_dbk22.cpp
//
// Author: Dillon Kern
// Date: 12/06/2017
// Assignment Number: 6
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
// given a text file, the program will determine
// all the parenthesis, braces, and square brackets match
// and are nested properly.

#include <iostream>
#include <cassert>
#include "IntStack.h"


using namespace std;

//***********************************************************
//IntStack::IntStack
//
// makes head NULL
//***********************************************************
IntStack::IntStack()
{
    head = NULL;
}
//***********************************************************
// IntStack::~IntStack
//
// Destructor dynamically allocates the node
//***********************************************************
IntStack::~IntStack()
{
    Node *Node = NULL,  *next = NULL;


    Node = head;

    while (Node != NULL)
    {
        next = Node->next;
        delete Node;
        Node = next;
    }
}
//***********************************************************
// void IntStack::push(int num)
//
// pushes the argument onto the stack
// int num holds the num variable.
//***********************************************************
void IntStack::push(int num)
{

    Node *newNode = NULL;

    newNode = new Node;
    newNode -> data= num;

    if (isEmpty())
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
        head = newNode;

    }

}
//***********************************************************
// int IntStack::pop()
//
//
// pops the value at the top of the stack off, and returns it as
//a result.
//***********************************************************
int IntStack::pop()
{

    int num;

    Node *temp = NULL;

    if (isEmpty())
    {
        cout << "The stack is empty.";
    }
    else
    {
        num = head->data;
        temp = head -> next;
        delete head;
        head = temp;
    }
    return num;
}
//***********************************************************
// bool IntStack::isEmpty()
//
//checks if the stack is empty
//***********************************************************
bool IntStack::isEmpty()
{

    bool stat;

    if (!head)
        stat = true;
    else
        stat = false;

    return stat;
}
//***********************************************************
//bool IntStack::isFull ()
//
//Checks if the stack is full
//***********************************************************
bool IntStack::isFull ()
{
    int i = 0;
    int const SIZE = 250;   //change the size depending on input.
    Node* newNode = head;
    while (newNode)
    {
        i++;
        newNode = newNode->next;
    }

    if (i >= SIZE)
        return true;
    else
        return false;

}




