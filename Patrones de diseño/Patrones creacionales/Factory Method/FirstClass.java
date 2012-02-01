/**
 * Si la super clase o clase padre fuera una clase abstracta en vez de una interfaz, se puede disminuir la cantidad de metodos a implementar.
 * @author: Skyvortex Solutions
 */
public class FirstClass implements Factory{

	public void methodOne(){
		System.out.println("Metodo uno de FirstClass.");
	}
	
	public void methodTwo(){
		System.out.println("Metodo dos de FirstClass.");	
	}
}
