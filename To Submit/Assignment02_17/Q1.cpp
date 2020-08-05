//Question 01

#include <iostream>
#include <vector>

using namespace std;

int largestNum(double num[], int);

int main()
{

  vector<int> posvec;
  vector<double> newval;
  vector<int> new_bottle_arrange;

  int number_of_bottels; //No of. bottles Sandun carried
  int ib;
  double val;
  int pos;
  double maxval = 0;
  int number_of_barrels,total_bottels_in_barrel=0; //No. of Barrels in wine yard

  cin >> number_of_bottels >> number_of_barrels;

  int bottles_per_barrel[number_of_barrels] = {};
  double value[number_of_barrels] = {};
  double vdensity[number_of_barrels] = {};

  for (int i = 0; i < number_of_barrels; i++)
  {
    cin >> ib;
    bottles_per_barrel[i] = ib;
    total_bottels_in_barrel+=ib;
  }

  for (int i = 0; i < number_of_barrels; i++)
  {
    cin >> val;
    value[i] = val;
  }

//calculating the value per bottle
if(number_of_bottels<total_bottels_in_barrel){

  for (int i = 0; i < number_of_barrels; i++)
  {
    vdensity[i] = (value[i] / bottles_per_barrel[i]);
  }

  int k = 0;
  while (true)//rearranging position,value per bottle and bottles per barrel according to descending order
  {
    pos = largestNum(vdensity, number_of_barrels);

    posvec.push_back(pos);
    k++;
    newval.push_back(vdensity[pos]);
    new_bottle_arrange.push_back(bottles_per_barrel[pos]);
    vdensity[pos] = -1;

    if (k == number_of_barrels)
    {
      break;
    }
  }

  
  int i=0;
  int bag = 0;
  
//getting bottles accordingly
  while(bag!=number_of_bottels && i!=number_of_barrels){

    if(bag+new_bottle_arrange[i]<=number_of_bottels){
      bag += new_bottle_arrange[i];
      maxval += newval[i]*new_bottle_arrange[i];
    }

    else{
      maxval += (number_of_bottels-bag)*newval[i];
      bag += (number_of_bottels-bag);
    }
    i++;
  }
}

else{
  for(int i=0;i<number_of_barrels;i++){
    maxval+=value[i];
  }
}

  cout << maxval;

  return 0;
}

int largestNum(double num[], int number_of_barrels)
{
  //Finding the max Digit
  double tmp = 0;
  int p = 0;
  for (int i = 0; i < number_of_barrels; i++)
  {
    if (num[i] >= tmp)
    {
      tmp = num[i];
      p = i;
    }
  }
  return p;
}