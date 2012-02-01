#include "defs.h"

void completa(int * arr, int largo)
{
	int i,j,dif;
	
	for(i=0;i<(largo-1);i++)
	{
		if ((arr[i+1]-arr[i])!= 1 && (arr[i+1]-arr[i])!= 0)
		{
			dif=(arr[i+1]-arr[i]);
			for(j=1;j<dif;j++)
			{
				cout<<arr[i]+j<<" ";
			}
		}
	}
	cout<<endl;
}

int main(int argc, char** argv)
{
	int i, *arreglo, *arreglo2, menor_i, j, a = 2, x;
	string menor_c, opc;
	arreglo = new int[argc]; 
	arreglo2 = new int[argc];

opc = argv[1];



if (opc == "-c")
{	
	for(i=0;i<argc-a;i++)
	{
		arreglo[i] = atoi(argv[i+a]); 
	}

	BubbleSort ordenabubble(arreglo,argc-a);
	arreglo2=ordenabubble.sort();
	cout<<"Bubble Sort: "<<ordenabubble.steps()<<" pasos."<<endl;
	menor_i = ordenabubble.steps();
	menor_c = "Bubble Sort";
	
	InsertionSort ordenainsert(arreglo,argc-a);
	arreglo2=ordenainsert.sort();
	cout<<"Insertion Sort: "<<ordenainsert.steps()<<" pasos."<<endl;
	if (menor_i == ordenainsert.steps())
	{
		menor_i = ordenainsert.steps();
		menor_c = menor_c + ", Insertion Sort";
	}
	if (menor_i > ordenainsert.steps())
	{
		menor_i = ordenainsert.steps();
		menor_c = "Insertion Sort";
	}
		
	ShellSort ordenashell(arreglo,argc-a);
	arreglo2=ordenashell.sort();
	cout<<"Shell Sort: "<<ordenashell.steps()<<" pasos."<<endl;
	if (menor_i == ordenashell.steps())
	{
		menor_i = ordenashell.steps();
		menor_c = menor_c + ", Shell Sort";
	}
	if (menor_i > ordenashell.steps())
	{
		menor_i = ordenashell.steps();
		menor_c = "Shell Sort";
	}
		
	HeapSort ordenaheap(arreglo,argc-a);
	arreglo2=ordenaheap.sort();
	cout<<"Heap Sort: "<<ordenaheap.steps()<<" pasos."<<endl;
	if (menor_i == ordenaheap.steps())
	{
		menor_i = ordenaheap.steps();
		menor_c = menor_c + ", Heap Sort";
	}
	if (menor_i > ordenaheap.steps())
	{
		menor_i = ordenaheap.steps();
		menor_c = "Heap Sort";
	}
	
	cout<<"Algoritmo mas rapido: "<<menor_c<<'.'<<endl;
}

else if (opc == "-o")
{	
	for(i=0;i<argc-2;i++)
	{
		arreglo[i] = atoi(argv[i+2]); 
	}
	ShellSort ordenashell(arreglo,argc-2);
	arreglo2=ordenashell.sort();
	completa(arreglo2,argc-2);
}

else
{
	a = 1;
	for(i=0;i<argc-a;i++)
	{
		arreglo[i] = atoi(argv[i+a]); 
	}

	BubbleSort ordenabubble(arreglo,argc-a);
	arreglo2=ordenabubble.sort();
	cout<<"Bubble Sort: "<<ordenabubble.steps()<<" pasos."<<endl;
	menor_i = ordenabubble.steps();
	menor_c = "Bubble Sort";
	
	InsertionSort ordenainsert(arreglo,argc-a);
	arreglo2=ordenainsert.sort();
	cout<<"Insertion Sort: "<<ordenainsert.steps()<<" pasos."<<endl;
	if (menor_i == ordenainsert.steps())
	{
		menor_i = ordenainsert.steps();
		menor_c = menor_c + ", Insertion Sort";
	}
	if (menor_i > ordenainsert.steps())
	{
		menor_i = ordenainsert.steps();
		menor_c = "Insertion Sort";
	}
		
	ShellSort ordenashell(arreglo,argc-a);
	arreglo2=ordenashell.sort();
	cout<<"Shell Sort: "<<ordenashell.steps()<<" pasos."<<endl;
	if (menor_i == ordenashell.steps())
	{
		menor_i = ordenashell.steps();
		menor_c = menor_c + ", Shell Sort";
	}
	if (menor_i > ordenashell.steps())
	{
		menor_i = ordenashell.steps();
		menor_c = "Shell Sort";
	}
		
	HeapSort ordenaheap(arreglo,argc-a);
	arreglo2=ordenaheap.sort();
	cout<<"Heap Sort: "<<ordenaheap.steps()<<" pasos."<<endl;
	if (menor_i == ordenaheap.steps())
	{
		menor_i = ordenaheap.steps();
		menor_c = menor_c + ", Heap Sort";
	}
	if (menor_i > ordenaheap.steps())
	{
		menor_i = ordenaheap.steps();
		menor_c = "Heap Sort";
	}
	
	cout<<"Algoritmo mas rapido: "<<menor_c<<'.'<<endl;
}
	
return 0;
}

