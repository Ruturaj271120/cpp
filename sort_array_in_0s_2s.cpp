// // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
// // this is done by me 
// // +++++++++++++++++++++++++++++++++++++++++++++++++++++
// C++ implementation of the approach
// Beautiful string
// #include<queue>
// #include<iostream>
// #include<cstdio>
// #include<cstring>
// #include<algorithm>
// #include<vector>
// ----------------------------------------------------

// C++ program to implement
// the above approach
 
#include <bits/stdc++.h>
 

using namespace std;
 
// Stores size of the grid

int m, n;
 
// Function to check valid
// cells of the grid

bool valid(int x, int y)
{

    return (x >= 0 && x < m && y >= 0 && y < n);
}
 
// Checks for the border sides

bool border(int x, int y)
{

    return (x == 0 || x == m - 1 || y == 0 || y == n - 1);
}
 
 
// Function to find shortest distance
// between two cells of the grid

int minStep(vector<vector<int>> mat)
{
 

    // Rows of the grid

    m = mat.size();
 

    // Column of the grid

    n = mat[0].size();
 

    // Stores possible move

    // of the person

    int dx[] = { 1, -1, 0, 0 };

    int dy[] = { 0, 0, 1, -1 };
 

    // Store possible cells visited

    // by the person

    queue<pair<int,int> > pQ;
 

    // Store possible cells which

    // are burning

    queue<pair<int,int> > fQ;
 

    // Traverse the grid

    for (int i = 0; i < m; i++){
 

        for (int j = 0; j < n; j++) {
 

            // If current cell is

            // burning

            if (mat[i][j] == 2)

                fQ.push({i, j});

            // If person is in

            // the current cell

            else if (mat[i][j] == 1) {

                if (border(i, j))

                    return 0;

                pQ.push({i, j});

            }

        }

    }

    // Stores shortest distance

    // between two cells

    int depth = 0;
 

    // Check if a cell is visited

    // by the person or not

    vector<vector<int>> visited(n,vector<int>(m,0));
 

    // While pQ is not empty

    while (pQ.size()>0) {
 

        // Update depth

        depth++;
 

        // Popped all the cells from

        // pQ and mark all adjacent cells

        // of as visited

        for (int i = pQ.size(); i > 0;i--) {
 

            // Front element of

            // the queue pQ

            pair<int,int>  pos = pQ.front();
 

            // Remove front element of

            // the queue pQ

            pQ.pop();
 

            // If cuurent cell is burning

            if (mat[pos.first][pos.second] == 2)

                continue;
 

            // Find all adjacent cells

            for (int j = 0; j < 4; j++) {
 

                // Stores row number of

                // adjacent cell

                int x = pos.first + dx[j];
 

                // Stores column number

                // of adjacent cell

                int y = pos.second + dy[j];
 

                // Checks if current cell

                // is valid

                if (valid(x, y) && mat[x][y] != 2 && !visited[x][y]) {
 

                    // Mark the cell as visited

                    visited[x][y] = 1;
 

                    // Enqueue the cell

                    pQ.push(pair<int,int> (x, y));
 

                    // Checks the escape condition

                    if (border(x, y))

                        return depth;

                }

            }

        }
 

        // Burn all the adjacent cells

        // of burning cells

        for (int i = fQ.size(); i > 0; i--) {
 

            // Front element of

            // the queue fQ

            pair<int,int>  pos = fQ.front();
 

            // Delete front element of

            // the queue fQ

            fQ.pop();
 

            // Find adjacent cells of

            // burning cell

            for (int j = 0; j < 4; j++) {
 

                // Stores row number of

                // adjacent cell

                int x = pos.first + dx[j];
 

                // Stores column number

                // of adjacent cell

                int y = pos.second + dy[j];
 

                // Checks if current

                // cell is valid

                if (valid(x, y) && mat[x][y] != 2) {
 

                    mat[x][y] = 2;
 

                    // Burn all the adjacent

                    // cells of current cell

                    fQ.push(pair<int,int> (x, y));

                }

            }

        }

    }

    return -1;
}
 
