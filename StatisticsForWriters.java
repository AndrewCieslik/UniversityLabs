import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class StatisticsForWriters {
    public static void main(String[] args) throws FileNotFoundException {

        File file = new File("Book.txt");
        Scanner sc = new Scanner(file);
        String rowReadFromFile; int words = 0; double dots = 0; double chars = 0;

            for(int i = 0; sc.hasNext(); i++) {
                rowReadFromFile = sc.nextLine();                         //read .txt row by row
                words += countWords(rowReadFromFile);                    //count words row by row
                dots += countDots(rowReadFromFile);                      //count dots row by row
                chars += countChars(rowReadFromFile);                    //count characters row by row
            }
        System.out.println("Number of words: " + words);
        System.out.println("Dots to chars ratio: " + String.format("%.2f", dots / chars));
    }
    public static int countWords(String string) {                                  //count words
        return string.split(" ").length;
    }
    public static double countChars(String string) {
        return (double) string.chars().filter(ch -> ch != ' ').count();            //count signs without whitespaces
    }
    public static double countDots(String string) {
        return (double) string.chars().filter(ch -> ch == '.').count();            //count dots
    }
}
