using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------                                                                                               
//CS311 HW2P2 Combine                                                                                                                        
//Name: Leovigildo Robles                                                                                                                    
//Compiler: g++                                                                                                                              
//--------------------------------------------                                                                                               

// Purpose:combine two sorted lists A and B into R                                                                                           
// PARAMETERS: Pass the two lists we recieved from the user by value, and the list that will  recieve the combined list by reference.        

// displays comparison every time it is done                                                                                                 
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  int ia = 0;
  int ib = 0;
  int ir = 0;

  // continues to add elements until the index of either list reaches the end                                                                
  while (ia != A.size() && ib != B.size())
    {
      cout << "comparison" << endl;
      if(A[ia] < B[ib]) // checks to see which element is the smallest and adds to R                                                         
        {
          R.push_back(A[ia]);
          ia++;
        }
      else
        {
          R.push_back(B[ib]);
          ib++;
        }
      ir++;
    }

  // checks to see if there is elements left in  either list then adds remaining elements into R.                                            
  if(A.size() != ia)
    {
      while(A.size() != ia)
        {
          R.push_back(A[ia]);
          ia++;
          ir++;
        }
    }
  else if(B.size() != ib)
    {
      while(B.size() != ib)
        {
            R.push_back(B[ib]);
            ib++;
            ir++;
        }
    }
}


int main()
{
    vector<int> L1;
    vector<int> L2;
    vector<int> L3;
    int N;  // how many elements in each of L1 and L2
    int e;  // for each element
    
    cout << "How many elements in each list?" << endl;
    cin >> N;
    
    cout << "List1"  << endl;
    for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);}
    
    cout << "List2"  << endl;
    for (int i = 1; i <=N; i++)
        { cout << "element :"; cin >> e; L2.push_back(e);}

    
    // call combine here to combine L1 and L2 into L3
    combine(L1,L2,L3);
    
    cout << "The result is: ";
    for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;
    
}// end of main
