public class Loop<T> extends SinglyLinkedList<T> {
    private void markNotVisited() {
        if (!this.isEmpty()) {
            Node<T> node = this.head;
            do {
                node.setVisited(false);
                node = node.getNext();
            } while (node != null && node.isVisited());
        }
    }

    public void createLoop(T dest) {
        if (!this.isEmpty()) {
            if (this.search(dest) == -1) {
                System.out.println("\n Destination: ", dest, " not present in list.");
                return;
            }
            boolean found = false;
            Node<T> p, q = this.head;
            p = q;
            do {
                if (p.getValue().equals(dest)) {
                    q = p;
                }
                p = p.getNext();
            } while (p.getNext() != null);
            if (p == null) {
                p = this.head;
            } else {
                if (p.getValue().equals(dest))
                    q = p;
            }
            p.setNext(q);
        }
    }

    public boolean isConnectedLoop() {
        if (this.isEmpty())
            return false;
        this.markNotVisited();
        Node<T> q, p = this.head;
        q = p.getNext();

        while (p != null && q != null) {
            p = p.getNext();
            q = q.getNext();
            if (q != null)
                q = q.getNext();
        }
    }
}
