test
#include <vector>
#include <thread>
#include <atomic>
#include <iostream>
using namespace std;

class Wallet
{
    atomic<int> mMoney;
public:
    Wallet() :mMoney(0){}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
       for(int i = 0; i < money; ++i)
       {
          mMoney++;
       }
    }
};

int testMultithreadedWallet(int N)
{
   Wallet walletObject;
   vector<thread> threads;
   for(int i = 0; i < N; ++i){
threads.push_back(thread(&Wallet::addMoney, &walletObject, 10000));
   }

   for(int i = 0; i < threads.size() ; i++)
   {
       threads.at(i).join();
   }
   return walletObject.getMoney();
}

int testAll(int NUM_TESTS)
{
  int val = 0;
  int failed_tests=0;
  for(int k = 0; k < NUM_TESTS; k++)
  {
	 if((val = testMultithreadedWallet(k)) != k*10000)
     {
       cout << "Test = "<<k<<" FAILED. Money in Wallet = "<<val << endl;
	   failed_tests++;
     }
  }
  return failed_tests;
}

int main()
{
	int N=10;
	int n=testAll(N);
	cout << "Tests: "<<N-n<<" PASSED, "<<n<<" FAILED."<<endl; 
	return n;
}
