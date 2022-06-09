import java.io.IOException;
import java.io.RandomAccessFile;

public class Parcela {
    private String nazwaDomu = "";
    private int liczbaKondygnacji = 0;
    private double cena = 0;
    private String lokalizacja = "";

    public Parcela() {
    }
    public Parcela(String nazwaDomu, int liczbaKondygnacji, double cena, String lokalizacja) {
        this.nazwaDomu = nazwaDomu;
        this.liczbaKondygnacji = liczbaKondygnacji;
        this.cena = cena;
        this.lokalizacja = lokalizacja;
    }
    public void dopiszParcele() {
        try {
            RandomAccessFile raf= new RandomAccessFile("Domy.dat", "rw");

            raf.writeUTF(nazwaDomu);
            raf.writeInt(liczbaKondygnacji);
            raf.writeDouble(cena);
            raf.writeUTF(lokalizacja);
        }
        catch (IOException e) {
            System.err.println("File error");
        }
    }

}
