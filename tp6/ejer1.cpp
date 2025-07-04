struct Nodo {
	int dato;
	Nodo* sig;
};

class ListaSimple {
private:
	Nodo* head;
	
public:
	ListaSimple() : head(nullptr) {}
	
	void agregar(int valor) {
		Nodo* nuevo = new Nodo{valor, head};
		head = nuevo;
	}
	
	void mostrar() {
		Nodo* aux = head;
		while (aux != nullptr) {
			cout << aux->dato << " -> ";
			aux = aux->sig;
		}
		cout << "NULL" << endl;
	}
	
	int minimo() {
		if (head == nullptr) throw runtime_error("Lista vacía");
		int min = head->dato;
		Nodo* aux = head->sig;
		while (aux != nullptr) {
			if (aux->dato < min) min = aux->dato;
			aux = aux->sig;
		}
		return min;
	}
};
 
