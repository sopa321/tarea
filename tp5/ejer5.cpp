void eliminarMultiplosDe3(ListaDoble& lista) {
    NodoDoble* aux = lista.inicio;
    while (aux) {
        NodoDoble* siguiente = aux->sig;
        if (aux->dato % 3 == 0) eliminarPorValor(lista, aux->dato);
        aux = siguiente;
    }
    cout << "Lista actualizada (sin múltiplos de 3): ";
    mostrarLista(lista);
