import java.util.Random;
public class JednorekiBandyta {

    private int kosztgry;
    private int procentprzechodzacydopuli;
    private float prawdopodobienstwowygranej;
    private float pulanagrod = 0;
    private int liczbarozegranychgier = 0;
    private int liczbawygranychgier = 0;

    public JednorekiBandyta(int kosztgry, int procentprzechodzacydopuli, float prawdopodobienstwowygranej) {
        if(kosztgry<=0){
            System.out.println("Bledna wartosc kosztu gry!");
            System.out.println("Wartosc ustawiona na domyslna = 10!");
            kosztgry=10;
        }
        else {
            this.kosztgry = kosztgry;
        }
        if(!(prawdopodobienstwowygranej<0.1)&&!(prawdopodobienstwowygranej>0.2)){
            this.prawdopodobienstwowygranej = prawdopodobienstwowygranej;
        }
        else{
            System.out.println("Bledna wartosc prawdopodobienstwa!");
            System.out.println("Wartosc ustawiona na domyslna = 0.1!");
            prawdopodobienstwowygranej=0.1f;
        }
        if(!(procentprzechodzacydopuli<1)&&!(procentprzechodzacydopuli>70)){
            this.procentprzechodzacydopuli = procentprzechodzacydopuli;
        }
        else{
            System.out.println("Bledna wartosc procenta przechodzacego do puli z kazdej gry!");
            System.out.println("Wartosc ustawiona na domyslna = 10!");
            procentprzechodzacydopuli=10;
        }
        this.procentprzechodzacydopuli = procentprzechodzacydopuli;
        this.prawdopodobienstwowygranej = prawdopodobienstwowygranej;
    }

    public void setKosztPojedynczejGry(int kosztgry){
        this.kosztgry = kosztgry;
    }
    public int getKosztPojedynczejGry(){
        return kosztgry;
    }
    public int getProcentPrzechodzacyDoPuli(){
        return procentprzechodzacydopuli;
    }
    public void setProcentPrzechodzacyDoPuli(int procent){
        if((!(procent<=1))&&(!(procent>=70))){
            procentprzechodzacydopuli = procent;
        }
    }
    public void setPrawdopodobienstwoWygranej(float prawdopodobienstwo){
        if(!(prawdopodobienstwo<0.1)&&!(prawdopodobienstwo>0.2)){
            prawdopodobienstwowygranej = prawdopodobienstwo;
        }
        else{
            System.out.println("Bledna wartosc prawdopodobienstwa!");
        }
    }

    public boolean graj(){
        liczbarozegranychgier++;

        Random random = new Random();

        if(1-random.nextDouble()>1-prawdopodobienstwowygranej) { //
            System.out.println("Wygrano! " + (pulanagrod + kosztgry) + "$");
            pulanagrod = 0;
            liczbawygranychgier++;
            return true;
        }
        else{
            pulanagrod = pulanagrod+(kosztgry*((float)procentprzechodzacydopuli/100));
            return false;
        }
    }

    public float aktualnapula(){
        return pulanagrod;
    }
    public int getLiczbaRozegranychGier(){
        return liczbarozegranychgier;
    }
    public int getLiczbaWygranychGier(){
        return liczbawygranychgier;
    }
}