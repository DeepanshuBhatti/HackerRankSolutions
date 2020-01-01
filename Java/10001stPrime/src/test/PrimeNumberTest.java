package test;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import main.PrimeNumber;

public class PrimeNumberTest {

    private PrimeNumber primeNumber;

    @Before
    public void setUp() {
        primeNumber = new PrimeNumber( 10001L);
    }

    @Test
    public void testGetNthPrimeNumber() {

        long prime = primeNumber.getNthPrimeNumber(0);
        Assert.assertEquals(2L, prime);

        prime = primeNumber.getNthPrimeNumber(2);
        Assert.assertEquals(5L, prime);

        prime = primeNumber.getNthPrimeNumber(15);
        Assert.assertEquals(53L, prime);

        prime = primeNumber.getNthPrimeNumber(10001);
        Assert.assertEquals(104759L, prime);
    }


}