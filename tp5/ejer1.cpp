void inicializar(ListaDoble& lista) {
    lista.inicio = nullptr;
    lista.fin = nullptr;
}

NodoDoble* crearNodo(int valor) {
    NodoDoble* nuevo = new NodoDoble;
    nuevo->dato = valor;
    nuevo->sig = nullptr;
    nuevo->ant = nullptr;
    return nuevo;
}

void insertarInicio(ListaDoble& lista, int valor) {
    NodoDoble* nuevo = crearNodo(valor);
    if (!lista.inicio) {
        lista.inicio = lista.fin = nuevo;
    } else {
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void insertarFinal(ListaDoble& lista, int valor) {
    NodoDoble* nuevo = crearNodo(valor);
    if (!lista.fin) {
        lista.inicio = lista.fin = nuevo;
    } else {
        nuevo->ant = lista.fin;
        lista.fin->sig = nuevo;
        lista.fin = nuevo;
    }
}

void insertarOrdenado(ListaDoble& lista, int valor) {
    NodoDoble* nuevo = crearNodo(valor);
    if (!lista.inicio || valor < lista.inicio->dato) {
        insertarInicio(lista, valor);
        return;
    }
    NodoDoble* actual = lista.inicio;
    while (actual->sig && actual->sig->dato < valor) {
        actual = actual->sig;
    }
    nuevo->sig = actual->sig;
    nuevo->ant = actual;
    if (actual->sig) actual->sig->ant = nuevo;
    else lista.fin = nuevo;
    actual->sig = nuevo;
}

void eliminarInicio(ListaDoble& lista) {
    if (lista.inicio) {
        NodoDoble* temp = lista.inicio;
        lista.inicio = lista.inicio->sig;
        if (lista.inicio) lista.inicio->ant = nullptr;
        else lista.fin = nullptr;
        delete temp;
    }
}

void eliminarFinal(ListaDoble& lista) {
    if (lista.fin) {
        NodoDoble* temp = lista.fin;
        lista.fin = lista.fin->ant;
        if (lista.fin) lista.fin->sig = nullptr;
        else lista.inicio = nullptr;
        delete temp;
    }
}

void eliminarPorValor(ListaDoble& lista, int valor) {
    NodoDoble* actual = lista.inicio;
    while (actual && actual->dato != valor) {
        actual = actual->sig;
    }
    if (actual) {
        if (actual == lista.inicio) eliminarInicio(lista);
        else if (actual == lista.fin) eliminarFinal(lista);
        else {
            actual->ant->sig = actual->sig;
            actual->sig->ant = actual->ant;
            delete actual;
        }
    }
}

NodoDoble* buscar(ListaDoble& lista, int valor) {
    NodoDoble* actual = lista.inicio;
    while (actual) {
        if (actual->dato == valor) return actual;
        actual = actual->sig;
    }
    return nullptr;
}

void mostrarLista(ListaDoble lista) {
    NodoDoble* aux = lista.inicio;
    while (aux) {
        cout << aux->dato << " <-> ";
        aux = aux->sig;
    }
    cout << "NULL" << endl;
}
