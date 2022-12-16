#include <iostream>
#include <fstream>
#include "BubbleSort.hpp"
#include "ShellSort.hpp"
#include "BitonicSort.hpp"
#include "Sequence.hpp"
#include "Comparator.hpp"
#include "Student.hpp"
#include "Complex.hpp"
#include "unit_tests_ArraySequence.hpp"
#include "unit_tests_DynamicArray.hpp"
#include "unit_tests_LinkedList.hpp"
#include "unit_tests_ListSequence.hpp"
#include "unit_tests_BubbleSort.hpp"
#include "unit_tests_ShellSort.hpp"
#include "unit_tests_BitonicSort.hpp"
#include <cstring>
#include <chrono>
#include <sys/stat.h>

using namespace std;


inline int isPowerOfTwo(int n) {
  return (n & (n - 1)) == 0;
}

inline bool fileExists (const string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

template <typename T>
float sort_time (ISorter<T>* sort, Sequence<T>* seq)
{
  typedef chrono::high_resolution_clock Clock;
  auto t1 = Clock::now();
  auto t2 = Clock::now();
  t1 = Clock::now();
  sort->Sort(seq, ascend);
  t2 = Clock::now();
  return chrono::duration<float>(t2 - t1).count();
}

int ask(const char* msgs[], int n)
{
  int choice = -1;
  string err = "";
  while (choice < 0 || choice >= n) {
    cout << err << endl;
    err = "Wrong input";
    for (int i = 0; i < n; i++) cout << msgs[i] << endl;
    cout << "Enter option: ";
    cin >> choice;
  }
  if(!choice) choice -= 20;
  return choice;
}

void clean(Sequence<int>* bst1, Sequence<double>* bst2, Sequence<Complex>* bst3, Sequence<string>* bst4, Sequence<char>* bst5, Sequence<Student>* bst6)
{  
  if(bst1) { delete bst1; }
  if(bst2) { delete bst2; }
  if(bst3) { delete bst3; }
  if(bst4) { delete bst4; }
  if(bst5) { delete bst5; }
  if(bst6) { delete bst6; }

}

void menu()
{
  const char* MAIN[] = {
    "0. Quit",
    "1. Create sequence",
    "2. Print sequence out",
    "3. Sort",
    "4. Run tests",
    "5. Run time test for specified length",
    "6. Draw graph"
  };
  int main_size = 7;

  const char* CREATE[] = {
    "0. Quit",
    "1. Integers",
    "2. Floats",
    "3. Students"
  };
  int create_size = 4;

  const char* TREE_OPERATIONS[] = {
    "0. Quit",
    "1. Bubble Sort",
    "2. Shell Sort",
    "3. Bitonic Sort"
  };
  int tree_operations_size = 4;

  Sequence<int>* bst1      = 0;
  Sequence<double>* bst2   = 0;
  Sequence<Complex>* bst3  = 0;
  Sequence<string>* bst4   = 0;
  Sequence<char>* bst5     = 0;
  Sequence<Student>* bst6  = 0;


  auto get_len = []()
  {
    int len;
    cout << "Enter number of elements: \n";
    cin >> len;
    while(len <= 0) {
      cout << "Inappropriate number of elements.\n";
      cout << "Enter number of elements: \n";
      cin >> len;
    }
    return len;
  };
  auto get_int_by_request = [] (string message)
  {
    int n;
    cout << "Enter " << message << ": \n";
    cin >> n;
    while(n <= 0) {
      cout << "Inappropriate " << message << " given. \n";
      cout << "Enter " << message << ": \n";
      cin >> n;
    }
    return n;
  };
  auto get_int_array = [](int len)
  {
    cout << "Enter ints: \n";
    int* a = new int[len];
    for(int i = 0 ; i < len; i++) cin >> a[i];
    return a;
  };
  auto get_double_array = [](int len)
  {
    cout << "Enter elements: \n";
    double* ar = new double[len];
    for(int i = 0 ; i < len; i++) cin >> ar[i];
    return ar;
  };
  auto get_Complex_array = [](int len)
  {
    cout << "Enter elements: \n";
    Complex* arr = new Complex[len];
    double Re;
    double Im;
    for(int i = 0 ; i < len; i++) {
      cout << "Enter Re: ";
      cin >> Re;
      cout << "Enter Im: ";
      cin >> Im;
      arr[i] = Complex(Re, Im);
    }
    return arr;
  };
  auto get_string_array = [](int len)
  {
    cout << "Enter strings: \n";
    string* array = new string[len];
    for(int i = 0 ; i < len; i++) cin >> array[i];
    return array;
  };
  auto get_char_array = [](int len)
  {
    cout << "Enter chars: \n";
    char* array = new char[len];
    for(int i = 0 ; i < len; i++) cin >> array[i];
    return array;
  };
  auto get_Student_array = [](int len)
  {
    cout << "Enter Students: \n";
    Student* array = new Student[len];
    int id;
    string firstName;
    string middleName;
    string lastName;
    for(int i = 0 ; i < len; i++) {
      cout << "ID: ";
      cin >> id;
      cout << "First name: ";
      cin >> firstName;
      cout << "Middle name: ";
      cin >> middleName;
      cout << "Last name: ";
      cin >> lastName;
      array[i] = Student(id, firstName, middleName, lastName);
    }
    return array;
  };
  auto get_sequence_type = []() {
    int type;
    cout << "Enter 1 - Array Sequence \n      2 - List Sequence: \n";
    cin >> type;
    while(type != 1 && type != 2) {
      cout << "Wrong input.\n";
      cout << "Reenter: \n";
      cin >> type;
    }
    return type;
  };

  auto ask_comparator = []()
  {
    int option;
    std::cout << "Enter 1 for ascending order or 2 for descending order:\n";
    std::cin >> option;
    while(option != 1 && option != 2) {
      std::cout << "Wrong input.\n";
      std::cout << "Reenter: \n";
      std::cin >> option;
    }
    return option;
  };
  auto get_rand_ints_array = [] (int len)
  {
    int *a = new int[len];
    for(int i = 0; i < len; i++) {
      a[i] = rand();
    }
    return a;
  };

  int option = 0;
  while(option >= 0) {
    switch(option) {
      case 0:
        option = ask(MAIN, main_size);
        break;

      case 1:
        clean(bst1, bst2, bst3, bst4, bst5, bst6);
        bst1 = 0;
        bst2 = 0;
        bst3 = 0;
        bst4 = 0;
        bst5 = 0;
        bst6 = 0;

        option = ask(CREATE, create_size) + main_size - 1;
        break;

      case 2:
        if(bst1) {
          for(int i = 0; i < bst1->GetLength(); i++) cout << bst1->Get(i) << endl;
        } else if(bst2) {
          for(int i = 0; i < bst2->GetLength(); i++) cout << bst2->Get(i) << endl;
        } else if(bst3) {
          
        } else if(bst4) {
          
        } else if(bst5) {
          
        } else if(bst6) {
          for(int i = 0; i < bst6->GetLength(); i++) cout << bst6->Get(i) << endl;
        } else {
          std::cout << "No sequence created\n";
        }
        option = 0;
        break;

      case 3:
        option = ask(TREE_OPERATIONS, tree_operations_size) + main_size + create_size - 2;
        break;

      case 4: //Run tests
        unit_tests_ArraySequence::Run();
        unit_tests_DynamicArray::Run();
        unit_tests_LinkedList::Run();
        unit_tests_ListSequence::Run();
        unit_tests_BubbleSort::Run();
        unit_tests_ShellSort::Run();
        unit_tests_BitonicSort::Run();
        
        option = 0;
        break;
      case 5:
      {
        int len = get_len();
        clean(bst1, bst2, bst3, bst4, bst5, bst6);
        bst1 = 0;
        bst2 = 0;
        bst3 = 0;
        bst4 = 0;
        bst5 = 0;
        bst6 = 0;

        int *a = get_rand_ints_array(len);

        bst1 = get_sequence_type() == 1 ? (Sequence<int>*) new ArraySequence<int>(a, len) : (Sequence<int>*) new ListSequence<int>(a, len);
        Sequence<int>* bst11 = bst1->GetSubsequence(0, len-1);
        Sequence<int>* bst12 = bst1->GetSubsequence(0, len-1);

        BubbleSort<int>* bubble = new BubbleSort<int>();
        ShellSort<int>* shell = new ShellSort<int>();
        BitonicSort<int>* bitonic = new BitonicSort<int>();

        if(isPowerOfTwo(len)) {
          cout << "Bitonic sort took: " << sort_time(bitonic, bst1) << '\n';
        } else {
          cout << "Bitonic sort hasn't been launched because given array length isn't a power of two" << endl;
        }
        cout << "Shell sort took: " << sort_time(shell, bst12) << '\n';
        cout << "Bubble sort took: " << sort_time(bubble, bst11) << '\n';      

        delete bubble;
        delete shell;
        delete bitonic;
        delete bst11;
        delete bst12;
        delete []a;

        option = 0;
      }
        break;
      case 6:
      {
        clean(bst1, bst2, bst3, bst4, bst5, bst6);
        int minRange = get_int_by_request("min length");
        int maxRange = get_int_by_request("max length");
        int step = get_int_by_request("step");

        int difference = maxRange - minRange;
        if(difference < 0 || step <= 0 || minRange < 1 || maxRange < 1) {
          option = 0;
          break;
        }

        int** timeRusults = new int*[3];

        int *a = get_rand_ints_array(maxRange);

        BubbleSort<int>* bubble = new BubbleSort<int>();
        ShellSort<int>* shell = new ShellSort<int>();
        BitonicSort<int>* bitonic = new BitonicSort<int>();

        bst1 = (Sequence<int>*) new ArraySequence<int>(a, maxRange);

        ofstream f("graph1.txt", fstream::trunc);

        // f << minRange << " " << maxRange << " " << step << endl;
        // for(int seqLen = minRange; seqLen <= maxRange; seqLen += step) {
        //   ArraySequence<int>* currentSeq = (ArraySequence<int>*) bst1->GetSubsequence(0, seqLen);
        //   f << sort_time(bubble, currentSeq) << " ";
        //   delete currentSeq;
        //   cout << "Bub: " << seqLen << endl;
        // }
        // f << endl;

        // for(int seqLen = minRange; seqLen <= maxRange; seqLen += step) {
        //   ArraySequence<int>* currentSeq = (ArraySequence<int>*) bst1->GetSubsequence(0, seqLen);
        //   f << sort_time(shell, currentSeq) << " ";
        //   delete currentSeq;
        //   cout << "Shell: " << seqLen << endl;
        // }
        // f << endl;


        for(int seqLen = minRange; seqLen <= maxRange; seqLen += step) {
          if(!isPowerOfTwo(seqLen)) continue;
          ArraySequence<int>* currentSeq = (ArraySequence<int>*) bst1->GetSubsequence(0, seqLen);
          f << sort_time(bitonic, currentSeq) << " ";
          delete currentSeq;
          cout << "Bit: " << seqLen << endl;
        }
        f << endl;

        f.close();


        // auto launch_and_write = [&bst1](ISorter<int>* sort, int len, const string& filename)
        // {
        //   ofstream f(filename);
        //   ArraySequence<int>* currentSeq = (ArraySequence<int>*) bst1->GetSubsequence(0, len);
        //   float time = sort_time(sort, currentSeq);
        //   f << time << endl;
        //   delete currentSeq;
        //   f.close();
          
        // };

        // for(int seqLen = minRange - 1; seqLen < maxRange; seqLen += step) {
        //   launch_and_write(bubble, seqLen, "bubble.txt");
        //   launch_and_write(shell, seqLen, "shell.txt");
        //   if(isPowerOfTwo(seqLen)) launch_and_write(bitonic, seqLen, "bitonic.txt");
        // }
        delete bubble;
        delete shell;
        delete bitonic;
        delete [] a;
        option = 0;
      }
        break;
      
      case 7: //Create int bst
      {
        int len = get_len();
        int* a = get_int_array(len);
        int sequenceType = get_sequence_type();
        bst1 = sequenceType == 1 ? (Sequence<int>*) new ArraySequence<int>(a, len) : (Sequence<int>*) new ListSequence<int>(a, len);
        delete [] a;
        option = 0;
      }
        break;
      case 8: //Create double bst
      {
        int len = get_len();
        double* a = get_double_array(len);
        int sequenceType = get_sequence_type();
        bst2 = sequenceType == 1 ? (Sequence<double>*) new ArraySequence<double>(a, len) : (Sequence<double>*) new ListSequence<double>(a, len);
        delete [] a;
        option = 0;
      }
        break;
      
      case 9: //Create Student bst
      {
        int len = get_len();
        Student* a = get_Student_array(len);
        int sequenceType = get_sequence_type();
        bst6 = sequenceType == 1 ? (Sequence<Student>*) new ArraySequence<Student>(a, len) : (Sequence<Student>*) new ListSequence<Student>(a, len);
        delete [] a;
        option = 0;
      }
        break;
      case 10: //Bubble Sort
      {
        int compChoice = ask_comparator();
        if(compChoice == 1) {
          if(bst1) {
            BubbleSort<int>* sort = new BubbleSort<int>();
            sort->Sort(bst1, ascend);
            delete sort;
          } else if(bst2) {
            BubbleSort<double>* sort = new BubbleSort<double>();
            sort->Sort(bst2, ascend);
            delete sort;
          } else if(bst6) {
            BubbleSort<Student>* sort = new BubbleSort<Student>();
            sort->Sort(bst6, ascend);
            delete sort;
          }
        } else {
          if(bst1) {
            BubbleSort<int>* sort = new BubbleSort<int>();
            sort->Sort(bst1, descend);
            delete sort;
          } else if(bst2) {
            BubbleSort<double>* sort = new BubbleSort<double>();
            sort->Sort(bst2, descend);
            delete sort;
          } else if(bst6) {
            BubbleSort<Student>* sort = new BubbleSort<Student>();
            sort->Sort(bst6, descend);
            delete sort;
          }
        }
        option = 0;
      }
        break;
      case 11: //Shell sort
      {
        int compChoice = ask_comparator();
        if(compChoice == 1) {
          if(bst1) {
            ShellSort<int>* sort = new ShellSort<int>();
            sort->Sort(bst1, ascend);
            delete sort;
          } else if(bst2) {
            ShellSort<double>* sort = new ShellSort<double>();
            sort->Sort(bst2, ascend);
            delete sort;
          } else if(bst6) {
            ShellSort<Student>* sort = new ShellSort<Student>();
            sort->Sort(bst6, ascend);
            delete sort;
          }
        } else {
          if(bst1) {
            ShellSort<int>* sort = new ShellSort<int>();
            sort->Sort(bst1, descend);
            delete sort;
          } else if(bst2) {
            ShellSort<double>* sort = new ShellSort<double>();
            sort->Sort(bst2, descend);
            delete sort;
          } else if(bst6) {
            ShellSort<Student>* sort = new ShellSort<Student>();
            sort->Sort(bst6, descend);
            delete sort;
          }
        }
        option = 0;
      }
        break;
      case 12: //Bitonic Sort
      {
        int compChoice = ask_comparator();
        if(compChoice == 1) {
          if(bst1) {
            BitonicSort<int>* sort = new BitonicSort<int>();
            sort->Sort(bst1, ascend);
            delete sort;
          } else if(bst2) {
            BitonicSort<double>* sort = new BitonicSort<double>();
            sort->Sort(bst2, ascend);
            delete sort;
          } else if(bst6) {
            BitonicSort<Student>* sort = new BitonicSort<Student>();
            sort->Sort(bst6, ascend);
            delete sort;
          }
        } else {
          if(bst1) {
            BitonicSort<int>* sort = new BitonicSort<int>();
            sort->Sort(bst1, descend);
            delete sort;
          } else if(bst2) {
            BitonicSort<double>* sort = new BitonicSort<double>();
            sort->Sort(bst2, descend);
            delete sort;
          } else if(bst6) {
            BitonicSort<Student>* sort = new BitonicSort<Student>();
            sort->Sort(bst6, descend);
            delete sort;
          }
        }
        option = 0;
      }
        break;
      
      default:
        option = 0;
    }
  }
  clean(bst1, bst2, bst3, bst4, bst5, bst6);
}