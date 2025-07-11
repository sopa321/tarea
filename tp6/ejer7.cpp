struct NodoAnalisis {
	int dato;
	NodoAnalisis* siguiente;
	NodoAnalisis(int d) : dato(d), siguiente(nullptr) {}
	int getDato() { return dato; }
	NodoAnalisis* getSiguiente() { return siguiente; }
};

void enigma(NodoAnalisis* nodo) {
	if(nodo != nullptr)
		if(nodo->getSiguiente() == nullptr)
		cout << nodo->getDato() << endl;
		else {
		enigma(nodo->getSiguiente());
		cout << nodo->getDato() << endl;
		}
}

int misterio(NodoAnalisis* nodo) {
	if(nodo == nullptr)
		return 0;
	else
		return misterio(nodo->getSiguiente()) + 1;
}

NodoAnalisis* desconocido(NodoAnalisis* nodo) {
	if(nodo == nullptr || nodo->getSiguiente() == nullptr)
		return nodo;
	else
		return desconocido(nodo->getSiguiente());
}

void probarAnalisis() {

	
	NodoAnalisis* n1 = new NodoAnalisis(6);
	NodoAnalisis* n2 = new NodoAnalisis(4);
	NodoAnalisis* n3 = new NodoAnalisis(9);
	NodoAnalisis* n4 = new NodoAnalisis(5);
	NodoAnalisis* n5 = new NodoAnalisis(8);
	n1->siguiente = n2;
	n2->siguiente = n3;
	n3->siguiente = n4;
	n4->siguiente = n5;
	
	cout << "\nResultado de enigma (imprime al revés):\n";
	enigma(n1);
	
	cout << "\nResultado de misterio (cantidad de nodos): " << misterio(n1) << endl;
	
	NodoAnalisis* ult = desconocido(n1);
	cout << "\nResultado de desconocido (último nodo): " << ult->getDato() << endl;
}

int main() {
	probarAnalisis();
	return 0;
}


 
