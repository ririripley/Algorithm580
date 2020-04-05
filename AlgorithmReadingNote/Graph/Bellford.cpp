//
// Created by 黄紫君 on 18/03/2020.
//

#include <iostream>
#define  LEN 100
#define INF 1000
using namespace std;
int DISTANCE[LEN]; //global variables should be captain written

struct EData{
    int start;
    int end;
    int dis;
    void setEData(int _start, int _end, int _dis){
        start = _start;
        end = _end;
        dis = _dis;
    }
};

bool Bellford(EData* edges, int edgnum, int vertex);

int main(){
    int edgnum;
    int vertex;

    cin >> edgnum; // 8
    cin >> vertex; // 5

    for(int i =0 ; i < vertex; i++){
        DISTANCE[i] = INF;
    }
    DISTANCE[0] = 0;


    EData* edges = new EData[edgnum];
    edges[0].setEData(0,2,-1);
    edges[1].setEData(0,1,4);
    edges[2].setEData(2,1,3);
    edges[3].setEData(3,1,5);
    edges[4].setEData(3,2,1);
    edges[5].setEData(2,3,-2);
    edges[6].setEData(4,3,-3);
    edges[7].setEData(2,4,2);



    if(Bellford(edges, edgnum, vertex))
        cout << "minimum exists!" << endl;
    else
        cout << "negative cycle exists!" << endl;

    cout << "Distance: " << endl;
    for (int i = 0 ; i < vertex; i++){
        cout << DISTANCE[i]  << endl;
    }
}

bool Bellford(EData* edges, int edgnum, int vertex) {

    for(int t = 0; t < vertex - 1; t++){
        for (int i = 0; i < edgnum; i++){
            int start = edges[i].start;
            int end = edges[i].end;
            if (DISTANCE[start] != INF){
                int dis = edges[i].dis;
//                cout << DISTANCE[end] << " before  ";
                DISTANCE[end] = (DISTANCE[end] > (DISTANCE[start] + dis) )? (DISTANCE[start] + dis) : DISTANCE[end];
// cout << start << "to end " << end <<"  DISTANCE[start] + dis " << DISTANCE[start] + dis << "   final: "<< DISTANCE[end] << endl;
          }
        }
    }

    /**
     * Check the negative cycle in the graph
     */

    for (int i = 0; i < edgnum; i++) {
        int start = edges[i].start;
        int end = edges[i].end;
        int dis = edges[i].dis;

        if (DISTANCE[end] > DISTANCE[start] + dis){
            return false;
        }
    }

    return true;
}
