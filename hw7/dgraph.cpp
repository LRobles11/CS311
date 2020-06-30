//CS311 Yoshii dgraph.cpp
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Leovigildo Robles
// File Type: implemenation file dgraph.cpp
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"
#include <iomanip>

//Purpose: constructor to initialize vertex name and visit
//Parameters: none
dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
  for(int i = 0; i <SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }
  countUsed = 0;
}
//Purpose:destrucot that calls the llist destructor
//Parameters: none
dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.         
{
}

//Purpose: reads from a file and stores the consnets into a table and updates count
//Parameters:  none
void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
  char X;
  while (fin >> Gtable[countUsed].vertexName)
    {
        fin >> Gtable[countUsed].outDegree;
        for(int i = 0; i < Gtable[countUsed].outDegree; i++)
        {
          fin >> X;
          (Gtable[countUsed].adjacentOnes).addRear(X); //this is a slist function from HW3
        }
      countUsed++;
    }
  fin.close();

}

//Purpose: displays all the contnets from the file into a nice table format
//Parameters:  none
void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows
  int space = 10; // hold width of output
  cout << left << setw(space) << "Vertex";
  cout << left << setw(space) << "OutDegree";
  cout << left << setw(space) << "Adjacents" << endl;
  cout << "--------------------------------------------" << endl;
  for(int i=0; i < countUsed; i++)
    {
      cout << left << setw(space) << Gtable[i].vertexName;
      cout << left << setw(space) << Gtable[i].outDegree;
      (Gtable[i].adjacentOnes).displayAll();
    }
}

//Purpose: finds the out degree of the vertex name and uses the ascii vakue to find the position of
//the vertex in the table.
//Parameters: the char V which is the vertex that is passed from the user
int dgraph::findOutDegree(char V)// throws exception
{// does not use a loop
  int pos = V - 65;
  if(pos >= 0 && pos < countUsed)
    {
      int deg = Gtable[pos].outDegree;
      return deg;
    }
  else
    throw BadVertex();
}

//Purpose: finds the adjacencies of the vertex using the ascii value to find the postion of the vertex
// in the table
//Parameters:  the char V which is the vertex that is passed from the user
slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop
  int pos = V - 65;
  if(pos >=0 && pos < countUsed)
    {
      slist s = Gtable[pos].adjacentOnes;
      return s;
    }
  else
    throw BadVertex();
}

//Purpose: To indicate the order in which the vertices were visited
//Parameters: the int vis which is the amount of vists the vertex has
//            the char V which is the vertex that is passed by the user
void dgraph::visit(int vis, char V)
{
  int pos = V - 65;
  if(pos >= 0 && pos < countUsed)
    {
      Gtable[pos].visit = vis;
    }
  else
    throw BadVertex();
}

//Purpose: checks to see if the given has already been visited and if so returns true
//Parameters:  the char V which is the vertex that is passed from the user
bool dgraph::isMarked(char V)
{
  int pos = V - 65;
  if(pos >= 0 && pos < countUsed)
    {
      if(Gtable[pos].visit == 0)
        {
          return false;
    }
      else
        return true;
    }
  else
    throw BadVertex();
}
