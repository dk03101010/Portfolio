#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED

using namespace std;
class Question
{
private:
   string Stem;
   string Answers[4];
   char key;

public:
    Question();

Question(string Stem1, string Answers1[], char key1);
    void setStem(string);
    string getStem();
    void setAnswers(string[]);
    string getAnswer(int);
    void setKey(char);
    char getKey();
    void display() const;
};

#endif // QUESTION_H_INCLUDED
