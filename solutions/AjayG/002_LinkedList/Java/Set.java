public class Set<T> extends SinglyLinkedList<T> {
    public boolean add(T value) {
        if (this.isEmpty()) {
            this.head = new Node<>(value);
            return true;
        } else {
            if (this.search(value) != -1)
                return false;
            return super.add(value);
        }
    }

    public boolean add(int index, T value) {
        if (index == 0) {
            this.head = new Node<>(value, this.head);
            return true;
        } else {
            if (this.search(value) != -1)
                return false;
            return super.add(index, value);
        }
    }
}
