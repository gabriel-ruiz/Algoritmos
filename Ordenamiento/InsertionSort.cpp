#include "defs.h"
using namespace std;
class InsertionSort
{
	public:
	
	void set(int contador){	this->contador = contador;	}
	
	InsertionSort(int* data, int length)
	{
		this->_data = new int[length];
		this->_length = length;
		for(int i = 0; i < length; i++)
			this->_data[i] = data[i];
	}
	
	~InsertionSort() 
	{
		delete[] this->_data;
	}
	
	int* sort()
	{
		int i, j, temp;
		this->set(contador = 0);
		
		for (i=1; i<this->_length; i++)
          { temp = this->_data[i];
			j = i-1;
			while ((this->_data[j] > temp) && (j >= 0) )
            {  
			 this->_data[j+1] = this->_data[j];
			 this->set(contador = contador+1);
			 j--;
            }
			this->_data[j+1] = temp;
		  }
		
		return this->_data;
		
	}

	int steps()
	{
		return contador;
	}
	
	int length()
	{
		return this->_length;
	}

	protected:
		int* _data;
		int _length;
		int contador;
};
