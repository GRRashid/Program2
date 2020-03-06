#ifndef PROGRAMMING_TEXTFLOW_H
#define PROGRAMMING_TEXTFLOW_H

#include <string>
using namespace std;

class TextFlow {
public:
    explicit TextFlow(const string&);
    explicit TextFlow();
    int Open(const string&);
    int Close();
    string GetName();
    bool IsOpen();
    int Write(const string&);
    int Write(int);
    int Write(float);
    ~ TextFlow();
private:
    string name;
    bool isopen = false;
    FILE* file;
};


#endif //PROGRAMMING_TEXTFLOW_H
