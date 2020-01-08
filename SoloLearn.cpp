

#include <iostream>
using namespace std;

int atoi_ex(const char* s); //declaring function prototype with two paramters//


int main() //Main to test function//
{
    const char sd[] = "-999999999";
    int output = atoi_ex(sd);
    cout << output ;
 
}

int atoi_ex(const char* s)//defining function with two parameters//
{
    int characterSize = 0; //Variable used to find the length of character
    int outputSign = 1;    //Variable used to output the sign of the output be it + or -
    int results = 0;       //Variable used for function return
    int elementPosition = 0;  
    int base = 1;// 16^0 ==1 
   
    while (s[characterSize] != '\0') // Finds the length of the character string //
    {
        characterSize++;
    }
    
    if (s[0] == '0' && s[1] == 'x')
    {
        for (int i = characterSize-1; i>=0; i--) //loop through the character string starting from the back
        {
            if (s[i] >= 'a' && s[i] <= 'f')
            {
                results = results + ((s[i] - 87) * base);  //converting calues from a - f to decimal using their ascii values
                base = base * 16;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                results = results + ((s[i] - '0') * base); //converting values from 0-9 in hex to decimal
                base = base * 16;
            }
        } 
    }
    else 
    {
        if (*s == '\0') //If the character contains invalid characters, the function returns 0
        {
            cout << "Error in conversion" << endl;
            return 0;

        }
        for (int i = 0; s[i] != '\0'; ++i)
        {
           
            if (s[i] == ' ')   //Skips whitepaces and increments element position 
            {
                elementPosition++;
            }

            if (s[i] == '-')   //If the current element position has a negative sign then the output will have a negative sign
            {
                outputSign = -1 * outputSign;
                elementPosition += 1;

            }
            if (s[i] == '+')   //If the current element position has a positive sign then the output will be positive
            {
                outputSign = +1 * outputSign;
                elementPosition += 1;

            }

            if (s[elementPosition] >= '0' && s[elementPosition] <= '9')    // Checks that the input is valid//
            {
                results = (10 * results) + (s[elementPosition] - '0'); // Converts string to integer by subtracting the values by their ascii deccimal values
                elementPosition++; //increment counter
            }
            
        }
    }
    return results * outputSign;
}


