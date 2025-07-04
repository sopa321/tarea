ListaSimple ordenarSeleccion(ListaSimple lista) {
	ListaSimple ordenada;
	Nodo* original = lista.getHead();
	while (original != nullptr) {
		Nodo* minNodo = original;
		Nodo* actual = original;
		while (actual != nullptr) {
			if (actual->dato < minNodo->dato) minNodo = actual;
			actual = actual->sig;
		}
		ordenada.agregar(minNodo->dato);
	
		Nodo* ant = nullptr;
		Nodo* aux = original;
		while (aux && aux != minNodo) {
			ant = aux;
			aux = aux->sig;
		}
		if (aux == original) original = original->sig;
		else if (ant) ant->sig = aux->sig;
		delete aux;
	}
	return ordenada;
}

ListaSimple combinarListasSinOrden(ListaSimple a, ListaSimple b) {
	ListaSimple resultado;
	Nodo* aux = a.getHead();
	while (aux) {
		resultado.agregar(aux->dato);
		aux = aux->sig;
	}
	aux = b.getHead();
	while (aux) {
		resultado.agregar(aux->dato);
		aux = aux->sig;
	}
	return resultado;
}

ListaSimple combinarListasConOrden(ListaSimple a, ListaSimple b) {
	ListaSimple resultado;
	Nodo* auxA = a.getHead();
	Nodo* auxB = b.getHead();
	while (auxA && auxB) {
		if (auxA->dato <= auxB->dato) {
			resultado.agregar(auxA->dato);
			auxA = auxA->sig;
		} else {
			resultado.agregar(auxB->dato);
			auxB = auxB->sig;
		}
	}
	while (auxA) {
		resultado.agregar(auxA->dato);
		auxA = auxA->sig;
	}
	while (auxB) {
		resultado.agregar(auxB->dato);
		auxB = auxB->sig;
	}
	return resultado;
}


 