// Driver Code

int main()
{
 

    // Given grid

    vector<vector<int>> grid = { { 0, 0, 0, 0 },

                     { 2, 0, 0, 0 },

                     { 2, 1, 0, 0 },

                     { 2, 2, 0, 0 } };
 

    cout<<minStep(grid);
}
// --------------------------------------


// C++ implementation of the approach
// #include <bits/stdc++.h>
// using namespace std;
 
// // Function to print the good permutation
// // of first N natural numbers
// int printPermutation(int n)
// {
//     // If n is odd
//     if (n % 2 != 0)
//         cout << -1;
 
//     // Otherwise
//     else
//         for (int i = 1; i <= n / 2; i++)
//             cout << 2 * i << " " << 2 * i - 1 << " ";
// }
 
// // Driver code
// int main()
// {
//     int n = 4;
//     printPermutation(n);
 
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// void fun(string t,int i,int n,string s){
//     if(i==n){
//         cout<<t<<endl;
//         cout<<"i0-->"<<i<<endl;
//     }
//     else{
//         cout<<"i1-->"<<i<<endl;
//         fun(t,i+1,n,s);
//         cout<<"n-->"<<n<<endl;
//         cout<<"i-->"<<i<<endl;
//         t=t+s[i];
//         fun(t,i+1,n,s);
//     }
// }

// int main(){
//     string str="abc";
//     fun("",0,str.length(),str);
    
//  } 
// #include <iostream>
// using namespace std;
 
// // Merges two subarrays of arr[].
// // First subarray is arr[l..m]
// // Second subarray is arr[m+1..r]
// void merge(int arr[], int l, int m, int r)
// {
//     cout<<"el2-->"<<l<<m<<r<<"\n";
//     int n1 = m - l + 1;
//     int n2 = r - m;
 
//     // Create temp arrays
//     int L[n1], R[n2];
 
//     // Copy data to temp arrays L[] and R[]
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];
 
//     // Merge the temp arrays back into arr[l..r]
 
//     // Initial index of first subarray
//     int i = 0;
 
//     // Initial index of second subarray
//     int j = 0;
 
//     // Initial index of merged subarray
//     int k = l;
 
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
 
//     // Copy the remaining elements of
//     // L[], if there are any
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
 
//     // Copy the remaining elements of
//     // R[], if there are any
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
 
// // l is for left index and r is
// // right index of the sub-array
// // of arr to be sorted */
// void mergeSort(int arr[],int l,int r){
//     cout<<"LR-->"<<l<<r<<"\n";
//     if(l>=r){
//         return;//returns recursively
//     }
//     int m =l+ (r-l)/2;
//     cout<<"m-->"<<l<<m<<r<<"\n";
//     mergeSort(arr,l,m);
//     cout<<"1-->"<<l<<m<<r<<"\n";
//     mergeSort(arr,m+1,r);
//     cout<<"2-->"<<l<<m<<r<<"\n";
//     merge(arr,l,m,r);
    
// }
 
// // UTILITY FUNCTIONS
// // Function to print an array
// void printArray(int A[], int size)
// {
//     for (int i = 0; i < size; i++)
//         cout << A[i] << " ";
// }
 
// // Driver code
// int main()
// {
//     int arr[] = { 12, 11, 13, 5, 6, 7 };
//     int arr_size = sizeof(arr) / sizeof(arr[0]);
 
//     cout << "Given array is \n";
//     printArray(arr, arr_size);
//     // cout<<"el1 -->"<<0<<arr_size - 1<<"\n";
//     mergeSort(arr, 0, arr_size - 1);
 
//     cout << "\nSorted array is \n";
//     printArray(arr, arr_size);
//     return 0;
// }







