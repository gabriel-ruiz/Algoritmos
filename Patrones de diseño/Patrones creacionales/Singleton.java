/**
 * @author: Skyvortex Solutions
 */
public class Singleton{

	/**
	 * Debe llevar la etiqueta static para que pueda ser accedida desde fuera del objeto, sin que se cambie su valor. 
	 * Es una unica instancia, independiente de cuantas veces se solicite un singleton.
	 */
	private static Singleton INSTANCE = null;
	
	/**
	 * Un metodo estatico puede ser accedido sin instanciar la clase. (No es necesario hacer "singleton = new Singleton()").
	 * Puede ser accedido como Singleton.getInstance() en cualquier momento.
	 */
	private static void createInstance(){
		if(INSTANCE == null)	
			INSTANCE = new Singleton();
	}
	
	public static Singleton getInstance(){
		if(INSTANCE == null)
			createInstance();
        return INSTANCE;
	}
	
	/**
	 * El resto de los metodos debe ser normales y corrientes.
	 * Other methods are just normal Java functions.
	 */
	public void normalMethod(){
		//codigo fuente
	}
}
