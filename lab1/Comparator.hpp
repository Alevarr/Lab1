#pragma once
#include <iostream>
#include <functional>

template<class T>
int ascend(T a, T b)
{
  return a > b;
};

template <class T>
int descend(T a, T b)
{
  return a < b;
};


// template <class T>
// bool (*compar)(T,T) GetComparator() {
  // bool ascend = [](T a, T b)
  // {
  //   return a > b;
  // };

  // bool descend = [](T a, T b)
  // {
  //   return a < b;
  // };

//   std::cout << "Enter 1 for ascending order or 2 for descending order:\n";
//   std::cin >> option;
//   while(option != 1 && option != 2) {
//     std::cout << "Wrong input.\n";
//     std::cout << "Reenter: \n";
//     std::cin >> option;
//   }
//   return option == 1 ? ascend : descend;
// };


// template <class T>
// class Comparator
// {
//   public:

//   public:
//     static int Ascend(T a, T b) 
//     {
//       return a > b;
//     }

//     static int Descend(T a, T b)
//     {
//       return a < b;
//     }
    

//     static int (*get)(T,T) GetFunction() {
//       int ascend = [](T a, T b)
//       {
//         return a > b;
//       };

//       int descend = [](T a, T b)
//       {
//         return a < b;
//       };

//       int option;
//       std::cout << "Enter 1 for ascending order or 2 for descending order:\n";
//       std::cin >> option;
//       while(option != 1 && option != 2) {
//         std::cout << "Wrong input.\n";
//         std::cout << "Reenter: \n";
//         std::cin >> option;
//       }
//       return option == 1 ? Comparator::Ascend : Comparator::Descend;
//     }
// };

