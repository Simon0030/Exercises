package main;

public class GenericsType<T> {

    private T t;

    public T get() {
        return t;
    }

    public void set(T t1) {
        this.t = t1;
    }

    public static void main(String[] args) {
        GenericsType<String> type = new GenericsType<>();
        type.set("PUT"); //valid
        System.out.println(type.get());
        GenericsType type1 = new GenericsType(); //raw type
        type1.set("UAM"); //valid
        System.out.println(type1.get());
        type1.set(10); //valid and autoboxing support
        System.out.println(type1.get());

        Checker<Integer> isOddAnonymous = new Checker<Integer>() {
            @Override
            public boolean check(Integer object) {
                return object % 2 != 0;
            }
        };
        System.out.println(isOddAnonymous.check(123));
        System.out.println(isOddAnonymous.check(124));

        Checker<Integer> isOddLambda = object -> object % 2 != 0;
        System.out.println(isOddLambda.check(123));
        System.out.println(isOddLambda.check(124));
    }
}
