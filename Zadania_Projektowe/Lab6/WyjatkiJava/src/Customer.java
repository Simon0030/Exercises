public class Customer {

    private String name;

    private Customer (){
    }

    public Customer (String s){
        this.name = s;
    }

    public String getName() {
        return name;
    }

    /**W hierarchii klas metoda klasy pochodnej może mieć taki sam typ zwracany i sygnaturę jak metoda w klasie bazowej.
     * Mówimy wtedy o przesłanianiu metody klasy bazowej.
     * Wywołanie przesłoniętej metody przez klasę pochodną spowoduje zawsze wywołanie wersji metody zdefiniowanej w klasie pochodnej.
     * Wersja metody zdefiniowana w klasie bazowej jest niewidoczna w klasie pochodnej.
     */
    @Override
    public boolean equals(Object obj) {
        return ((Customer) obj).getName().equals(this.getName());
    }

}
