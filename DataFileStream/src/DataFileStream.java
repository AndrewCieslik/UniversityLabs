import java.io.*;
import java.util.ArrayList;

public class DataFileStream {

    static int liczbaSztuk;
    static int liczbaProduktów;


    public static void addToFile(String nazwaTowaru, double cena, int liczbaSztuk) {
        try {
            FileOutputStream fis = new FileOutputStream("Towar.dat");
            DataOutputStream dos = new DataOutputStream(fis);

            dos.writeUTF(nazwaTowaru);
            dos.writeDouble(cena);
            dos.writeInt(liczbaSztuk);
            liczbaProduktów++;
            dos.close();

        } catch (IOException e) {
            System.err.println("Błąd wczytywania pliku");
        }
    }

    public static int przetwarzajPlik(String nazwaPliku, String nazwaTowaru) {

        ArrayList<String> tablicaNazw = new ArrayList<String>();

        try {
            FileInputStream fis = new FileInputStream(nazwaPliku);
            DataInputStream dis = new DataInputStream(fis);

            for(int i = 0; i <liczbaProduktów; i++) {
                tablicaNazw.add(dis.readUTF());
                dis.readDouble();
                dis.readInt();
            }
            dis.close();

        } catch (IOException e) {
            System.err.println("Błąd wczytywania pliku");
        }

        System.out.println(tablicaNazw);
        return liczbaSztuk;
    };


    public static void main (String[] args) {
       //addToFile("Korzenie",20.00,200);
        addToFile("Porcelana",40.00,50);
        addToFile("Porcelana",40.00,50);

        przetwarzajPlik("Towar.dat", "Porcelana");




    }
}