using namespace std;
#include <bits/stdc++.h>
class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int sumarray = accumulate(arr.begin(),arr.end(),0);
    if(sumarray < S) return 0;
    int windowStart =0;
    int ans = INT_MAX;
    int windowEnd;
    int windowSum =0;
    for(windowEnd =0 ;windowEnd < arr.size();windowEnd++){
        windowSum += arr[windowEnd];
        while(windowStart < arr.size() && windowSum >= S) {
            windowSum -= arr[windowStart];
            ans = min(ans,(windowEnd - windowStart + 1));
            windowStart++;
        }
    }
    return ans;
  }
};
int main(int argc, char* argv[]) {
  int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
}
