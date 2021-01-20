import javax.swing.event.CaretListener;
import java.util.ArrayList;
import java.util.List;

public class Bank implements SearchAccounts, SearchCustomer{

    private ArrayList<Customer> customers = new ArrayList<>();
    private ArrayList<Account> accounts = new ArrayList<>();

    @Override
    public Account findByNumber(int number) throws AccountNotFoundException {
        for (int i = 0; i < accounts.size(); i ++){
            if (accounts.get(i).getNumber() == number){
                return accounts.get(i);
            }
        }
        throw new AccountNotFoundException();
    }

    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException {
        ArrayList<Account> customerAccounts = new ArrayList<>();
        for (int i = 0; i < accounts.size(); i ++){
            Account account = accounts.get(i);
            if (account.getCustomer().equals(cust) ){
                customerAccounts.add(account);
            }
        }
        if (customerAccounts.size() > 0){
            return customerAccounts;
        }
        throw new AccountNotFoundException();
    }

    @Override
    public Customer findByName(String name) throws CustomerNotFoundException {
        for (int i =0; i < customers.size(); i ++){
            if (customers.get(i).getName().equals(name)){
                return customers.get(i);
            }
        }
        throw new CustomerNotFoundException();
    }

    public void addClient (Customer customer){
        customers.add(customer);
    }

    public void addAccount (Account account){
        accounts.add(account);
    }
}
