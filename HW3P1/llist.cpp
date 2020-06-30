//CS311 Yoshii Linked List class                                                                                                               

//INSTRUCTION:                                                                                                                                 
//Must use the provided HW3P1_help.doc to create llist.cpp                                                                                     
//It helps to first create if-then-else structure to fill in later.                                                                            
//- Make sure PURPOSE and PARAMETER comments are given in detail                                                                               
//- Make sure all if-then-else are commented describing which case it is                                                                       
//- Make sure all local variables are described fully with their purposes                                                                      

//EMACS HINT:                                                                                                                                  
//  You can copy from a Word document to emacs (contrl-right click)                                                                            
//  cntr-K cuts and cntr-Y pastes                                                                                                              
//  Esc x replace-str does string replacements                                                                                                 
//  Esc > goes to the end of the file; Esc < to the beginning                                                                                  
//  Tab on each line will indent perfectly for C++                                                                                             

// ====================================================                                                                                        
//HW#: HW3P1 llist                                                                                                                             
//Your name: Leovigildo Robles                                                                                                                 
//Complier:  g++                                                                                                                               
//File type: llist.cpp implementation file                                                                                                     
//=====================================================                                                                                        

using namespace std;
#include<iostream>
#include"llist.h"

llist::llist()
{ cout << "... in llist constructor..." << endl;
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist()
{ cout << ".... in llist destructor..." << endl;
  int x;
  while( !isEmpty() )
    {
      deleteFront(x);
    }
}

//PURPOSE: checks to see if there is any elements inside of the list and if there is none returns true                                         
// otherwise returns fase                                                                                                                      
//PARAMETER: none                                                                                                                              
bool llist::isEmpty()
{
  if(Front == NULL && Rear == NULL && Count == 0)
    {
      return true;
    }
  else
    return false;
} // be sure to check all 3 data members                                                                                                       

//PURPOSE: displays all the elements in the list but if the list is empty displays an empty list                                               
//PARAMETER: none                                                                                                                              
void llist::displayAll()
{
  Node* P;
  //special case: if list is empty display an empty list                                                                                       
  if(isEmpty())
    {
      cout << "[ empty ]" << endl;
    }
  else
    {
      cout << "[ ";
      P = Front;
      while(P != NULL)
        {
          cout << P->Elem << " ";
          P = P->Next;
        }
      cout << "]" << endl;;
    }
}  // be sure to display horizontally in [  ] with         
// blanks between elements                                                                                                                     

//PURPOSE: adds an element at the end of the list but if the lsit is empty in has both the front and                                           
//rear pointers both pointing to it since it is the only element in the list.                                                                  
//PARAMETER: pass the element (newNum) to be added                                                                                             
void llist::addRear(el_t NewNum)
{
  //special case: if the list is empty it ends up being the front/rear                                                                         
  if (isEmpty())
    {
      Node* newNode;
      newNode = new Node;
      Front = newNode;
      Rear = newNode;
      newNode->Elem = NewNum;
      Count++;
    }
  //regular case                                                                                                                               
  else
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }

} // comment the 2 cases                                                                                                                       

//PURPOSE:  adds an element to the end of the list but if the list is empty  it would have both the                                            
// front and rear pointers pointing to it since it is the only element in the list.                                                            
//PARAMETER: pass the lement (newNum) to be added                                                                                              
void llist::addFront(el_t NewNum)
{
  Node* newNode;
  //special case: if the list is empty it ends up being the front/rear                                                                         
  if (isEmpty())
    {
      newNode= new Node;
      Front = newNode;
      Rear = newNode;
      newNode->Elem =NewNum;
      Count++;
    }
  //regular case                                                                                                                               
  else
    {
      newNode = new Node;
      newNode->Elem = NewNum;
      newNode->Next = Front;
      Front = newNode;
      Count++;
    }
} // comment the 2 cases                                                                                                                       

