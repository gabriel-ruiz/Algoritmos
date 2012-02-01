/** 
 * claseUno y claseDos se declaran de la misma forma, pero se instancian como objetos distintos. Su comportamiento tambien sera distinto.
 * @author: Skyvortex Solutions
 */
public class Main{
	private static Factory claseUno;
	private static Factory claseDos;
	
	public static void main(String[] args){
		claseUno = new FirstClass();
		claseDos = new SecondClass();
		claseUno.methodOne();
		claseDos.methodTwo();
	}
}
