//CS311 Yoshii
//INSTRUCTION:                                                                                                                                                                    
//Look for ** to complete this program                                                                                                                                            
//The string output should match my hw1queueDemo.out                                                                                                                              

//=========================================================                                                                                                                       
//HW#: HW1P2 queue application (generate all strings)                                                                                                                             
//Your name: Leovigildo Robles                                                                                                                                                    
//Complier:  g++                                                                                                                                                                  
//File type: client program client2.cpp                                                                                                                                           
//===========================================================                                                                                                                     

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: Using a queue to generate all possible strings consisting of the characters provided                                                                    
//Algorithm: The algorithm works by initially adding elements "A", "B", and  "C" into the queue. To generate new strings,                                                         
// an element is popped off the queue and characters from setChar array are sequentially appended to the element forming new strings.                                             
// they are later printed and contine to do until until the queue is full.                                                                                                        
int main()
{
  el_t setChar[3] = { "A", "B", "C"};
  el_t temp; // variable to hold character when removing                                                                                                                          
  el_t newStr; // varaible to hold the new generated string                                                                                                                       

  queue myQueue;

  //put the intital contents of the charcaters into the queue                                                                                                                     
  for(int i =0; i<3; i++)
    {
      myQueue.add(setChar[i]);
      cout << setChar[i] << endl;
    }

// ** "A", "B", "C" in the queue                                                                                                                                                  
  // ** while loop -- indefinitely                                                                                                                                                
  while (!myQueue.isFull()) // check to see if queue is full to detemine to continue making strings                                                                               
    {
      try
        {
          myQueue.remove(temp);

          for (int i=0; i<3; i++)
            {
              newStr=temp + setChar[i];
              myQueue.add(newStr);
              cout << newStr << endl;
            }
        }
        catch (queue::Overflow)
            {
                cerr << "ERROR: Queue is full." << endl;
            }
        
    }// end of loop
    
}
