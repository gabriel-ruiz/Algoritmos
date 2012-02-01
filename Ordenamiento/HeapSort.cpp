#include "defs.h"
using namespace std;
class HeapSort
{
	public:
	
	void set(int intercambios2){	this->intercambios2 = intercambios2;	}
	
	HeapSort(int* data, int length)
	{
		this->_data = new int[length];
		this->_length = length;
		for(int i = 0; i < length; i++)
			this->_data[i] = data[i];
	}
	
	~HeapSort() 
	{
		delete[] this->_data;
	}
	
	int* sort()
	{
		this->set(intercambios2=0);
		heapsort2(this->_data, this->_length);
		return this->_data;
		
	}
	
	void empuja2(int *a, int r, int fin)
	{
        long int hijo;
        int temp;

        while (2 * r + 1 <= fin ){
                hijo = 2 * r + 1;
                if (hijo + 1 <= fin){
                        if (a[hijo] < a[hijo + 1])
                                hijo = hijo + 1;
                }
                if (a[r] < a[hijo]){
                        this->set(intercambios2 = intercambios2+1);
                        temp = a[r];
                        a[r] = a[hijo];
                        a[hijo] = temp;
                        r = hijo;
                }else
                        return;
        }
	}


	void heapify2(int *a, int n)
	{
	        long int i;
	        for (i = (n - 2) / 2; i >= 0; i--)
	        empuja2(a, i, n-1);
	}

	void heapsort2(int *a, int n)
	{
		int fin = n - 1;
		int temp;
		heapify2(a, n);
		while (fin > 0 )
		{
				temp = a[fin];
				a[fin] = a[0];
				a[0] = temp;
				this->set(intercambios2 = intercambios2+1);
				fin--;
				empuja2(a, 0, fin);
		}
	}

	int steps()
	{	
		return intercambios2;	
	}
	
	int length()
	{
		return this->_length;
	}

	protected:
		int* _data;
		int _length;
		int intercambios2;
};
