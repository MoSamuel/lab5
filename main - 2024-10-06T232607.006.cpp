#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int linear_search(vector<string>& container, string element){
    for(int i=0; i<(int)container.size(); i++){
        if(container[i]==element)return(i);
    }
    return(-1);
}
int binary_search(vector<string>& container, string element){
    int s = 0, e = (int)container.size();
    while(s<e-1){
        int f = (s+e)/2;
        if(container[f]>element){
            e=f;
        }
        else{
            s=f;
        }
    }
    if(container[s]==element){
        return(s);
    }
    else{
        return(-1);
    }
}
vector<string> get_data(){
    vector<string> string_data_set;
    string temp = ".....";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int n = alphabet.length();
    for(int i=0; i<n; i++){
        temp[4]=alphabet[i];
        for(int j=0; j<n; j++){
            temp[3]=alphabet[j];
            for(int k=0; k<n; k++){
                temp[2]=alphabet[k];
                for(int l=0; l<n; l++){
                    temp[1]=alphabet[l];
                    for(int m=0; m<n; m++){
                        temp[0]=alphabet[m];
                        string_data_set.push_back(temp);
                    }
                }
            }
        }
    }
    sort(string_data_set.begin(), string_data_set.end());
    return(string_data_set);
}
int main()
{
    vector<string> data = get_data();
    while(1==1){
        cout << "test string: " << endl;
        string element; cin >> element;
        auto start = chrono::system_clock::now();
        cout  << "index for linear search " << linear_search(data, element) << endl;
        auto end = chrono::system_clock::now();
        cout << "time for linear search " << duration_cast<microseconds>(end - start).count() << endl;
        start = chrono::system_clock::now();
        cout << "index for binary search " << binary_search(data, element) << endl;
        end = chrono::system_clock::now();
        cout << "time for binary search " << duration_cast<microseconds>(end - start).count() << endl;
    }
    return 0;
}