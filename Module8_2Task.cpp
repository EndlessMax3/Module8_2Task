#include <iostream>
#include "Stack.h"
using std::boolalpha;
bool verifyParntness(const char* s)
{
    int len = strlen(s);
    Stack<char> st;
    for (int i = 0; i < len; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '[')
            st.push(ch);
        if (ch == ')' || ch == ']')
            if (st.isEmpty()) return false;
            else
            {
                char ch2 = st.pop();
                if (!((ch2 == '(' || ch2 == ')') || (ch2 == '[' || ch2 == ']')))
                    return false;
            }
    }
    return st.isEmpty();
}

int main()
{
    Stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
    st1.push(6);
    st1.push(7);
    st1.push(8);
    st1.push(9);
    st1.push(10);
    st1.push(11);
    st1.push(12);
    st1.pop();
    //вывод st1 в консоль
    cout << "Stack 1(int): " << endl;
    while (!st1.isEmpty())
        cout << st1.pop() << " ";
    cout << endl;

    Stack<char>* st2 = new Stack<char>;
    st2->push('A');
    st2->push('B');
    st2->push('C');
    st2->push('D');
    st2->push('E'); 
    st2->push('F');
    st2->push('G');
    st2->push('H');
    st2->push('K');
    st2->push('L');
    st2->push('M');
    st2->push('N');
    st2->pop();
    //вывод st2 в консоль
    cout << "Stack 2(char): " << endl;
    while (!st2->isEmpty())
        cout << st2->pop() << " ";
    cout << endl;

    const char* str = "( ( [ + ] ) - [ ] * () )";
    cout << "For string '" << str << "': " << verifyParntness(str) << endl;
    bool result = st2->isEmpty();
    delete st2;
    return result;

}
