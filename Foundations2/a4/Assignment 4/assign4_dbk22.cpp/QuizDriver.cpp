#include <iostream>
#include "Question.h"
using namespace std;

int main()
{
    //Question q;
//Question(string, string[], char);
/*
  Question q[5]={{"What name is given to half of a Byte (4 bits)?"},
  {"Which country is home to the Kangaroo?"},
  {"What do you use to measure an angle?"},
  {"The Great Sphinx has the head of a human and the body of a what?"},
  {"What is the flat rubber disc used in a game of ice hockey?"}};
//}
*/
string q1Answers [] = {"Nibble","Ort","Scrap","Snippet"};
string q2Answers [] = {"China","India","Mexico","Australia"};
string q3Answers [] = {"Compass","Protractor","Ruler","T-Square"};
string q4Answers [] = {"Camel","Eagle","Lion","Alligator"};
string q5Answers [] = {"Birdie","Puck","Dart","Tile"};
Question q1("What name is given to half of a Byte (4 bits)?",q1Answers,'A');
Question q2("What name is given to half of a Byte (4 bits)?",q1Answers,'A');
Question q3("What name is given to half of a Byte (4 bits)?",q1Answers,'A');
Question q4("What name is given to half of a Byte (4 bits)?",q1Answers,'A');
Question q5("What name is given to half of a Byte (4 bits)?",q1Answers,'A');
Question q[5]={q1,q2,q3,q4,q5};


        for (int i=0; i<5; i++){
        q[i].display();

        }
    //cout <<


return 0;

}

