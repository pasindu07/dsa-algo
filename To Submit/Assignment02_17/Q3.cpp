#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> weights;
    int number_of_products, tmp_weight, number_of_containers = 0, tmp_val = 0;
    cin >> number_of_products;

    for (int i = 0; i < number_of_products; i++)
    {
        cin >> tmp_weight;
        weights.push_back(tmp_weight);
    }

    sort(weights.begin(), weights.end());

    for (int i = 0; i < number_of_products; i++)
    {

        if (weights[i] > tmp_val)
        {
            tmp_val = weights[i] + 4;
            number_of_containers++;
        }
        else
            continue;
    }

    cout << number_of_containers << endl;

    return 0;
}
