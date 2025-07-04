template <typename T>
struct NodoG {
	T dato;
	NodoG* sig;
};

template <typename T>
class ListaGenerica {
private:
	NodoG<T>* inicio;
	
public:
	ListaGenerica() : inicio(nullptr) {}
	
	void agregar(T valor) {
		NodoG<T>* nuevo = new NodoG<T>{valor, inicio};
		inicio = nuevo;
	}
	
	int contarPrimos() {
		int cuenta = 0;
		NodoG<T>* aux = inicio;
		while (aux) {
			int n = aux->dato;
			if (n > 1) {
				bool primo = true;
				for (int i = 2; i * i <= n; i++) {
					if (n % i == 0) {
						primo = false;
						break;
					}
				}
				if (primo) cuenta++;
			}
			aux = aux->sig;
		}
		return cuenta;
	}
	
	void contarMayusMinus(int& mayus, int& minus) {
		mayus = minus = 0;
		NodoG<T>* aux = inicio;
		while (aux) {
			if (isupper(aux->dato)) mayus++;
			else if (islower(aux->dato)) minus++;
			aux = aux->sig;
		}
	}
};

 
