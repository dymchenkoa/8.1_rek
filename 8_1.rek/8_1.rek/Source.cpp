#include <iostream>
#include <string>
using namespace std;

int IsOrNot(char* s)
{
    int counter = 0;
    for (size_t i = 0; i < strlen(s) - 4; i++)
        if (s[i] == 'w' && s[i + 1] == 'h' && s[i + 2] == 'i' && s[i + 3] == 'l' && s[i + 4] == 'e')
            ++counter;
    return counter;
}

char* change(char* s)
{
    char* sNew = new char[101];
    size_t l = 0;
    for (size_t i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'w' && s[i + 1] == 'h' && s[i + 2] == 'i' && s[i + 3] == 'l' && s[i + 4] == 'e')
        {
            sNew[l] = '*';
            sNew[l + 1] = '*';
            sNew[l + 2] = '*';
            l += 3;
            i += 4;
        }
        else
        {
            sNew[l] = s[i];
            ++l;
        }
    }
    sNew[l] = '\0';
    strcpy_s(s, strlen(sNew) + 1, sNew);
    delete[] sNew;
    return s;
}

int main()
{
    char* s = new char[101];
    cout << "Enter string:" << endl;
    cin.getline(s, 100);
    int count = IsOrNot(s);
    if (count > 0)
    {
        cout << "Count of 'while': " << count << endl;
        char* t = change(s);
        cout << t;
    }
    else
        cout << "'while' is not found." << endl;
    delete[] s;
    cout << endl;
}