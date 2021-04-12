#include <iostream>
#include "instruction.h"
#include "map.h"
#include<cstdlib>
#include<ctime>
#include "printmap.h"

using namespace std;



int main(){

// before the game begin, provide players with basic instructions and rules about the game
   showinstruction();
   
// use current time to genrate a random number from 1-5 for map genration
   srand(time(NULL));
   int number=rand()%5+1;
   int map[10][10];

// genrate a map 
   mapContainer(map, number);
   
// define the position of heal_pack
   Position heal_pack;
   heal_pack.x=5;
   heal_pack.y=4;
   int number_of_heal_pack = 1;
   
// initialize the beginning position on the first colomn
   int initial_pos=rand()%10;
   Position start={initial_pos, 0};
   Position current = start;

   
// setting the end position of the game
   int out = rand()%10;
   Position end = {out,9};
   
// use dynamic variable to set the blood of player
   int * blood = new int(3);

   
   char input;
   int expect_num;
   
// use dynamic variable to store the steps
   int * num_step = new int(0);
   
// initialize marks which will be use to rate players performance in the game
   int * mark = new int(0);
   cout<<"Input the expected number of movement you need to reach end point: ";
   
//require player to input an int to estimate steps he need to finish the game
   cin>>expect_num;
   int * num_of_tool = new int (1);
   
// print out the map to help player carry on his game
// 'o' represent current position '*' represent heal_pack
   printmap(map, heal_pack, current);
   
   while (true){
      
  // provide information and summary of current condition after each step
      cout<<"Your current position is: "<<current.x<<" "<<current.y<<endl;
      cout<<"Number of landmines around you: "<<map[current.x][current.y]<<endl;
      cout << "You have " << *blood << " blood(s)." <<endl;
      cout<<"Please input your next action: ";
      cin>>input;
      *num_step+=1;
      
  // define the functin of special tool
      if (input == 'p') {
         
  // players can use special tool at most one time
         if ( *num_of_tool == 0 ) {
            cout << "You have used up all the tools, you cannot use it any more!" <<endl;
            *num_step -= 1;
            continue;
         }
         else {
            cout << "You are now using special tool, please input your movement: ";
            cin >> input;
            
   // classify situaions into four direction movement
            if (input == 'w'){
               // the situation of invalid movement
               if (current.x == 0 || current.x == 1){
                  cout << "You reach the boundary, invalid movement!" << endl;
                  printmap(map, heal_pack, current);
                  continue;}
               
  // the situation of running into a wall
               else if ( map[current.x-2][current.y] == 999 ){
                  cout << "This is a wall, you cannot reach it." << endl;
                  printmap(map, heal_pack, current);
                  continue;}
               
  // situation that tool is used successfully
               else{
                  current.x -= 2;
                  *num_of_tool -= 1;}
            }
            
  // the situation of move left
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
            
   //the situation of move down
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
            
 // the situation of move right
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
      
// the situation that move up without using tool
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
      
// the situation that move left without using tool
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
       
// the situation that move down without using tool
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
       
 // the situation that move right without using tool
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
      
// the situation that you run into a landmine 
      if ( map[current.x][current.y] == 100 ){
         cout << "You reach a landmine!" << endl;
         *blood-=1;
      
// the situation that you run out of your blood and lose the game
         if (*blood == 0){
            cout << "You use up all your blood" << endl << "You lose!" <<endl;
            cout << "Your final mark is -9999!" <<endl;
            break;}
      
// the situation that run into a landmine but still alive 
// player will be sent to a random positon in the first colomn and start their journey again
         else if (*blood > 0){
            cout << "Go back and try again!" << endl;
            int restart_pos=rand()%10;
            current.x = restart_pos;
            current.y = 0;
            printmap(map, heal_pack, current);
            continue;}
        }
      
//the situation that player reach destination can win the game
      else if ( current.x == end.x && current.y == 9){
         cout << "Congratulation, you reach the endpoint!" << endl;
         cout << "You win!" <<endl;
         
// at the end, calculate the mark according to critria set in the instruction
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
         
// return total mark to the player to rate his performance
         cout << "You have used " << *num_step << " movements to reach the endpoint." <<endl;
         cout<<"Your final mark is: "<<*mark<<endl;
         break;
      }
      
// the situation that player pick up a heal pack
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
   
// delete all dynamaic menory
   delete blood;
   blood = 0;
   delete mark;
   mark = 0;
   delete num_step;
   num_step = 0;
   delete num_of_tool;
   num_of_tool = 0;
}
