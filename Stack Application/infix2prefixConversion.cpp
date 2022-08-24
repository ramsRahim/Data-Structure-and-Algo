#include<bits/stdc++.h>
#include"/Users/rahimhossain/Documents/codes/Data Structure and Algo/MYSTACK.h"

using namespace std;

// s1 : Reverse the string

/* s2:
        1. if(0-9)--> print
        2. if ')' --> push
        3. if '(' ---> pop and print until ')'
        4. 1(+,-),2(*,/), -1(others)
*/

int precisionCalc(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '/' || c == '*'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else return -1;
}

string infixToPrefic(string chk){

    reverse(chk.begin(),chk.end());
    Stack<char> st;
    string result;
    for(int i=0; i<chk.length();i++)
    {
        if(chk[i] >= '0' && chk[i] <= '9'){
            result+=chk[i];
        }

        else if(chk[i] == ')'){
            st.push(chk[i]);
        }
        else if(chk[i] == '('){
            while(!st.empty() && st.TOP()!=')')
            {
                result+=st.pop();
            }
            if(!st.empty())
                 st.pop();
        }

        else{
            while(!st.empty() && precisionCalc(st.TOP()) >= precisionCalc(chk[i]))
            {
                result += st.pop();
            }

            st.push(chk[i]);
        }
    }

    while(!st.empty())
    {
        result += st.pop();
    }

    reverse(result.begin(),result.end());

    return result;
}

int prefixEvaluation(string chk){
    Stack<int> st;

    for(int i=chk.length()-1;i>=0;i--){
        // chk[i] 0 to 9 --> Operand
        if(chk[i] >= '0' && chk[i] <= '9'){
            st.push(chk[i]-'0');
        }
        //chk[i]-->operator
        else{
            int a = st.pop();
            int b = st.pop();

            switch(chk[i])
            {
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(a/b);
                break;
            case '^':
                st.push(pow(a,b));
                break;
            default:
                break;
            }
        }
    }

    return st.TOP();
}

int main()
{
    string infix, prefix;
    //cin>>infix;
    infix = "(7+(4*5))-(2+0)";
    prefix = infixToPrefic(infix);
    cout<<prefix<<endl;
    cout<<prefixEvaluation(prefix)<<endl;
    return 0;
}


