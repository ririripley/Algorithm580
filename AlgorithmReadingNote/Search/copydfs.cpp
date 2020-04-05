
//
// Created by 黄紫君 on 11/03/2020.
//
#include <iostream>
#include <vector>
#define LEN 13
using namespace std;
int square[LEN][LEN];
vector< vector<int> > result;
vector<int> circum;

bool diagValid(int length, int row, int col, int rowmove, int colmove, int square[][LEN])
{
    int dupli = 0;
    while (row >= 0 && row < length && col >= 0 && col < length)
    {
        if(square[row][col] == 1)
            dupli++;
        if(dupli > 1)
            return false;
        row = row + rowmove;
        col = col + colmove;
    }
    return true;
}

bool isValidcol(int length, vector<int> content)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            square[i][j] = 0;
        }
    }
    int _size = content.size();
    for(int i = 0; i < _size;)
    {
        square[i][content[i]] = 1;
        i++;
    }
#if 0
    for(int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
			cout << square[i][j] << "  ";
		cout << endl;
	}
#endif
    for(int i = 0; i < length; i++)
    {
        int rowcopy = 0;
        for(int j = 0; j < length; j++)
        {
            if(square[i][j] == 1)
                rowcopy++;
            if(rowcopy > 1)
                return false;
        }

    }

    for(int i = 0; i < length; i++)
    {
        int columncopy = 0;
        for(int j = 0; j < length; j++)
        {
            if(square[j][i] == 1)
                columncopy++;
            if(columncopy > 1)
                return false;
        }

    }

    int row = 0;
    for (int col = 0; col < length; col++)
    {
        if(!diagValid(length, row, col, 1, 1, square))
            return false;
        if(!diagValid(length, row, col, 1, -1, square))
            return false;
    }

    int col = 0;
    for (int row = 1; row < length; row++)
    {
        if(!diagValid(length, row, col, 1, 1, square))
            return false;

    }
    col = length - 1;
    for (int row = 0; row < length; row++)
    {
        if(!diagValid(length, row, col, 1, -1, square))
            return false;
    }
    return true;
}




void dfs(vector< vector<int> >& result, vector<int>& circum, int length)
{
    static int print_ = 0;
    if(circum.size() == length)
    {
        if(print_ < 3)
        {
            for(int i = 0; i < length; i++)
            {
                cout << (circum[i] + 1) << " ";
            }
            print_++;
            cout << endl;
        }
        result.push_back(circum);
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            circum.push_back(i);
            if(isValidcol(length, circum))
            {
                dfs(result, circum, length);
            }
            //	else
            //		cout << "shit" << endl;
            circum.pop_back();
        }
    }
}

int main()
{
    int num;
    cin >> num;
//	int num = 6;
    for (int i = 0; i < LEN; i++)
    {
        for( int j = 0; j < LEN; j++)
        {
            square[i][j] = 0;
        }
    }

//	cin >> num;
    circum.clear();
    result.clear();
    dfs(result, circum, num);
    cout << result.size() << endl;

}

