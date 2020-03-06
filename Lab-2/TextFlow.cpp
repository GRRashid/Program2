#include "TextFlow.h"
#include <cstdlib>
using namespace std;

TextFlow::TextFlow() {
    this->name = "";
    this->isopen = false;
    this->file = nullptr;
}

TextFlow::TextFlow(const string& name) {
    Open(name);
}

int TextFlow::Open(const string& NewName) {
    this->name = NewName;
    if(!(this->file = fopen(NewName.c_str(), "w"))) return 1;
    this->isopen = true;
    return 0;
}

int TextFlow::Close() {
    fclose(this->file);
    this->file = nullptr;
    this->name = "";
    this->isopen = false;
    return 0;
};

string TextFlow::GetName() {
    return this->name;
};

bool TextFlow::IsOpen() {
    return isopen;
}

int TextFlow::Write(const string& text) {
    if (!IsOpen()) return 1;
    for (const char& i : text)
        putc((int)i, this->file);
    return 0;
}

int TextFlow::Write(int number) {
    if (!IsOpen()) return 1;
    char* text = new char[100];
    itoa(number, text, 10);
    int res = this->Write(text);
    return res;
}
int TextFlow::Write(float number) {
    if (!IsOpen()) return 1;
    char* text = new char[100];
    sprintf(text, "%f", number);
    int res = this->Write(text);
    return res;
}
TextFlow::~TextFlow() {
    Close();
}
