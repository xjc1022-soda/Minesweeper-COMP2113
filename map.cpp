#include <iostream>
# include "map.h"
using namespace std;

int mapContainer(int x){
  if (x==1){
   int map_one[10][10]={{0  ,1  ,100,2  ,1  ,1  ,1  ,100,1  ,0  },
                        {1  ,2  ,2  ,2  ,100,2  ,2  ,2  ,999,0  },
                        {1  ,100,2  ,2  ,2  ,2  ,100,1  ,0  ,0  },
                        {0  ,1  ,2  ,100,1  ,1  ,2  ,2  ,999,0  },
                        {0  ,0  ,1  ,1  ,2  ,999,2  ,100,1  ,0  },
                        {1  ,1  ,1  ,0  ,1  ,100,2  ,2  ,1  ,1  },
                        {1  ,100,2  ,999,1  ,2  ,2  ,2  ,100,1  },
                        {1  ,2  ,100,2  ,1  ,2  ,100,3  ,2  ,2  },
                        {0  ,1  ,1  ,2  ,100,2  ,2  ,3  ,100,1  },
                        {0  ,0  ,0  ,999,1  ,1  ,1  ,100,2  ,1  }};
   return map_one[10][10];}
  
  else if (x==2){
   int map_two[10][10]={{1  ,100,2  ,1  ,0  ,0  ,1  ,100,100,1  },
                        {1  ,2  ,100,2  ,1  ,0  ,1  ,2  ,2  ,1  },
                        {0  ,1  ,2  ,100,1  ,999,1  ,1  ,0  ,0  },
                        {1  ,1  ,2  ,1  ,999,1  ,100,1  ,0  ,0  },
                        {1  ,100,2  ,999,0  ,999,1  ,2  ,1  ,1  },
                        {1  ,2  ,100,2  ,1  ,1  ,999,1  ,100,1  },
                        {1  ,2  ,2  ,2  ,100,1  ,1  ,2  ,2  ,1  },
                        {1  ,100,1  ,1  ,999,2,  2  ,100,1  ,0  },
                        {1  ,2  ,1  ,2  ,1  ,100,3  ,2  ,1  ,0  },
                        {0  ,0  ,1  ,100,2  ,2,  100,1  ,0  ,0  }};
    return map_two[10][10];}

  else if (x==3){
   int map_three[10][10]={{0  ,1  ,1  ,999,1  ,0  ,1  ,1  ,1  ,0  },
                          {0  ,1  ,2  ,100,2  ,2  ,2  ,100,2  ,1  },
                          {1  ,2  ,100,3  ,100,3  ,100,3  ,100,1  },
                          {1  ,100,3  ,3  ,2  ,100,2  ,3  ,2  ,2  },
                          {1  ,2  ,100,2  ,2  ,1  ,2  ,2  ,100,1  },
                          {0  ,1  ,2  ,100,2  ,2  ,2  ,100,2  ,1  },
                          {0  ,0  ,1  ,2  ,100,3  ,100,2  ,1  ,0  },
                          {0  ,0  ,999,1  ,2  ,100,2  ,1  ,0  ,0  },
                          {0  ,0  ,999,0  ,1  ,999,1  ,999,999,0  },
                          {0  ,0  ,0  ,999,0  ,0  ,0  ,0  ,999,0  }};
    return map_three[10][10];}
  
  else if (x==4){
  int map_four[10][10]={{1,100,2,2,100,1,1,1,1,0},
                        {2,2,3,100,3,3,2,100,1,0},
                        {1,100,2,2,100,2,100,2,999,0},
                        {1,1,1,1,1,3,2,2,0,0},
                        {0,1,1,1,999,,1,100,1,0,0},
                        {1,2,100,1,0,1,2,2,999,0},
                        {1,100,2,1,999,1,100,1,0,0},
                        {1,1,1,0,0,1,2,2,1,0},
                        {0,0,999,1,1,999,2,100,2,0},
                        {0,0,0,1,100,1,2,100,2,0}};
    return map_four[10][10];}
  else if (x==5){
   int map_five[10][10]={{0,0,0,0,1,100,1,0,0,0},
                         {1,1,2,1,2,2,2,1,100,0},
                         {1,100,3,100,1,1,100,1,0,0},
                         {1,2,100,2,999,100,3,100,1,0},
                         {0,2,2,2,999,1,2,1,1,0},
                         {0,1,100,1,1,1,2,1,1,0},
                         {1,1,2,1,1,100,2,100,1,0},
                         {1,100,2,1,1,0,999,1,1,0},
                         {1,2,3,100,1,0,999,1,1,0},
                         {0,1,100,2,1,0,1,100,1,0}};
    return map_five[10][10];}
}
