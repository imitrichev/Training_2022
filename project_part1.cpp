#include <vector>
#include <thread>
#include <iostream>

class Wallet
{
    int mMoney;
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
   std::vector<std::thread> threads;
   for(int i = 0; i < N; ++i){
threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 10000));
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
       std::cout << "Test = "<<k<<" FAILED. Money in Wallet = "<<val << std::endl;
	   failed_tests++;
     }
  }
  return failed_tests;
}

int main()
{
	int N=10;
	int n=testAll(N);
	std::cout << "Tests: "<<N-n<<" PASSED, "<<n<<" FAILED."<<std::endl; 
	return n;
}
