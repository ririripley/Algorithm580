//
// Created by 黄紫君 on 11/03/2020.
//

#include <iostream>
#include <vector>

const int STEP[][2] = {
        {1, 1},
        {1, -1},
        {-1, -1},
        {-1, 1}
};

using namespace std;
bool check_constraint(vector<int> vec, int len);
void DFS(vector< vector<int> > & vecList, vector<int> vec, int len, int & total);

int main(){
    int len;
    int total = 0;

//    cout << "please input the number for N : " << endl;
    cin >> len;

    vector< vector<int> > vecList;
    vector<int> vec;
    DFS(vecList, vec, len, total);

//    cout << "The total number is : " << total << endl;


//    cout << "The solutions are listed as follows: " << endl;
    for(int i = 0 ; i < vecList.size(); i++){
        vector<int> vec_ = vecList[i];
        for (int j = 0; j < len; j++){
            cout << vec_[j] << " ";
        }
        cout << endl;
    }
    cout << total<<endl;

}

void DFS(vector< vector<int> > & vecList, vector<int> vec, int len, int & total){

    if(vec.size() == len){
        total++;
        if(vecList.size() < 3)
            vecList.push_back(vec);
        return;
    }

    // your choice
    for(int i = 1; i <= len; i++){
        vec.push_back(i);
        if (check_constraint(vec, len)){
            DFS(vecList, vec, len, total);
        }
        vec.pop_back();
    }
}

bool check_constraint(vector<int> vec, int len){
    int nums[len][len];
    for(int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            nums[i][j] = 0;
        }
    }

    for (int i = 0; i < vec.size(); i++){
        nums[i][vec[i] - 1] = 1;
    }

    for(int i =0; i < vec.size();i++){
        int row = i;
        int col = vec[i] - 1;

        // row check
        for(int k = 0, num = 0; k < len; k++){
            if(nums[row][k] == 1)
                num++;
            if(num > 1){
                return false;
            }
        }

        // column check
        for(int k = 0, num = 0; k < len; k++){
            if(nums[k][col] == 1)
                num++;
            if(num > 1){
                return false;
            }
        }

        //diagonal check

        for (int k = 0; k < 4; k++){
            int nrow = row;
            int ncol = col;

            nrow = nrow + STEP[k][0];
            ncol = ncol + STEP[k][1];

            while(nrow >= 0 && nrow < len && ncol > 0 && ncol < len){
                if(nums[nrow][ncol] == 1){
                    return false;
                }
                nrow = nrow + STEP[k][0];
                ncol = ncol + STEP[k][1];
            }
        }
    }
    return true;
}

