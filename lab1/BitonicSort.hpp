#pragma once
#include "ISorter.hpp"
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include "Student.hpp"
#include <stdio.h>

template <class T> class BitonicSort : public ISorter<T>
{
  private:
    int (*Compar)(T, T);
  public:
    BitonicSort() {}

  public:
    virtual void Sort(Sequence<T>* sequence, int (*compar) (T, T)) override 
    {
      this->Compar = compar;
      T a = sequence->Get(0);
      T b = sequence->Get(1);
      int direction = (int)(a > b) == compar(a, b) ? 1 : 0; 
      this->BitSort(sequence, 0, sequence->GetLength(), direction);
    }

  private:

    void BitMerge(Sequence<T>* sequence, int startIndex, int count, int direction)
    {
      if(count > 1) {
        int k = count / 2;
        for (int i = startIndex; i < startIndex + k; i++)
        {
          if(direction == (sequence->Get(i) > sequence->Get(i + k)))
            this->Swap(sequence, i, i+k);        
        }
        BitMerge(sequence, startIndex, k, direction);
        BitMerge(sequence, startIndex + k, k, direction);
      }
      
    }

    void BitSort(Sequence<T>* sequence, int startIndex, int count, int direction)
    {
      if(count <= 1) return;
      int k = count / 2;
      BitSort(sequence, startIndex, k, 1);
      BitSort(sequence, startIndex + k, k, 0);
      BitMerge(sequence, startIndex, count, direction);
    }
};