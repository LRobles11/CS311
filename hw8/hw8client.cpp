// CS311 Yoshii - complete ** for HW8 client 
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Leovigildo Robles
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{ /*
 Loop:
   Interactively add about 20 keys and names to the table,
     making sure some of them  collide. (function add)
     You can create el_t containing a key and name using a constructor.
  */
  htable table;
  int key;
  string name;
  for(int i=0 ; i <20 ; i++)
    {
      cout << "Enter a key (3 digit number): ";
      cin >> key;
      cout << "Enter name: ";
      cin >> name;

      el_t X(key, name);
      table.add(X);
    }

  table.displayTable(); // DisplayTable.

  /*
 Loop:
  Interactively look up names using keys. (function find)
    Cout the key + name if found else (blank element was returned)
    an error message.
  */
  int input;
  while (input != -1)
    {
      cout << "Look for (enter -1 to exit program)? ";
      cin >> input;

      if(input != -1)
        {
          el_t empty; // varaible that holds a blank element to compare
          el_t Y;
          Y = table.find(input);

          if (Y == empty)
            {
              cout << input << " not found!" <<endl;
            }
          else
            {
              cout << "Found " << input << ": " << Y << endl;
            }
        }
    }
  return 0;
}
