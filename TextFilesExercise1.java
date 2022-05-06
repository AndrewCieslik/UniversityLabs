import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Random;
import java.util.Scanner;

public class TextFilesExercise1  {
    public static void main (String[] args) throws NoSuchElementException,FileNotFoundException {
        Random random = new Random();
        File file = new File("files.txt");
        PrintWriter writer = new PrintWriter(file);
        int sum = 0;
        int randomInt;
        for (int i = 0; i < 1000; i++) {
            randomInt = random.nextInt();
            writer.println(randomInt);

            sum += randomInt;
        }
        writer.close();

        int average = sum/1000;
        Scanner readFile = new Scanner(file);

        File fileBiggerThanAverage = new File("biggerThanAverage.txt");
        PrintWriter biggerWriter = new PrintWriter(fileBiggerThanAverage);

        File fileSmallerThanAverage = new File("smallerThanAverage.txt");
        PrintWriter smallerWriter = new PrintWriter(fileSmallerThanAverage);

        for (int j = 0; j < 1000; j++) {
            int read = readFile.nextInt();
            System.out.println(read);
            if (read > average) {
                biggerWriter.println(read);
            } else {
                smallerWriter.println(read);
            }
        }
        biggerWriter.close();
        smallerWriter.close();
    }
}
