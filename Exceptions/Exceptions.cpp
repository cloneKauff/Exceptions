// Morgan Kauffer
// CIS 1202 501
// April 28, 2023

#include<string> 
#include<iostream>


using namespace std;

//Classes for exceptions
class invalidCharacterException
{

};


class invalidRangeException
{

};

class caseConversionException
{

};


char character(char start, int offset)
{
    int startVal = int(start);
    int charWanted = startVal + offset;


    try {
        //determines whether starting value is uppercase or lowercase. Throws exception if not.
        if (startVal < 65 || (startVal > 90 && startVal < 97) || startVal > 122)
        {
            throw invalidCharacterException();
        }

     
        else if (charWanted < 65 || (charWanted > 90 && charWanted < 97) || charWanted > 122)
        {
            throw invalidRangeException();
        }

        //throws exception for starting value of uppercase/lowercase attempting to convert to the opposite case
        else if ((charWanted >= 65 && charWanted <= 90 && startVal >= 95 && startVal <= 122) || (charWanted >= 95 && charWanted <= 122 && startVal >= 65 && startVal <= 90))
        {
            throw caseConversionException();
        }
    }

   
    catch (invalidCharacterException except1)
    {
        cout << "ERROR: Invalid character exception." << endl;
        return ' ';
    }
    catch (invalidRangeException except2)
    {
        cout << "ERROR: Invalid range exception. " << endl;
        return ' ';
    }
    catch (caseConversionException except3)
    {
        cout << "ERROR: Cannot change uppercase to lowercase." << endl;
        return ' ';
    }

    //result if no exception is thrown
    return char(charWanted);
}

int main()
{
    cout << character('a', 1) << endl;
    cout << character('a', -1) << endl;
    cout << character('Z', -1) << endl;
    cout << character('?', 5) << endl;
    cout << character('A', 32) << endl;
    
    system("pause");
}