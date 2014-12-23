#include <iostream>
#include <vector>
#include <math.h>
#include <sys/time.h>

using namespace std;

int main(int argc, char* argv[])
{
  timeval time_start, time_end;

  gettimeofday(&time_start, NULL);
  long microsec_start = ((uint64_t)time_start.tv_sec * 1000000) + time_start.tv_usec;

  std::vector<int> primes;
  int i, j, flag, count;

  std::string input = argv[1];

  // get limit from argument provided
  int num = atoi(input.c_str());

  // loop from 2 to given limit
  for (i = 2; i <= num; i++) {
    flag = 1;
    count = primes.size();
    // loop over all primes
    for (j = 0; j < count; j++) {
      // check if prime less than the square root of the number
      if (primes[j] >= round(sqrt(i))) {
        break;
      }
      // check divisibility
      if (i % primes[j] == 0) {
        flag = 0;
        break;
      }
    }
    // if the number was not divisible add to primes
    if (flag == 1) {
      primes.push_back(i);
    }
  }

  std::vector<int>::iterator it = primes.begin();

  while (it != primes.end()) {
    cout << *it << "\n";
    it++;
  }

  cout << endl;

  gettimeofday(&time_end, NULL);
  long microsec_end = ((uint64_t)time_end.tv_sec * 1000000) + time_end.tv_usec;

  cout << "total time = " << (microsec_end - microsec_start)/1000 << endl;

  return 0;
}
