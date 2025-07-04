class Pila {
private:
	Nodo* tope;
	
public:
	Pila() : tope(nullptr) {}
	
	void push(int valor) {
		Nodo* nuevo = new Nodo{valor, tope};
		tope = nuevo;
	}
	
	void pop() {
		if (tope) {
			Nodo* temp = tope;
			tope = tope->sig;
			delete temp;
		}
	}
	
	int cima() {
		if (!tope) throw runtime_error("Pila vacía");
		return tope->dato;
	}
	
	bool vacia() { return tope == nullptr; }
};

class Cola {
private:
	Nodo* frente;
	Nodo* final;
	int contador;
	
public:
	Cola() : frente(nullptr), final(nullptr), contador(0) {}
	
	void encolar(int valor) {
		Nodo* nuevo = new Nodo{valor, nullptr};
		if (!frente) frente = final = nuevo;
		else {
			final->sig = nuevo;
			final = nuevo;
		}
		contador++;
	}
	
	void desencolar() {
		if (frente) {
			Nodo* temp = frente;
			frente = frente->sig;
			delete temp;
			contador--;
			if (!frente) final = nullptr;
		}
	}
	
	int primero() {
		if (!frente) throw runtime_error("Cola vacía");
		return frente->dato;
	}
	
	int cantidad() { return contador; }
};

 