//PURPOSE: deletes the element at the front of the list. If the list is empty it would throw an error                                          
// of if there is only 1 element in the list then it would need to make front and rear point to null                                           
// since the list will end up being empty.                                                                                                     
//PARAMETER: provide a holder (OldNum) for the element deleted (pass by ref)                                                                   
void llist::deleteFront(el_t& OldNum)
{
  //error case: cant delete from an empty list (underflow)                                                                                     
  if (isEmpty())
    {
      throw Underflow();
    }
  //special case: if deleting makes the list empty                                                                                             
  else if( Count == 1)
    {
      OldNum = Front->Elem;
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  //regular case                                                                                                                               
  else
    {
      OldNum = Front->Elem;
      Node *Second;
      Second = Front->Next;
      delete Front;
      Front = Second;
      Count--;
    }
} // comment the 3 cases                                                                                                                       

//PURPOSE: deletes the element at the end of the list. If the list is empty it would throw an error                                            
// of if there is only 1 element in the list then it would need to make front and rear point to null                                           
// since the list will end up being empty.                                                                                                     
//PARAMETER: provide a holder (OldNum) for the element deleted (pass by ref)                                                                   
void llist::deleteRear(el_t& OldNum)
{
  //error case: cant delete from an empty list (underflow)                                                                                     
  if(isEmpty())
    {
      throw Underflow();
    }
  //special case: if deleting makes the list empty                                                                                             
  else if ( Count == 1)
    {
      OldNum = Rear->Elem;
      delete Rear;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  //regular case                                                                                                                               
  else
    {
      Node* P;
      OldNum = Rear->Elem;
      P = Front;
      //to traverse through the list to get to the node right before rear                                                                      
      while(P->Next != Rear)
        {
          P = P->Next;
        }
      delete Rear;
      Rear = P;
      Rear->Next = NULL;
      Count--;
    }
} // comment the 3 cases                                                                                                                       


/* harder ones follow */

// Utility Function to move a local pointer to the Ith node                                                                                    
void llist::moveTo(int I, Node*& temp)
{ // moves temp I-1 times                                                                                                                      
  for ( int j = 1; j <= I-1; j++)
    {
      temp = temp->Next;
    }
}

//PURPOSE: deletes the Ith elemnt in the list from the user input. If the user input is less than 1 or                                         
// greater than the size of the list, it throws an error for being out of range. If the input is 1 then                                        
// calls deleteFront or if the input is equal to the size of list then calls deleteRear.                                                       
//PARAMETER: pass the element (I) where the desired node is to be deleted / provide a holder (OldNum) for                                      
// the element to be deleted (pass by ref)                                                                                                     
void llist::deleteIth(int I, el_t& OldNum)
{
  //error case: Out of range if Ith number is not in the range of the list                                                                     
  if (I > Count || I < 1)
    {
      throw OutOfRange();
    }
  //special case: if the Ith number is the first number in the list                                                                            
  else if(I == 1)
    {
      deleteFront(OldNum);
    }
  //special case: if ther Ith number is the last number in the list  
  else if(I == Count)
    {
      deleteRear(OldNum);
    }
  //regular case                                                                                                                               
  else
    {
      Node *P= Front;
      Node *Second;
      moveTo(I-1, P);
      Second = P->Next;
      OldNum = Second->Elem;
      P->Next = Second->Next;
      delete Second;
      Count--;
    }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.                                                  

//PURPOSE:inserts element in the Ith postion in the list from the user input. If the user input is less                                        
// than 1 or greater than the size of the list, it throws an error for being out of range. If the input                                        
// is 1 then calls addFront or if the input is equal to the size of list then calls addRear.                                                   
//PARAMETER: pass the element (I) where the desired node is to be inserted / pass the element (newNum) to                                      
// be added                                                                                                                                    
void llist::insertIth(int I, el_t newNum)
{
  //error case: out of range if Ith number is not in the range of the list                                                                     
  if ( I > Count+1 || I < 1)
    {
      throw OutOfRange();
    }
  //special case: if the Ith number is the first number in the list                                                                            
  else if(I==1)
    {
      addFront(newNum);
    }
  // special case: if the Ith number is the last number in the list                                                                            
  else if( I == Count+1)
    {
      addRear(newNum);
    }
  //regular case                                                                                                                               
  else
    {
      Node *P = Front;
      Node *newNode;
      Node *Second;
      moveTo(I-1, P);
      Second = P->Next;
      newNode = new Node;
      newNode->Elem = newNum;
      P->Next = newNode;
      newNode->Next = Second;
      Count++;
    }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.                                                  

//PURPOSE: performs a shallow copy of the linked list                                                                                          
//PARAMETER:provide a holder (Original) for the linked list to be copied (pass by ref)                                                         
llist::llist(const llist& Original)
{
  //  this->'s data members need to be initialized here first                                                                                  
  Front = NULL; Rear = NULL; Count = 0;
  //  this-> object has to be built up by allocating new cells                                                                                 
  //  and copying the values from Original into each cell as we did with                                                                       
  //  operator= above. To do this,                                                                                                             

  // this-> object has to be built up by allocating new cells with OtherOne elements (**)                                                      
  Node* P;  // local pointer for OtherOne                                                                                                      
  P = Original.Front;
  while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.                                                              
    {
      this->addRear(P->Elem);    //P’s element is added to this->                                                                              
      P = P->Next;                         // Go to the next node in OtherOne                                                                  
    }
  // Nothing to return because this is a constructor                                                                                           

} // use my code                                                                                                                               

//PURPOSE: overloading the = operation to perfrom a deep copy fo the linked list                                                               
//PARAMETER: provide a holder (OtherOne) for the linked list to be copied (pass by ref)                                                        
llist& llist::operator=(const llist& OtherOne)
{
  el_t x;
  // First make sure this-> and OtherOne are not the same object.                                                                              
  // To do this, compare the pointers to the objects .                                                                                         
  if (&OtherOne != this)  // if not the same                                                                                                   
    {
      // this-> object has to be emptied first.                                                                                                
      while (! this->isEmpty() )
        {
          this->deleteRear(x);
        }
      // this-> object has to be built up by allocating new cells with OtherOne elements                                                  
      Node* P;  // local pointer for OtherOne                                                                                                  
      P = OtherOne.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.                                                          
        {
          this->addRear(P->Elem);    //P’s element is added to this->                                                                          
          P = P->Next;                         // Go to the next node in OtherOne                                                              
        }
    }// end of if                                                                                                                              
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.                                       

} // use my code      

                                                                                                                   