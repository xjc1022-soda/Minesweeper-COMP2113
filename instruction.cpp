//read instruction file input
#include<iostream>
#include<fstream>
using namespace std;

void showinstruction(string filename){
   ifstream fin;
   fin.open(filename);
   if ( fin.fail() ) {
      cout << "Error in file opening!" 				<< endl;
      exit(1);
   }
   string x;
   while(getline(fin,x)){
    cout<<x<<endl;
   }
   fin.close();
}
