 package basicmath;

class problems {
   public static int countdigits(int n){
    int cn=0;
    while(n>0){
      int last= n%10;
      n= n/10;
      cn = cn+1;
    }
    return cn;
    
   }
   public static int reversenum(int n){
    int rev=0;
    while(n>0){
      int last = n%10;
      n=n/10;
      rev=(rev*10)+last;
    }
    return rev;
   }
   public static void palindrome(int n) {
    int revnum = 0;
    int dup = n;

    while (n > 0) {
        int id = n % 10;
        revnum = (revnum * 10) + id; // Correct multiplication
        n = n / 10;
    }

    if (dup == revnum) {
        System.out.println("true");
    } else {
        System.out.println("false");
    }
}
   
    public static void main(String[] args) {
      int result = countdigits(3455667);
      int result1 = reversenum(1234);
      System.out.println("the result is "+result1);
      System.out.println("the result is "+result);
     
    }
    
}