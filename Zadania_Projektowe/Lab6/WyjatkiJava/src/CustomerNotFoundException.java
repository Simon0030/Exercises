public class CustomerNotFoundException extends Exception {

    static final long serialVersionUID = 1L;
    private String name;

    public CustomerNotFoundException() {

    }

    public CustomerNotFoundException(String errorMsg, String name) {
        super(errorMsg);
        this.name = name;
    }

    public String getName() {
        return name;
    }
}
