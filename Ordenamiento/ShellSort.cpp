#include "defs.h"
using namespace std;
class ShellSort
{
	public:
	
	void set(int contador){	this->contador = contador;	}
	
	ShellSort(int* data, int length)
	{
		this->_data = new int[length];
		this->_length = length;
		for(int i = 0; i < length; i++)
			this->_data[i] = data[i];
	}
	
	~ShellSort() 
	{
		delete[] this->_data;
	}
	
	int* sort()
	{
		int h, b,j,i;
		this->set(contador = 0);
		for (h=1 ; h<this->length() ; h=3*h+1);
			for (; h>0 ; h/=3)
				for ( i=h ; i<this->length() ; i++)
				{
					b = this->_data[i];
					j=i;
					while (j>=h && this->_data[j-h]>b)
					{
						this->_data[j] = this->_data[j-h];
						j -= h;
						this->set(contador = contador+1);
					}
					this->_data[j] = b;
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
