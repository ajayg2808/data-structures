
public interface LinkedList<T> {
    public boolean add(T value);

    public boolean add(int index, T value);

    public T remove(T value);

    public T remove(int index);

    public int size();

    public boolean isEmpty();

    public void revert();

    public void display();
}
