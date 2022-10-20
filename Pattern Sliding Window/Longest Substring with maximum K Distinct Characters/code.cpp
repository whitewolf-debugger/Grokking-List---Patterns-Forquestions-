#include <bits/stdc++.h>
using namespace std;
class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    // TODO: Write your code here
    int windowStart =0;
    int windowEnd = 0;
    vector<int> freqMap(256,0);
    int distinct =0;
    for(;windowEnd < str.size();windowEnd++) {
      if(freqMap[str[windowEnd]] == 0) {
        freqMap[str[windowEnd]]++;
        distinct++;
        while(windowStart < windowEnd && distinct > k) {
          freqMap[str[windowStart]]--;
          if(freqMap[str[windowStart]] == 0) {
            distinct--;
          }
          windowStart++;
        }
      }else {
        freqMap[str[windowEnd]]++;
      }
      maxLength = max(maxLength,windowEnd - windowStart + 1);
    }
    return maxLength;
  }
};
int main(int argc, char *argv[]) {
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 2)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 1)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("cbbebi", 3)
       << endl;
}
