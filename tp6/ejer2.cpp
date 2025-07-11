struct Nodo2 {
	int dato;
	Nodo2* sig;
};

class ListaContada {
public:
	Nodo2* inicio;
	Nodo2* fin;
	int contador;
	
	ListaContada() : inicio(nullptr), fin(nullptr), contador(0) {}
	
	void agregar(int valor) {
		Nodo2* nuevo = new Nodo2{valor, nullptr};
		if (!inicio) inicio = fin = nuevo;
		else {
			fin->sig = nuevo;
			fin = nuevo;
		}
		contador++;
	}
	
	void eliminar() {
		if (inicio) {
			Nodo2* temp = inicio;
			inicio = inicio->sig;
			delete temp;
			contador--;
			if (!inicio) fin = nullptr;
		}
	}
	
	int cantidad() const { return contador; }
	
	void mostrar() {
		Nodo2* aux = inicio;
		while (aux) {
			cout << aux->dato << " -> ";
			aux = aux->sig;
		}
		cout << "NULL" << endl;
	}
};
 
