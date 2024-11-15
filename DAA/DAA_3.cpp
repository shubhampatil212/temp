#include <bits/stdc++.h>

using namespace std;

struct Item {
   int value;
   int weight;
};
class Solution {
   public:
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {
         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

   }
};
// int main() {
//    int n = 7, weight = 15;
//    Item arr[n] = { {10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1} };
//    Solution obj;
//    double ans = obj.fractionalKnapsack(weight, arr, n);
//    cout << "The maximum value is " << setprecision(2) << fixed << ans;
//    return 0;
// }
int main() {
   int n, weight;
   cout << "Enter the number of items: ";
   cin >> n;
   
   cout << "Enter the maximum weight of the knapsack: ";
   cin >> weight;
   
   Item* arr = new Item[n];
   for (int i = 0; i < n; i++) {
      cout << "Enter value and weight for item " << i + 1 << ": ";
      cin >> arr[i].value >> arr[i].weight;
   }

   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   
   cout << "The maximum value is " << setprecision(2) << fixed << ans;

   delete[] arr;
   return 0;
}