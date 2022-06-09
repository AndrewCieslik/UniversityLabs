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

                System.out.println("Długość pliku: " + raf.length());
                raf.readUTF();
                int czytanaKondygnacja = raf.readInt();
                long wskaznikCeny = raf.getFilePointer();
                raf.readDouble();
                String czytanaLokalizacja = raf.readUTF();

                    if (czytanaKondygnacja == 1 && czytanaLokalizacja.equals("Wies")) {
                        raf.seek(wskaznikCeny);
                        double czytanaCena = raf.readDouble();
                        raf.seek(wskaznikCeny);
                        raf.writeDouble(czytanaCena * 0.9);
                        raf.readUTF();
                        System.out.println("Wskaźnik na końcu pętli: " + raf.getFilePointer());
                    }
            }
            raf.close();

        } catch (IOException e) {
            System.err.println("Błąd odczytu pliku");
        }
    }

    public static void main (String[] args) {

        Parcela parcelaMiasto = new Parcela("Chata", 2, 70000, "Miasto");
        parcelaMiasto.dopiszParcele();

        Parcela parcelaNaWsi = new Parcela("Chata", 1, 90000, "Wies");
        parcelaNaWsi.dopiszParcele();

        System.out.println("=== Przed zmianą cen ===");
        czytajPLik();
        System.out.println("========================");

        zmienCene();

        System.out.println("=== Po zmianie cen ===");
        czytajPLik();
        System.out.println("======================");
    }
}
