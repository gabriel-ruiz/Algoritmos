#include "defs.h"
using namespace std;
class BubbleSort
{
	public:
	
	void set(int contador){	this->contador = contador;	}
	
	BubbleSort(int* data, int length)
	{
		this->_data = new int[length];
		this->_length = length;
		for(int i = 0; i < length; i++)
			this->_data[i] = data[i];
	}
	
	~BubbleSort() 
	{
		delete[] this->_data;
	}
	
	int* sort()
	{
		int i,j,aux;
		this->set(contador = 0);
		for (i=this->_length-1;i>0;i--)
		{
			for (j=0;j<i;j++)
			{
				if ((this->_data[j])>(this->_data[j+1]))
				{	
					
					aux = this->_data[j];
					this->_data[j] = this->_data[j+1];
					this->_data[j+1] = aux;
					this->set(contador = contador+1);
				}
			}
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
