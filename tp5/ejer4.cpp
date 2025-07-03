void mostrarMayorYMenor(ListaDoble lista) {
    if (!lista.inicio) return;
    int mayor = lista.inicio->dato;
    int menor = lista.inicio->dato;
    NodoDoble* aux = lista.inicio;
    while (aux) {
        if (aux->dato > mayor) mayor = aux->dato;
        if (aux->dato < menor) menor = aux->dato;
        aux = aux->sig;
    }
    cout << "Mayor: " << mayor << ", Menor: " << menor << endl;
}
