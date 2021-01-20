public interface SearchCustomer {
    Customer findByName (String name) throws CustomerNotFoundException;
}
