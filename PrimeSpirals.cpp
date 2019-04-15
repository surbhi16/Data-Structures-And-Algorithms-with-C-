#include<iostream>
#include<vector>

using namespace std;

const int MAX_START = 50;   // maximum starting number

void do_prime_spiral(const int n, const int start);                //initializes 1D vector and computes primes numbers
void make_spiral(vector<int> primes,const int n,const int start);  //initializes 2D vector and arranges elements in spiral form
void print_spiral(vector<vector<int> > &prime_spiral,const int n); //prints the spiral arrangement 2D vector

/**

 * The main: Generate and print prime spirals of various sizes.

 */

int main()
{

      do_prime_spiral(5, 1);
      do_prime_spiral(25, 11);
      do_prime_spiral(35, 0);
      do_prime_spiral(50, 31);
      do_prime_spiral(101, 41);

}

void do_prime_spiral(const int n,const int start)
{
  //checks if the passed parameters meet given criteria
  //computes the vector of given size 
  //and marks prime numbers 
  //calls make_spiral() to store prime numbers as they would appear in spiral form
  
  cout<<"Prime spiral of size "<<n<<" starting at "<<start<<endl;

  if(n%2==0)
   {
    cout<<"***** Error: Size "<<n<<" must be odd."<<endl;
    cout<<"\n";
   }
  else if(start==0)
   {
    cout<<"***** Error: Starting value 0 < 1 or > 50"<<endl;
    cout<<"\n";
   }
  else if(start>MAX_START)
    {
     cout<<"***** Error: Starting value "<<n<<" must be less than 50."<<endl;
     cout<<"\n";
    }
  else
  {
   vector<int> numbers;
   int elements = start;
   int value =0;
   int multiplier=2;
   int size=n*n;
   int begin =1;
  
   if(start!=1)
   {
     size=size+start;
   }
 
  for(int i=1;i<=size;i++)
  {
    numbers.push_back(i);
  }

  numbers[0]=0;
  
  for(int i=begin;i<size;i++)
  {
    for(int j=begin;j<=size;j++)
    {
     value=numbers[i]*multiplier;
     if(value>size)
       break;
     for(int k=begin;k<=size;k++)
     {
      if(value==numbers[k])
      {
         numbers[k]=0;
         break;
      }
     }
     multiplier++;
      
    }
     multiplier=2; 
  }
   make_spiral(numbers,n,start);
  }
}

void make_spiral(vector<int> primes,const int n,const int start) 
{

  //finds the middle position of a matrix and stores the first element of array there
  //gradually proceeds in right,up and then left direction
  //stores these numbers in the direction of spiral in another matrix 
  //calls print_spiral() to print the 2D array
  
  int rows=0;              //rows of the new 2D vector
  int cols=0;              //columns of the new 2D vector
  rows=cols=n;             //old vector's dimension set to the given size n
  int mark=n/2;            //marks the row position in the middle of the 2D matrix
  int mark2=mark;          //marks the column position of middle of 2D matrix
  int all_elements=n*n;    //maximum number of elements a vector can have
  int row_copy=0;          //marks column position of first element of 2D vector formed from 1D
  int col_copy=0;          //marks row position of first element of 2D vector formed from 1D

  vector<vector<int> > copy;    //holds the final arrangement of elements
  vector<vector<int> > matrix;  //holds the 1D vectors values in 2D

  int k=0;            //iterates through the 1D vector
  int down =0;        //marks downward direction of spiral


 for(int i=0;i<n;i++)
 {
   vector<int> temp;
   for(int j=0;j<n;j++)
   {
     temp.push_back(0); 
   }
   copy.push_back(temp);
 }

 
  if(start!=1)
    k=start-1;
 
  for(int i=0;i<n;i++)
  {
    vector<int> temp;
    for(int j=0;j<n;j++)
    {
      temp.push_back(primes[k]);
      k++;
    }
    matrix.push_back(temp);
  }

  copy[mark][mark2]=matrix[row_copy][col_copy];


  int loop_count=all_elements-2;
  int down_temp=0;


  while(loop_count>0)
  {

    int right;
    int flag=0;

  if(down==cols-1)
  { 
    right=down;
    flag=1;
  }
  else
   right=down+1;

  int right_temp=right;

  while(right!=0)
  {

    if(mark2<rows-1)
     mark2++;

    if(col_copy==cols-1)
    {
      row_copy++;
      col_copy=0;
    }
    else
      col_copy++;


    copy[mark][mark2]=matrix[row_copy][col_copy];

    loop_count--;
    right--;

  }  


  if(flag==1)
    break;
  else
  {
   right=right_temp;
   int up=right;
   int up_temp=up;
   
   while(up!=0)
   {
    if(mark!=0)
     mark--;

   if(col_copy==cols-1)
   {
     row_copy++;
     col_copy=0;
   }
   else
     col_copy++;

   copy[mark][mark2]=matrix[row_copy][col_copy];

   loop_count--;
   up--;

  }

  up=up_temp;


  int left=right+1;
  int left_temp=left;

 while(left!=0)
 {
   if(mark2!=0)
     mark2--;

   if(col_copy==cols-1)
   {
     row_copy++;
     col_copy=0;
   }
   else
     col_copy++;

   copy[mark][mark2]=matrix[row_copy][col_copy];

   loop_count--;
   left--;

  }

 left=left_temp;
 down=left;
 down_temp=down;


 while(down!=0)
 {

   if(mark<cols-1)  
      mark++;

   if(col_copy==cols-1)
   {
     row_copy++;
     col_copy=0;
   }
   else
     col_copy++;


   copy[mark][mark2]=matrix[row_copy][col_copy];

   loop_count--;
   down--;

 }  

   down=down_temp;
 }

 }

 print_spiral(copy,n);

}


void print_spiral(vector<vector<int> > &prime_spiral,const int n)
{
  //prints the 2D vector which has spiral arrangement of elements in it
  //numbers which are marked 0 are not prime, hence '.'
  //numbers which are non zero are prime, hence '#'
  
  cout<<"\n"; 
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
     if(prime_spiral[i][j]==0)
      {
      cout<<".";
      }
     else
      cout<<"#";
    }
    cout<<"\n";
  }
   cout<<"\n";
} 
