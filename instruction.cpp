//read instruction file input
#include<iostream>
#include "instruction.h"
#include<fstream>
using namespace std;

void showinstruction(){
   ifstream fin;
   fin.open("instruction.txt");
   if ( fin.fail() ) {
      cout << "Error in file opening!" << endl;
      exit(1);
   }
   string x;
   while(getline(fin,x)){
    cout<<x<<endl;
   }
   fin.close();
}
