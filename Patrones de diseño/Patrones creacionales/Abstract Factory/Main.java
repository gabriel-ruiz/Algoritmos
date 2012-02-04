public class Main{
	private static Document doc;
	
	public static void main(String[] args){
		if(args[0].contains("Number"))
			doc = new SimpleDocument();
		else
			doc = new ComplexDocument();
		doc.getFactory();
		doc.printPhrase();
	}
}
