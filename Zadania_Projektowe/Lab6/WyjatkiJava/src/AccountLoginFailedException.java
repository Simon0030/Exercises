public class AccountLoginFailedException extends Exception {

    static final long serialVersionUID = 1L;
    private int password;
    private String login;

    private String name;
    private int accountNumber;

    public AccountLoginFailedException() {
    }

    public AccountLoginFailedException(String errorMsg, String s, int passwd) {
        super(errorMsg);
        login = s;
        password = passwd;
    }

    public AccountLoginFailedException(String errorMsg, String s, int passwd, String n, int aN) {
        super(errorMsg);
        login = s;
        password = passwd;
        name = n;
        accountNumber = aN;
    }

    public int getPassword() {
        return password;
    }

    public String getLogin() {
        return login;
    }

    public String getName() {
        return name;
    }

    public int getAccountNumber() {
        return accountNumber;
    }
}
