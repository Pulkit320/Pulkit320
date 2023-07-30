#include "bits/stdc++.h"
using namespace std;
void helper(int r,int c,vector<vector<int>> &a,map<pair<int,int>,map<int,int>> &mp,vector<map<int,int>> row,vector<map<int,int>>col);
void solveSudoku(vector<vector<int>> a);

int main(){
    vector<vector<int>> a ={
    {0, 0, 8, 6, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 0, 4},
    {3, 6, 0, 0, 0, 1, 0, 9, 0},
    {5, 9, 0, 0, 0, 6, 0, 3, 0},
    {0, 7, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 6, 0, 0}, 
    {8, 5, 0, 4, 0, 0, 0, 0, 9},
    {0, 0, 1, 0, 0, 0, 0, 8, 0},
    {0, 0, 7, 0, 0, 5, 0, 0, 0} };
    solveSudoku(a);
    return 0;
}

void helper(int r,int c,vector<vector<int>> &a,map<pair<int,int>,map<int,int>> &mp,vector<map<int,int>> row,vector<map<int,int>>col){
    if(r==9){
        for(auto it:a){
            for(auto i:it)
                cout<<i<<" ";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    if(c==9){
        helper(r+1,0,a,mp,row,col);
        return;
    }
    if(a[r][c]!=0){
        helper(r,c+1,a,mp,row,col);
        return;
    }
    for(int i=1;i<=9;i++){
        int rw = r/3,cl = c/3;
        if(!mp[{rw,cl}][i] and !row[r][i] and !col[c][i]){
            mp[{rw,cl}][i]=true;
            row[r][i]=true;
            col[c][i]=true;
            a[r][c] = i;
            helper(r,c+1,a,mp,row,col);
            mp[{rw,cl}][i]=false;
            row[r][i]=false;
            col[c][i]=false;
            a[r][c] = 0;

        }
    }
}

void solveSudoku(vector<vector<int>> a){
    map<pair<int,int>,map<int,int>>mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j]!=0){
                mp[{i/3,j/3}][a[i][j]] = true;
                row[i][a[i][j]] = true;
                col[j][a[i][j]] = true;
            }
        }
    }
    helper(0,0,a,mp,row,col);
}