public class ComplexDocument extends Document{
	private Factory factory;
	
	public Factory getFactory(){
		factory = new LetterFactory();
		return factory;
	}
	
	public void printPhrase(){
		factory.printSymbol();
	}
}
