import java.io.IOException;
import java.io.RandomAccessFile;

public class Parcela {
    private final String nazwaDomu;
    private final int liczbaKondygnacji;
    private final double cena;
    private final String lokalizacja;

    public Parcela(String nazwaDomu, int liczbaKondygnacji, double cena, String lokalizacja) {
        this.nazwaDomu = nazwaDomu;
        this.liczbaKondygnacji = liczbaKondygnacji;
        this.cena = cena;
        this.lokalizacja = lokalizacja;
    }

    public void dopiszParcele() {
        try {
            RandomAccessFile raf= new RandomAccessFile("Domy.dat", "rw");
            raf.seek(raf.length());
            raf.writeUTF(nazwaDomu);
            raf.writeInt(liczbaKondygnacji);
            raf.writeDouble(cena);
            raf.writeUTF(lokalizacja);
        }
        catch (IOException e) {
            System.err.println("Błąd odczytu pliku");
        }
    }
}
