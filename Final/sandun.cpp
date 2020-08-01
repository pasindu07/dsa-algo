//Question 01

#include <iostream>
#include <vector>

using namespace std;

int largestNum(int num[], int n);

int main()
{

  vector<int> posvec;
  vector<int> newval;
  vector<int> new_bottle_arrange;

  int number_of_bottels; //No of. bottles Sandun carried
  int ib;
  int val;
  int pos;
  double maxval = 0;
  int number_of_barrels,total_bottels_in_barrel=0; //No. of Barrels in wine yard


  cin >> number_of_bottels >> number_of_barrels;

  // cout << "Enter the No. of barrels available in wine yard : ";

  int bottles_per_barrel[number_of_barrels] = {};
  int value[number_of_barrels] = {};
  int vdensity[number_of_barrels] = {};

  // cout << "Enter the No. of bottles in each barrel :";

  for (int i = 0; i < number_of_barrels; i++)
  {
    cin >> ib;
    bottles_per_barrel[i] = ib;
    total_bottels_in_barrel+=ib;
  }

  // cout << "\nEnter the corresponding price of each barrel : ";

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
  while (true)
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

  // double x[number_of_barrels] = {};
  int i=0;
  int bag = 0;

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

/*
  while (cur_b < number_of_bottels)
  {
    for (int i = 0; i < number_of_barrels; i++)
    {
      if (cur_b + bottles_per_barrel[posvec[i]] <= number_of_bottels)
      {
        x[posvec[i]] = 1;
        cur_b = cur_b + bottles_per_barrel[posvec[i]];
      }
      else
      {
        x[posvec[i]] = ((number_of_bottels - cur_b) / bottles_per_barrel[posvec[i]]);
        cur_b = number_of_bottels;
      }
    }
  }
  

  //To calculate the values of items in th knapsack
  double y = 0;
  for (int i = 0; i < number_of_barrels; i++)
  {
    if (x[i] != 0)
    {
      y = x[i] * value[i];
      maxval = maxval + y;
    }
  }
  */
}

else{
  for(int i=0;i<number_of_barrels;i++){
    maxval+=value[i];
  }
}

  cout << maxval;

  return 0;
}

int largestNum(int num[], int number_of_barrels)
{
  //Finding the max Digit
  int tmp = 0;
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