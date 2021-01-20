public class AccountNotFoundException extends Exception {

    static final long serialVersionUID = 1L;
    private Account account;

    public AccountNotFoundException() {
    }

    public AccountNotFoundException(String errorMsg, Account account) {
        super(errorMsg);
        this.account = account;
    }

    public Account getAccount() {
        return account;
    }
}
