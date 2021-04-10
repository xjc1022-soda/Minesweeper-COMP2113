#include <iostream>
#include "instruction.h"
#include "map.h"
#include<cstdlib>
#include<ctime>
#include "printmap.h"

using namespace std;



int main(){
   showinstruction();
   srand(time(NULL));
   int number=rand()%5+1;
   int map[10][10];
   mapContainer(map, number);
   Position heal_pack;
   heal_pack.x=5;
   heal_pack.y=4;
   int number_of_heal_pack = 1;

   int initial_pos=rand()%10;
   Position start={initial_pos, 0};
   Position current = start;

   printmap(map, heal_pack, current);

   int out=rand()%10;
   Position end={out,9};

   int blood=3;


   char input;
   while (true){
      cout<<"Your current position is: "<<current.x<<" "<<current.y<<endl;
      cout<<"Number of landmines around you: "<<map[current.x][current.y]<<endl;
      cout << "You have " << blood << " blood(s)." <<endl;
      cout<<"Please input your next action: ";
      cin>>input;

      if (input == 'w'){
        if (current.x == 0){
          cout << "You reach the boundary, invalid movement!" << endl;
          printmap(map, heal_pack, current);
          continue;}
        else if ( map[current.x-1][current.y] == 999 ){
          cout << "This is a wall, you cannot pass through it." << endl;
          printmap(map, heal_pack, current);
          continue;}
        else
          current.x -= 1;
      }
      else if (input == 'a'){
        if (current.y == 0){
          cout << "You reach the boundary, invalid movement!" << endl;
          printmap(map, heal_pack, current);
          continue;}
        else if ( map[current.x][current.y-1] == 999 ){
          cout << "This is a wall, you cannot pass through it." << endl;
          printmap(map, heal_pack, current);
          continue;}
        else
          current.y -= 1;
      }
      else if (input == 's'){
        if (current.x == 9){
          cout << "You reach the boundary, invalid movement!" << endl;
          printmap(map, heal_pack, current);
          continue;}
        else if ( map[current.x+1][current.y] == 999 ){
          cout << "This is a wall, you cannot pass through it." << endl;
          printmap(map, heal_pack, current);
          continue;}
        else
          current.x += 1;
      }
      else if (input == 'd'){
        if (current.y == 9){
          cout << "You reach the boundary, invalid movement!" << endl;
          printmap(map, heal_pack, current);
          continue;}
        else if ( map[current.x][current.y+1] == 999 ){
          cout << "This is a wall, you cannot pass through it." << endl;
          printmap(map, heal_pack, current);
          continue;}
        else
          current.y += 1;
      }

      if ( map[current.x][current.y] == 100 ){
         cout << "You reach a landmine!" << endl;
         blood-=1;
         if (blood == 0){
            cout << "You use up all your blood" << endl << "You lose!" <<endl;
            break;}
         else if (blood > 0){
            cout << "Go back and try again!" << endl;
            int restart_pos=rand()%10;
            current.x = restart_pos;
            current.y = 0;
            printmap(map, heal_pack, current);
            continue;}
        }

      else if ( current.x == end.x && current.y == 9){
         cout << "Congratulation, you reach the endpoint!" << endl;
         cout << "You win!" <<endl;
         break;
      }
      else if ( current.x == heal_pack.x && current.y == heal_pack.y){
         if (number_of_heal_pack == 0){
            cout << "You have already picked up the heal pack. You cannot pick the heal pack any more!" << endl;
            printmap(map, heal_pack, current);
          }
         else {
            blood += 1;
            cout << "You get a heal pack. One blood added!" << endl;
            number_of_heal_pack -= 1;
            printmap(map, heal_pack, current);
           }
         }
      else{
         printmap(map, heal_pack, current);
         continue;
      }
   }
}
