import java.io.IOException;
import java.io.RandomAccessFile;

public class Main {

    public static void main (String[] args) {

        Parcela nowaParcela = new Parcela("Chata", 2, 70000, "Wies");
        nowaParcela.dopiszParcele();
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
            System.err.println("File error");
        }
    }
}
