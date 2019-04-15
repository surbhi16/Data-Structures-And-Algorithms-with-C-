#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include<iostream>
#include<string>

using namespace std;

class RomanNumeral
{
  string roman;
  int decimal;

  void to_roman();
  void to_decimal();
 
  public:
    /**
     * Default constructor.
     */
    RomanNumeral();
    
    //Parameterized constructor
    
    RomanNumeral(string value);
    RomanNumeral(int value);

    //Getter methods 
    
    string get_roman();
    int get_decimal();
    
    //Overloading insertion and extraction operator
    
    friend ostream& operator <<(ostream& os,RomanNumeral& rout);
    friend iostream& operator >>(istream& is,RomanNumeral& rin);
    
    //Overloading artihmetic operators 
    
    friend RomanNumeral operator+(RomanNumeral r,RomanNumeral n);
    friend RomanNumeral operator-(RomanNumeral r,RomanNumeral n);
    friend RomanNumeral operator/(RomanNumeral r,RomanNumeral n);
    friend RomanNumeral operator*(RomanNumeral r,RomanNumeral n);
    
    //Overloading operators to check equality
    
    friend int operator==(RomanNumeral r,RomanNumeral n);
    friend int operator!=(RomanNumeral r,RomanNumeral n);
    
    
    /***** Complete this class declaration. *****/
};
#endif /* ROMANNUMERAL_H_ */
