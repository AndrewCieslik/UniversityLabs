import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
public class RefundacjaLekow {
    Integer refundacja(String nazwaPliku, String nazwaLeku) {

        ArrayList<String> nazwa = new ArrayList<>();
        ArrayList<String> firma = new ArrayList<>();
        ArrayList<Integer> cena = new ArrayList<>();
        ArrayList<Character> refundowane = new ArrayList<>();

        int indeks = 0;

        try {
            File file = new File(nazwaPliku + ".txt");
            Scanner sc = new Scanner(file);
            RandomAccessFile raf = new RandomAccessFile(nazwaPliku + ".WYN", "w");

            while (sc.hasNextLine()) {
                nazwa.add(sc.nextLine());
                firma.add(sc.nextLine());
                cena.add(Integer.valueOf(sc.nextLine()));
                refundowane.add(sc.nextLine().charAt(0));
            }
            sc.close();

            for (int i = 0; i < nazwa.size(); i++) {

                if (nazwaLeku.equals(nazwa.get(i))) {
                    indeks = i;
                }

                if (cena.get(i) > 50 && refundowane.get(i).equals('N')) {
                    raf.writeUTF(nazwa.get(i));
                    raf.writeInt(cena.get(i));
                }
            }
            raf.close();
        } catch (IOException e) {
            System.err.println(" Input/Output File Error");
        }
        return cena.get(indeks);
    }
}


