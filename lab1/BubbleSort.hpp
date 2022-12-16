#pragma once
#include "ISorter.hpp"
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include "Sequence.hpp"

template <class T> class BubbleSort : public ISorter<T>
{
  public:
    BubbleSort() {}

  public:
    virtual void Sort(Sequence<T>* sequence, int (*compar) (T, T)) override 
    {
      int len = sequence->GetLength();
      
      for (int i = 0; i < len; i++)
      {
        for (int j = 0; j < len - i -1; j++)
        {
          if( compar(sequence->Get(j), sequence->Get(j + 1)) ) this->Swap(sequence, j, j+1);
        }
        
      }
           
    }
};