import java.net.*;
import java.io.*;
public class client{
	public static void main(String[] args) throws IOException{
		Socket s = new Socket("10.110.50.78",7777);

		PrintWriter pr = new PrintWriter(s.getOutputStream());
		pr.println("ashik is sending this");
		pr.flush();
	}
}