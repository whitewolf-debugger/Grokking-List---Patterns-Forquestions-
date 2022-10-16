using namespace std;
#include <iostream>
#include <vector>
class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    // TODO: Write your code here
    int windowStart =0 ,windowEnd; 
    int runningSum = 0;
    for(windowEnd = 0; windowEnd < arr.size();windowEnd++){
      runningSum += arr[windowEnd];
      if((windowEnd - windowStart + 1 ) == k) {
        maxSum = max(maxSum,runningSum);
        runningSum -= arr[windowStart];
        windowStart++;
      }
    }
    return maxSum;
  }
};

int main(int argc, char* argv[]) {
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5}) << endl;
}
