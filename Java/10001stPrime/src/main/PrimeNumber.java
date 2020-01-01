package main;

import java.util.ArrayList;
import java.util.List;

public class PrimeNumber {
    private List<Long> primeNumberList;
    private Long limit;
    private boolean isPlusTwo;

    public PrimeNumber(Long limit) {
        isPlusTwo = false;
        primeNumberList = new ArrayList<>();
        primeNumberList.add(2L);
        primeNumberList.add(3L);
        this.limit = limit;
        populatePrimeNumbersList();
    }

    public Long getNthPrimeNumber(int n) {
        return primeNumberList.get(n);
    }

    private int getSize() {
        return primeNumberList.size();
    }

    private void populatePrimeNumbersList() {
        long number = 5;
        while (getSize() <= limit) {
            if (!isNotPrime(number)) {
                primeNumberList.add(number);
            }
            number = incrementNumber(number);
        }
    }

    private long incrementNumber(long i) {
        isPlusTwo = !isPlusTwo;
        return isPlusTwo ? i + 2 : i + 4;
    }

    private boolean isNotPrime(long i) {
        for (int j = 0; j < getSize(); j++) {
            long jthPrimeNumber = getNthPrimeNumber(j);
            if (jthPrimeNumber > Math.sqrt(i)) {
                return false;
            }
            if (i % jthPrimeNumber == 0) {
                return true;
            }
        }
        return false;
    }
}
