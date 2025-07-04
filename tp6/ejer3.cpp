int buscar_indice(ListaContada& lista, int valor) {
	Nodo2* aux = lista.inicio;
	int i = 0;
	while (aux) {
		if (aux->dato == valor) return i;
		aux = aux->sig;
		i++;
	}
	return -1;
}

Nodo2* buscar_por_indice(ListaContada& lista, int pos) {
	Nodo2* aux = lista.inicio;
	int i = 0;
	while (aux) {
		if (i == pos) return aux;
		aux = aux->sig;
		i++;
	}
	return nullptr;
}

 
