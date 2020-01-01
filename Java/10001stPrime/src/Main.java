import main.PrimeNumber;

import java.util.Scanner;
import java.util.logging.Logger;

public class Main {
    private final static Logger logger =
            Logger.getLogger(Logger.GLOBAL_LOGGER_NAME);

    public static void main(String[] args) {

        try {
            PrimeNumber primeNumber = new PrimeNumber( 200000L);
            Scanner scanner = new Scanner(System.in);
            int testCase = scanner.nextInt();
            while (testCase-- > 0) {
                int n = scanner.nextInt();
                String primeValue = primeNumber.getNthPrimeNumber(n).toString();
                logger.info(primeValue);
            }
        } catch (Exception e) {
            logger.severe(e.getMessage());
        }
    }
}
