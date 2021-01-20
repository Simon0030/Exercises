public class Account {

    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;

    public Account() {
    }

    public Account(int n, Customer c, int p, String l) {
        this.accountNumber = n;
        this.owner = c;
        this.password = p;
        this.login = l;
    }

    public Customer getCustomer (){
        return owner;
    }

    public int getNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    public double withdraw (double amount){
        balance =- amount;
        return balance;
    }

}
