#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int allocate_masks(int,int,vector<int>);


int main(){

 int num_students,tmp_mark;
 int diff_counter=0;//counts # of diffrent values
 vector<int> scores;
 vector<int> mask_alloc;

 cin >> num_students;

 for(int i=0;i<num_students;i++){
     cin >> tmp_mark;
     scores.push_back(tmp_mark);
 }

tmp_mark=-1;
 sort(scores.begin(),scores.end());
 reverse(scores.begin(),scores.end());

 for(int i=0;i<num_students;i++){
     
     if(tmp_mark!=scores[i]){
         diff_counter++;
     }

     tmp_mark = scores[i];
 }

 cout <<"\n"<<allocate_masks(num_students,diff_counter,scores) <<endl;


    return 0;
}


int allocate_masks(int num_students,int diff_counter,vector<int> scores){

  int tot_masks=0;
    for(int i=0;i<num_students;i++){

        if(diff_counter==1){
            tot_masks+= diff_counter;
        }
        else if(diff_counter==2){
            tot_masks+= diff_counter;
            diff_counter--;
        }
        else{
            diff_counter--;
            tot_masks+= diff_counter;
        }
    }

    return tot_masks;


}