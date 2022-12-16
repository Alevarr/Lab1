#pragma once
#include "ISorter.hpp"
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include <stdio.h>

template <class T> class ShellSort : public ISorter<T>
{
  public:
    ShellSort() {}

  public:
    virtual void Sort(Sequence<T>* sequence, int (*compar) (T, T)) override 
    {
      auto select = [&] (int index) 
      {
        T item = sequence->Get(index);
        sequence->Remove(index);
        return item;
      };
      
      int len = sequence->GetLength();
      for(int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; i++)
        {
          int j;
          for(j = i; (j >= gap) && compar(sequence->Get(j - gap), sequence->Get(j)); j -= gap)
            this->Swap(sequence, j, j - gap);

        }
        
      }
    }
};