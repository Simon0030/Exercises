import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws AccountNotFoundException {

        Bank bank = new Bank();

        Customer klient = new Customer("Klient");
        bank.addClient(klient);
        Account account = new Account(1, klient, 123, "login");
        bank.addAccount(account);

        try {
            Customer customer = bank.findByName("Klient");
            System.out.println("Znaleziono klienta: " + customer.getName());
        } catch (CustomerNotFoundException e){
            e.printStackTrace();
        }

        try {
            Account account1 = bank.findByNumber(20);
            System.out.println("Znaleziono konto o numerze " + account1.getNumber());
        } catch (AccountNotFoundException e){
            e.printStackTrace();
        }

        try {
            Account account1 = bank.findByNumber(20);
            System.out.println("Znaleziono konto o numerze " + account1.getNumber());
        } catch (AccountNotFoundException e){
            e.fillInStackTrace();
            e.printStackTrace();
        }

        try {
            ArrayList<Account> accounts = bank.findAllCustomerAccounts(klient);
            System.out.println("Znaleziono konta klienta: " + klient.getName());
            for (Account account1: accounts){
                System.out.println(account1.getNumber() + "\t");
            }
        } catch (AccountNotFoundException e){
            e.printStackTrace();
        }

        throw  new AccountNotFoundException();



    }
}
