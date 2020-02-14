using namespace std;
class Question
{
private:
   string Stem;
   string Answers[4];
   char key;

public:
    Question();
    Question(string, string[], char);
    void setStem(string);
    string getStem();
    void setAnswers(string[]);
    string getAnswer(int);
    void setKey(char);
    char getKey();
    void display() const;
};
