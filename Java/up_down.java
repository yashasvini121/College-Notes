public class main{
    public static void main(String args[]){
        String input = "uduuu";
        int ups = 0, downs = 0;
        for(int i=0; i<input.length(); i++){
            if(input.charAt(i) == 'u'){
                ups++;
            }
            else if(input.charAt(i) == 'd'){
                downs++;
            }
        }
        
        System.out.println("No of ups: " + ups);
        System.out.println("No. of downs: " + downs);
    }
}
