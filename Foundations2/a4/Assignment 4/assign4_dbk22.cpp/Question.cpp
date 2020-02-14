
// File Name: QuestionTester.cpp
//
// Author: Yijuan Lu
// Date: 10/30/2017
// Assignment Number:4
// CS 2308 Fall 2017
// Instructor: Yijuan Lu
//
// Driver to test the Question class.

#include <iostream>
#include <iomanip>
using namespace std;

#include "Question.h"

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

 void  Question::setStem(string s){

    Stem=s;
 }

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
    /*cout << "A." << ('A'+i)<< Answers.[0] << endl;
    cout << "B." << Answers.[1] << endl;
    cout << "C." << Answers.[2] << endl;
    cout << "D." << Answers.[3] << endl;*/

    for( int i = 0; i < 4; i++)
    {
        cout << char('A' + i) << "." << Answers[i] << endl;
    }
}
//
//int main()
//{
//    Question q1;
//    q1.setStem("What name is given to half of a Byte (4 bits)?");
//    string q1Answers [] = {"Nibble","Ort","Scrap","Snippet"};
//    q1.setAnswers(q1Answers);
//    q1.setKey('A');
//
//    cout<< "q1 stem: " << q1.getStem() << endl;
//    cout<< "q1 first answer: " << q1.getAnswer(0) << endl;
//    cout<< "q1 last answer: " << q1.getAnswer(3) << endl;
//    cout <<"q1 correct answer: " << q1.getKey() << endl;
//    cout << endl;
//    string q2Answers [] = {"China","India","Mexico","Australia"};
//    Question q2("Which country is home to the Kangaroo?",q2Answers,'D');
//
//    q2.display();
//    cout << endl;
//    return 0;
//}
/* Expected output:

 q1 stem: What name is given to half of a Byte (4 bits)?
 q1 first answer: Nibble
 q1 last answer: Snippet
 q1 correct answer: A

 Which country is home to the Kangaroo?
 A. China
 B. India
 C. Mexico
 D. Australia

 */
