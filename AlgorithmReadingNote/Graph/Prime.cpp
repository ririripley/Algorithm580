
//
// Created by 黄紫君 on 11/03/2020.
//

#include <iostream>

using namespace std;
#define LEN 30
int lowcost[LEN];
int closest[LEN];
int mp[LEN][LEN];
int num;
const int inf = 1000;
int prim(int v);
int main() {
    cin >> num;
    mp[0][0] = 0;
    mp[1][1] = 0;mp[3][3] = 0;
    mp[2][2] = 0;


    mp[0][1] = 4;mp[0][2] = 9;mp[0][3] = 21;
    mp[1][2] = 8;mp[1][3] = 17;mp[2][3] = 16;

//    for(int i = 0; i< num; i++){
//        for(int j =0; j <= i ; j++){
//            if(i == j){
//                mp[i][j] = 0;
//            }
//            else{
//                mp[i][j] = inf;
//            }
//
//
//        }
//    }
//
//    mp[0][1] = 12;mp[0][8] = 25;mp[1][2] = 10;mp[1][7] = 40;mp[1][8] = 8;mp[2][3] = 18;mp[2][6] = 55;
//    mp[4][5] = 60;mp[3][4] = 44;mp[4][6] = 38;mp[6][7] = 35;mp[7][8] = 35;
    for (int i = 0; i < num; i++){
        for(int j = i; j < num; j++)
        mp[j][i] = mp[i][j];
    }

   cout << "The least distance: " <<  prim(0) << endl;
}


int prim(int v) {
    // initialize lowcost
    for (int i = 0; i < num; i++) {
        lowcost[i] = mp[v][i];
    }

    lowcost[v] = 0;


    int dis = 0;

for(int k = 0; k < num -1; k++){
    int max = inf;
    int minone = 0;
    for (int i = 0; i < num; i++) {
//        cout << i <<" : " << lowcost[i] << endl;
        if (lowcost[i] != 0 && lowcost[i] < max) {
            max = lowcost[i];
            minone = i;
        }
    }
    if (!minone) return dis;
    cout << "p: " << minone<< endl;
    dis += lowcost[minone];
    lowcost[minone] = 0; //visited points should be set as 0
//    cout << "p: " << minone << endl;
    for (int i = 0; i < num; i++) {

        if (lowcost[i] > mp[minone][i]) {
            lowcost[i] = mp[minone][i]; // update the distance since new point has been added to the network

        }
    }
}
//    cout << "dis: " << dis << endl;
    return dis;

}
