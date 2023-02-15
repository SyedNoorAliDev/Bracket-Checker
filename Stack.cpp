#include <iostream>
using namespace std;
class Stack {
private:
    string array[1000];
    int top;
public:
    Stack() {
        top = -1;
    }
    int getTop(){
        return this->top;
    }

    bool push(string num) {
        top++;
        if (top <= 1000) {
            array[top] = num;
            cout << "  Pushed! ";
            return true;
        }
        cout << "  Stack Overflow  ";
        return false;
    }
    string getTopValue(){
        if (top>-1){
            string t=array[top];
            return t;
        } return "empty stack";

    }

    string pop() {
        if (top < 0) {
            return " ";
        } else {
            string a = array[top];
            --top;
            cout<<"  Popped!  ";
            return a;
        }

    }
    bool peek() {
        if (top < 0) {
            return true;
        }
        return false;

    }

    void printStack() {
        cout<<endl;
        for (int i = 0; i < top; i++) {
            cout <<" "<<array[i]<<" ";
        }
        cout<<endl;
    }

};