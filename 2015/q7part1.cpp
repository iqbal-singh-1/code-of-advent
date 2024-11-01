#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//check if it is numeric
bool isNum(string s){
    for(char c: s){
        if(c<'0' || c>'9') return 0;
    }
    return 1;
}


//perform operations
int performOperation(string o,int a,int b=0){
    if(o=="OR") return a|b;
    else if(o=="AND") return (a&b);
    else if(o=="LSHIFT") return (a<<b);
    else if(o=="RSHIFT") return (a>>b);
    else if(o=="NOT") return 65535-a;
}

//count no of words
int wordCount(string str){
    int count = 1;
    for(char c:str){
        if(c==' ') count++;
    }
    return count;
}

//extracting one word from the input based on the requirements
string extractWord(string str,int count){
    string temp;
    count--;
    for(char c:str){
        if(c==' '){
            count--;
            continue;
        }
        if(count==0)temp+=c;
    }
    return temp;
}

//solve the problem
int solve(string unknownVariable,vector<string> & inputs,vector<string> & variables, vector<int> & values){

    //return if the string is number
    if(isNum(unknownVariable)){
        return stoi(unknownVariable);
    }

    //look for value if already found and return it
    int i = 0;
    for(string s: variables){
        if(s==unknownVariable){
            return values[i];
        }
        i++;
    }

    //find the unknown variable on the right side
    i = 0;
    int count;
    string rightWord;
    int ans = 0;
    for(string str:inputs){
        count = wordCount(str);
        rightWord = extractWord(str,count);
        if(rightWord==unknownVariable) break;
        i++;
    }
    if(count==3){
        //if count is 3, input format must be like "x -> y" where x may be variable or number
        //find the value of x

        ans = solve(extractWord(inputs[i],1),inputs,variables,values);
    }
    else if(count==4){
        //input format is like "NOT a -> b" where a may be varaiable or number
        //find the value of x and invert it 

        int x = solve(extractWord(inputs[i],2), inputs, variables, values);
        ans = performOperation("NOT",x);
    }
    else if(count==5){
        //input format is like "a and b -> c"
        //find the value of a and b

        int x = solve(extractWord(inputs[i],1), inputs, variables, values);
        int y = solve(extractWord(inputs[i],3), inputs, variables, values);
        string opt = extractWord(inputs[i],2);
        ans = performOperation(opt,x,y);
    }
    //return the answer and store it in the variables and values
    variables.push_back(rightWord);
    values.push_back(ans);
    return ans;
}

int main(){
    string s = "10 -> a";
    vector<string> inputs;
    vector<string> variables;
    vector<int> values;
    ifstream myfile("q7input.txt");

    //storing input in a vector
    while(getline(myfile,s)){
        inputs.push_back(s);
    }
    myfile.close();

    //print the answer
    cout<<solve("a",inputs,variables,values);
}