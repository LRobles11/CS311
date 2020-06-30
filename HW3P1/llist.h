//CS311 Yoshii
//INSTRUCTION:                                                                                         
//Llist class - header file template                                                                   
//You must complete the ** parts and then complete llist.cpp                                           
//Don't forget PURPOSE and PARAMETERS                                                                  

// =======================================================                                             
// HW#: HW3P1 llist                                                                                    
// Your name: Leovigildo Robles                                                                        
// Compiler:  g++                                                                                      
// File type: headher file  llist.h                                                                    
//=======================================================                                              

// alias el_t : element type definition                                                                
typedef int el_t;

//a list node is defined here as a struct Node for now                                                 
struct Node
{
  el_t Elem;   // elem is the element stored                                                           
  Node *Next;  // next is the pointer to the next node                                                 
};
//---------------------------------------------------------                                            

class llist
{

 protected:
    Node *Front;       // pointer to the front node
    Node *Rear;        // pointer to the rear node
    int  Count;        // counter for the number of nodes

    // untility function to move to a specified node position
    void moveTo(int, Node*&);

 public:

    // Exception handling classes
    class Underflow{};
    class OutOfRange{};  // thrown when the specified Node is out of range

    llist ();     // constructor to create a list object
    ~llist();     // destructor to destroy all nodes

    //Puropose: checks to see if the linked list is empty and if so it returns true.
    bool isEmpty();

    //Purpose: displays all the elements in the linked list
    void displayAll();

    //Purpose:adds a new node to the front of the list
    //Parameters: the value of the node to be added
    void addFront(el_t);
    
    //Purpose: adds a new node to the end of the list
    //Parameters: the value of the node to be added
    void addRear(el_t);
    
    //Purpose: deletes the first element in the list
    //Parameters: the value that is to be removed
    void deleteFront(el_t&);
    
    //Purpose:deletes the last element in the list
    //Parameters: the value that is to be removed
    void deleteRear(el_t&);
    
    //Purpose: deletes the Ith element in the list which is whatever the user inputs
    //Parameters: which position the value that needs to be removed
    void deleteIth(int, el_t&);  // calls moveTo
    
    //Purpose: inserts the elemnt into the Ith location in the list
    //Parameters: which postion in the list and what value to be added
    void insertIth(int, el_t);   // calls moveTo
    
    //Copy Constructor to allow pass by value and return by value of a llist
    llist(const llist&);
    
    //Overloading of = (returns a reference to a llist)
    llist& operator=(const llist&);
    
};
