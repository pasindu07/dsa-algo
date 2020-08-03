#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

 int num_students,tmp_mark,tot_masks=0;
 int diff_counter=0;//counts # of diffrent values
 vector<int> scores;
 vector<int> mask_alloc;

 cin >> num_students;

 for(int i=0;i<num_students;i++){
     cin >> tmp_mark;
     scores.push_back(tmp_mark);
 }

for(int i=0,j=1;j<=num_students;i++,j++){

    if(scores[i]<scores[j] && i==0){
        mask_alloc.push_back(1);
        mask_alloc.push_back(2);
    }
    else if(scores[i]>scores[j] && i==0){
        mask_alloc.push_back(2);
        mask_alloc.push_back(1); 
    }
    else if(scores[i]<scores[j]){
        mask_alloc.push_back(mask_alloc[i]+1);
    }
    else if(scores[i]==scores[j]){
        mask_alloc.push_back(mask_alloc[i]);
    }
    else
        mask_alloc.push_back(1);
    
}

for(int i=0;i<num_students;i++){
    cout << mask_alloc[i] << " ";
    tot_masks+=mask_alloc[i];
}
cout << "\n";
cout << tot_masks << endl;

 return 0;

}