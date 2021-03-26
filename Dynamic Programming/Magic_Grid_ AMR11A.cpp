//Link to the problem: https://www.spoj.com/problems/AMR11A/
//Problem Statement: 
/*
Thanks a lot for helping Harry Potter in finding the Sorcerer's Stone of Immortality in October. Did we not tell you that it was just an online game ? uhhh! now here is the real onsite task for Harry. You are given a magrid S ( a magic grid ) having R rows and C columns. Each cell in this magrid has either a Hungarian horntail dragon that our intrepid hero has to defeat, or a flask of magic potion that his teacher Snape has left for him. A dragon at a cell (i,j) takes away |S[i][j]| strength points from him, and a potion at a cell (i,j) increases Harry's strength by S[i][j]. If his strength drops to 0 or less at any point during his journey, Harry dies, and no magical stone can revive him.

Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner cell (R,C). From a cell (i,j), Harry can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and he can not move outside the magrid. Harry has used magic before starting his journey to determine which cell contains what, but lacks the basic simple mathematical skill to determine what minimum strength he needs to start with to collect the Sorcerer's Stone. Please help him once again.

STDIN: 
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with S[i][j] < 0 contain dragons, others contain magic potions.

STDOUT: 
Output T lines, one for each case containing the minimum strength Harry should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).

Example: 
Input: 
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0

Output: 
2
1
2
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
#define pb push_back
typedef long long ll;

int solution(vi *mat, int r, int c){
    vi result[r]; 
    rep(i, r) result[i].resize(c); 
    result[r-1][c-1] = 1; 
    for(int j = c-2; j>= 0; j--){
        result[r-1][j]  = result[r-1][j+1] - mat[r-1][j];
        if(result[r-1][j] <= 0) result[r-1][j] = 1; 
    }
    for(int i = r-2; i>= 0; i--){
        result[i][c-1]  = result[i+1][c-1] - mat[i][c-1]; 
        if(result[i][c-1] <= 0) result[i][c-1] = 1; 

    }
    for(int i = r-2; i >= 0; i--){
        for(int j = c-2; j>= 0; j--){
            result[i][j] = min(result[i+1][j], result[i][j+1]) - mat[i][j]; //1
            if(result[i][j]<=0) result[i][j] = 1; 
        }
    }
    return result[0][0]; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; 
    cin >> t; 
    while(t--){
        int r, c; 
        cin >> r >> c;
        vi mat[r]; 
        rep(i, r){
            rep(j, c){
                int t; 
                cin >> t; 
                mat[i].pb(t); 
            }
        }
        // cout << "Called" << endl; 
        cout << solution(mat, r, c) << endl; 
    }
}