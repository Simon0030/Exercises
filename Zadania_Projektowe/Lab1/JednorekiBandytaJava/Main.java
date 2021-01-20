
public class Main {
    public static void main(String args[]) {

        JednorekiBandyta bandyta = new JednorekiBandyta(120, 7, 0.15f);
        while(true){
            System.out.println("Aktualna pula:"+bandyta.aktualnapula());
            if(bandyta.graj()){
                System.out.println("Liczba rozegranych gier:" + bandyta.getLiczbaRozegranychGier());
                System.out.println("Liczba  wygranych gier:"+ bandyta.getLiczbaWygranychGier());
                break;
            }
        }
    }
}
