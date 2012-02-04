public class SimpleDocument extends Document{
	private Factory factory;
	
	public Factory getFactory(){
		factory = new NumberFactory();
		return factory;
	}
	
	public void printPhrase(){
		factory.printSymbol();
	}
}
