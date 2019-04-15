#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const int UNITS_PER_CAN = 3;
    const string INPUT_FILE_NAME = "counts.txt";

    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    int plant_count=0;
   
    // Loop once for each number of plants read from the input file.
    // Stop when the number of plants is 0 or less.
    // During each loop, simulate Plan Near and Plan Far.
    do
    {
     
     //Initialize variables.
      
     int water_amount=UNITS_PER_CAN , cum_steps=0 , step_units=0 , difference=1 , temp=0 ,plant_number;
     int flag=0 , faucet=0 , loop_count=0 , steps=0, near_step_units=0,far_step_units=0 ;

     input >> plant_count;
     plant_number=1;

     //Should not proceed if the plant count is 0.
        
     if(plant_count==0)
     {
       break;
     }
     else
     {
      //Plan Near
      cout << endl;
      cout << "==========================" << endl;
      cout << " Plan Near with " << plant_count << " plants" << endl;
      cout << "==========================" << endl;
      cout << endl;
      cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
      cout << "---------  ----------  ----------  ---------------" << endl;
 
      loop_count=plant_count+1;
          
      while(loop_count!=0)
      { 
       if(water_amount==0 || loop_count==1)
       {
        //Walk back to the faucet.
  
        cout<<"FAUCET"<<"\t";        
        cum_steps=cum_steps+plant_number-1;
        
        if(loop_count!=1) 
        {
          flag=1; 
        } 
          
       plant_number--; 
       
       }  
       else
       {
        cout<<"Plant "<<plant_number<<"\t";
       
        if(faucet==1)
        { 
         cum_steps+=plant_number; 
         faucet=0;
        } 
        else 
        { 
         cum_steps++; 
        } 
      }   

      difference=cum_steps-temp;
      step_units+=difference*water_amount;
       
      cout<<"\t"<<setw(2)<<cum_steps;
      cout<<"\t"<<setw(4)<<water_amount;
      cout<<"\t"<<"\t"<<setw(2)<<step_units<<endl; 
      
      //Saving the previous value of cummulative steps to caculate step-units

      temp=cum_steps;
      
      if(flag==1) 
      {
       //Water can is refilled at the faucet.
        
        water_amount=UNITS_PER_CAN;
        faucet=1;
        flag=0; 
      }
      else
      { 
       water_amount--;
       loop_count--;
      } 
      plant_number++;
     }
     
     //Obtain the final step-units value to compare later with Plan Far's value.
 
     near_step_units=step_units; 
     
     cout<<"\n"; 
     cout<<"Plan Near: Total steps = "<<cum_steps<<", total step-units = "<<near_step_units<<endl;  
     cout<<"\n"; 
   
     //Plan Far     
     
     cout << "=========================" << endl;
     cout << " Plan Far with " << plant_count << " plants" << endl;
     cout << "=========================" << endl;
     cout << endl;
     cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
     cout << "---------  ----------  ----------  ---------------" << endl;
      
     //Reset the variables for reuse.
 
     loop_count=plant_count+1;
     plant_number=plant_count;
     cum_steps=plant_count-1;
     difference=1;
     water_amount=UNITS_PER_CAN;
     step_units=0 , faucet=0 , flag=0 , temp=0;
   
     while(loop_count!=0)
     {
      if(water_amount==0 || loop_count==1)
      {
        cout<<"FAUCET"<<"\t";
        cum_steps=cum_steps+plant_number+1;
       
        if(loop_count!=1)
        {
         flag=1;
        } 
        plant_number++;
      }
      else
      {
       cout<<"Plant "<<plant_number<<"\t";
       
       if(faucet==1)
       {
        cum_steps+=plant_number;
        faucet=0;
       }
       else
       {
        cum_steps++;
       }
      } 
      
      difference=cum_steps-temp;
      step_units+=difference*water_amount;

      cout<<"\t"<<setw(2)<<cum_steps;
      cout<<"\t"<<setw(4)<<water_amount;
      cout<<"\t"<<"\t"<<setw(2)<<step_units<<endl;
 
      temp=cum_steps;
      
      if(flag==1)
      {
        water_amount=UNITS_PER_CAN;
        faucet=1;
        flag=0;
      }
      else
      {
       water_amount--;
       loop_count--;
      }
      plant_number--;
    }
   
    //Obtain the final step-units value to compare later with Plan Near's value.
 
    far_step_units=step_units;
    cout<<"\n";         
    cout<<"Plan Far: Total steps = "<<cum_steps<<", total step-units = "<<far_step_units<<endl;
    cout<<"\n";

    //Determine which plan is better,better means fewer step-units.
    
    cout << "*** With " << plant_count << " plants, ";
         
    if(near_step_units>far_step_units)
    {
     difference = near_step_units-far_step_units;
     cout<<"Plan Far is better with "<<difference<<" fewer step-units."<<endl;
    }
    else 
    {
     difference = far_step_units-near_step_units;
     cout<<"Plan Near is better with "<<difference<<" fewer step-units."<<endl;
    }  
   }
  }while (plant_count > 0);
    
 return 0;
}
