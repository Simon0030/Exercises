package recycling;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Wezel {
    @Deprecated
    @Override
    protected void finalize ( ) throws Throwable {
        System.out.println("Finalizowanie_obiektu");
        super.finalize();
    }

    private ArrayList<Wezel> polaczenia = new ArrayList<>();
    private HashMap<Wezel, Boolean> polaczeniaHashMap = new HashMap<>();
    private TreeMap<Wezel, Boolean> polaczeniaTreeMap = new TreeMap<>();

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        for (int i = 0; i < 100000; i++) {
            Wezel w1 = new Wezel ( ) ;
            Wezel w2 = new Wezel ( ) ;
            w1.dodajPolaczenie(w2);
            w2.dodajPolaczenie(w2);
        }
            s.nextLine();
            s.close();
    }

    public void dodajPolaczenie (Wezel wezel){
        this.polaczenia.add(wezel);
    }

    public void dodajPoloczenieHashMap (Wezel wezel, boolean b){
        this.polaczeniaHashMap.put(wezel, b);
    }

    public void dodajPolaczenieTreeMap (Wezel wezel, boolean b){
        this.polaczeniaTreeMap.put(wezel, b);
    }

}
