/*
* Assignment 3.b Spirals
* Author : Surabhi Sonkhaskar
* 
*/


#include<iostream>
#include<iomanip>

using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

int rows=0;                 //row count of matrix, initialized to 0
int cols=0;                 //column count of matrix, initialized to 0

void make_spiral(int *arr,int rows,int cols);       //arranges the elements of array as they would appear in spiral 
void print_spiral(int *arr1,int rows,int cols);     //prints the 2D array formed
void do_prime_spiral(const int n, const int start); //generates the matrix starting from the given value

int main()
{
    do_prime_spiral(1,1);
    do_prime_spiral(5,1);
    do_prime_spiral(9, 11);
    do_prime_spiral(12, 13);
    do_prime_spiral(15, 17);
}


void do_prime_spiral(const int n,const int start)
{
   
  //function should not proceed if the start value is greater than 50
  //also the size of the given matrix should be even
  //creates a matrix which holds value starting from the given START value
  //calls make_spiral() to arrange the elements in spiral form and store in another matrix

  rows=cols=n;

  cout<<"Spiral of size "<<n<<" starting at "<<start<<endl;
  int count=0;

  if(start>MAX_START)
   cout<<"Maximum starting number can be 50";

  if(cols%2==0)
  {
   cout<<"***** Error: Size "<<cols<<" must be odd."<<endl;
   cout<<"\n";
  }
  else
  {

  rows=cols;
  int matrix[rows][cols];
  count=start;  

  for(int i=0;i<rows;i++)
  {
   for(int j=0;j<cols;j++)
   {
     matrix[i][j]=count;
     count++;
    }
  }

  make_spiral(*matrix,rows,cols);

}

}
void make_spiral(int *arr,int rows,int cols)
{
  
  //finds the middle position of a matrix and stores the first element of array there
  //gradually proceeds in right,up and then left direction
  //stores these numbers in the direction of spiral in another matrix 
  //calls print_spiral() to print the 2D array
  
  
  int mark=rows/2;
  int mark2=mark;
  int all_elements=rows*cols;
  int row_copy=0;
  int col_copy=0;
  int matrix_copy[rows][cols];
  int matrix[rows][cols];
  int k=0;
  int down =0;

  for(int i=0;i<rows;i++)
  {
   for(int j=0;j<cols;j++)
   {
     matrix_copy[i][j]=0;
   }
  }

  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      matrix[i][j]=arr[k];
      k++;
    }
  }

  matrix_copy[mark][mark2]=matrix[row_copy][col_copy];

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

    matrix_copy[mark][mark2]=matrix[row_copy][col_copy];
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
   matrix_copy[mark][mark2]=matrix[row_copy][col_copy];
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
   matrix_copy[mark][mark2]=matrix[row_copy][col_copy];
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

   matrix_copy[mark][mark2]=matrix[row_copy][col_copy];
   loop_count--;
   down--;
 }  
   down=down_temp;
 }

 }
 print_spiral(*matrix_copy,rows,cols);

}

void print_spiral(int *arr1,int rows,int cols)
{
  //outer loop keeps count of rows of the matrix
  //inner loop keeps count of the columns 
  //since 2D array is stored as 1D array internally,
  //we can print it using one variable i.e arr1[element]

 int element=0;
 cout<<"\n";
 
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
    cout<<setw(4)<<arr1[element];
    element++;
  }
  cout<<"\n"; 
 }
 cout<<"\n";
}
