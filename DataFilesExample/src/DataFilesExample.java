import java.io.*;

public class DataFilesExample {
    //write 3 variables to .dat and read them

    public static void main (String[] args) throws IOException {
        //write to file
        FileOutputStream fos = new FileOutputStream("DataExample.dat");
        DataOutputStream out = new DataOutputStream(fos);

        int integer = 1234;
        String string = "Example";
        double variable = 9.55;
        int integer2 = 1235;


        out.writeInt(integer);
        out.writeUTF(string);
        out.writeDouble(variable);
        out.writeInt(integer2);
        out.close();

        //read from file
        FileInputStream fis = new FileInputStream("DataExample.dat");
        DataInputStream din = new DataInputStream(fis);

        int integer1;
        String string1;
        double variable1;
        int integerNext;

        integer1 = din.readInt();
        string1 = din.readUTF();
        variable1 = din.readDouble();
        integerNext = din.readInt();


        System.out.println(integer1);
        //System.out.println(string1);
        //System.out.println(variable1);
        System.out.println(integerNext);

        din.close();
    }
}
