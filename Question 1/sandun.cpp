//Question 01

#include <iostream>
#include <vector>

using namespace std;

int largestNum(int num[], int n);

int main()
{

  vector<int> posvec;
  vector<int> newvec;

  double N; //No of. bottles Sandun carried
  int ib;
  int val;
  int pos;
  int n; //No. of Barrels in wine yard

  cout << "Enter the No. of Bottles Sandun carried : ";
  cin >> N;

  cout << "Enter the No. of barrels available in wine yard : ";
  cin >> n;

  int b[n] = {};
  int v[n] = {};
  int vdensity[n] = {};

  cout << "Enter the No. of bottles in each barrel :";

  for (int i = 0; i < n; i++)
  {
    cin >> ib;
    b[i] = ib;
  }

  cout << "\nEnter the corresponding price of each barrel : ";

  for (int i = 0; i < n; i++)
  {
    cin >> val;
    v[i] = val;
  }

  cout << "No. of Bottles in each Barrel :";
  for (int i = 0; i < n; i++)
  {
    cout << b[i] << " ";
  }
  cout << endl;

  cout << "Price of each corresponding barrel :";
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    vdensity[i] = (v[i] / b[i]);
  }

  cout << "Value Densities of each Barrel:";
  for (int i = 0; i < n; i++)
  {
    cout << vdensity[i];
  }

  //get the highest value density
  int k = 0;
  while (true)
  {
    pos = largestNum(vdensity, n);

    posvec.push_back(pos);
    k++;
    newvec.push_back(vdensity[pos]);
    vdensity[pos] = -1;

    if (k == n)
    {
      break;
    }
  }

  // cout << "\n Positions of the values with highest density items :";
  // for (int i = 0; i < n; i++)
  // {
  //   cout << posvec[i];
  // }

  // cout << "\n Largest Number that can be made : ";
  // for (int i = 0; i < newvec.size(); i++)
  // {
  //   cout << newvec[i];
  // }

  double x[n] = {};
  double cur_b = 0;

  while (cur_b < N)
  {
    for (int i = 0; i < n; i++)
    {
      if (cur_b + b[posvec[i]] <= N)
      {
        x[posvec[i]] = 1;
        cur_b = cur_b + b[posvec[i]];
      }
      else
      {
        x[posvec[i]] = ((N - cur_b) / b[posvec[i]]);
        cur_b = N;
      }
    }
  }

  cout << "\n How sandun filled his bottles from each barrel(, 0=Not taken,value between 1 and 0 = decimal value of fraction taken ) : " << endl;
  cout << "1=Taken Entire volume" << endl;
  cout << "0=Not taken" << endl;
  cout << "value between 1 and 0 = decimal value of volume of fraction take" << endl;

  for (int i = 0; i < newvec.size(); i++)
  {
    cout << "Barrel[" << i + 1 << "] = " << x[i] << endl;
  }

  cout << endl;
  //To calculate the values of items in th knapsack
  double y = 0;
  double maxval = 0;
  for (int i = 0; i < n; i++)
  {
    if (x[i] != 0)
    {
      y = x[i] * v[i];
      maxval = maxval + y;
    }
  }

  cout << "Maximum value of wine Sandun gets from this deal :" << maxval;

  return 0;
}

int largestNum(int num[], int n)
{
  //Finding the max Digit
  int tmp = 0;
  int p = 0;
  for (int i = 0; i < n; i++)
  {
    if (num[i] >= tmp)
    {
      tmp = num[i];
      p = i;
    }
  }
  return p;
}