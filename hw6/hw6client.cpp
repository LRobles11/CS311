// CS311 Yoshii
// HW6 Client file
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client
// Name: Leovigildo Robles
// File type: client program  (tester) hw6client.cpp
// ================================================

#include "dgraph.h"
using namespace std;


int main()
{ /*
  0.Declare table object
  1.fillTable()
  2.displayGraph()
  while (the user does not want to stop)
    a.the user will specify which vertex
    b.findOutDegree of the vertex and display the result
    b.findAdjacency of the vertex and display the result (see Hint)
    c.catch exception to display error mesg but do not exit
  */
  dgraph Table;
  slist adjacents;

  Table.fillTable();
  Table.displayGraph();


  int exit = 0;
  el_t vertex;
  while(exit == 0)
    {

      cout << endl;

      cout << "Enter a vertex or enter a 1 to exit: ";
      cin >> vertex;
      cout << endl;
      if (vertex != '1')
        {
          try
            {
              int degree = Table.findOutDegree(vertex);
              slist adjacents = Table.findAdjacency(vertex);
              cout << "The degree is: " << degree << endl;
              cout << "Adjacents are: " ;
              adjacents.displayAll();
              cout << endl;
            }
          catch(dgraph::BadVertex)
            {
              cerr << "ERROR: Vertex does not exist!!!" << endl;
            }
        }
      else
        {
          exit = 1;
        }
    }
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.
                                                                                                        
*/
