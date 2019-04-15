#include "RomanNumeral.h"

using namespace std;

RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
  
}

RomanNumeral::RomanNumeral(string value)
{
   roman=value;
   to_decimal();
}

RomanNumeral::RomanNumeral(int value)
{
   decimal=value;
   to_roman();
}

void RomanNumeral::to_roman()
{
  int temp;
  string result="";
  int n =1;
  int count=0;

  while(decimal!=0)
  {
    count++;
    decimal=decimal/10;
  }

  while(decimal!=0)
  {
    temp = decimal/10;
    for(int i=1;i<count;i++)
       n=n*10;
    temp=temp*n;
    
   if(temp==1000)
   {
     result +="M";
   }
   else if(temp==900)
   {
     result +="CM";
   }
   else if(temp==50)
   {
     result +="L";
   }
   else if(temp==40)
   {
     result+="XL";
   }
   else if(temp==9)
   {
      result+="IX";
   }
   else if(temp==3)
   {
      result+="III";
   }
   else
   {
     result +="";
   }
   n=n/10;
   decimal=decimal/10;
 }
  roman = result;
}

void RomanNumeral::to_decimal()
{
 
    int sum =0;

    for(int i=0;i<9;i++)
    {
       switch(roman[i])
       {
          case 'M' : sum = sum + 1000;
                     break;
 
          case 'D' : sum = sum + 500; 
                     break;

          case 'C' : sum = sum + 100;
                     break;
         
          case 'L' : sum = sum + 50;
                     break;
        
          case 'X' : sum = sum + 10;
                     break;

          case 'V' : sum = sum + 5;
                     break;

          case 'I' : sum = sum + 1;
                     break;
        }
      }
      
      decimal = sum;
} 


ostream& operator <<(ostream& os,RomanNumeral& rout)
{
   os << "[" << rout.decimal << ":" << rout.roman <<"]" ;
   return os;
}

istream& operator >>(istream& is,RomanNumeral& rin)
{
   string str;
   is >> str;
   rin.roman=str;
   rin.to_decimal();
   retrun is;
}

RomanNumeral operator+(RomanNumeral r,RomanNumeral n)
{
   RomanNumeral rn;
   rn.decimal = r.decimal+n.decimal;
   return rn;
}

RomanNumeral operator-(RomanNumeral r,RomanNumeral n)
{
   RomanNumeral rn;
   rn.decimal = r.decimal-n.decimal;
   return rn;
}

RomanNumeral operator/(RomanNumeral r, RomanNumeral n)
{
   RomanNumeral rn;
   rn.decimal = r.decimal/n.decimal;
   return rn;
}

RomanNumeral operator*(RomanNumeral r, RomanNumeral n)
{
   RomanNumeral rn;
   rn.decimal = r.decimal*n.decimal;
   return rn;
}

int operator==(RomanNumeral r,RomanNumeral n)
{
   RomanNumeral rn;
   if(r.decimal==n.decimal)
   {
      return 1;
   }
   else
     return 0;
}

int operator!=(RomanNumeral r,RomanNumeral n)
{
   RomanNumeral rn;
   if(r.decimal!=n.decimal)
   {
      return 1;
   }
   else 
      retrun 0;
}