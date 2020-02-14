
// File Name: Question.cpp
//
// Author: Dillon Kern
// Date: 11/06/2017
// Assignment Number:4
// CS 2308 Fall 2017
// Instructor: Yijuan Lu
//
// Driver to test the Question class.

#include <iostream>
#include <iomanip>
#include "Question.h"

using namespace std;


//***********************************************************
// Question::Question: Creates the Question class, 4 answer choices, and the key
//
//
//
//
//
//***********************************************************
Question::Question(){
    Stem=" ";
    for(int i=0;i<4;i++)
    {
         Answers[i]=" ";
    }
    key ='x';
}

Question::Question(string Stem1, string Answers1[], char key1)
 {

    Stem = Stem1;
    for(int i=0;i<4; i++){
        Answers[i]= Answers1[i];
    }
    key= key1;

 }
//***********************************************************
// Question::Question: Creates a stem for the question
//

//***********************************************************
 void  Question::setStem(string s){

    Stem=s;
 }
//***********************************************************
// Question::Question: Creates the Question class, 4 answer choices, and the key
//
//
//***********************************************************
 string Question::getStem(){

 return Stem;
 }

void Question::setAnswers(string arr[]){

for (int i=0; i < 4; i++)
{
    Answers[i]=arr[i];
}
}

string Question::getAnswer(int index)
{
    return Answers[index];
}

void Question::setKey(char k){
    key=k;
}

char Question::getKey(){

return key;
}
void Question::display() const{
    cout << Stem << endl;

    for( int i = 0; i < 4; i++)
    {
        cout << char('A' + i) << "." << Answers[i] << endl;
    }
    cout<<endl;
}
