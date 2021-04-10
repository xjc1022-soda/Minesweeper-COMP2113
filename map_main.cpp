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

   

   int out = rand()%10;
   Position end = {out,9};

   int * blood = new int(3);


   char input;
   int expect_num;
   int * num_step = new int(0);
   int * mark = new int(0);
   cout<<"Input the expected number of movement you need to reach end point: ";
   cin>>expect_num;
   int * num_of_tool = new int (1);
   
   printmap(map, heal_pack, current);
   
   while (true){
      cout<<"Your current position is: "<<current.x<<" "<<current.y<<endl;
      cout<<"Number of landmines around you: "<<map[current.x][current.y]<<endl;
      cout << "You have " << *blood << " blood(s)." <<endl;
      cout<<"Please input your next action: ";
      cin>>input;
      *num_step+=1;
      if (input == 'p') {
         if ( *num_of_tool == 0 ) {
            cout << "You have used up all the tools, you cannot use it any more!" <<endl;
            continue;
         }
         else {
            cout << "You are now using special tool, please input your movement: ";
            cin >> input;
            if (input == 'w'){
               if (current.x == 0 || current.x == 1){
                  cout << "You reach the boundary, invalid movement!" << endl;
                  printmap(map, heal_pack, current);
                  continue;}
               else if ( map[current.x-2][current.y] == 999 ){
                  cout << "This is a wall, you cannot reach it." << endl;
                  printmap(map, heal_pack, current);
                  continue;}
               else{
                  current.x -= 2;
                  *num_of_tool -= 1;}
            }
            else if (input == 'a'){
               if (current.y == 0 || current.y == 1){
                  cout << "You reach the boundary, invalid movement!" << endl;
                  printmap(map, heal_pack, current);
                  continue;}
               else if ( map[current.x][current.y-2] == 999 ){
                  cout << "This is a wall, you cannot reach it." << endl;
                  printmap(map, heal_pack, current);
                  continue;}
               else{
                  current.y -= 2;
                  *num_of_tool -= 1;}
            }
            else if (input == 's'){
               if (current.x == 9 || current.x == 8){
                  cout << "You reach the boundary, invalid movement!" << endl;
                  printmap(map, heal_pack, current);
                  continue;}
               else if ( map[current.x+2][current.y] == 999 ){
                  cout << "This is a wall, you cannot reach it." << endl;
                  printmap(map, heal_pack, current);
                  continue;}
               else{
                  current.x += 2;
                  *num_of_tool -=1;}
            }
            else if (input == 'd'){
               if (current.y == 9 || current.y == 8){
                  cout << "You reach the boundary, invalid movement!" << endl;
                  printmap(map, heal_pack, current);
                  continue;}
               else if ( map[current.x][current.y+2] == 999 ){
                  cout << "This is a wall, you cannot reach it." << endl;
                  printmap(map, heal_pack, current);
                  continue;}
              else{
                 current.y += 2;
                 *num_of_tool -= 1;}
            }
         }
      }
      else if (input == 'w'){
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
         *blood-=1;
         if (*blood == 0){
            cout << "You use up all your blood" << endl << "You lose!" <<endl;
            break;}
         else if (*blood > 0){
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
         *mark += (*blood)*100;
         if(number_of_heal_pack==0){
         *mark += 200;}
         *mark -= abs(expect_num-(*num_step))*8;
         if (*num_step<=30){
         *mark += (30-(*num_step))*20;
         }
         else if(*num_step>40){
         *mark -= ((*num_step)-40)*8;
         }
         cout<<"Your final mark is: "<<*mark<<endl;
         break;
      }
      else if ( current.x == heal_pack.x && current.y == heal_pack.y){
         if (number_of_heal_pack == 0){
            cout << "You have already picked up the heal pack. You cannot pick the heal pack any more!" << endl;
            printmap(map, heal_pack, current);
          }
         else {
            *blood += 1;
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
   delete blood;
   blood = 0;
   delete mark;
   mark = 0;
   delete num_step;
   num_step = 0;
   delete num_of_tool;
   num_of_tool = 0;
}
