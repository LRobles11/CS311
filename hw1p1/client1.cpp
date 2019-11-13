//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Leovigildo Robles
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: Enter a postfix operation to be solved and checks to see if the expression is valid or not and prints the result.
//Algorithm: Take in an expression (char) and converts the nums into integers which is later pushed into the stack, and once an operand is found the last 2 elements are popped and the result is calculated. Loop continues until there is no more ints int the stack.
int main()
{
    stack postfixstack;  // integer stack
    string expression;   // user entered expression
    
    cout << "type a postfix expression: " ;
    cin >> expression;
    
    int i = 0;  // character position within expression
    char item;  // one char out of the expression
    
    int result; // store the result of the operation
    
    int box1;  // receive things from pop
    int box2;  // receive things from pop
    
    while (expression[i] != '\0')
    {
        try
        {
            item = expression[i];  // current char
            
            // ** do all the steps in the algorithm given in Notes-1
            if (item >= '0' && item <= '9') // maker sure the user inputs a single digit number
            {
                postfixstack.push(item-48); // convert char to an int
                postfixstack.displayAll();
            }
            
            // checks the operand to see what operation to do
            else if ( (item =='+') || (item == '-') || (item == '*'))
            {
                postfixstack.pop(box1);
                postfixstack.pop(box2);
                
                if ( item == '-')
                {
                    result = box2 - box1;
                }
                
                else if (item == '+')
                {
                    result = box2 + box1;
                }
                
                else if ( item == '*')
                {
                    result = box2 * box1;
                }
                
                postfixstack.push(result); // push result back into the stack
                postfixstack.displayAll();
            }
            else throw "invlaid item"; // display error message if user doesn's enter  a valid input
            
        } // this closes try
        
        // Catch exceptions and report problems and quit the program now (exit(1)).
        // Error messages describe what is wrong with the expression.
        catch (stack::Overflow)
        {
            cerr << "ERROR: Expression too long" << endl;
        }
        catch (stack::Underflow)
        {
            cerr << "ERROR: too few operands" << endl;
        }
        catch (char const* errormsg ) // for invalid item case
        {
            cerr <<"ERROR: Invalid expression" << endl;
        }
        
        // go back to the loop after incrementing i
        i++;
    }// end of while
    
    // After the loop successfully completes:
    // Pop the result and show it.
    postfixstack.pop(result);
    cout << "The result is " << result << endl;
    // If anything is left on the stack, an incomplete expression
    // was found so inform the user.
    if (postfixstack.isEmpty() == false)
    {
        cerr<< "ERROR: incomplete expression" << endl;
    }
    
}// end of the program  
