 package basicmath;

class problems {

  //count teh number of digits
   public static int countdigits(int n){
    int cn=0;
    while(n>0){
      int last= n%10;
      n= n/10;
      cn = cn+1;
    }
    return cn;
    
   }
   //reverse the number
   public static int reversenum(int n){
    int rev=0;
    while(n>0){
      int last = n%10;
      n=n/10;
      rev=(rev*10)+last;
    }
    return rev;
   }
   //palindrome
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
//amstrong number
   public static void amstrong(int n){
    int sum = 0;
    int dup = n;
    while(n>0){
      int lst = n%10;
      sum = sum + (lst*lst*lst);
      n= n/10;
    }
    if(sum == dup){
      System.out.println(" yes");
    }else{
      System.out.println("no");
    }
   }
    public static void main(String[] args) {
      int result = countdigits(3455667);
      int result1 = reversenum(1234);
      amstrong(123);
      System.out.println("the result is "+result1);
      System.out.println("the result is "+result);
     
    }
    
}