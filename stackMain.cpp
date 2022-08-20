#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

int globalID = 100;

class person{
    string name;
    int id;
    float salary;

public:
    person(){
        name = "";
        id = -1;
        salary = -1.0;
    }
    void setName(string name){
        this->name = name;
    }

    void setSalary(float salary){
        this->salary = salary;
    }

    person(string name,float salary)
    {
        setName(name);
        setSalary(salary);
        id = globalID;
        globalID++;
    }

    int getID(){
        return id;
    }

    string getName(){
        return name;
    }

    float getSalary()
    {
        return salary;
    }

    void print(){
        cout<<name<<" | "<<id<<" | "<<salary<<endl;
    }


};

int main()
{
    Stack <person> st;
    person a ("Rahim Hossain",654.6);
    person b ("Madiha Hossain",754.6);
    person c ("Karim Hossain",854.6);
    st.push(a);
    st.push(b);
    st.push(c);

    while (!st.empty()){
        person print;
        print = st.pop();
        print.print();
    }
       
    return 0;
}