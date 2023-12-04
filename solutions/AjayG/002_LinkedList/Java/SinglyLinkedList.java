import java.util.Scanner;

public class SinglyLinkedList<T> implements LinkedList<T>, Menu {

    protected Node<T> head = null;

    public SinglyLinkedList() {
        this.head = null;
    }

    protected class Node<S> {
        private S value;
        private Node<S> next = null;
        private boolean isVisited;

        public Node(S value) {
            this.value = value;
            this.next = null;
        }

        public Node(S value, Node<S> next) {
            this.value = value;
            this.next = next;
            this.isVisited = false;
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

        public void setVisited(boolean isVisited) {
            this.isVisited = isVisited;
        }

        public boolean isVisited() {
            return this.isVisited;
        }
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
            Node<T> t = new Node<>(value, p.getNext());
            p.setNext(t);
            return true;
        }
    }

    public T remove(T value) {
        if (this.isEmpty()) {
            return null;
        } else {
            Node<T> q, p = this.head;
            do {
                if (p.getValue().equals(value)) {
                    if (p.equals(this.head)) {
                        this.head = p.getNext();
                    } else {
                        q.setNext(p.getNext());
                    }
                    return p.getValue();
                }
                q = p;
                p = p.getNext();
            } while (p != null);
        }
        return null;
    }

    public T remove(int index) {
        if (!this.isEmpty()) {
            Node<T> q, p;
            q = p = this.head;
            if (index == 0) {
                this.head = p.getNext();
                return p.getValue();
            }
            while (p != null && --index >= 0) {
                q = p;
                p = p.getNext();
            }
            if (p != null)
                return null;

            q.setNext(p.getNext());
            return p.getValue();
        }
        return null;
    }

    public int size() {
        int count = 0;
        Node<T> p = this.head;
        while (p != null) {
            count++;
            p = p.getNext();
        }
        return count;
    }

    public int search(T value) {
        int index = -1;
        if (!this.isEmpty()) {
            index = 0;
            Node<T> p = this.head;
            while (p != null && p.getValue().equals(value)) {
                index++;
                p = p.getNext();
            }
            if (p == null)
                return -1;
            return index;
        }
        return index;
    }

    public boolean isEmpty() {
        return this.head == null;
    }

    public void revert() {
        if (!this.isEmpty()) {
            Node<T> q = null, r = null, p = this.head;
            while (p != null) {
                r = p.getNext();
                p.setNext(q);
                q = p;
                p = r;
            }
            this.head = q;
        }
    }

    public void revertRecursive() {
        if (!this.isEmpty()) {
            this.head = this.revert(this.head);
        }
    }

    private Node<T> revert(Node<T> p) {
        if (p == null || p.getNext() == null)
            return p;

        Node<T> q = this.revert(p.getNext());
        p.getNext().setNext(p);
        p.setNext(null);
        return q;
    }

    public void display() {
        Node<T> p = this.head;
        System.out.print("[ ");
        while (p != null) {
            T t = p.getValue();
            System.out.print(t + " ");
            p = p.getNext();
        }
        System.out.println("]");
    }

    public void printOptions() {
        System.out.println("1. Insert element");
        System.out.println("2. Insert element at index");
        System.out.println("3. Display List");
        System.out.println("4. Delete element");
        System.out.println("5. Delete element at index");
        System.out.println("6. Search element");
        System.out.println("7. Revert list");
        System.out.println("8. Revert list (recursive)");
    }

    public void handleMenu() {

        Scanner sc = new Scanner(System.in);
        int ch = -1;
        do {
            this.printOptions();
            System.out.println("9. Exit");
            System.out.print("Select option: ");
            sc.nextInt(ch);

            switch (ch) {
                case 1:
                    break;

                case 2:
                    break;

                case 3:
                    break;

                case 4:
                    break;

                case 5:
                    break;

                case 6:
                    break;

                case 7:
                    break;

                case 8:
                    break;

                case 9:
                    break;

                default:
                    break;
            }
        } while (ch != 9);
        sc.close();
    }
}