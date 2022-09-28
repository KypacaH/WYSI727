#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ifstream file("C:\\Users\\Cookiezi\\Desktop\\input2.txt");
    int n;
    vector<int> arr;
    while (file >> n){
        arr.push_back(n);
    }
    for (int i=0; i < arr.size(); i++) {
        //cout << arr[i] << " ";

    }

    int s;
    s = arr.size();
    int M[s/2][2];

    for (int i = 0; i < s/2; i++) {
        for (int j = 0; j < 2; j++) M[i][j] = arr[2*i+j];
    }
    double cos=0; double sin=0;
    cos = M[0][0] / sqrt(pow(M[0][0], 2) + pow(M[0][1], 2));
    sin = M[0][1] / sqrt(pow(M[0][0], 2) + pow(M[0][1], 2));

    int N[s/2][2];
    for (int i=0; i<s/2; i++){
        N[i][0]=M[i][0]*cos + M[i][1]*sin;
        N[i][1]=M[i][1]*cos - M[i][0]*sin;
    }
    int m=0;
    int p=0;
    int b=N[0][0];
    for (int i=0;i<s/2-1;i++){
        if (b<N[i+1][0]) {
            m=i+1; b=N[i+1][0];}
        else {
            m=m;
            b=b;
        }
    }
    b=N[0][0];
    for (int i=0;i<s/2-1;i++){
        if (b<N[i+1][0]) {
            p=p;}
        else {
            p=i;
            b=N[i+1][0];
        }

    }

    cout << "Leftmost:\t" << M[p][0]<<"\t"<<M[p][1]<< endl;
    cout << "Rightmost:\t" << M[m][0]<<"\t"<<M[m][1]<< endl;
    cout << "I changes the file" << endl;
    file.close();
    return 0;
}