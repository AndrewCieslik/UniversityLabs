import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class Main {
    public static void czytajPLik() {
        RandomAccessFile raf = null;
        try {
            raf = new RandomAccessFile("Domy.dat", "r");
            while (raf.getFilePointer() < raf.length()) {
                System.out.println("Name: " + raf.readUTF() + " levels: " + raf.readInt() + " price: " + raf.readDouble() + " location: " + raf.readUTF());
            }
        } catch (IOException e) {
            System.err.println("Błąd odczytu pliku");
        } finally {
            if (raf != null) {
                try {
                    raf.close();
                } catch (IOException e) {
                    System.err.println("Failed closing the file: " + e.getMessage());
                }
            }
        }
    }

    public static void zmienCene() {
        try {
            RandomAccessFile raf = new RandomAccessFile("Domy.dat", "rw");

            raf.seek(0);
            while (raf.getFilePointer() < raf.length()) {

                raf.readUTF();
                System.out.println(raf.getFilePointer());
                int czytanaKondygnacja = raf.readInt();
                System.out.println(raf.getFilePointer());

                long wskaznikCeny = raf.getFilePointer();
                raf.readDouble();
                System.out.println(raf.getFilePointer());

                String czytanaLokalizacja = raf.readUTF();
                System.out.println(raf.getFilePointer());

                if (czytanaKondygnacja == 1 && czytanaLokalizacja.equals("Wies")) {
                    raf.seek(wskaznikCeny);
                    double czytanaCena = raf.readDouble();
                    raf.seek(wskaznikCeny);
                    raf.writeDouble(czytanaCena * 0.9);
                }
            }
            raf.close();
        } catch (IOException e) {
            System.err.println("Błąd odczytu pliku");
        }
    }

    public static void main (String[] args) {
        System.out.println("=== Przed zmianą cen ===");
        czytajPLik();
        System.out.println("========================");

        Parcela parcelaMiasto = new Parcela("Chata", 2, 70000, "Miasto");
        parcelaMiasto.dopiszParcele();
        Parcela parcelaNaWsi = new Parcela("Chata", 1, 90000, "Wies");
        parcelaNaWsi.dopiszParcele();
        zmienCene();

        System.out.println("=== Po zmianie cen ===");
        czytajPLik();
        System.out.println("======================");
    }
}
