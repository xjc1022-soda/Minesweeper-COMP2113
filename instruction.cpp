//read instruction file input
#include<iostream>
#include "instruction.h"
#include<fstream>
using namespace std;

// read instruction from "instruction.txt"  and print it out to the player 
void showinstruction(){
   ifstream fin;
   fin.open("instruction.txt");
   if ( fin.fail() ) {
      cout << "Error in file opening!" << endl;    
      //test whether can read from the text
      exit(1);
   }
   string x;
   while(getline(fin,x)){
    cout<<x<<endl;                     
      //print out the instruction
   }
   fin.close();
}
