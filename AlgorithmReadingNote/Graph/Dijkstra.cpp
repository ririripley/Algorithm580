//
// Created by 黄紫君 on 22/03/2020.
//

#include <iostream>
#define LEN 100
#define INF 1000
#include <string.h>
using namespace std;
int DIS[LEN];
int VIS[LEN];
int PATH[LEN];


void Dijkstra(int mat[][6], int num);//find the shortest path starting from NODE 0 to all other nodes

void count(int node);




int main(){

    int num = 6;

    int mat[6][6]={{0,INF,10,INF,30,100},{INF,0,5,INF,0,0},{INF,INF,0,50,INF,INF}
    ,{INF,INF,INF,0,INF,10},{INF,INF,INF,20,0,60},{INF,INF,INF,INF,INF,0}};

    memset(VIS,0,LEN);
    for(int i = 0; i < num;i++){
        DIS[i] = INF;
        PATH[i] = -1;
    }
    DIS[0] = 0;
    PATH[0] = 0;

    Dijkstra(mat,num);


    for (int i = 0; i < num; i++){
        cout << DIS[i] << endl;
    }

    cout << "START" << "    " << "END" << "     " << "PATH" << "    " << "DIS" << endl;

for (int i = 0;i < num; i++){
    count(i);
    cout << endl;
//    cout << PATH[i] << endl;
}

}


void count(int node){
    if(node == 0)
        cout << to_string(0);
    else if(PATH[node] == -1)
        cout << "no path!";
    else
    {
        count(PATH[node]);
        cout <<" -> " << to_string(node);
    }
}

void Dijkstra(int mat[][6], int num){

    for(int i = 0; i < num; i++) {
        // After every loop here, the shortest path towards one node is assured.

        int temp = INF;
        int load = -1;
        for(int j = 0; j < num; j++){
            if(!VIS[j] && DIS[j] < temp ){
                temp = DIS[j];
                load = j;
            }
        }

        if(load != -1){
            VIS[load] = 1;

            // Update Info After Adding New Point
            for(int i = 0; i < num;i++) {
                if(!VIS[i] && mat[load][i] != INF && (DIS[load] + mat[load][i] < DIS[i])){
                    DIS[i] =  mat[load][i] + DIS[load];
                    PATH[i] = load;
                }
            }
        }




    }
}
