//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Leovigildo Robles
// File type: client hw7client.cpp
//==========================================

// ** Be sure to include dgraph, slist and stack
#include <iostream>
#include "dgraph.h"
#include "stack.h"


// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  dgraph Table;
  stack Stack;
  slist adjacents;
  char tempVer; //temp variable to hold the vertex being removed
  int trav = 1; // variable to hold the amount of traversals (2 because we traverse A before the loop)             

  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that has the comments.

  Table.fillTable();
  Table.displayGraph();

  Stack.push('A'); // pushes A onto the stack to start

  //while the stack is not empty
  while (!Stack.isEmpty())
    {
      //removes vertex from the stack
      Stack.pop(tempVer);
      cout << "Removed " << tempVer << " from the stack" << endl;

      // check to see if the vertex has already been visited
      if (Table.isMarked(tempVer) == false) // if has not been visited
        {
          //marks vertex to be visited
          Table.visit(trav, tempVer);
          cout << "Visit " << tempVer << " as " << trav << endl;
          adjacents = Table.findAdjacency(tempVer);

          //if vertex has adjacents
          if(!adjacents.isEmpty())
            {
              cout << ".... Pushing ";
              adjacents.displayAll();

              // put adjacents into stack
              while (!adjacents.isEmpty())
                {
                  adjacents.deleteRear(tempVer);
                  Stack.push(tempVer);
                }
            }
          else
            {
              cout << "Deadend reached - Back Up!!!" << endl;
            }

          //increment traversal after each visit
          trav++;
        }
      else
        {
          cout << tempVer << " has already been visited - Back Up !!" << endl;
        }

      //display contents of the stack
      Stack.displayAll();
      cout << endl;
    }

  cout << endl;

  cout << "Graph after DFS: " << endl;
  cout << "-----------------------------------------" << endl;
  Table.displayGraph();

  return 0;
}
