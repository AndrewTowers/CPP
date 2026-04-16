#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    string str;

    if (argc == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return 0;
    }
    for (int i = 0; argv[1][i]; i++)
    {
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            str += argv[1][i] - 32;
        else
            str += argv[1][i];
    }
    cout << str << endl;
    return 0;
}