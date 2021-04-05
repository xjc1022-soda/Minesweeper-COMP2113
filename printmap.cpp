#include <iostream>
#include "printmap.h"
using namespace std;

struct Position {
   int x;
   int y;};
void printmap(int map[][10];Position heal_pack, Position current){
   for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        if ({i,j}==heal_pack)
            cout<<"*"<<" ";
        else if({i,j}==currentpos)
            cout<<"O"<<" ";
        else
            cout<<"x"<<" ";
    }
     cout<<endl;
   }
}
