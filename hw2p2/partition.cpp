#include<iostream>
using namespace std;

// You may not change my code in any manner.  0 pts if you do.                                                                               
// Simply add your code for **                                                                                                               

//----------------------------------------                                                                                                   
//CS311 HW2P2 Partition                                                                                                                      
//Name: Leovigildo Robles                                                                                                                    
//Compiler: g++                                                                                                                              
//-----------------------------------------                                                                                                  

// partitions the array a into smaller than pivot and others.                                                                                
// f is the beginning of the section to be partitioned                                                                                       
// r is the end of the section to be partitioned                                                                                             
// return the first slot of the Large section                                                                                                
int partition(int pivot, int a[], int f, int r)
{
  int left = f; // pointer from the left                                                                                                     
  int right = r; // pointer from the right                                                                                                   
  int m =left+1; // element after f (Xindex)                                                                                                 
  int temp; // temp variable used for swap                                                                                                   

  // loop for finding out of place pairs and swap them                                                                                       
  for(int i=left+1; i<=right; i++)
    {
      if(a[i] < pivot) // checks to see if element is less than pivot                                                                        
        {
          if(i != m) // checks to see if equal if not swap elements                                                                          
            {
              temp = a[m];
              a[m] = a[i];
              a[i] = temp;
            }
          m++; // increments left index by 1                                                                                                 
        }
    }
  a[left] = a[m-1];
  a[m-1]=pivot;
  if (m == 1) // special case where nothing is less than the pivot                                                                           
    return m;
  else
    return m-1;

}

int main()
{
    int x;  // number of elements
    int nums[10];
    cout << "How many elements? (must be less than 10) ";
    cin >> x;
    cout << "Enter elements one per line.." << endl;
    for (int i = 0; i < x; i++)
    { cin >> nums[i]; }
    
    // the pivot is always the first element
    cout << "Ok the pivot is " << nums[0] << endl;
    
    int part = partition(nums[0], nums, 0, x-1);
    
    cout << "Results..." << endl;
    // display up to the partition without endl
    for (int i = 0; i < part; i++)
        cout << nums[i];
    
    cout << "|";
    // display from the partition on.. without endl
    for (int i = part; i < x; i++)
        cout << nums[i];
    
    cout << endl;
    
}
