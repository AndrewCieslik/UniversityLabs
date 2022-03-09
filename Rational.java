public class Rational implements Comparable<Rational> {          //+ comparable
    private int numerator;
    private int denominator;

    public Rational(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
    }

    public int getNumerator() {
        return numerator;
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    public void setDenominator(int denominator) {
        this.denominator = denominator;
    }

    public Rational add(Rational arg) {     // +
        return new Rational((this.numerator * arg.denominator + arg.numerator * this.denominator), this.denominator * arg.denominator);
    }

    public Rational mul(Rational arg) {     // *
        return new Rational(this.numerator * arg.numerator, this.denominator * arg.denominator);
    }

    public Rational sub(Rational arg) {      // -
        return new Rational(this.numerator * arg.denominator - arg.numerator * this.denominator, this.denominator * arg.denominator);
    }

    public Rational div(Rational arg) {     // /
        return new Rational(this.numerator * arg.denominator, this.denominator * arg.numerator);
    }

    public boolean equals(Rational arg) {   // ==
        return this.numerator * arg.denominator == this.denominator * arg.numerator;
    }

    public int compareTo(Rational arg) {         //comparable (returning int: 0, -1 or 1)
        if (this.numerator * arg.denominator == this.denominator * arg.numerator)
            return 0;
        else if (this.numerator * arg.denominator > arg.numerator * this.denominator)
            return 1;
        else
            return -1;
    }

    public String toString() {
        return this.numerator/gcd(this.numerator,this.denominator) + "/" + this.denominator/gcd(this.numerator,this.denominator);
                        //   /gcd() added to shorten result
    }

    public static int gcd(int a, int b)  //greatest common divisor
    {
        if (a == 0) {
            return b;
        } else {
            return gcd(b % a, a);
        }
    }
}


