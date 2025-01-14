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
    public static void main(String[] args) {
        print();
    }
    
}
