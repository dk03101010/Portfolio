#include <iostream>
#include "Question.h"
#include "Question.cpp"
using namespace std;
// File Name: assign1_yl12.cpp
//
// Author: Dillon Kern
// Date: 11/06/2017
// Assignment Number: 4
// CS 2308.256 Fall2017
// Instructor: Yijuan Lu
//
// Creates an array of 5 elements, containing the questions and answers and displays the test results
//
int main(){
string q1Answers [4] = {"Nibble","Ort","Scrap","Snippet"};
string q2Answers [4] = {"China","India","Mexico","Australia"};
string q3Answers [4] = {"Compass","Protractor","Ruler","T-Square"};
string q4Answers [4] = {"Camel","Eagle","Lion","Alligator"};
string q5Answers [4] = {"Birdie","Puck","Dart","Tile"};
Question q1("What name is given to half of a Byte (4 bits)?",q1Answers,'A');
Question q2("Which country is home to the Kangaroo?",q2Answers,'D');
Question q3( "What do you use to measure an angle?",q3Answers,'B');
Question q4("The Great Sphinx has the head of a human and the body of a what?",q4Answers,'C');
Question q5("What is the flat rubber disc used in a game of ice hockey?",q5Answers,'B');

Question q[5]={q1,q2,q3,q4,q5};


        for (int i=0; i<5; i++){
        q[i].display();

        }
         for (int i=0; i<5; i++){
        cout<<q[i].getKey()<<" ";
        }




return 0;
}
