#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main(int argc,  char* argv[])
{
    int i = 0;
    string test;
    std::stack<char> s;
    test = argv[1];

    ofstream outfile("test.txt");
    outfile << "Errors:\n" << std::endl;
    while (test[i] != '\0')
    {
        char temp = test[i];
        i++;
        if (temp == '(' || temp == '{' || temp == '[')
        {
            s.push(temp);
            continue;
        }
        else
        {
            if (temp == ')' || temp == '}' || temp == ']')
            {
                if (s.empty())
                {
                   outfile << "Closing breaket without any opening breacket at word no " << i << std::endl;
                   break;
                }
                if (temp == ')'){

                    if( s.top() == '(' )
                    {
                        s.pop();
                        continue;
                    }
                    else {
                            outfile << "Closing of '" << s.top() << "' by ')' breaket at word no. " << i << std::endl;
                            break;
                    }
                }

                if (temp == '}'){
                    if( s.top() == '{' )
                    {
                        s.pop();
                        continue;
                    }
                    else {
                            outfile << "Closing of '" << s.top() << "' by '}' breaket at word no. " << i << std::endl;
                            break;
                    }
                }

                if (temp == ']'){
                    if( s.top() == '[' )
                    {
                        s.pop();
                        continue;
                    }
                    else {
                        outfile << "Closing of '" << s.top() << "' by ']' breaket at word no. " << i << std::endl;;
                        break;
                    }
                }
            }
        }
    }

    if (!s.empty() && i == test.size())
    {
        outfile << "Some breackets left unclosed" << std::endl;
    }
    outfile.close();
    return 0;
}
