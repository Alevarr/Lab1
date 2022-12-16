#pragma once
#include "Sequence.hpp"

template <class T> 
class ISorter
{
public:
  virtual void Sort(Sequence<T>* sequence, int (*compar) (T, T)) = 0;
  
protected:
  void Swap(Sequence<T>* sequence, int i, int k)
  {
    if(i == k) return;
    T iElement = sequence->Get(i);
    T kElement = sequence->Get(k);

    if(k > i) {
      sequence->Remove(k);
      sequence->Remove(i);

      sequence->InsertAt(i, kElement);
      sequence->InsertAt(k, iElement);
    } else {
      sequence->Remove(i);
      sequence->Remove(k);

      sequence->InsertAt(k, iElement);
      sequence->InsertAt(i, kElement);
    }
  }
};

