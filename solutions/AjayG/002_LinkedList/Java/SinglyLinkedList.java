
public class SinglyLinkedList<T> implements LinkedList<T> {

    protected class Node<S> {
        private S value;
        private Node<S> next = null;

        public Node(S value) {
            this.value = value;
            this.next = null;
        }

        public Node(S value, Node<S> next) {
            this.value = value;
            this.next = next;
        }

        public void setValue(S value) {
            this.value = value;
        }

        public S getValue() {
            return this.value;
        }

        public void setNext(Node<S> next) {
            this.next = next;
        }

        public Node<S> getNext() {
            return this.next;
        }
    }

    private Node<T> head = null;

    public SinglyLinkedList() {
        this.head = null;
    }

    public boolean add(T value) {
        if (this.isEmpty()) {
            this.head = new Node<>(value);
            return true;
        } else {
            Node<T> p = this.head;
            while (p.getNext() != null) {
                p = p.getNext();
            }
            p.setNext(new Node<>(value));
            return true;
        }
    }

    public boolean add(int index, T value) {
        if (index == 0) {
            this.head = new Node<>(value, this.head);
            return true;
        } else {
            Node<T> p = this.head;
            while (p.getNext() != null && --index > 0) {
                p = p.getNext();
            }
            if (index > 1) {
                return false;
            }
            Node<T> t = new Node<>(value);
            t.setNext(p.getNext());
            p.setNext(t);
            return true;
        }
    }

    public T remove(T value) {
        if (this.isEmpty()) {
            return null;
        } else {
            Node<T> p = this.head;
            while (p != null && !p.getValue().equals(value)) {
                p = p.getNext();
            }
        }
        return value;
    }

    public T remove(int index) {
        return null;
    }

    public int size() {
        return 0;
    }

    public boolean isEmpty() {
        return true;
    }

    public void revert() {
    }

    public void display() {
    }
}