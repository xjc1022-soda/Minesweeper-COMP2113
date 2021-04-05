#include <iostream>
#include "instruction.h"
#include "map.h"
#include<cstdlib>
#inlcude<ctime>
#include "printmap.h"

using namesapce std;

struct Position {
   int x;
   int y;};
int main(){
   showinstruction();
   srand(time(NULL));
   int number=rand()%5+1;
   int map[10][10];
   mapContainer(map, number);
   
   if (number == 1){
     Position heal_pack={1,7};}
   else if (number == 2){
     Postion heal_pack={3,5};}
   else if (number == 3){
     Postion heal_pack={6,5};}
   else if (number == 4){
     Postion heal_pack={5,4};}   
   else if (number == 5){
     Postion heal_pack={5,4};}
   
   int initial_pos=rand()%10;
   Position start={initial_pos, 0};
   
   printmap(map, heal_pack, start);
   
}
