// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Leovigildo Robles
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h"

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{ }


// positions always start at 1
//Purpose: search for a certain elemnent in the list and returns the postion where it is located otherwise returns 0. If its an empty list just display that the list is empty.       
//Parameter: pass the element (key) to be searched for
int slist::search(el_t key)
{
  if(isEmpty())
    {
      cout << " [ empty ] " << endl;
    }
  else
    {
      int pos = 1;
      Node *P = Front; // creating pointer to search throught the list
      while (P != NULL)
        {
          if (P->Elem == key)
            {

              return pos;
            }
          P = P->Next;
          pos++;
        }
      return 0;
    }
}

//Purpose: replace an element in a certain position in the list with the elemnet the user requests
//Parameters: pass the element (pos)  where the desitred node is to be replaced with the element provided (element)
// don't forget to throw OutOfRange for bad pos
void slist::replace(el_t element, int pos)
{
  el_t temp; // temp value to hold deleted element
  //error case: pos not in the list
  if (pos < 1 || pos > Count)
    {
      throw OutOfRange();
    }
  //special case: if pos is front of the list
  else if (pos == 1)
    {
      deleteFront(temp);
      addFront(element);
    }
  //special case: if pos is at end of list
  else if( pos == Count)
    {
      deleteRear(temp);
      addRear(element);
    }
  //regular case:
  else
    {
      deleteIth(pos, temp);
      insertIth(pos, element);
    }
}

//Purpose: overloading the == operator and returns true if the lists are the same otherwise returns false
//Parameter: provider a holder (OtherOne) for the linked list to be compared (pass by ref)
bool slist::operator==(const slist& OtherOne)
{
  if (this->Count != OtherOne.Count)// if not the same length, return false
    {
      return false;
    }

// if the same lengths, check each node to see if the elements are the same

  Node *x; //pointer towards orginal list
  Node *y; // pointer towards the other list

  x=this->Front;
  y=OtherOne.Front;

  while (x != NULL)
    {
      if (x->Elem != y->Elem)
        {
          return false;
        }
      x=x->Next;
      y=y->Next;
    }
  return true;
}

//Purpose: search for a certain elemnent in the list and returns the element if found
//otherwise returns an empty element. If its an empty list just reurn empty element.
//Parameter: pass the element (key) to be searched for
el_t slist::search2(el_t key)
{
  if(isEmpty())
    {
      //cout << " [ empty ] " << endl;
      return el_t(); // returns empty element if empty
    }
  else
    {
      Node *P = Front; // creating pointer to search throught the list
      while (P != NULL)
        {
          if (P->Elem == key)
            {
              return P->Elem;
            }
          P = P->Next;
        }
      return el_t(); //returns empty element if not in list
    }
}
