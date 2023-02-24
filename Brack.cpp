#include <iostream>
using namespace std;
#include "Stack.cpp";
class BracketDetector{
private:
    Stack st;
    int counter;
    int errorLoc1;
    int errorLoc2;
public:
    BracketDetector(){
        counter = -1;
        errorLoc1 = 0;
        errorLoc2 = 0;
    }
    string stringMaker(string str){
        string a;
        for (char c:str){
            if ((c == '(') || (c == '{') || (c == '[') || (c == ')') || (c == '}') || (c == ']')){
                a += c;
            }
        }
        return a;
    }
    bool isEven(string str){
        if ((stringMaker(str).size()%2)==0){
            return true;
        }
        return false;
    }
    bool CheckBrackets(string str){
        str = stringMaker(str);
        if (isEven(str)){
            cout<<endl<<"Entering in for loop"<<endl;
            for (int i=0;i<(str.size());i++){
                if ((str[i] == '(') || (str[i] == '{') || (str[i] == '[')){
                    string ab(1,str[i]);
                    counter += 1;
                    st.push(ab);
                    errorLoc2 = -1;
                    if (errorLoc1 == -1){
                        errorLoc1 = i;
                    }

                }
                else if ((st.getTopValue() != "empty stack")){
                    if ((str[i] == ')' && st.getTopValue()[0]=='(') || ((str[i] == '}' && st.getTopValue()[0]=='{')) || (str[i] == ']' && st.getTopValue()[0]=='[')){
                        st.pop();
                        counter -= 1;
                        errorLoc1 = -1;
                    }
                } else {
                    counter -= 1;
                    errorLoc1 = -1;
                    if (errorLoc2 != -1){
                        errorLoc2 = i;
                        cout<<errorLoc2;
                    }
                }
                if (counter<-1){
                    errorLoc2 = i;
                    break;
                }

            }
            errorDescriptionGenerator(str);
        } else {
            cout<<endl<<"Odd Number of Brackets"<<endl;
        }
    }
    int errorLocation1(){
        return errorLoc1;
    }
    int errorLocation2(){
        return errorLoc2;
    }
    void errorDescriptionGenerator(string str){
        if (st.getTop()>-1){
            cout<<endl<<"ERROR: No. of (Open Brackets > Closed brackets)"<<endl;
            cout<<endl<<"Description: Unclosed brackets at "<<errorLocation1()<<endl;
        }
        else if (counter == -1){
            cout<<endl<<"Balanced"<<endl;
        }
        else if (counter<-1){
            cout<<endl<<"ERROR: No. of (Closed Brackets > Open brackets)"<<endl;
            cout<<endl<<"Description: Closing brackets were never opened at "<<errorLocation2()<<endl;
        }
    }
};
int main(){
    
    string str;
    cin>>str;
    BracketDetector b;
    b.CheckBrackets(str);
}
