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
    public static void main(String[] args) {
      int result = countdigits(3455667);
      int result1 = reversenum(1234);
      System.out.println("the result is "+result1);
      System.out.println("the result is "+result);
     
    }
    
}