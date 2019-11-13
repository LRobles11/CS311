using namespace std;
#include <iostream>

//--------------------------------------------                                                                                                                                                              
// CS311 HW2P1 Binary Search                                                                                                                                                                                
// Name: Leovigildo Robles                                                                                                                                                                                  
// Compiler: g++                                                                                                                                                                                            
// --------------------------------------------                                                                                                                                                             


// Purpose of program: to find an element in a previoulsy established array using binary search recursivley
// Algorithm: Using binary search, the program goes through a previously established array of intergers and looks for a match with a user input. The function "binarySearch" checks the middle element of the array and returns if middle == element, increments middle and assigns to first if element is greater than middle, decrements middle and assigns to last if element is less than middle, or returns -1 if first and last are of eaual value.

// x is what we are looking for in L; first and last are slot numbers                                                                                                                                       
int binarySearch(int L[], int x, int first, int last)
{
  //find the middle of the array                                                                                                                                                                            
  int middle = (first+last)/2;

  cout << "comparing against an element in slot " << middle << endl;

  // checks to see if element is in the middle                                                                                                                                                              
  if (x == L[middle])
    {
      return middle;
    }
  //checks to see if first is equal to last because if true thrn the element is not in the list                                                                                                             
  else if (first == last)
    {
      cout << "Not found" << endl;
      return -1;
    }
  //if x is bigger than the middle element then you check thr upper half of list by updating first                                                                                                          
  else if( x > L[middle])
    {
      first = middle + 1;
    }
  //if x is smaller than the middle element then you check the lower half of list by updating last                                                                                                          
  else if (x < L[middle])
    {
      last = middle - 1;
    }
  //calls recursivly to check if all middle elements match the number looked for                                                                                                                            
  return binarySearch(L, x, first, last);
}


int main()
{
  int A[10];
  int e;  // to look for this                                                                                                                                                                               

  // fixed elements for A                                                                                                                                                                                   
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A                                                                                                                                                              
  int respos = binarySearch(A, e, 0, 9);

  if (respos == -1) cout << "Element not found" << endl;
  else cout << "Found it in position " << respos+1 << endl;
    
  return 0;
    
}
