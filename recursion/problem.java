package recursion;

public class problem {
    static int cnt = 0;
    
        public static void print(){
           if(cnt >= 10){
           return ;

       }
       System.out.println(cnt);
       cnt++;
       print();
    }
    public static void print1(int i , int n){
        if(i>n){
            return;
        }
        System.out.println("hii");
        print1(i+1,n);
    }
    public static void print2(int i , int n){
        if(i>n){
            return;
        }
        System.out.println(i);
        print2(i+1,n);
    }

    //print the sum of n numbers
    public static void sumofnum(int i , int sum){
        if(i<1){
            System.out.println(" the sum of the n number : "+sum);
            return;
        }
        sumofnum(i-1, sum+i);
    }
    //print the sumof n number with the power of 3
    public static int sum1(int n){
        if(n==0){
            return 0;
        }
        return (int)Math.pow(n, 3) + sum1(n-1);
    }
// factroial of the number
public static int fact(int n){
    if( n == 0){
        return 1;
    
    }
    return n* fact(n-1);
}

//reversing the array
public static void revarray(int n[]){
    System.out.println("shfj");
}
    public static void main(String[] args) {
        int n=4;
        sumofnum(n,0);
       System.out.println("the factroial of the number : " +fact(n));
        System.out.println("the sum of the number with the power of 3 : "+sum1(n));   
    }
    
}
