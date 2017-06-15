// solution: https://www.hackerrank.com/challenges/deque-stl

#include <iostream>
#include <deque> 
using namespace std;

void pushMax(deque<int>& list, int value) {
    // keep values greater than value but update values less than value
    deque<int>::reverse_iterator it = list.rbegin();  // it would likely be faster to search from the end and stop when appropriate
    // cout << value << " -- "; 
    while (it != list.rend()) {
        if (*it < value) {
             // cout << "[" << *it << "] ";
            *it = value;
        } else {
             break;
        }
        it++;
    }
    list.push_back(value);
    // cout << "\n";
}

void printKMax(int arr[], int n, int k){
   //Write your code here.
   deque<int> list;
   for (int i = 0; i < k; i++) {
       pushMax(list, arr[i]);
   }
   
   cout << list.front();
   for (int i = k; i < n; i++) {
       list.pop_front();
       pushMax(list, arr[i]);
       cout << " "<< list.front();
   }
    
   cout << "\n";
}

int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
