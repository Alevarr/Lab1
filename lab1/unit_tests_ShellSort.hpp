#include <cassert>
#include <iostream>
#include "ArraySequence.hpp"
#include "ShellSort.hpp"
#include "Comparator.hpp"

class unit_tests_ShellSort {
  private:
    static void test_All()
    {
      int *a = new int[8];
      a[0] = 3;
      a[1] = 5;
      a[2] = 1;
      a[3] = 4;
      a[4] = 0;
      a[5] = 8;
      a[6] = 3;
      a[7] = 2;

      Sequence<int>* as = new ArraySequence<int>(a, 8);
      ShellSort<int>* shell = new ShellSort<int>();
      shell->Sort(as, ascend);
      assert(as->Get(0) == 0);
      assert(as->Get(1) == 1);
      assert(as->Get(2) == 2);
      assert(as->Get(3) == 3);
      assert(as->Get(4) == 3);
      assert(as->Get(5) == 4);
      assert(as->Get(6) == 5);
      assert(as->Get(7) == 8);

      shell->Sort(as, descend);
      assert(as->Get(0) == 8);
      assert(as->Get(1) == 5);
      assert(as->Get(2) == 4);
      assert(as->Get(3) == 3);
      assert(as->Get(4) == 3);
      assert(as->Get(5) == 2);
      assert(as->Get(6) == 1);
      assert(as->Get(7) == 0);

      delete [] a;
      delete as;
      delete shell;
    }

    public:
    static void Run()
    {
      test_All();
      std::cout << "ShellSort tests finished successfully. \n";
    }
};