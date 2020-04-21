#include "TextFlow.h"
#include <iostream>
using namespace std;


int main() {
    TextFlow a = TextFlow();
    char com;
    string text;
    int num;
    float numf;
    while (true) {
        cout << "-------===MENU===-------\n"
                "Available commands:\n"
                "1. Open file with entered name\n"
                "2. Close file.\n"
                "3. Check: is open?\n"
                "4. Get File name\n"
                "5. Enter string in file\n"
                "6. Enter int in file\n"
                "7. Enter float in file\n"
                "8. Exit\n"
                "Enter number: ";
        cin >> com;
        switch (com) {
            case '1':
                cout << "Enter name: ";
                cin >> text;
                a.Open(text);
                break;
            case '2':
                if (a.Close() != 0)
                    cout << "Not Closed" << '\n';
                else
                    cout << "Closed" << '\n';
                break;
            case '3':
                cout << "Is Open?: " << (a.IsOpen()? "YES": "NO") << '\n';
                break;
            case '4':
                cout << a.GetName() << '\n';
                break;
            case '5':
                cin >> text;
                a << text;
                cout << "Add string\n";
                break;
            case '6':
                cin >> num;
                a << num;
                cout << "Add int\n";
                break;
            case '7':
                cin >> numf;
                a << numf;
                cout << "Add float\n";
                break;
            case '8':
                goto exit;
            default:
                break;
        }
    }
    exit:
    return 0;
}
