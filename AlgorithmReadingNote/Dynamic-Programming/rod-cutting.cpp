//
// Created by 黄紫君 on 10/03/2020.
//

#include <iostream>
#define CATEGORY 8
#define LEN 8
using namespace std;
int table1[CATEGORY][2] = {{1,1},{2,5},{3,8},{4,9},{5,10},{6,17},{7,17},{8,20}};
int table2[CATEGORY][2] = {{1,3},{2,5},{3,8},{4,9},{5,10},{6,17},{7,17},{8,20}};

int table[LEN + 1] = {0,0,0,0,0,0,0,0,0};

int maxvalue(int rod) {
    int maximum = 0;
    for (int j = 0; j < CATEGORY; j++) {
        if (table2[j][0] <= rod) {
            int temp = table[rod - table2[j][0]] + table2[j][1];
            if (temp > maximum)
                maximum = temp;
        }
    }
    return maximum;
}



int main(){
    int rod = 8;
    for(int i = 0; i <=rod; i++){
        table[i] = maxvalue(i);
    }
    for(int j = 0; j <= rod; j++){
        cout << table[j] << endl;
    }

}