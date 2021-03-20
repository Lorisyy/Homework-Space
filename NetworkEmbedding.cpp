/*
    Create date: 2021 March 18 17:00PM (GMT+8)
    Created and Finished by 18342107 Su Yongye (Independently)

    This is for Assignment 1 of Distributed Computing Spring 2021.
    Problem Description:
            As we have studied in Chapter 2 lectures, a 2^r × 2^s wrap-around mesh (torus)
        can be embedded in a 2r+s-node hypercube by mapping node (i; j) of the mesh
        onto node G(i; r) || G(j; s) of the hypercube (where k denotes concatenation of
        the two Gray codes).
            Given an input 2r × 2s wrap-around mesh, where r and s are integers, design a
        C-program that implements the above embedding. Your code should correctly
        generates the hypercube addresses for all the nodes of the input mesh for any
        values of r and s, and print out the output for the following examples:
            1. r = 2 and s = 2;
            2. r = 3 and s = 4;
            3. r = 6 and s = 5.

*/

/*
    Two functions are implemented to generate gray code:
        1. Recursive method as mentioned on the class.
        2. A commonly used coding method in digital circuits of electrical engineering. 
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int DecimaltoGray( int x)
{
    return x^(x>>1);
}

string DecimaltoBinary(int n){
    string   s="";
    for(int a=n;a;a=a/2)
        s=s+(a%2?'1':'0');
    reverse(s.begin(),s.end());
    return s;
}

// @param i&r the ith node on 2^r mesh edge
// a recursive method is used in the function
string RecursiveGrayCodeGenerator(int i,int r)
{
    if(r==1&&i==0)return "0";
    else if(r==1&&i==1)return "1";
    else{
        if(i<pow(2,r-1))
            return RecursiveGrayCodeGenerator(i,r-1);
        int base = pow(2,r-1);
        int base_2 = pow(2,r);
        return DecimaltoBinary(base)+RecursiveGrayCodeGenerator(base_2-1-i,r-1);
    }
}


// @param i&r the ith node on 2^r mesh edge
// This is a commonly used encoding method in digital circuits of electrical engineering. 
string BinaryBasedGrayCodeGenerator(int i,int r)
{
    int gray_number = DecimaltoGray(i);
    string res = DecimaltoBinary(gray_number);
    if(res.length()<=r){
        while(r-res.length()>0){
            res = "0"+res;
        }
    }
    return res;
}

int main(){
    int r,s;
    cout<<"Please input the parameter of a 2^r × 2^s wrap-around mesh (torus) "<<endl;
    cout<<"In the order of:\nr s"<<endl;
    cin>>r>>s;
    // cout<<DecimaltoGray(r)<<"\t"<<DecimaltoGray(s)<<endl;
    for(int i = 0;i<pow(2,r);i++){
        for(int j = 0;j<pow(2,s);j++){
            cout<<"For node("<<i<<","<<j<<"), it is embedded as node "<<BinaryBasedGrayCodeGenerator(i,r)<<BinaryBasedGrayCodeGenerator(j,s)<<endl;
        }
        cout<<endl;
    }
    cout<<"Graphic mesh is implemented like this"<<endl;
    for(int i = 0;i<pow(2,r);i++){
        cout<<"node("<<i<<","<<0<<"): "<<BinaryBasedGrayCodeGenerator(i,r)<<BinaryBasedGrayCodeGenerator(0,s);
        for(int j = 1;j<pow(2,s);j++){
            cout<<"---"<<"node("<<i<<","<<j<<"): "<<BinaryBasedGrayCodeGenerator(i,r)<<BinaryBasedGrayCodeGenerator(j,s);
        }
        cout<<endl;
    }
    
    // for(int i = 0;i<16;i++){
    //     cout<<BinaryBasedGrayCodeGenerator(i,r)<<endl;
    // }
    
}
