# Landmine

## Group 171 COMP2113
```
Xu Jiacheng 3035639094     
Yung Yiu Yin 3035689336
```

## Sample output
[sample 1](https://github.com/xjc1022-soda/landmine/blob/main/sample_input_output_1.docx)  
[sample 2](https://github.com/xjc1022-soda/landmine/blob/main/sample_input_output_2.docx)  
[sample 3](https://github.com/xjc1022-soda/landmine/blob/main/sample_input_output_3.docx)

## Game Instructions and Rules:
```
Welcome to the game landmine.
You will start at a point on the first column from left and aim to arrive at the destination on the last column on the right.
The system will tell which point you are now staying at. You could move upward, leftward, downward or rightward by 1 step each time.
Input 'w' to move upwards, 's' to move downwards, 'd' to move right , 'a' to move left.(only lower character will be valid)
```
```
Steps estimation: you need to input a number to estimate the steps you need to complete the game   
(if the estimation is far away from the actual number of movements you take, many marks will be deducted.)
```
```
You have 3 bloods. Whenever you reach the landmines, 1 blood is deducted and you will be sent back randomly to one of the points  
in the first column.   
(may not be the same as the entrance mentioned above)
The system will provide you with numbers of total landmines within 3*3 square.   
(the current location is the centre of the square)
```
```
Special bonus: There is 1 healing pack in each map, when the player reaches that point, 1 blood is added   
(only available once in each round)
```
```
Special tools: when you press 'p'(lower character!) you can jump 2 steps at one time(can jump over landmine and walls). 
Note: let say your current position is (2,2) and (2,4) is a wall, and you input 'p' and then 'd'.     
      Your movement is invalid because you reach a wall.       
      However, the special tool will not be depleted in this case.    
      If you want to use it again, you must input 'p' again before your movement.  
```
```
If you run into wall or exceed boundary after using special tool, steps will be counted.
```
```
The winning condition : the player could reach the exit without using up all the 3 drops of blood. 
Mark caculation: 1.each remaining blood worth 100 marks
                 2.reaching heal_pack can earn 200 marks
                 3.total steps less than 30 can earn marks(20 marks each movement)
                 4.total steps more than 40 will lose marks(8 marks each movement)
                 5.estimation error will lose marks(one absolute error will result in 8 marks deduction )
```
```
The landmine will not disappear after you run into it.
```


## Code requirements:
```
1.Generation of random game sets or events
--we use random number to generate the map and randomly set the beginning point, restarting point and destination
```
```
2.Data structures for storing game status
--we use struct Position to store the current position of the player and store the position of heal_pack, beginning point and end point.
```
```
3.Dynamic memory management
--we use dynamic memory method and pointers to store the situation of blood, tool and steps.
```
```
4.File input/output (e.g., for loading/saving game status)
--we read instruction form file instruction.txt
```
```
5.Program codes in multiple files
--we use many head file besides main function, including map.h, printmap.h and instruction.h
```



## Library used:
```
#include<iostream>    --standarded input and output form
#include<fstream>     --supprot file input and output, read instruction from "instruction.txt"
#include<cstdlib>     --use function srand to generate random number
                      --use fucntion abs to caculate the estimation error of steps
#include<ctime>       --use time(NULL) as input of srand function
```  

## Compilation and execution instructions:
```
Use makefile to execute the progarm:
Download everything to Ubuntu, open the terminal and type: "make map_main" at the terminal, and then open "map_main.cpp" by atom, and run it on atom. 
Follow the screen output instruction after each step(input)
```

© 2021 GitHub, Inc.
