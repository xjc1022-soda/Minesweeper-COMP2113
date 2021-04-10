#include <iostream>
#include "printmap.h"
using namespace std;

// to visialize the map for the player 
// show exsiting position and heal pack for the player
void printmap(int map[][10], Position heal_pack, Position current){
   for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        if (i==heal_pack.x && heal_pack.y==j)
            cout<<"*"<<" ";
        else if(i==current.x && j==current.y)
            cout<<"O"<<" ";
        else
            cout<<"x"<<" ";
    }
     cout<<endl;
   }
}
