import java.io.*;
import java.util.Scanner;

public class TextFilesExercise2 {
    public static void main (String[] args) throws FileNotFoundException {
        File fileRead = new File("Houses.csv");                                 //read data from Houses.csv
            try {
                FileReader fileReader = new FileReader(fileRead);
                BufferedReader bfReader = new BufferedReader(fileReader);
                bfReader.lines().forEach(System.out::println);
                bfReader.close();
            }
            catch (FileNotFoundException ex) {
                System.err.println("File does not exist");
            } catch (IOException e) {
                e.printStackTrace();
            }
        Scanner sc = new Scanner(fileRead);
        String rowReadFromFile;

        File fileWrite = new File("OneStoreyHouses.csv");                       //new csv for selected houses
        PrintWriter writer = new PrintWriter(fileWrite);

        for(int i = 0; sc.hasNext(); i++) {
            rowReadFromFile = sc.next(); sc.nextLine();                         //read Houses.csv row by row

            //only 1 storey houses in the countryside:
            if (rowReadFromFile.split(",")[2].equals("1") && rowReadFromFile.split(",")[3].equals("Wies")) {

                String price = rowReadFromFile.split(",")[1];                   //house price from second column csv (String)
                Double priceDouble = Double.parseDouble(price);                 //change String price to Double price
                priceDouble -= 0.1*priceDouble;                                 // - 10% SELL

                writer.println(rowReadFromFile.split(",")[0] + "," + priceDouble);   //write House name and sell price to new csv
            }
        }
    writer.close();
    sc.close();
    }
}
